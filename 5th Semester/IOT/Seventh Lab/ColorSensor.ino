const int out = 10, redLedPin = 2, greenLedPin = 3, blueLedPin = 4, s[4] = {8, 9, 12, 11};
int redValue = 0, greenValue = 0, blueValue = 0;

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 4; i++)
    {
        pinMode(s[i], OUTPUT);
    }
    pinMode(out, INPUT);
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
    digitalWrite(s[0], HIGH);
    digitalWrite(s[1], HIGH);
}

void loop()
{
    updateColors();
    Serial.print("R Intensity:");
    Serial.print(redValue, DEC);
    Serial.print(" G Intensity: ");
    Serial.print(greenValue, DEC);
    Serial.print(" B Intensity : ");
    Serial.print(blueValue, DEC);
    Serial.println();

    if (redValue < blueValue && redValue < greenValue)
    {
        Serial.println(" - (Red Color)");
        digitalWrite(redLedPin, HIGH);
    }
    else if (blueValue < redValue && blueValue < greenValue)
    {
        Serial.println(" - (Blue Color)");
        digitalWrite(blueLedPin, HIGH);
    }
    else if (greenValue < redValue && greenValue < blueValue)
    {
        Serial.println(" - (Green Color)");
        digitalWrite(greenLedPin, HIGH);
    }
    delay(300);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
}

void updateColors()
{
    // Red filter
    digitalWrite(s[2], LOW);
    digitalWrite(s[3], LOW);
    redValue = pulseIn(out, HIGH);
    // Blue filter
    digitalWrite(s[3], HIGH);
    blueValue = pulseIn(out, HIGH);
    // Green filter
    digitalWrite(s[2], HIGH);
    greenValue = pulseIn(out, HIGH);
}
