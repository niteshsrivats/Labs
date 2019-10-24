const int ledPin = 3, buzzerPin = 2, sensorPin = A0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (analogRead(sensorPin) < 100)
  {
    Serial.println("Fire Detected.");
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  delay(100);
}
