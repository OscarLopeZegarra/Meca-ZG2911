/**
 * @file My firsr Robot .cpp
 * @author Oscar Lopez (oscar.lopez10@unmsm.edu.pe)
 * @brief My first stable robot with multiple basic functions
 * @version 1.0
 * @date 11.02.2023
 * 
 */


/***************************************************************************************************************
 *  									                       			INCLUDE
***************************************************************************************************************/

#include <Arduino.h>
#include <ESP32Servo.h>
#include "Ultrasonic.h" //Libreria creada para activar al sensor de ultrasonido
#include "Motor.h" //Libreria creado especialmente para los motores 
#include "Servo.h" //Libreria creada para el control del servomotor en este proyecto en especifico
#include "InfraredSensor.h" //Libreria creado especificamente para el funcionamiento de los sensores para el seguidor de linea
#include "CLI.h" //Libreria creada para la modalidad del robot



using namespace std;


/***************************************************************************************************************
 *  						                  						  ENUMERATIONS
 **************************************************************************************************************/

enum Comands{
  //Comandos para el funcionamiento del carro 
  //CMD = "COMANDS" 
  CMD_FORWARD = 'w', 
  CMD_BACKWARD = 's', 
  CMD_RIGTH = 'a',
  CMD_LEFT = 'd', 
  CMD_STOP = 'q' 
};

/***************************************************************************************************************
 *  						                  						  GLOBAL VARIABLES
 **************************************************************************************************************/



//Variables para el control del sensor de ultrasionido
int globalObjectDetectionRange = 15;
int globalDelayValue = 600;
float globalDistance = 0.0;

/***************************************************************************************************************
 *  					                							FUNCTION DECLARATION
 **************************************************************************************************************/
//Declaramos las funciones para luego utilizarlas
void setup();
void loop();
void LineFollower();
void BytesReceived(); //Comandos del carro
void ObjectDetector(); //Detecta los objetos cercanos al carro


/***************************************************************************************************************
 *  					                							FUNCTION DEFINITION
 **************************************************************************************************************/

void setup(){

 InitiliationServo();
 InitializationUltrasonic();
 InitializationMotor();
 InitializationInfraredSensor();

//Activacion del monitor serial para poder colocar los comandos
Serial.begin(115200);

}
//=====================================================================================================

void loop(){
    
  if(Serial.available()> 0){  //Si hay comunicacion de datos 
    
  }


}
//=====================================================================================================

void BytesReceived(){ // Despues de recibir el comando
  char bytesReceived = (char)Serial.read();
   
    switch(bytesReceived){

      //Va hacia adelante
      case CMD_FORWARD:
      Serial.println("Forward"); 
      TurnForwardCar();
      
      break;

      //Va hacia atras
      case CMD_BACKWARD:
      Serial.println("Backward");
      TurnBackwardCar();
      
      break;

      //Va hacia la derecha
      case CMD_RIGTH:
      Serial.println("Right");
      TurnRightCar();

      break;
    
      //Va hacia la izquierda
      case CMD_LEFT:
      Serial.println("Left");
      TurnLeftCar();
   
      break;

      //Se detiene el carro
      case CMD_STOP:
      Serial.println("Stop");
      StopCar();
      break;

      default: 
        break;
    }  
  }
//=====================================================================================================

void ObjectDetector(){
  globalDistance = MeasuringDistance(); //Medir distancia
  Serial.println(globalDistance); // Muestra en el monitor serial la distancia

  //Se va a detener el carro de golpe si detecta un objeto cercano a los 15 centimetros
  if (globalDistance < globalObjectDetectionRange){
    StopCar();

    //El servo mirara a la derecha
    myServo.write(globalRighttAngleOfVision);
    delay(globalDelayValue); //Un pequenio retraso para que pueda realizar sus procesos tranquilo
    globalServoReadRight = MeasuringDistance();

    //El servo mirara a la izquierda
    myServo.write(globalLeftAngleOfVision);
    delay(globalDelayValue); //Un pequenio retraso para que pueda realizar sus procesos tranquilo
    globalServoReadLeft = MeasuringDistance();

    //En automatico el coche girara a la izquierda, esquivando el obstaculo
    if(globalServoReadLeft > globalServoReadRight){
      Serial.println("Giro hacia la izquierda");
      TurnLeftCar(); 
    }

    //En automatico el coche girara a la izquierda, esquivando el obstaculo
    if(globalServoReadRight > globalServoReadLeft){
      Serial.println("Giro hacia la derecha");
      TurnRightCar(); 
    }
  }
}
//=====================================================================================================

void LineFollower(){


}