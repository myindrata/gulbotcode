#include <VarSpeedServo.h>
VarSpeedServo myservo1,myservo2,myservo3,myservo4,myservo5;
float serv[4];
float j1=90;float j2=120;float j3=50;float j4=90; float j5=0;
          
int a;              
const int servoPin1 =6; // the digital pin used for the servo
const int servoPin2 =7;
const int servoPin3=8;
const int servoPin4=10;
const int servoPin5=11;
  
int LED=13;
void setup()
{ 
  Serial.begin(115200);
  myservo1.attach(servoPin1, 830, 2170);  // attaches the servo on pin 9 to the servo object
  myservo1.write(j1,255,false);
  delay(3000);
  myservo2.attach(servoPin2, 850, 2150);  // attaches the servo on pin 9 to the servo object
  myservo2.write(j2,255,false);
  delay(3000);
  myservo3.attach(servoPin3, 850, 2150);  // attaches the servo on pin 9 to the servo object
  myservo3.write(j3,255,true);
  delay(3000);
  myservo4.attach(servoPin4, 850, 2150);  // attaches the servo on pin 9 to the servo object
  myservo4.write(j4,255,true);
  delay(3000);
  myservo5.attach(servoPin5);  // attaches the servo on pin 9 to the servo object
  myservo5.write(j5,255,true);
  delay(3000);
  pinMode(LED, OUTPUT);  

 }
 
void loop() 
{  
  receiveM();
  if (a==8)gerak_awal();  
  else if (a==1) {
    gerak_ambil();
//    myservo4.write(60,11,true);
    a=2;
    digitalWrite(LED, LOW); 
    Serial.println(a);
  }
  else if (a==3) {
        gerak_letak();
//    myservo4.write(120,11,true); //gerak letak
    a=4;
    digitalWrite(LED, LOW); 
    Serial.println(a); 
  }
  else if (a==5) {
        gerak_awal();
 //myservo4.write(90,11,true); 
    a=6;
    digitalWrite(LED, LOW);
    delay(5000);
    Serial.println(a);
  }
  //else{
  //while (a==0) gerak_ambil(); //objek target
  //while (a==2) gerak_letak();//grab
  //while (a==4) gerak_inisial();
  //}
}

void receiveM(){
  if(Serial.available())
  {
  for(int i=0;i<=3;i++) serv[i]=Serial.parseFloat();
    j1=serv[0];
    j2=serv[1];
    j3=serv[2];
    a=serv[3];
  }  
}

void gerak_awal(){   //gerak inisial awal
  digitalWrite(LED, HIGH); 
 //myservo4.attach(servoPin4, 850, 2150);
 myservo1.write(j1, 11, false);   
 myservo2.write(j2, 11, false);      
 myservo3.write(j3, 11, true);
 myservo4.write(60,11,true);
 myservo5.write(0,255,true);
}

void gerak_ambil(){
  digitalWrite(LED, HIGH);
//gerak dan ambil
 myservo1.write(j1, 11, false);   
 myservo2.write(j2, 11, false);      
 myservo3.write(j3, 11, true);
 myservo4.write(135,11,true);
 delay(2000);
 myservo5.write(40,255,true);
 delay(500);
 myservo4.write(70,11,true);
// a=2;
// Serial.println(a);
}

void gerak_letak(){
  digitalWrite(LED, HIGH); 
 myservo1.write(j1, 11, false);   
 myservo2.write(j2, 11, false);      
 myservo3.write(j3, 11, true);
 myservo4.write(120,11,true);
 delay(500);
 myservo5.write(0,255,true);
 delay(500);
 myservo4.write(70,11,true);
//a=4;
// Serial.println(a);

}

void attach_servo(){
  myservo1.attach(servoPin1, 850, 2150);  // attaches the servo on pin 9 to the servo object  
  myservo2.attach(servoPin2, 850, 2150);  // attaches the servo on pin 9 to the servo object 
  myservo3.attach(servoPin3, 850, 2150);  // attaches the servo on pin 9 to the servo object  
  myservo4.attach(servoPin4, 850, 2150);  // attaches the servo on pin 9 to the servo object  
  myservo5.attach(servoPin5, 850, 2150);  // attaches the servo on pin 9 to the servo object
}

void blinking(){
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(100);     
}

void blinking2(){
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(20);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(20);     
}

