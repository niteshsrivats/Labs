const int ledPin = 3, ldrPin = 5;
int ldrValue, ledValue;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  ldrValue = analogRead(ldrPin);
  ledValue = map(ldrValue, 300, 1000, 255, 0);
  Serial.println(String(ldrValue) + ":" + String(ledValue));
  analogWrite(ledPin, ledValue);
  delay(100);
}
