#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX, TX

int en[8];
int mt[8];

int mleft, mright;
float velo;
String inString;
int vx,vy,mode;
int cnt=0;

void setup() {
  Serial.begin(9600);
  Serial.println("dfdffsfds");
  BT.begin(9600); // Default communication rate of the Bluetooth module
  delay(500);
}

void loop() {
  readBTval();
  //if (abs(vx) <=250 && abs (vy)<=250)drive(vx, vy);
  //drive(xAxis, yAxis);
}

void readBTval(){
 if(BT.available()>0){
  int inChar=BT.read();
  inString+=(char)inChar;
  if(inChar==';'){
    if(cnt==0){
      mode=inString.toInt();
      Serial.print("mode: ");
      Serial.print(mode);
    }
    if(cnt==1){
      vx=inString.toInt();
      Serial.print(" vx: ");
      Serial.print(vx);
    }
    inString="";
    cnt++;
  }
  if(inChar=='\n'){
    vy=inString.toInt();
    Serial.print(" vy: ");
    Serial.println(vy);
    inString="";
    cnt=0;
  }
 }
}
void drive(float x, float y){
  velo=sqrt(x*x+y*y)/2;
  mleft=int(velo +float(x/2)+0.5);
  mleft=constrain(mleft,0,250);
  mright=int(velo -float(x/2)+0.5);
  mright=constrain(mright,0,250);
  Serial.print(x);
  Serial.print(";");
  Serial.print(y);
  Serial.print(";");
  Serial.print(velo);
  Serial.print(";");
  Serial.print(mleft);
  Serial.print(";");
  Serial.println(mright);
}

void kalibrasi(){
  
}
