#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

int LED = D8;

char ssid[] = "spideywifi";          
char pass[] = "sayantan20";  

int status = WL_IDLE_STATUS;
WiFiClient  client;
int readValue; // variable to save channel field reading
    
unsigned long myChannelNumber = 879851; // modify this with your own Channel Number
const char * myReadAPIKey = "DBP1KHZ4175W7N1A";

void setup() {
  Serial.begin(115200); // for debugging reasons
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);
}

void loop() {
  // Read the latest value from field 1 of your channel
   readValue = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
  Serial.print("readValue = "); // debugging instrument
  Serial.println(readValue);    // debugging instrument

  if ( readValue == 1){
    digitalWrite(LED, HIGH); // please notice if you need to modify this to LOW 
                            //  if your board's port active low
  }
  else{
    digitalWrite(LED, LOW); // please notice if you need to modify this to HIGH 
                            //  if your board's port active low   
  }
}
