#ifndef CLI_h
#define CLI_h
#include <Arduino.h>

int ControlAccions(){
  int opcion = 0;
  
  Serial.println("Enter the number that accompanies the robot's modality: ");
  Serial.println("1.Line follower ");
  Serial.println("2.avoid obstacles");
  Serial.println("3.Follower of people");
  Serial.println("4.Bluetooth controlled trolley ");
  while(Serial.available() == 0){
    //Se deja en blanco porque no va a ejecutar nada para esperar a que el usuario digite
  }
  opcion = Serial.parseInt();

  return opcion;
}


#endif