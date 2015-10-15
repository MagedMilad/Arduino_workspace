/*
 * function : add two numbers and show the result
 * input    : two numbers 
 * output   : the result
 */
 

//different states of operation
const int STATE_ready = 0;
const int STATE_waitingFirstNum = 1;
const int STATE_waitingSecondNum = 2;
const int STATE_printingResult = 3;


//variables storing the firrst and the second number and the current state
int num[2];
int sign[2];
int currentState=STATE_ready;


//check ascii value is number and append it to firstNum ,secondNum as num = 1, 2 accordingly  
int readNum(int ascii, int index){
  int i=0;
  if(ascii >='0' && ascii <='9'){
    i= ascii-'0';
    num[index] = num[index] * 10 + i;
    return 0;
  }
  if(ascii == '-'){
    sign[index] *= -1;
    return 0;
  }
  if(ascii == '\n'){
    return -1;
  }
}



void setup() {
  Serial.begin(9600);
}

void loop() {
  switch(currentState){
    //opening (default) state
    case STATE_ready:
      num[0] = num[1]= 0;
      sign[0]= sign[1]=1;
      Serial.print("enter first num : ");
      currentState = STATE_waitingFirstNum;
      break;
    //reading the first number until a \n is hit
    case STATE_waitingFirstNum:
      if(Serial.available() > 0){
        if(readNum(Serial.read(),0) == -1){
          num[0] *= sign[0];
          Serial.println(num[0]);
          Serial.print("enter second num : ");
          currentState = STATE_waitingSecondNum;
        }
      }
      break;
    //reading the second number until a \n is hit then calculating the sum
    case STATE_waitingSecondNum:
    if(Serial.available() > 0){
        if(readNum(Serial.read(),1) == -1){
          num[1] *= sign[1];
          Serial.println(num[1]);
          Serial.print("the sum is :");
          Serial.println(num[0]+num[1]);
          currentState = STATE_ready;
        }
      }
  }
}
