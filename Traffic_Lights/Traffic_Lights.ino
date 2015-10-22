const int out_pins[2] = {8,9};
const int in_pin = 7;
const int debounce_delay = 10;
int pivote = 0;
int cur_time=0,currentTime=0,prevTime;
bool prev_state,cur_state;

void setup() {
  pinMode(out_pins[0],OUTPUT);
  pinMode(out_pins[1],OUTPUT);
  pinMode(in_pin,INPUT);
  digitalWrite(out_pins[0],HIGH);
  digitalWrite(out_pins[1],LOW);
  Serial.begin(9600);
  prev_state = cur_state= 0 ;
}

void flip(){
  digitalWrite(out_pins[pivote] , LOW);
  digitalWrite(out_pins[pivote ^ 1] , HIGH);
  pivote ^=1;
}

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


void loop() {
  Serial.println(analogRead(14));
  delay(1);
  cur_time++;
  debounce(in_pin);
  if(cur_time == 2000){
    cur_time=0;
    flip();
  }
}
