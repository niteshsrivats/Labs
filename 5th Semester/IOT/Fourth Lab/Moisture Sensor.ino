#include <Servo.h>

Servo motor;
const int moisturePin = A0, motorPin = 9;
int moistureValue;

void setup()
{
  pinMode(motor, OUTPUT);
  motor.attach(9);
}

void loop()
{
  moistureValue = analogRead(moisturePin);
  if (moistureValue > 750)
  {
    for (int i = 0; i < 180; i++)
    {
      motor.write(i);
      delay(15);
    }
    for (int i = 180; i > 0; i--)
    {
      motor.write(i);
      delay(15);
    }
  }
  delay(1000);
}
