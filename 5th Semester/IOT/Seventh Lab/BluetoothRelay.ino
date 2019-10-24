#include <SoftwareSerial.h>

SoftwareSerial serial(10, 11);
const int relay[4] = {2, 3, 4, 5};
char val;

void setup()
{
    Serial.begin(9600);
    serial.begin(38400);
    for (int i = 0; i < 4; i++)
    {
        pinMode(relay[i], OUTPUT);
        digitalWrite(relay[i], HIGH);
    }
}

void loop()
{
    if (serial.available() > 0)
    {
        val = serial.read();
        Serial.println(val);
    }

    if (val == '1')
    {
        digitalWrite(relay1, LOW);
    }
    else if (val == '2')
    {
        digitalWrite(relay2, LOW);
    }
    else if (val == '3')
    {
        digitalWrite(relay3, LOW);
    }
    else if (val == '4')
    {
        digitalWrite(relay4, LOW);
    }
    else if (val == '9')
    {
        digitalWrite(relay1, LOW);
        digitalWrite(relay2, LOW);
        digitalWrite(relay3, LOW);
        digitalWrite(relay4, LOW);
    }

    else if (val == 'A')
    {
        digitalWrite(relay1, HIGH);
    }
    else if (val == 'B')
    {
        digitalWrite(relay2, HIGH);
    }
    else if (val == 'C')
    {
        digitalWrite(relay3, HIGH);
    }
    else if (val == 'D')
    {
        digitalWrite(relay4, HIGH);
    }
    else if (val == 'I')
    {
        digitalWrite(relay1, HIGH);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
    }
}
