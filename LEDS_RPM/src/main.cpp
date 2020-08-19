#include <Arduino.h>
#include <mcp2515.h>
#include <TimerOne.h>
#include <SPI.h>


#define SPI_SCK 52 // (relógio do barramento) pino 52
#define SPI_SI 51 // (entrada escrava barramento) pino 51
#define SPI_SO 50 // (saída escrava barramento) pino 50
#define SPI_CS_CAN 53 // (seleção escravo CAN...) pino 53
#define LED_RPM 40 // (fita de LED) pino 40

MCP2515 mcp2515 (SPI_CS_CAN); // (configura pino CS)cria uma instancia do modulo transcrever CAN 

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}