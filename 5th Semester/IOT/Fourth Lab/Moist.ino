#include <Servo.h>
Servo ms;
const int moist = 0;
const int motor = 9;
int moistValue;

void setup() {
  ms.attach(9);
  Serial.begin(9600);
}

void loop() {
  moistValue = analogRead(moist);
  Serial.println(moistValue);
  if (moistValue > 500) {
    for (int i = 0; i < 180; i++) {
      ms.write(i);
      delay(15);
    }
    for (int i = 180; i > 0; i--) {
      ms.write(i);
      delay(15);
    }
  }
  delay(1000);
}
