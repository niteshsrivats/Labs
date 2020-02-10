const int ledPin = 3;
int brightness = 0, fadeAmount = 5;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  analogWrite(ledPin, brightness);
  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255)
  {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}
