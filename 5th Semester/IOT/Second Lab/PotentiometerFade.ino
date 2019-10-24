const int potentiometerPin = 3, ledPin = 4;
int potentiometerReading, ledValue;

void setup()
{
  pinMode(potentiometerPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  potentiometerReading = analogRead(potentiometerPin);
  ledValue = map(potentiometerReading, 0, 1023, 0, 255);
  analogWrite(ledPin, ledValue);
}
