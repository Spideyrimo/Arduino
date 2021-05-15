//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int pot1x; 
int pot1y; 
int pot2x; 
int pot2y; 

//create an RF24 object
RF24 radio(9, 10);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  
  //Set module as transmitter
  radio.stopListening();

pinMode(A0, INPUT); 
pinMode(A1, INPUT);
pinMode(A2, INPUT); 
pinMode(A3, INPUT);
}
void loop()
{
  int data[4];
pot1x = analogRead(A0); 
pot1y = analogRead(A1);
pot2x = analogRead(A2); 
pot2y = analogRead(A3);

data[0]=map(pot1x,0,1023,0,255);
data[1]=map(pot1y,0,1023,0,255);
data[2]=map(pot2x,0,1023,0,255);
data[3]=map(pot2y,0,1023,0,255);  
  radio.write(&data, sizeof(data));
  
  delay(1000);
}
