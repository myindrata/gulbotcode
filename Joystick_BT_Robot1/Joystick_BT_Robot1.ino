#include <SoftwareSerial.h>
#include <PID_v1.h>

SoftwareSerial BT(52, 53); // RX, TX

int en[8];
int mt[8];

int mleft, mright;
float velo;
String inString;
int VR,VL,mode;
int cnt=0;

//Define Variables we'll be connecting to
double RSetpoint, RInput, ROutput;
double LSetpoint, LInput, LOutput;
//Specify the links and initial tuning parameters
double Kp=2, Ki=5, Kd=1;
PID RPID(&RInput, &ROutput, &RSetpoint, Kp, Ki, Kd, DIRECT);
PID LPID(&LInput, &LOutput, &LSetpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  Serial.begin(9600);
  Serial.println("GulbotV2");
  BT.begin(9600); // Default communication rate of the Bluetooth module
  delay(500);
  for(int i=0;i<8;i++){
    en[i]=3+i;
    mt[i]=i;
    pinMode(en[i],OUTPUT);
    digitalWrite(en[i],HIGH);
  }
  /*
  pinMode(en[0],OUTPUT);
  pinMode(en[1],OUTPUT);
  pinMode(en[2],OUTPUT);
  pinMode(en[3],OUTPUT);
  pinMode(en[4],OUTPUT);
  pinMode(en[5],OUTPUT);
  pinMode(en[6],OUTPUT);
  pinMode(en[7],OUTPUT);
  */
}

void loop() {
  //bluetooth control
  readBTval();
  motor(VR);
  motor(VL);
  //take new VR, VL as setPoint
  /*
  RSetpoint=VR;
  LSetpoint=VL;
  RPID.Compute();
  LPID.Compute();
  Serial.println(ROutput);
  motor((int)(ROutput+0.5));
  motor((int)(LOutput+0.5));
  //take last VR VL as input
  RInput=(int)(ROutput+0.5);
  LInput=(int)(LOutput+0.5);
*/
}
