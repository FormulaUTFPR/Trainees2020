//--------------inclusão de bibliotecas--------------//
#include <mcp2515.h> //mcp2515 module function libery
#include <SPI.h>     //SPI protocol function libery
#include <EK304CAN.h>
#include <CAN.h>
#include "Adafruit_NeoPixel.h" //coisa do LED
//--------------------------------------------------//

//---------------------------pinagem--------------------------------//
#define SPI_SCK 52    // define SPI_SCK (SPI's clock bus) as 52 pin
#define SPI_SI 51     // define SPI_SI  (SPI's slave input bus) as 51 pin
#define SPI_SO 50     // define SPI_SO  (slave output do SPI bus) as 50 pin
#define SPI_CS_CAN 53 // define SPI_CS_CAN  (CAN's slave select on SPI bus) as 53 pin
#define LED 40        // define LED tape as 40 pin
//------------------------------------------------------------------//

#define RPM_CAN_ID 0x002 //define RPM ID as 0x002
#define NUMPIXELS 10     //numero de LEDs da fita
int Valor_RPM = 0;       //armazenará os valores de RPM

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800); //configuração da fita de LED
MCP2515 mcp2515(SPI_CS_CAN);                                                        // cria uma instância do módulo transciever CAN (configura pino CS)
can_frame canMSG;                                                                   // define package received fron CAN

//-----declaração de funções----//
void CAN_READ();
void LED_RPM();
//------------------------------//

void setup()
{

  Serial.begin(9600);
  SPI.begin();

  pixels.setBrightness(255);
  pixels.begin(); // This initializes the NeoPixel library.

  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ); //set CAN speed and clock frequency
  mcp2515.setNormalMode();
}

void loop()
{

  CAN_READ();
  LED_RPM();
}

//-------------------------------Funções---------------------------------------//

void CAN_READ()
{ //Ler mensagem da CAN e guardar o valor do RPM

  if (mcp2515.readMessage(&canMSG) == MCP2515::ERROR_OK)
  { //Check if data received is OK

    if (canMSG.can_id == RPM_CAN_ID)
    {

      Valor_RPM = canMSG.data[1];
      Valor_RPM = Valor_RPM << 8;
      Valor_RPM += canMSG.data[0];

      Serial.println(Valor_RPM);
    }
  }
  else
    Serial.print("Package error!");
}

void LED_RPM()
{ //Demonstrar o valor de RPM na fita de LED RGB

  if (1000 < Valor_RPM && Valor_RPM < 1100)
  {

    for (int i = 0; i < 0; i++)
    {
      pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
      pixels.show();
    }
    if (1100 < Valor_RPM < 2200)
    {

      for (int i = 0; i < 1; i++)
      {
        pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
        pixels.show();
      }
      if (2200 < Valor_RPM && Valor_RPM < 3300)
      {

        for (int i = 0; i < 2; i++)
        {
          pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
          pixels.show();
        }
        if (3300 < Valor_RPM && Valor_RPM < 4400)
        {

          for (int i = 0; i < 3; i++)
          {
            pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
            pixels.show();
          }
          if (4400 < Valor_RPM && Valor_RPM < 5500)
          {

            for (int i = 0; i < 4; i++)
            {
              pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
              pixels.show();
            }
            if (5500 < Valor_RPM && Valor_RPM < 6600)
            {

              for (int i = 0; i < 5; i++)
              {
                pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
                pixels.show();
              }
              if (6600 < Valor_RPM && Valor_RPM < 7700)
              {

                for (int i = 0; i < 6; i++)
                {
                  pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
                  pixels.show();
                }

                if (7700 < Valor_RPM && Valor_RPM < 8800)
                {

                  for (int i = 0; i < 7; i++)
                  {
                    pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
                    pixels.show();
                  }

                  if (8800 < Valor_RPM && Valor_RPM < 9900)
                  {

                    for (int i = 0; i < 8; i++)
                    {
                      pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
                      pixels.show();
                    }

                    if (9900 < Valor_RPM && Valor_RPM < 12000)
                    {

                      for (int i = 0; i < 9; i++)
                      {
                        pixels.setPixelColor(i, pixels.ColorHSV(20000 - i * 2150));
                        pixels.show();
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
