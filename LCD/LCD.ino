#include <LiquidCrystal.h>

const int sensor_pin = 14;
const int out_pin = 6;
int limit = 31;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(out_pin, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.noBlink();
  lcd.setCursor(0, 1);
  lcd.print("cur:    limit:  ");
}

void loop() {
  //read the current voltage at 10 bit resolution (0 to 1023)
  int val = analogRead(sensor_pin);
  //scale the value to temperature (10mV = 1 deg)
  float temp  = val / 1023.0 * 500;
    lcd.setCursor(3, 0);
  if(temp > limit){
    lcd.print("WARNING!");
    digitalWrite(out_pin, HIGH);
  }else{
    lcd.print("        ");
    digitalWrite(out_pin, LOW);
  }
  lcd.setCursor(4, 1);
  lcd.print((int)temp);
  lcd.setCursor(14, 1);
  lcd.print(limit);
  delay(200);
}
