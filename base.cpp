#include <Arduino.h>
#include "Base.h"
bool statusConveyorReturn = false;
void Base::init(){
  // Configura elementos
  motor.Inicializar_Motor();
  LedStatus.init();
  // Configura elementos para el inicio
  motor.Stop();
  //Configuracione extra de pines
}

void Base::Status(){
  if(statusConveyorReturn){
    LedStatus.twoBlink();
  }
}

void Base::start(){
  
  LedStatus.off();
  motor.Adelante();
  Serial.println("Start Conveyor.");  
  statusConveyorReturn = false;
}
void Base::Stop(){
  LedStatus.on();
  motor.Stop();
  statusConveyorReturn = false;
  Serial.println("Stop Conveyor."); 
}
void Base::reverse(){
  motor.Atras();
  Serial.println("Return Conveyor.");  
  statusConveyorReturn = true;
}
