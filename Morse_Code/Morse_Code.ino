/*
 * function : display SOS signal represented in Morse Code with a led and a buzzer with TimeSlot modulator
 * input : potentiometer to modify TimeSlot
 * output: led and a buzzer
 */
 
//potentiometer analog pen
const int pot = A0;
//led/buzzer output leg
const int led = 13;
//variable to hold current TimeSlot value
int timeSlot = 10;
 
 
//reads the potentiometer value and updates the value of TimeSlot variable
void updateTime(){
  timeSlot = analogRead(pot);
  if(timeSlot< 10){
    timeSlot=10;
  }
}
 
//a custom function of delay to check for TimeSlot changes within the delay time
void delayTimeSlots(int i){
  int t = 0;
  while(t++ < i * timeSlot){
    delay(1);
    updateTime();
  }
}
 
 
void dot(){
  delayTimeSlots(1);
}
 
void dash(){
  delayTimeSlots(3);
}
 
void charSeparator(){
  delayTimeSlots(3);
}
 
void wordSeparator(){
  delayTimeSlots(7);
}
 
void s(){
  digitalWrite(led, HIGH);
  dot();
  digitalWrite(led, LOW);
  dot();
  digitalWrite(led, HIGH);
  dot();
  digitalWrite(led, LOW);
  dot();
  digitalWrite(led, HIGH);
  dot();
  digitalWrite(led, LOW);
}
 
void o(){
  digitalWrite(led, HIGH);
  dash();
  digitalWrite(led, LOW);
  dot();
  digitalWrite(led, HIGH);
  dash();
  digitalWrite(led, LOW);
  dot();
  digitalWrite(led, HIGH);
  dash();
  digitalWrite(led, LOW);
}
 
 
void setup() {
  pinMode(led, OUTPUT);
}
 
void loop() {
  s();
  charSeparator();
  o();
  charSeparator();
  s();
  wordSeparator();
}
