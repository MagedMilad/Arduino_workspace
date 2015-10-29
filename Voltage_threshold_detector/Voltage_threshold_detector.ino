/*
 * function : trigger a warning sound and light if the voltage on 
 *            pot_pin exceeds the threshold voltage
 * input    : potentiometer  
 * output   : a led and a buzzer
 */


const int pot_pin = 14;
const int out_led = 13;

void setup() {
  pinMode(out_led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //read the current voltage at 10 bit resolution (0 to 1023)
  int val = analogRead(pot_pin);
  //scale the value to volt (0 to 5)
  float volt  = (val / 1023.0) * 5.0;
  Serial.println(volt);
  if(volt > 3){
    digitalWrite(out_led,HIGH);
  }
  else if(volt < 2.5){
    digitalWrite(out_led,LOW);
  }
}
