
int inputPin = 2 int pirState = LOW;
int val = 0;

void setup()
{
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(inputPin);
  if (val != pirState)
  {
    if (val == HIGH)
    {
      Serial.println("Motion Detected.");
    }
    else
    {
      Serial.println("Motion Finished.");
    }
    pirState = val;
  }
  delay(50);
}
