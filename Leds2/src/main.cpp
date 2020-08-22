#include <SPI.h>                    //Biblioteca de funções do protocolo SPI 
#include <mcp2515.h>               //Biblioteca REDE CAN
#include <Adafruit_NeoPixel.h>     //Biblioteca GROVE RGB

#define CAN_SCK 13                //Pinos da CAN(modulo mcp2515)
#define CAN_SI 11
#define CAN_SO 12
#define CAN_CS 10

#define LED_RPM 40                //Pino da fita de led

#define SPI_SCK 52                //Define clock do SPI bus
#define SPI_SI 51                 //Define SPI_SI slave input do SPI bus
#define SPI_SO 50                 //Define SPI_SO slave output do SPI bus
#define SPI_CS_CAN 53             //Define SPI_CS_CAN slave select da CAN no SPI bus 

MCP2515 mcp2515(SPI_CS_CAN);      //Pino where SPI CS is connected
struct can_frame canMsg;          //Armazena o formato de mensagem CAN 

int NUMPIXELS;               //Numero de pixels da fita
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED_RPM, NEO_GRB + NEO_KHZ800); 
int RPM;                          //Variavel global que armazena o valor rpm
void setupCAN();
void taskCAN();
void fitaLED();

void setup() {
  setupCAN();
  SPI.begin();                    //Inicia a biblioteca SPI
  strip.begin();                  //Inicia a bilbioteca dos leds
  strip.setBrightness(40);        //Seta o brilho dos leds
  strip.show();                   //Inicializa todos os pixels em nivel baixo
}

void loop() 
{
  taskCAN();
  fitaLED();
}

void setupCAN()                   //Funcao que prototipa o modulo 2515
{
  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS, MCP_16MHZ); 
  mcp2515.setNormalMode();
}

void taskCAN()                    //Funcao que recebe o valor do sensor
{
  if (mcp2515.readMessage (&canMsg) == MCP2515 :: ERROR_OK)   
    mcp2515.readMessage(&canMsg);
  
    switch(canMsg.can_id)
    {
      case 0x002:
      RPM = canMsg.data[1];
      RPM = RPM << 8;
      RPM += canMsg.data[0];
      break;
    }
}

void fitaLED()                                        //Funcao que define as cores da fita de led
{      
  int numeroRPMPixels = int(RPM/1000);
  NUMPIXELS = numeroRPMPixels;

  for(int i=0;i<NUMPIXELS;i++)
  {

    if (RPM>=1000 && RPM<2200)
    {
      strip.setPixelColor(i, strip.Color(0,255,0));      //define a cor VERDE PURO
      strip.show();                                      //envia a cor
    }
                                           
    if (RPM>=2200 && RPM<3400)
    {
      strip.setPixelColor(i, strip.Color(112,250,7));    //define a cor VERDE
      strip.show();                                      //envia a cor
    }

    if (RPM>=3400 && RPM<4600)
    {
      strip.setPixelColor(i, strip.Color(130,255,0));    //define a cor VERDE
      strip.show();                                      //envia a cor
    }

    if (RPM>=4600 && RPM<5800)
    {
      strip.setPixelColor(i, strip.Color(166,255,13));    //define a cor VERDE
      strip.show();                                       //envia a cor
    }

    if (RPM>=5800 && RPM<7000)
    {
      strip.setPixelColor(i, strip.Color(222,255,13));    //define a cor AMARELO
      strip.show();                                       //envia a cor
    }

    if (RPM>=7000 && RPM<8200)
    {
      strip.setPixelColor(i, strip.Color(255,255,0));     //define a cor AMARELO PURO 
      strip.show();                                       //envia a cor
    }

    if (RPM>=8200 && RPM<9400)
    {
      strip.setPixelColor(i, strip.Color(250,221,7));     //define as cor AMARELO
      strip.show();                                       //envia a cor
    }

    if (RPM>=9400 && RPM<10600)
    {
      strip.setPixelColor(i, strip.Color(255,197,13));    //define as cor AMARELO
      strip.show();                                       //envia a cor
    }

    if (RPM>=10600 && RPM<11800)
    {
      strip.setPixelColor(i, strip.Color(255,92,13));     //define a cor LARANJA
      strip.show();                                       //envia a cor
    }

    if (RPM>=11800 && RPM<13000)
    {
      strip.setPixelColor(i, strip.Color(255,0,0));       //define a cor  VERMELHO PURO
      strip.show();                                       //envia a cor
    }
 
  }
}