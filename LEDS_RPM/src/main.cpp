/* 
IDÉIA:
LIGOU A CHAVE: acende a fita de LEDs de forma crescente (Verde (3 leds), Amarelo (2 leds), Vermelho (2 leds) e Azul (3 leds)) 
e retorna até ficar apenas o 1 LED verde aceso.
DEU A PARTIDA: (1000 RPM) apenas o 1 LED verde aceso, conforme vai acelerando os LEDs vão se acendendo gradativamente
MAXIMO RPM: (1000 RPM antes da maxima alcançada pelo carro) todos os LEDs ficam piscando 
*/

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
#define LED_COUNT 10 // (quantidade de LEDs na fita) 10 LEDs

#define MAX_RPM 12000 // (maxima RPM possivel no carro) 12000 RPM

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GBR + NEO_KHZ800); // cria uma instância da Classe Adafruit NeoPixel chamada "leds"

void setup() {

  Serial.begin(9600); // inicia a porta serial, configura a taxa de dados para 9600 bps
  leds.begin(); // inicia a fita de LED
  clearLEDs(); //apaga todos os LEDs
  leds.show(); //atualiza o estado dos LEDs

}

void loop() {

  if (READ_RPM > 100){

    digitalWrite (LED_1, HIGH);//LIGAR LED 1
    delay (100)
    digitalWrite (LED_1, LOW);//DESLIGA LED 1
    delay (100)

  }
  if (READ_RPM > ((MAX_RPM/10).1)){
    digitalWrite (LED_2, HIGH);//LIGAR LED 2
    delay (100)
    digitalWrite (LED_2, LOW);//DESLIGA LED 2
    delay (100)
  }
  if (READ_RPM > ((MAX_RPM/10).2)){
    digitalWrite (LED_3, HIGH);//LIGAR LED 3
    delay (100)
    digitalWrite (LED_3, LOW);//DESLIGA LED 3
    delay (100)
  }
  if (READ_RPM > ((MAX_RPM/10).3)){
    digitalWrite (LED_4, HIGH);//LIGAR LED 4
    delay (100)
    digitalWrite (LED_4, LOW);//DESLIGA LED 4
    delay (100)
  }
  if (READ_RPM > ((MAX_RPM/10).4)){
    digitalWrite (LED_5, HIGH);//LIGAR LED 5
    delay (100)
    digitalWrite (LED_5, LOW);//DESLIGA LED 5
    delay (100)
  }
  if (READ_RPM > ((MAX_RPM/10).5)){
    digitalWrite (LED_6, HIGH);//LIGAR LED 6
    delay (100)
    digitalWrite (LED_6, LOW);//DESLIGA LED 6
    delay (100)
  }
  if (READ_RPM > ((MAX_RPM/10).6)){
    digitalWrite (LED_7, HIGH);//LIGAR LED 7
    delay (100)
    digitalWrite (LED_7, LOW);//DESLIGA LED 7
    delay (100)
  }
  if (READ_RPM > ((MAX_RPM/10).7)){
    digitalWrite (LED_8, HIGH);//LIGAR LED 8
    delay (100)
    digitalWrite (LED_8, LOW);//DESLIGA LED 8
    delay (100)
  }
  if (READ_RPM > ((MAX_RPM/10).8)){
    digitalWrite (LED_9, HIGH);//LIGAR LED 9
    delay (100)
    digitalWrite (LED_9, LOW);//DESLIGA LED 9
    delay (100)
  }
  if (READ_RPM > ((MAX_RPM/10).9)){
   digitalWrite (LED_10, HIGH);//LIGAR LED 10
    delay (100)
    digitalWrite (LED_10, LOW);//DESLIGA LED 10
    delay (100)
  }

 
}