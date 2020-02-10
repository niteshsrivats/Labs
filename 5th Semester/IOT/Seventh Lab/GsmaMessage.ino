#include <SoftwareSerial.h>

SoftwareSerial serial(2, 3);

void setup()
{
  serial.begin(9600);
  Serial.begin(9600);
  delay(100);
}

void loop()
{
  if (Serial.available() > 0)
  {
    switch (Serial.read())
    {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
    }
  }

  if (serial.available() > 0)
  {
    Serial.write(serial.read());
  }
}

void SendMessage()
{
  serial.println("AT+CMGF=1"); // Sets the GSM Module in Text Mode
  delay(1000);
  serial.println("AT+CMGS=\"+919901922538\"\r");
  delay(1000);
  serial.println("Hello");
  delay(100);
  serial.println((char)26); // ASCII code of CTRL+Z
  delay(1000);
}

void RecieveMessage()
{
  serial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
}
