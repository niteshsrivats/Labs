int button = 3;
int led = 4;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(button);
  if (reading){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
