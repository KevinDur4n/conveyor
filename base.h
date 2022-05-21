#include "Motor.h"
#include "Led.h"
class Base{
  private:
  public:
  Motor_DC motor;
  Led LedStatus;
  Base(
    int pinMotorA,
    int pinMotorB,
    int pinLed
    ):
  motor(pinMotorA,pinMotorB), LedStatus(pinLed){}
  
  void init();
  void start();
  void Stop();
  void reverse();
  void Status();
};
