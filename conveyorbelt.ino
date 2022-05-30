#include "Base.h"
#include <SoftwareSerial.h>
//pines de interrupcion 2, 3, 21, 20, 19 , 18 .
//pines pwm 2 - 13, 44 - 46
//pines uart (18,19) , (0,1)

int readpinA;
int readpinB;
int intPinEmergency = 21;
int intPinSensor = 20;
int LEDpin = 12;
int pinPiston = 2;
//Serial Events
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
volatile bool bottleCap = false;
volatile int numBottleCap = 0;
//SoftwareSerial BTserial(19, 18); // Digital pins 2 and 3 for bluetooth RX and TX
Base conveyor(40,41,LEDpin, pinPiston);
Servo piston;

void setup() {
 conveyor.init();
 Serial.begin(9600);
 Serial1.begin(9600);
 pinMode(intPinEmergency,INPUT_PULLUP);
 pinMode(intPinSensor,INPUT);
 pinMode(LEDpin,OUTPUT);
 pinMode(13, OUTPUT);
 digitalWrite(13,LOW);
 attachInterrupt(digitalPinToInterrupt(intPinEmergency), eventEmergency, FALLING);
 attachInterrupt(digitalPinToInterrupt(intPinSensor), eventSensor, RISING);
 piston.attach(pinPiston);
 piston.write(0);
 Serial.println("Conveyor Belt beging...");
 Serial1.println("Conveyor Belt beging...");
 conveyor.Stop();
}

void loop() {
  conveyor.Status();
  
  if(bottleCap == true){
    numBottleCap++;
    Serial1.print("value");Serial1.println(numBottleCap);
    conveyor.Stop();
    outPiston(180);
    bottleCap = false;
    digitalWrite(13,LOW);
    conveyor.start();
    
  }
  
  
}

void eventEmergency(){
    Serial.println("Emergency Stop Conveyor.");
    conveyor.Stop();
}

void eventSensor(){
    //Dectect a bottle cap
    Serial.println("Bottle cap Dectected.");
    bottleCap = true;
    digitalWrite(13,HIGH);
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
      if(inputString == "start\n" ){
        conveyor.start();
        Serial1.println("Start conveyor.");
      }
       if(inputString == "stop\n"){
        conveyor.Stop();
        Serial1.println("Stop conveyor.");
      }
       if(inputString == "reverse\n" ){
        conveyor.reverse();
        Serial1.println("Reverse conveyor.");
      }
      
      inputString = "";
    }
  }
}

void serialEvent1(){
  while (Serial1.available()) {
    // get the new byte:
    char inChar = (char)Serial1.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop canstart
    // do something about it:
    if (inChar == '\n') {
      if(inputString == "1\n" ){
        conveyor.start();
      }
       if(inputString == "2\n"){
        conveyor.Stop();
      }
       if(inputString == "3\n" ){
        conveyor.reverse();
      }
      
      inputString = "";
    }
  }
}

void outPiston (int targetDeg){
  int pos = 0;
  piston.write(targetDeg);
  delay(2000);
  piston.write(0);
  
}
