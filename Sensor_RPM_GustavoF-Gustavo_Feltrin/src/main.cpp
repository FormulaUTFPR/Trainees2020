#include <SPI.h>
#include <mcp2515.h>
#include <CAN.h>
#include <EK304CAN.h>
#include "TimerOne.h"


//Pinos da CAN - pinagem do modulo mcp2515
#define CAN_SCK 13
#define CAN_SI 11
#define CAN_SO 12
#define CAN_CS 10

//Pino do sensor
#define PIN_SPEED 3

//id sensor de RPM
#define ID_ADDRESS_SENSOR_RPM 0x002

//Define para calculo de rpm
#define NUM_DENTES_FALTANTES 3
#define segundosRPM 60
#define rpm_inicial 1000

//define timer1
#define TMR_BASE 40000
#define TMR_FUNC 1000000

bool tmrFuncOverflow = false;
bool tmrFuncEnable = true;
int tmrFuncCount = 0;

//Criar Pacotes para CAN
can_frame canRPM;
struct can_frame canMsg;

//Criar variaveis globais
unsigned long rpm =0; //variavel utilizada para calcular o rpm
unsigned long rpm_resolucao =0; //rpm com resolução de 20 que será enviado para a CAN
int count = 1; //contador para identificar uma volta completa, visto que são 3 dentes faltantes

//protótipo da função setupCAN
void setupCAN(); 
void enviarCAN();
void sensorRPM(void);
void callback();

MCP2515 mcp2515(CAN_CS);

void setup()
{
  Serial.begin(9600); //inicia a serial para debug
  Serial.println("Transmissor CAN");
  pinMode(PIN_SPEED, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_SPEED), sensorRPM, FALLING); //quando a tensão começa a diminuir aciona a função sensorRPM

  Timer1.initialize(TMR_BASE); // Inicializa o Timer1 e configura para um período de 0,04 segundos
  Timer1.attachInterrupt(enviarCAN); // Configura a função callback() como a função para ser chamada a cada interrupção do Timer1

  setupCAN();
}

void loop()
{
  sensorRPM();
  enviarCAN();
}

//configura o ID do sensor e o tamanho do pacote, respectivamente
void setupCAN()
{
  CAN_Init(&mcp2515, CAN_1000KBPS);

  canRPM.can_id = ID_ADDRESS_SENSOR_RPM;
  canRPM.can_dlc = 2; //Pacote nunca enviado
}

//função que interrompe o programa, a fim de enviar a mensagem à 25Hz
void callback()
{
    if (tmrFuncEnable == true) {
    tmrFuncCount++;
    if (tmrFuncCount >= TMR_FUNC / TMR_BASE)
    {
      tmrFuncCount = 0;
      tmrFuncOverflow = true;
    }
  }
}

//quantifica rotações
void sensorRPM(void)
{
  long diferencaTempo; //período para 1 revolução
  long frequencia; //inverso do período
  unsigned long tempoChamadoUltimaVez; //marca o tempo anterior

  if (count % NUM_DENTES_FALTANTES == 0)
  {
    //a cada 3 pulsos da tensão provocados pelos 3 dentes faltantes é adicionado 1 rotação
    diferencaTempo = micros() - tempoChamadoUltimaVez; //Diferença de tempo desde que foi chamado
    tempoChamadoUltimaVez = micros();

    diferencaTempo * 3; //define a quantidade de dentes faltando
    frequencia = 1 / diferencaTempo;
    rpm = frequencia / segundosRPM;
  }
  else
  {
    count++; //contador de dentes faltantes
  }
  //configurando resolução de 20
  if (rpm >= rpm_inicial && rpm % 20 == 0)
  {
    rpm_resolucao = rpm; //resolução do rpm 
  }
}


//enviar pacote de rpm para a CAN
void enviarCAN()
{
  if (tmrFuncOverflow == true) {
    canMsg.data[0] = rpm_resolucao;               //envia o valor de rpm na posição [0]
    canMsg.data[1] = 0x00;               //determina os outros campos como 0 [1], [2]...
    canMsg.data[2] = 0x00;            
    canMsg.data[3] = 0x00;  
    canMsg.data[4] = 0x00;
    canMsg.data[5] = 0x00;
    canMsg.data[6] = 0x00;
    canMsg.data[7] = 0x00;
    mcp2515.sendMessage(&canRPM);     //envia a CAN message
    tmrFuncOverflow = false;
  }
}