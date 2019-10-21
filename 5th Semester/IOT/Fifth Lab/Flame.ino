const int led = 3;
const int buzzer = 2;
const int sensorPin = A0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (analogRead(sensorPin) < 100) {
    Serial.println("Fire hazard.");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}
