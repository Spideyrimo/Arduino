//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 10);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

struct data{
  byte pot1x;
  byte pot1y;
  byte pot2x;
  byte pot2y;
  };

data value;
void setup()
{
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_HIGH);
  
  //Set module as transmitter
  radio.stopListening();

pinMode(A0, INPUT); 
pinMode(A1, INPUT);
pinMode(A2, INPUT); 
pinMode(A3, INPUT);
}
void loop()
{

value.pot1x=map(analogRead(A0),0,1023,0,255);
value.pot1y=map(analogRead(A1),0,1023,0,255);
value.pot2x=map(analogRead(A2),0,1023,0,255);
value.pot2y=map(analogRead(A3),0,1023,0,255);  
  radio.write(&value, sizeof(data));
  
  delay(1000);
}
