#include <IR.h>

const int num1= 551520375;
const int num2= 551524455;
const int plus = 551486205;
const int minu = 551518845;

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
      return 900;
    case plus:
      return min(delayValue+100, 1000);
    case minu:
      return max(delayValue-100, 100);
    default :
      return 500;
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
        Serial.print("current blink rate :");
        Serial.println(delayValue);
        irrecev.resume();
    }
  delay(100);
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
