#include<Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
const int flexpin1 = A0;
const int flexpin2 = A1;
const int flexpin3 = A2;
const int flexpin4 = A3;
void setup()
{
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(3);
}
void loop()
{
  int flexposition1;
  int servoposition1;
  int flexposition2;
  int servoposition2;
  int flexposition3;
  int servoposition3;
  int flexposition4;
  int servoposition4;
  flexposition1=analogRead(flexpin1);
  servoposition1 = map(flexposition1,750,950,0,90);
  servoposition1 = constrain(servoposition1,0,90);
  servo1.write(servoposition1);
  
  flexposition2=analogRead(flexpin2);
  servoposition2 = map(flexposition2,700,930,0,90);
  servoposition2 = constrain(servoposition2,0,90);
  servo2.write(servoposition2);

  flexposition3=analogRead(flexpin3);
  servoposition3 = map(flexposition3,900,980,0,90);
  servoposition3 = constrain(servoposition3,0,90);
  servo3.write(servoposition3);

  flexposition4=analogRead(flexpin4);
  servoposition4 = map(flexposition4,690,820,0,90);
  servoposition4 = constrain(servoposition4,0,90);
  servo4.write(servoposition4);
 
  Serial.print("sensor1: ");
  Serial.print(flexposition1);
  Serial.print("servo1: ");
  Serial.println(servoposition1);
  delay(100);
  
  Serial.print("sensor2: ");
  Serial.print(flexposition2);
  Serial.print("servo2: ");
  Serial.println(servoposition2);
  delay(100);

   Serial.print("sensor3: ");
  Serial.print(flexposition3);
  Serial.print("servo3: ");
  Serial.println(servoposition3);
  delay(100);

  Serial.print("sensor4: ");
  Serial.print(flexposition4);
  Serial.print("servo4: ");
  Serial.println(servoposition4);
  delay(100);
}
