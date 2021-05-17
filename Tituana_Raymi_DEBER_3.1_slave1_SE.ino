

/////////////////////////////SLAVE 1///////////////////////////////////////////

#include <Wire.h>
char dato;
const int led1 =8;
const int led2 =9;
const int led3 =10;


void setup() {
Wire.begin(4);    //id slave
Serial.begin(9600);
Wire.onReceive(receiveEvent);
pinMode(led1,OUTPUT); //pin8 salida
pinMode(led2,OUTPUT); //pin9 salida
pinMode(led3,OUTPUT); //pin10 salida

}

void loop() {


}
void receiveEvent(int bytes){
  while(Wire.available()){
    dato=Wire.read();
    switch (dato){
      case 'R':
      
      digitalWrite(led1,HIGH);
      delay(20000);
      digitalWrite(led1,LOW);
      delay(20000);
      digitalWrite(led2,HIGH);
      delay(20000);
      digitalWrite(led2,LOW);
      delay(20000);
      digitalWrite(led3,HIGH);
      delay(20000);
      digitalWrite(led3,LOW);  


      break;

      default:
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      break;
    }
  }
}
