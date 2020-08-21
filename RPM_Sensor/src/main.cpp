#include <Arduino.h>
#include <mcp2515.h>
#include "TimerOne.h"
#include <SPI.h>
#include <can.h>
#include <EK304CAN.h>



//Pinos da CAN
  #define CAN_SCK 13
  #define CAN_SI 11
  #define CAN_SO 12
  #define CAN_CS 10
//Pino do Sensor RPM
  #define PIN_SPEED 3
//ID do Pacote de RPM
  #define RPM_PACKAGE_ID 0x002
//DLC do Pacote
  #define RPM_PACKAGE_DLC 2


//Quantidade de Dentes Faltantes
  #define NO_TEETH_NUMBER 3


//Base do Timer : 1 seg (1.000.000 microsegs) / 25Hz
 #define TMR_BASE 40000


//Cria uma instância do módulo transceiver CAN (configura pino CS)
 MCP2515 mcp2515(CAN_CS);


//Criar pacotes da CAN
can_frame canRPMSensor;


//Variaveis Globais
  int rot = 0;


void setup() 
{
 Serial.begin(9600);
 Serial.println("setup");
 setupCAN();
 Timer1.initialize(TMR_BASE);
 Timer1.attachInterrupt(send_can);

}

void loop() 
{
  RPM;

}

//Configurando a CAN
void setupCAN()
{
  CAN_Init(&mcp2515,CAN_1000KBPS);
  canRPMSensor.can_id = RPM_PACKAGE_ID;
  canRPMSensor.can_dlc = RPM_PACKAGE_DLC;

}


//Calculo da Rotacao
void RPM()
{
  //Variaveis Locais
  int n;
  int n_overflow;
  unsigned long timer;
  unsigned long init_timer;
  unsigned long diff;
  int tensao;

  //Marcando o tempo de 1 rotacao
  init_timer = micros();
  n = 0;
  while(n < NO_TEETH_NUMBER)      //Numero n de Dentes para completar 1 rotacao
  {
  tensao=analogRead(PIN_SPEED);
   if(tensao !=0 && n_overflow == 0)        //n_overflow==0 para evitar mais de uma leitura em um mesmo dente
   {
     n++;
     n_overflow = 1;
   }
   if(tensao == 0)                       //Caso a tensao volte a 0, a contagem de Dentes volta a funcionar
   {
     n_overflow = 0;
   }
  }
   timer = micros();
   diff = timer-init_timer;          //Diferenca entre o instante apos a rotacao para o anterior
   
   
   rot = 60000000/diff;
   canRPMSensor.data[0]=rot;             //1 min (60.000.000 microsegs)  /  tempo de 1 rotacao

}

//Enviando o valor RPM para a CAN
void send_can()
{
  mcp2515.sendMessage(&canRPMSensor);
}



