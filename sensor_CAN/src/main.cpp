#include <Arduino.h>
#include <CAN.h>
#include <mcp2515.h>
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


//Criar Pacotes para CAN
can_frame canRPM;

#define TMR_BASE 1000000
#define TMR_FUNC 250000

bool tmrFuncOverflow = false;
bool tmrFuncEnable = true;
int tmrFuncCount = 0;

void setup() {
  Serial.begin(9600); //inicia a serial para debug
  Serial.println("Transmissor CAN");

  setupCAN();

  // Inicia o barramento CAN a 1000 kbps
  if (!CAN.begin(1E6)) {
    Serial.println("Falha ao iniciar o controlador CAN"); //caso não seja possível iniciar o controlador
    while (1);
  }

  attachInterrupt(digitalPinToInterrupt(PIN_SPEED), ISR, CHANGE);

  Timer1.initialize(TMR_BASE); // Inicializa o Timer1 e configura para um período de 0,1 segundos
  Timer1.attachInterrupt(callback); // Configura a função callback() como a função para ser chamada a cada interrupção do Timer1
}

//configura o ID do sensor e o tamanho do pacote, respectivamente
void setupCAN() {
  canRPM.can_id = ID_ADDRESS_SENSOR_RPM;
  canRPM.can_dlc = 2;
}

//quantifica rotações
void sensorRPM(void) {
  int count;
  int rotacao = 0;
  float voltage;
  voltage = analogRead(PIN_SPEED);    //obtém o valor da tensão
  for (count==0; voltage != 0; count++){
    if (count % 3 == 0){
      //a cada 3 pulsos da tensão provocados pelos 3 dentes faltantes é adicionado 1 rotação
      rotacao = rotacao++;
    }
  }
}

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

void loop() {
  // put your main code here, to run repeatedly:
}