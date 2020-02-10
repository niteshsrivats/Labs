const int calibrationTime = 5000, pirPin = 2, ledPin = 13;
int pirState = LOW, val = 0, startTime = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  calibrate();
}

void loop()
{
  val = digitalRead(pirPin);
  if (val != pirState)
  {
    if (val == HIGH)
    {
      digitalWrite(ledPin, HIGH);
      startTime = millis() / 1000;
      Serial.println("Motion Detected at " + String(startTime));
    }
    else
    {
      digitalWrite(ledPin, LOW);
      Serial.println("Motion Finished at " + String(millis() / 1000));
    }
    pirState = val;
  }
  delay(10);
}

void calibrate()
{
  Serial.println("Calibrating PIR Sensor:");
  digitalWrite(pirPin, LOW);
  delay(calibrationTime);
  Serial.println("Calibrated PIR Sensor.");
}
