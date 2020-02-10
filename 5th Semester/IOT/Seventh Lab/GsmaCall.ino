#include <SoftwareSerial.h>

SoftwareSerial serial(2, 3);

void setup()
{
    serial.begin(9600);
    Serial.begin(9600);
    Serial.println("Calling...");
    serial.println("ATD+987653210");
    delay(1000);
}

void loop()
{
}
