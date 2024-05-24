#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
bool ledState = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    lcd.setRGB(255, 255, 255); // Set backlight color to white (RGB values: 255, 255, 255)
    lcd.setCursor(0, 0);
    lcd.print("Please Return");
    lcd.setCursor(0, 1);
    lcd.print("Phone");
    
    for (int i = 0; i < 3; i++) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }

    lcd.clear();
    lcd.setRGB(0, 255, 0); // Set backlight color to green (RGB values: 0, 255, 0)
  }
}
