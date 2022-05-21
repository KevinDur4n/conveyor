#include <Arduino.h>
#include "Led.h"

void Led::init(){
  pinMode(_pin,OUTPUT);
  digitalWrite(_pin,LOW);
}

void Led::twoBlink(){
  on();
  delay(50);
  off();
  delay(50);
  on();
  delay(50);
  off();
}

void Led::fourBlink(){
  on();
  delay(50);
  off();
  delay(50);
  on();
  delay(50);
  off();
  delay(50);
  on();
  delay(50);
  off();
  delay(50);
  on();
  delay(50);
  off();
}

void Led::on(){
  digitalWrite(_pin,HIGH);
}

void Led::off(){
  digitalWrite(_pin,LOW);
}
