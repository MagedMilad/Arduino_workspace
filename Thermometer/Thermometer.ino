/*
 * function : trigger a warning sound and light if the temperature >28
 * input    : LM35  
 * output   : a led and a buzzer
 */

const int sensor_pin = 14;
const int out_led = 13;

void setup() {
  pinMode(out_led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //read the current voltage at 10 bit resolution (0 to 1023)
  int val = analogRead(sensor_pin);
  //scale the value to temperature (10mV = 1 deg)
  float temp  = val / 1023.0 * 500;
  Serial.println(temp);
  if(temp > 28){
    digitalWrite(out_led,HIGH);
  }
  else{
    digitalWrite(out_led,LOW);
  }
  delay(100);
}
