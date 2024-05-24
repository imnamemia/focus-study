#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int numRows = 2;
const int numCols = 16;
const int buttonPin = 3;  


byte smiley[numRows] = {
  B00000000,
  B01010100,
  B01010100,
  B00000000,
  B10000001,
  B10000001,
  B01111110,
  B00000000
};


byte frown[numRows] = {
  B00000000,
  B01010100,
  B01010100,
  B00000000,
  B01111110,
  B10000001,
  B10000001,
  B00000000
};

void setup() {
  lcd.begin(numCols, numRows);
  lcd.setRGB(255, 255, 255);  
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {  
    // Display the smiley face
    lcd.createChar(0, smiley);
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
  } else {
    // Display the frown face if the button is not pressed
    lcd.createChar(0, frown);
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
  }
}
