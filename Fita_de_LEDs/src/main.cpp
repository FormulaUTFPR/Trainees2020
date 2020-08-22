//--------------inclusão de bibliotecas--------------//
#include <Arduino.h> //Arduino function libery 
#include <mcp2515.h> //mcp2515 module function libery 
#include <SPI.h> //SPI protocol function libery 
#include <EK304CAN.h>
#include <CAN.h>
#include "Adafruit_NeoPixel.h" //coisa do LED
#include <avr/power.h>  //coisa do LED

//--------------------------------------------------//

#endif //coisa do LED
#ifdef __AVR__ //coisa do LED

//---------------------------pinagem--------------------------------//
#define SPI_SCK 52    // define SPI_SCK (SPI's clock bus) as 52 pin
#define SPI_SI 51     // define SPI_SI  (SPI's slave input bus) as 51 pin
#define SPI_SO 50     // define SPI_SO  (slave output do SPI bus) as 50 pin
#define SPI_CS_CAN 53 // define SPI_CS_CAN  (CAN's slave select on SPI bus) as 53 pin
#define LED_RPM 40    // define LED tape as 40 pin
//------------------------------------------------------------------//


void setup() {

  can_frame canMSG; // define package received fron CAN 
  #define RPM_CAN_ID = 0x002 //define RPM ID as 0x002

  Serial.begin(9600);
  SPI.begin();

  #define NUMPIXELS 10
  Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_RPM, NEO_GRB + NEO_KHZ800);
  pixels.setBrightness(255);
  pixels.begin(); // This initializes the NeoPixel library.

  MCP2515 mcp2515(SPI_CS_CAN); // cria uma instância do módulo transciever CAN (configura pino CS)
  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS,MCP_8MHZ); //set CAN speed and clock frequency
  mcp2515.setNormalMode();

}

void loop() {

  void CAN_READ();
  void LED_RPM();

}

//-------------------------------Funções---------------------------------------//

void CAN_READ(){ //Ler mensagem da CAN e guardar o valor do RPM

    If(mcp2515.readMessage(&canMSG)==MCP2515: :ERROR_OK) {  //Check if data received is OK

       if(canMSG.can_id==RPM_CAN_ID){

        sensors[SENSOR_ROTATION_ID].valor = frame.data[1];
        sensors[SENSOR_ROTATION_ID].valor = sensors[SENSOR_ROTATION_ID].valor << 8;
        sensors[SENSOR_ROTATION_ID].valor += frame.data[0];

        setAckTime(sensors[SENSOR_ROTATION_ID].origin);

        Serial.println(sensors[SENSOR_ROTATION_ID].valor);

        break;
      }

    }
    else(){
    Serial.print("Package error!")
  }

}


void LED_RPM(){ //Demonstrar o valor de RPM na fita de LED RGB

  int delayval = 50; 

 if(1000<sensors[SENSOR_ROTATION_ID].valor<1100){
  
   	for(int i=0;i<0;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}
   

  }
  if(1100<sensors[SENSOR_ROTATION_ID].valor<2200){
  
   	for(int i=0;i<1;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}

  }
   if(2200<sensors[SENSOR_ROTATION_ID].valor<3300){
  
   	for(int i=0;i<2;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}

  }
   if(3300<sensors[SENSOR_ROTATION_ID].valor<4400){
  
   	for(int i=0;i<3;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}
  }
    if(4400<sensors[SENSOR_ROTATION_ID].valor<5500){
  
   	for(int i=0;i<4;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}
  }
    if(5500<sensors[SENSOR_ROTATION_ID].valor<6600){
  
   	for(int i=0;i<5;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}
  }
    if(6600<sensors[SENSOR_ROTATION_ID].valor<7700){
  
      for(int i=0;i<6;i++){
        pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
        pixels.show(); 
        delay(delayval);}
    }
         
    if(7700<sensors[SENSOR_ROTATION_ID].valor<8800){
  
   	for(int i=0;i<7;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}
    }
      
    if(8800<sensors[SENSOR_ROTATION_ID].valor<9900){
  
   	for(int i=0;i<8;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}
    }
            
    if(9900<sensors[SENSOR_ROTATION_ID].valor<12000){
  
   	for(int i=0;i<9;i++){
      pixels.setPixelColor(i, pixels.ColorHSV(20000-i*2150)); 
      pixels.show(); 
      delay(delayval);}
      
  }

}