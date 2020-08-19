#include <Arduino.h>
#include <SPI.h>                   //Biblioteca de funções do protocolo SPI 
#include <Adafruit_NeoPixel.h>    //Biblioteca grove rgb


#define LED_RPM 40                //pino da fita de led

#define SPI_SCK 52                // define SPI_SCK (clock do SPI bus) no pino 52
#define SPI_SI 51                 // define SPI_SI  (slave input do SPI bus) no pino 51
#define SPI_SO 50                 // define SPI_SO  (slave output do SPI bus) no pino 50
#define SPI_CS_CAN 53             // define SPI_CS_CAN  (slave select da CAN no SPI bus) no pino 53

#define NUMPIXELS      10         // numero de pixels da fita

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_RPM, NEO_GRB + NEO_KHZ800);   //*******


void setup() {
  
  pixels.setBrightness(255);
  pixels.begin();  //inicia a biblioteca

}

void loop() {
  for(int i=0;i<NUMPIXELS;i++){

     pixels.setPixelColor(i, pixels.Color(0,150,0));    //define as cores
     pixels.show();                                     //envia a cor

     delay(1000);

  }
}