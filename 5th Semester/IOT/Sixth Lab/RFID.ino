#include <SoftwareSerial.h>
SoftwareSerial serial(3, 10);

int count;
char input[12], check[12] = {'5', '1', '0', '0', '9', '3', 'E', '0', '2', 'A', '0', '8'};
const int greenLedPin = 11, redLedPin = 9;
boolean flag;

void setup()
{
  Serial.begin(9600);
  serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop()
{
  if (serial.available())
  {
    count = 0;
    while (serial.available() && count < 12)
    {
      input[count] = serial.read();
      count++;
      delay(5);
    }

    Serial.println(input);
    for (int i = 0; i < 12; i++)
    {
      if (input[i] != check[i])
      {
        flag = true;
        break;
      }
    }
    if (flag)
    {
      digitalWrite(redLedPin, HIGH);
      delay(1000);
      digitalWrite(redLedPin, LOW);
      flag = false;
    }
    else
    {
      digitalWrite(greenLedPin, HIGH);
      delay(1000);
      digitalWrite(greenLedPin, LOW);
    }
  }
  delay(100);
}
