/*
 * function : light the red led for 2 seconds then turn it off 
 *            and light up the green led and then swap
 * input : push button to flip the current state of leds and an IR sensor 
 * output: 2 leds (red + green)
 */

//led pins
const int out_pins[2] = {8,9};
//push button pin
const int in_pin = 7;


int IRpin = A0;               // IR photodiode on analog pin A0
int IRemitter = 2;            // IR emitter LED on digital pin 2
int ambientIR;                // variable to store the IR coming from the ambient
int obstacleIR;               // variable to store the IR coming from the object
int value[10];                // variable to store the IR values
int distance;                 // variable that will tell if there is an obstacle or not
int oldDistance;              // variable that will hold previous distance value

const int debounce_delay = 10;
int pivote = 0;
int cur_time=0,currentTime=0,prevTime;
bool prev_state,cur_state;

void setup() {
  pinMode(IRemitter,OUTPUT);  // IR emitter LED on digital pin 2
  digitalWrite(IRemitter,LOW);// setup IR LED as off
  pinMode(13,OUTPUT);
  pinMode(out_pins[0],OUTPUT);
  pinMode(out_pins[1],OUTPUT);
  pinMode(in_pin,INPUT);
  digitalWrite(13,LOW);
  digitalWrite(out_pins[0],HIGH);
  digitalWrite(out_pins[1],LOW);
  Serial.begin(9600);
  prev_state = cur_state= 0 ;
  distance = oldDistance = 0;
}

//a function to turn off the current led and light up the other led
void flip(){
  digitalWrite(out_pins[pivote] , LOW);
  pivote ^=1;
  digitalWrite(out_pins[pivote] , HIGH);
}

//a function to detect a debounced pulse from the push button to flip the leds
void debounce(int pin){
  int in = digitalRead(pin);
  if(in!= prev_state){
    prevTime= millis();
  }
   if ((millis() - prevTime) > debounce_delay) {
       if (in != cur_state) {
         cur_state = in;
       
         if(cur_state == HIGH){
            flip();
            cur_time = 0;
         }
       }
   }
  prev_state = in;
}


int readIR(int times){
  for(int x=0;x<times;x++){
    digitalWrite(IRemitter,LOW);     //turning the IR LEDs off to read the IR coming from the ambient
    delay(1);                        // minimum delay necessary to read values
    ambientIR = analogRead(IRpin);   // storing IR coming from the ambient
    digitalWrite(IRemitter,HIGH);    //turning the IR LEDs on to read the IR coming from the obstacle
    delay(1);                        // minimum delay necessary to read values
    obstacleIR = analogRead(IRpin);  // storing IR coming from the obstacle
    value[x] = ambientIR-obstacleIR; // calculating changes in IR values and storing it for future average
  }
  
  for(int x=0;x<times;x++){          // calculating the average based on the "accuracy"
    distance+=value[x];
  }
  return(distance/times);            // return the final value
}

void loop() {
  //delay(1);
  cur_time++;
  debounce(in_pin);
  distance = readIR(2);
  if(distance == 0 && oldDistance>0){
    flip();
    cur_time = 0;
    oldDistance =0 ;
  }
  else{
    oldDistance = distance;
  }
  if(cur_time == 500){
    cur_time=0;
    flip();
  }
}
