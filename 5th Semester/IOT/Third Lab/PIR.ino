const int calibrationTime = 5000;
const int pir = 2;
const int led = 13;
int pirState = LOW;
int val = 0;
int startTime = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);
  calibrate();
}

void loop()
{
  val = digitalRead(pir);
  if (val != pirState)
  {
    if (val == HIGH)
    {
      digitalWrite(led, HIGH);
      startTime = millis() / 1000;
      Serial.println("Motion Detected at " + String(startTime));
    }
    else
    {
      digitalWrite(led, LOW);
      Serial.println("Motion Finished at " + String(millis() / 1000));
    }
    pirState = val;
  }
  delay(10);
}

void calibrate()
{
  Serial.println("Calibrating PIR Sensor:");
  for (int i = 0; 100; i++)
  {
    digitalWrite(pir, LOW);
    Serial.println("Calibrating: " + String(calibrationTime - (i * (calibrationTime / 100))) + "ms");
    delay(calibrationTime / 100);
  }
  Serial.println("Calibrated PIR Sensor.");
}
