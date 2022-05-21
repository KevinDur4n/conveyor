#include <Arduino.h>                //Permite utilizar los comandos de Arduino
#include "Motor.h"

void Motor_DC::Inicializar_Motor()  
{
  pinMode(_A, OUTPUT);             //Pines declarados en Salida
  pinMode(_B, OUTPUT);
  
}
void Motor_DC::Atras()             //Funcion de movimiento atras
{
  digitalWrite(_A, LOW);           
  digitalWrite(_B, HIGH);
}
void Motor_DC::Adelante()          //Funcion de movimiento adelante
{
  digitalWrite(_A, HIGH);
  digitalWrite(_B, LOW);
}
void Motor_DC::Stop()              //Funcion de parada
{
  digitalWrite(_A, LOW);
  digitalWrite(_B, LOW);
}
