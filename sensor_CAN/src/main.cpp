#include <Arduino.h>
#include <CAN.h>
#include <mcp2515.h>
#include <TimerOne.h>

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

void setup() {
  Serial.begin(9600); //inicia a serial para debug
  Serial.println("Transmissor CAN");

  setupCAN();

  // Inicia o barramento CAN a 1000 kbps
  if (!CAN.begin(1E6)) {
    Serial.println("Falha ao iniciar o controlador CAN"); //caso não seja possível iniciar o controlador
    while (1);
  }
}

void setupCAN() {
  canRPM.can_id = ID_ADDRESS_SENSOR_RPM;
  canRPM.can_dlc = 2;
}

void sensorRPM(void) {
  float voltage;
  voltage = map(analogRead(PIN_SPEED));
  canRPM.data[0] = ();
}

void loop() {
  // put your main code here, to run repeatedly:
}