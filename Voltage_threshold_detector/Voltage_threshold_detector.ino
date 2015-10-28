
const int pot_pin = 0; // choose one ya mina
const int out_led = 13;

void setup() {
  pinMode(out_led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 int val = analogRead(pot_pin);
 float volt  = (val / 1023.0) * 5.0;
 Serial.println(volt);
 if(volt > 3){
  digitalWrite(out_led,HIGH);
 }
 else if(volt < 2.5){
  digitalWrite(out_led,LOW);
 }
}
