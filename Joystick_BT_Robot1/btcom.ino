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
      VR=inString.toInt();
      Serial.print(" VR: ");
      Serial.print(VR);
    }
    inString="";
    cnt++;
  }
  if(inChar=='\n'){
    VL=inString.toInt();
    Serial.print(" VL: ");
    Serial.println(VL);
    inString="";
    cnt=0;
  }
 }
}
