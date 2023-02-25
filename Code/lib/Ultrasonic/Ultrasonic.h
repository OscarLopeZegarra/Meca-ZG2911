#ifndef Ultrasonic_h
#include<Arduino.h>


#define Ultrasonic_h
#define PIN_ECHO 14
#define PIN_TRIG 12

void InitializationUltrasonic(){
  pinMode(PIN_ECHO,INPUT);
  pinMode(PIN_TRIG,OUTPUT);

}

int MeasuringDistance(){
  //Variables para el funcionamiento del sensor
  float distance = 0;
  long duration = 0;
  int delayInStarting = 2;
  int delayToKeepOn = 10;
  //Lanza el pulso del sensor
  digitalWrite(PIN_TRIG,LOW);
  delayMicroseconds(delayInStarting);
  digitalWrite(PIN_TRIG,HIGH);
  delayMicroseconds(delayToKeepOn);
  digitalWrite(PIN_TRIG,LOW);

  //Leemos el tiempo que tarda el sensor
  duration = pulseIn(PIN_ECHO,HIGH);

  //Calculamos la distancia
  distance = (float)((distance*0.034)/2);

  return distance;
}

#endif