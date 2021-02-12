

#include "EmonLib.h"
#define LED 11                          // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
double Irms,a;
void setup()
{  
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  emon1.current(A4,5000);
  Irms = emon1.calcIrms(1480); 
  a = Irms;
}

void loop()
{
   Irms = emon1.calcIrms(1480);  // Calculate Irms only
  

  //Serial.print("Current : ");
  //Serial.print(Irms);           // Irms
  //Serial.println(" mA");
  if(Irms>a+10)
   {
      Serial.print(Irms);
      Serial.println("  ON");
       digitalWrite(11,HIGH);
    }
  else
    {
       Serial.print(Irms);
       Serial.println("  OFF");
       digitalWrite(11,LOW);
      }  
}
