#include <Servo.h>
const Servo ms;
const int motor = 9;
const int sensorPin = A0;
int sensorValue;

void setup()
{
  pinMode(motor, OUTPUT);
  ms.attach(motor);
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue > 750)
  {
    for (int pos = 0; pos <= 180; pos += 1)
    {
      ms.write(pos);
      delay(30);
    }
    for (int pos = 180; pos >= 0; pos -= 1)
    {
      ms.write(pos);
      delay(30);
    }
  }
  delay(1000);
}
