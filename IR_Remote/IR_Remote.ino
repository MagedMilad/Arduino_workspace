#include <IR.h>

const int num1= 338831067;
const int num2= 2737486129;
const int plus = 924466310;
const int minu = 3768077238;

int rec_pin = 2;
int led_pin = 13;
int delayValue=500;
int state=1;
IRrecv irrecev(rec_pin);
decode_results results;

int getValue(int i){
  switch(i){
    case num1:
      return 100;
    case num2:
      return 300;
    case plus:
      return 600;
    case minu:
      return 1000;
    default :
      return 1000;
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  irrecev.enableIRIn();
}

void loop() {
    if(irrecev.decode(&results) ){
        //Serial.println(results.value);
        delayValue = getValue(results.value);
        Serial.print("blink rate :");
        Serial.println(delayValue);
        irrecev.resume();
    }
  //delay(100);
  delay(delayValue);
  if(state == 1){
    digitalWrite(led_pin, HIGH);
  }
  else if(state == -1){
    digitalWrite(led_pin, LOW);
  }
  state = -1*state;
  //Serial.println(state);
}
