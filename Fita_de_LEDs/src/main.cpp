#include <Arduino.h>
#include <mcp2515.h>
#include <TimerOne.h> 
#include <SPI.h> //Biblioteca de funções do protocolo SPI

//--------------------informações úteis--------------------//
//PACOTE DE RPM:21:13 06/08/2020

//ID do pacote de RPM: 0x002

//DLC do pacote: 2

//	INFORMAÇÕES DA CAN:Velocidade da rede: 1000KBPS
//--------------------------------------------------------//

#define LED_RPM 40 //Pino da fita de LED

void setup() {

//PINAGEM 

#define SPI_SCK 52    // define SPI_SCK (clock do SPI bus) no pino 52
#define SPI_SI 51     // define SPI_SI  (slave input do SPI bus) no pino 51
#define SPI_SO 50     // define SPI_SO  (slave output do SPI bus) no pino 50
#define SPI_CS_CAN 53 // define SPI_CS_CAN  (slave select da CAN no SPI bus) no pino 53


MCP2515 mcp2515(SPI_CS_CAN); // cria uma instância do módulo transciever CAN (configura pino CS)

}

void loop() {
  // put your main code here, to run repeatedly:
}