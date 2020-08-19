#include <Arduino.h> //Arduino function libery 
#include <mcp2515.h> //mcp2515 module function libery 
#include <TimerOne.h> 
#include <SPI.h> //SPI protocol function libery 


#define LED_RPM 40    // define LED tape as 40 pin

//mcp2515 module (Receive CAN and send as SPI to Arduino)
#define SPI_SCK 52    // define SPI_SCK (SPI's clock bus) as 52 pin
#define SPI_SI 51     // define SPI_SI  (SPI's slave input bus) as 51 pin
#define SPI_SO 50     // define SPI_SO  (slave output do SPI bus) as 50 pin
#define SPI_CS_CAN 53 // define SPI_CS_CAN  (CAN's slave select on SPI bus) as 53 pin


struct can_frame canMSG; // define package received fron CAN 

MCP2515 mcp2515(SPI_CS_CAN); // cria uma instância do módulo transciever CAN (configura pino CS)

void setup() {

  Serial.begin(9600);
  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS,MCP_8MHZ); //set CAN speed and clock frequency
  mcp2515.setNormalMode();

  RPM.can_id = 0x002;
  RPM.can_dlc = 2;
}

void loop() {
  
  If(mcp2515.readMessage(&canMSG)==MCP2515: :ERROR_OK) {  //Check if data received is OK

    if(canMSG.can_id==0x002){

        //ler pacote do RPM, ver se precisa colocar na escala certa, associar escala de RPM com escala de altura e cor na fita de LEDs

      }


    }
  else(){
    Serial.print("Package error!")
  }

}
//testanto comit