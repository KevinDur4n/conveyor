#include "Base.h"
Base conveyor(2,3,12);
int readpinA;
int readpinB;
//Serial Events
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
 conveyor.init();
 Serial.begin(9600);
 pinMode(12,OUTPUT);
 pinMode(13, OUTPUT);
 digitalWrite(13,LOW);
 Serial.println("Conveyor Belt beging...");
 conveyor.Stop();
 
}

void loop() {
  conveyor.Status();
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
    if (inChar == '\n') {
      Serial.println(inputString);  
      if(inputString == "start\n"){
        conveyor.start();
        Serial.println("Start Conveyor.");
      }
       if(inputString == "stop\n"){
        conveyor.Stop();
        Serial.println("Stop Conveyor.");  
      }
       if(inputString == "reverse\n"){
        conveyor.reverse();
        Serial.println("Return Conveyor.");  
      }
      
      inputString = "";
    }
  }
}
