int val[2]={0,0};
int sign[2]={1,1};
int mode=0;
int idx=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char ch = Serial.read();
    if(idx < 4 && ch >= '0' && ch <= '9'){
      val[mode] = (val[mode]*10) + (ch - '0');
      idx++;
    }
    else if(ch == '-'){
      sign[mode]*=-1;
    }
    else{
      if(mode==1){
        val[0]*=sign[0];
        val[1]*=sign[1];
        Serial.println(val[0]+val[1]);
        val[0]=val[1]=0;
        sign[0]=sign[1]=1;
      }
      else{
        mode^=1;
      }
    }
  }

}
