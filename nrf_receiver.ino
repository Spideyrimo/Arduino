//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Motor A Connections
//int enA = 9;
int in1 = 14;
int in2 = 4;
 
// Motor B Connections
//int enB = 5;
int in3 = 7;
int in4 = 6;
//create an RF24 object
RF24 radio(9, 8); // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);

  radio.setPALevel(RF24_PA_MIN);
  
  //Set module as receiver
  radio.startListening();

  //pinMode(enA, OUTPUT);
  //pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }

  if(text[0]=131 && text[1]>127)   //FORWARD
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      //analogWrite(enA,text[1]);
      //analogWrite(enB,text[1]);
      }
    if(text[0]=131 && text[1]<127)   //BACKWARD
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      //analogWrite(enA,text[1]);
      //analogWrite(enB,text[1]);
      }   
    if(text[0]<131 && ((text[1]<127) || (text[1]>=127)))   //RIGHT
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      //analogWrite(enA,text[1]);
      //analogWrite(enB,text[1]);
      } 
    if(text[0]>131 && ((text[1]<127) || (text[1]>=127)))   //LEFT
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

      //analogWrite(enA,text[1]);
      //analogWrite(enB,text[1]);
      }     
     if(text[0]=131 && text[1]=127)   //STOP
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);

      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

      //analogWrite(enA,text[1]);
      //analogWrite(enB,text[1]);
      }     
}
