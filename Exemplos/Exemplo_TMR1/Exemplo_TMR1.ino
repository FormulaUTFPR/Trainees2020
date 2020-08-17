#include "TimerOne.h"

#define TMR_BASE 100000
#define TMR_FUNC2 1000000
#define TMR_FUNC 1000000

bool tmrFuncOverflow = false;
bool tmrFuncEnable = true;
int tmrFuncCount = 0;

bool tmrFunc2Overflow = false;
bool tmrFunc2Enable = true;
int tmrFunc2Count = 0;

void setup()
{
pinMode(13, OUTPUT);
Timer1.initialize(TMR_BASE); // Inicializa o Timer1 e configura para um período de 0,1 segundos
Timer1.attachInterrupt(callback); // Configura a função callback() como a função para ser chamada a cada interrupção do Timer1
}


void callback()
{
  if (tmrFuncEnable == true) {
    tmrFuncCount++;
    if (tmrFuncCount >= TMR_FUNC / TMR_BASE)
    {
      tmrFuncCount = 0;
      tmrFuncOverflow = true;
    }
  }

  if (tmrFunc2Enable == true) {
    tmrFuncCount++;
    if (tmrFunc2Count >= TMR_FUNC2 / TMR_BASE)
    {
      tmrFunc2Count = 0;
      tmrFunc2Overflow = true;
    }
  }
}


void loop()
{
  canSend(); 
  piscaLed();
  //10 funcoes
}


void canSend(){
  if (tmrFuncOverflow == true) {
      print("Olá");
      tmrFuncOverflow = false;
    }
}

void piscaLed(){
  if (tmrFunc2Overflow == true) {
      print("Olá");
      tmrFunc2Overflow = false;
    }
}

