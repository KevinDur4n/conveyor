#include <Arduino.h>
#include "Base.h"
bool statusConveyorReturn = false;
void Base::init(){
  motor.Inicializar_Motor();
  LedStatus.init();
  motor.Stop();
}
void Base::start(){
  LedStatus.off();
  motor.Adelante();
  statusConveyorReturn = false;
}
void Base::Stop(){
  LedStatus.on();
  motor.Stop();
  statusConveyorReturn = false;
}
void Base::reverse(){
  motor.Atras();
  statusConveyorReturn = true;
}

void Base::Status(){
  if(statusConveyorReturn){
    LedStatus.twoBlink();
  }
}
