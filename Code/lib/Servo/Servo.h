#ifndef Servo_h
#include <Arduino.h>
#include <ESP32Servo.h>

#define Servo_h

Servo myServo;

int globalPinServo = 2; //Variable del pin servo
//Variables para el control de la posicion del servo 
int globalServoInitialPosicion = 90;
int globalRighttAngleOfVision = 10;
int globalLeftAngleOfVision = 170;
int globalServoPosicion = 0;
int globalServoReadLeft = 0;
int globalServoReadRight = 0;


void InitiliationServo(){

  //Vinculamos el pin del servo indicando el rango de velocidad
  myServo.attach(globalPinServo,500,1500);

  //Posicion del servo inicial
  myServo.write(globalServoInitialPosicion);

}




#endif