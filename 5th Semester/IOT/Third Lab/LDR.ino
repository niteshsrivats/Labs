const int led = 3;
const int ldr = 5;
int ldrValue, ledValue; 
      
void setup() {
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}
void loop() { 
  ldrValue = analogRead(ldr);
  ledValue = map(ldrValue, 300, 1000, 255, 0);
  Serial.println(String(ldrValue) + ":" + String(ledValue));
  analogWrite(led, ledValue);
  delay(100);
}
