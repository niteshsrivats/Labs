#include <SoftwareSerial.h>

SoftwareSerial serial(10, 11);
const int ledPin = 13;
char data;

void setup()
{
    Serial.begin(9600);
    serial.begin(38400);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    while (Serial.available())
    {
        serial.write(Serial.read());
    }
    while (serial.available())
    {
        data = serial.read();
    }

    if (data == '1')
    {
        digitalWrite(ledPin, HIGH);
    }
    else if (data == '0')
    {
        digitalWrite(ledPin, LOW);
    }
}
