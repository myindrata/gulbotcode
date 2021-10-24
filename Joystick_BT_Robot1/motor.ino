void motor(int vpwm){
  if (vpwm>=0 && vpwm<254){
   analogWrite(mt[0],vpwm);//Maju
   analogWrite(mt[2],vpwm);
   analogWrite(mt[4],vpwm);
   analogWrite(mt[6],vpwm);
   
   analogWrite(mt[1],0);
   analogWrite(mt[3],0);
   analogWrite(mt[5],0);
   analogWrite(mt[7],0);
  }
  else if(vpwm<0 && vpwm>-254){ // Mundur
   analogWrite(mt[0],0);
   analogWrite(mt[2],0);
   analogWrite(mt[4],0);
   analogWrite(mt[6],0);
   
   analogWrite(mt[1],abs(vpwm));
   analogWrite(mt[3],abs(vpwm));
   analogWrite(mt[5],abs(vpwm));
   analogWrite(mt[7],abs(vpwm));   
  } 
}
