#ifndef Motor_h
#include <Arduino.h>

#define Motor_h
#define PIN_MOTOR_RIGHT_FWD 18
#define PIN_MOTOR_RIGHT_BWD 19
#define PIN_RIGHT_MOTOR_SPEED 16
#define PIN_MOTOR_LEFT_FWD 5
#define PIN_MOTOR_LEFT_BWD 17
#define PIN_LEFT_MOTOR_SPEED 4

void InitializationMotor(){
//Variables para la velocidad del motor
int globalMotorSpeed = 0;

while(Serial.available() == 0){
    //Se deja en blanco porque no va a ejecutar nada para esperar a que el usuario digite
  }
  globalMotorSpeed = Serial.parseInt();

//Inicializacion de los pines del motor
pinMode(PIN_MOTOR_RIGHT_FWD,OUTPUT);
pinMode(PIN_MOTOR_RIGHT_BWD,OUTPUT);
pinMode(PIN_MOTOR_LEFT_FWD,OUTPUT);
pinMode(PIN_MOTOR_LEFT_BWD,OUTPUT);
pinMode (PIN_RIGHT_MOTOR_SPEED,OUTPUT);
pinMode(PIN_LEFT_MOTOR_SPEED,OUTPUT);

//Configuramos los motores a velocidad de 150 hasta 255
analogWrite (PIN_RIGHT_MOTOR_SPEED,globalMotorSpeed);
analogWrite(PIN_LEFT_MOTOR_SPEED,globalMotorSpeed);

//Los motores se inician apagados
digitalWrite(PIN_MOTOR_RIGHT_FWD,LOW);
digitalWrite(PIN_MOTOR_RIGHT_BWD,LOW);
digitalWrite(PIN_MOTOR_LEFT_BWD,LOW);
digitalWrite(PIN_MOTOR_LEFT_FWD,LOW);


}

void StopCar(){
  //Configuramos los motores para que se detenga
  digitalWrite(PIN_MOTOR_RIGHT_FWD,LOW);
  digitalWrite(PIN_MOTOR_RIGHT_BWD,LOW);
  digitalWrite(PIN_MOTOR_LEFT_FWD,LOW);
  digitalWrite(PIN_MOTOR_LEFT_BWD,LOW);
  
}

void TurnForwardCar(){
  //Configuramos los motores para que se dirija hacia adelante
  digitalWrite(PIN_MOTOR_RIGHT_FWD,HIGH);
  digitalWrite(PIN_MOTOR_RIGHT_BWD,LOW);
  digitalWrite(PIN_MOTOR_LEFT_FWD,HIGH);
  digitalWrite(PIN_MOTOR_LEFT_BWD,LOW);
  
}

void TurnBackwardCar(){
  digitalWrite(PIN_MOTOR_RIGHT_FWD,LOW);
  digitalWrite(PIN_MOTOR_RIGHT_BWD,HIGH);
  digitalWrite(PIN_MOTOR_LEFT_FWD,LOW);
  digitalWrite(PIN_MOTOR_LEFT_BWD,HIGH);
  
}

void TurnRightCar(){
  //Configuramos los motores para que se dirija a la derecha
  digitalWrite(PIN_MOTOR_RIGHT_FWD,LOW);
  digitalWrite(PIN_MOTOR_RIGHT_BWD,HIGH);
  digitalWrite(PIN_MOTOR_LEFT_FWD,HIGH);
  digitalWrite(PIN_MOTOR_LEFT_BWD,LOW);
  
}


void TurnLeftCar(){
  //Configuramos los motores para que se dirija a la izquierda
  digitalWrite(PIN_MOTOR_RIGHT_FWD,HIGH);
  digitalWrite(PIN_MOTOR_RIGHT_BWD,LOW);
  digitalWrite(PIN_MOTOR_LEFT_FWD,LOW);
  digitalWrite(PIN_MOTOR_LEFT_BWD,HIGH);
  
}


#endif