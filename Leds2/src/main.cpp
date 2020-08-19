#include <SPI.h>                   //Biblioteca de funções do protocolo SPI 
#include <Adafruit_NeoPixel.h>    //Biblioteca grove rgb


#define LED_RPM 40                //pino da fita de led

#define SPI_SCK 52                // define SPI_SCK (clock do SPI bus) no pino 52
#define SPI_SI 51                 // define SPI_SI  (slave input do SPI bus) no pino 51
#define SPI_SO 50                 // define SPI_SO  (slave output do SPI bus) no pino 50
#define SPI_CS_CAN 53             // define SPI_CS_CAN  (slave select da CAN no SPI bus) no pino 53

#define NUMPIXELS      10         // numero de pixels da fita

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED_RPM, NEO_GRB + NEO_KHZ800);   //*******


void setup() {
  
  strip.begin();
  strip.setBrightness(40);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  for(int i=0;i<NUMPIXELS;i++){

     pixels.setPixelColor(i, pixels.Color(0,150,0));    //define as cores
     pixels.show();                                     //envia a cor

     delay(1000);

  }
}