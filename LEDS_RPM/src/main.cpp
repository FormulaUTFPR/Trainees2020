#include <Arduino.h>
#include <mcp2515.h>
#include <TimerOne.h>
#include <SPI.h>

#include <Adafruit_NeoPixel.h> 


#define SPI_SCK 52 // (relógio do barramento) pino 52
#define SPI_SI 51 // (entrada escrava barramento) pino 51
#define SPI_SO 50 // (saída escrava barramento) pino 50
#define SPI_CS_CAN 53 // (seleção escravo CAN...) pino 53
#define LED_RPM 40 // (fita de LED) pino 40

MCP2515 mcp2515 (SPI_CS_CAN); // (configura pino CS) cria uma instancia do modulo transcrever CAN 

#define G 0x008000 // (LED Green)
#define Y 0xFFFF00 // (LED Yellow)
#define R 0xFF0000 // (LED Red)
#define B 0x0000FF // (LED Blue)

#define PIN 4 // (pino de controle) pino 4
#define LED_COUNT 10 // (quantidade de LEDs na fita)

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GBR + NEO_KHZ800); // cria uma instância da Classe Adafruit NeoPixel chamada "leds"

void setup() {

  Serial.begin(9600); // inicia a porta serial, configura a taxa de dados para 9600 bps
  leds.begin(); // inicia a fita de LED
  clearLEDs(); //apaga todos os LEDs
  leds.show(); //atualiza o estado dos LEDs

}

void loop() {
  // put your main code here, to run repeatedly:
}