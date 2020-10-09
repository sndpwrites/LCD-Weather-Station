#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.print("Loading...");
}


void loop()
{
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    while (Serial.available() > 0) {
      // display each character to the LCD
      char myChar = Serial.read();
      if (myChar == '~') {
        lcd.setCursor(0,1);
      } else {
      lcd.print(myChar);  
      }
    }  
}
}
