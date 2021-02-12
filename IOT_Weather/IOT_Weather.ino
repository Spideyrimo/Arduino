#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include<DHT.h>


DHT dht(D1,DHT11);
float hum;
float temp;

char ssid[] = "spideywifi";          
char pass[] = "sayantan20";  

int status = WL_IDLE_STATUS;
WiFiClient  client;

    
unsigned long myChannelNumber = 1223296; // modify this with your own Channel Number
const char * myWriteAPIKey = "TCYHVDI9ADMQDH76";

void setup() {
  Serial.begin(115200); // for debugging reasons
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  dht.begin();
}

void loop() {
  // Read the latest value from field 1 of your channel
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  ThingSpeak.writeField(myChannelNumber, 1,temp, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2,hum, myWriteAPIKey);
  
}
