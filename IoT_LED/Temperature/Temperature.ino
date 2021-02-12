#include<DHT.h>

DHT dht(3,DHT11);
float hum;
float temp;

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print(" degree");
  Serial.println(" C");
  delay(1000);

  Serial.print("Humidity = ");
  Serial.println(hum);
  delay(1000);
}
