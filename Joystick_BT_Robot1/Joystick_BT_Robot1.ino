#include <SoftwareSerial.h>
#include <PID_v1.h>

SoftwareSerial BT(2, 3); // RX, TX

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
}

void loop() {
  //bluetooth control
  readBTval();
  //take new VR, VL as setPoint
  RSetpoint=VR;
  LSetpoint=VL;
  RPID.Compute();
  LPID.Compute();
  motor((int)(ROutput+0.5));
  motor((int)(LOutput+0.5));
  //take last VR VL as input
  RInput=(int)(ROutput+0.5);
  LInput=(int)(LOutput+0.5);
}
