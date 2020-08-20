#include <SPI.h>
#include <mcp2515.h>
#include <CAN.h>
#include <EK304CAN.h>
#include "TimerOne.h"

//Refazer bibliotecas

//Pinos da CAN - pinagem do modulo mcp2515

#define CAN_SCK 13
#define CAN_SI 11
#define CAN_SO 12
#define CAN_CS 10

//Pino do sensor

#define PIN_SPEED 3

//id sensor de RPM
#define ID_ADDRESS_SENSOR_RPM 0x002

//Defines
#define NUM_DENTES_FALTANTES 4

MCP2515 mcp2515(CAN_CS); //Pino 10 é o Slave

//Criar Pacotes para CAN
can_frame canRPM;

//Criar variaveis globais

unsigned long tempoChamadoUltimaVez;
int count = 1;

void setupCAN(); //Criar protótipo da função setupCAN
void enviarCAN();
void sensorRPM(void);

void setup()
{
  Serial.begin(9600); //inicia a serial para debug
  Serial.println("Transmissor CAN");
  pinMode(PIN_SPEED, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_SPEED), sensorRPM, RISING);

  setupCAN();
}

void loop()
{
  enviarCAN();
}

//configura o ID do sensor e o tamanho do pacote, respectivamente
void setupCAN()
{
  CAN_Init(&mcp2515, CAN_100KBPS);

  canRPM.can_id = ID_ADDRESS_SENSOR_RPM;
  canRPM.can_dlc = 2; //Pacote nunca enviado
}

//quantifica rotações
void sensorRPM(void)
{
  long diferencaTempo;
  long frequencia;

  if (count % NUM_DENTES_FALTANTES == 0)
  {
    //a cada 3 pulsos da tensão provocados pelos 3 dentes faltantes é adicionado 1 rotação
    diferencaTempo = micros() - tempoChamadoUltimaVez; //Diferença de tempo desde que foi chamado
    tempoChamadoUltimaVez = micros();

    diferencaTempo * 3;
    frequencia = 1 / diferencaTempo;
  }
  else
  {
    count++;
  }
}

void enviarCAN()
{
}