#ifndef InfaredSensor.h
#include <Arduino.h>

#define InfaredSensor.h
#define PIN_RIGHT_INFRARED_SENSOR 9
#define PIN_LEFT_INFRARED_SENSOR 10

/*Variables para el sensor Inflarojo del seguidor de Linea
  El sensor emite seniales de 0 y 1 
  Donde:
  0 -> El sensor detecta el blanco
  1 -> El sensor detecta negro 
  Detectamos el valor y lo registramos
*/
int globalRightSensorOutputValue = 0;
int globalLeftSensorOutputValue = 0;

void InitializationInfraredSensor(){
  pinMode(PIN_RIGHT_INFRARED_SENSOR,INPUT);
  pinMode(PIN_LEFT_INFRARED_SENSOR,INPUT);

}

void InfraredReading(){
  globalRightSensorOutputValue = digitalRead(PIN_RIGHT_INFRARED_SENSOR);
  globalLeftSensorOutputValue = digitalRead(PIN_LEFT_INFRARED_SENSOR);
}



#endif