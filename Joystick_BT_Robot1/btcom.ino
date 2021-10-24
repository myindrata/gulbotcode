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
      VL=inString.toInt();
      Serial.print(" VL: ");
      Serial.print(VL);
    }
    inString="";
    cnt++;
  }
  if(inChar=='\n'){
    VR=inString.toInt();
    Serial.print(" VR: ");
    Serial.println(VR);
    inString="";
    cnt=0;
  }
 }
}
