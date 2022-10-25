#include <VarSpeedServo.h>
VarSpeedServo myservo1,myservo2,myservo3,myservo4,myservo5;
float serv[4];

float j1=90;float j2=120;float j3=50;float j4=90; float j5=10;

int a;                       
const int servoPin1 =6; // the digital pin used for the servo
const int servoPin2 =7;
const int servoPin3=8;
const int servoPin4=9;
const int servoPin5=10;

void setup()
{ 
  a=6;
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{ 
  receiveM();
  while (a==0) gerak_ambil(); //objek target
  while (a==2) gerak_letak();//grab
  while (a==4) gerak_inisial();
}

void receiveM(){
  if(Serial.available())
  {
  for(int i=0;i<=3;i++) serv[i]=Serial.parseFloat();
  a=serv[3];
  }  
}

void gerak_ambil(){
for (int q=0; q<10; q++){
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);
}
//gerak dan ambil

a=1;
Serial.println(a);
}

void gerak_letak(){
//gerak dan letak
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(3000);
  a=3;
  Serial.println(a);
}


void gerak_inisial(){
//proses ke lokasi kotak
  delay(1000);
  a=5;
  Serial.println(a);
}



