String inputString = "";         // a String to hold incoming data
String signString="";
bool stringCom = false;  // whether the string is complete
bool objCom = false;  // whether the string is complete
bool endCom = false; 
float data[20][4];
// Keep track of the last comma so we know where to start the substring
int count_sv=0;
int count_obj=0;
int num_obj=0;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringCom) {
    data[count_obj][count_sv]=inputString.toFloat();
    Serial.print(count_obj);
    Serial.print(",");
    Serial.print(count_sv);
    Serial.print(": ");
    Serial.print(data[count_obj][count_sv]);
    Serial.print('-');
    count_sv++;
    stringCom = false;
    inputString = "";
  }
  if (objCom){
    count_sv=0;
    count_obj++; 
    objCom =false;
    inputString = "";
  }
  if (endCom){
    count_sv=0;
    num_obj=count_obj;
    Serial.println(num_obj);
    count_obj=0;
    endCom =false;
    inputString = "";
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == ',') {
      stringCom = true;
    }
    if (inChar == '#') {
      objCom = true;
    }
    if (inChar == 'n') {
      endCom = true;
    }
  }
}
