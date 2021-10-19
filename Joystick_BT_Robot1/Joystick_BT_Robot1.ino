#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX, TX

int en[8];
int mt[8];


#define in1 4
#define in2 5

#define in3 6
#define in4 7


#define in1 8
#define in2 9

#define in3 10
#define in4 11

int xAxis, yAxis;
int mleft, mright;
float velo;

void setup() {
  for(int i=0;i<8;i++){
    en[i]=i+22;
    mt[i]=i+4;
    pinMode(en[i],OUTPUT);
    pinMode(mt[i],OUTPUT);
  }

  Serial.begin(9600);
  BT.begin(9600); // Default communication rate of the Bluetooth module
  delay(500);
}

void loop() {
  readbt();
  drive(xAxis, yAxis);
}

void readbt(){
  if (BT.available() >= 2) {
    xAxis = BT.read();
    delay(5);
    yAxis = BT.read();
    Serial.print(xAxis);
    Serial.print(",");
    Serial.println(yAxis);
  }
}
void drive(int x, int y){
  velo=sqrt(x*x+y*y);
  mleft=int(velo+(x/2)+0.5);
  mright=int(velo-(x/2)+0.5);
  Serial.print(mleft);
  Serial.print(",");
  Serial.println(mright);
}

void kalibrasi(){
  
}
