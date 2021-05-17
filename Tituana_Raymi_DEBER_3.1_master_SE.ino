
/////////////////////////////MASTER///////////////////////////////////////////

 
 #include <Wire.h>      //Libreria I2C  
 char dato;             //Variable de almacenamiento de datos 
 
void setup() {
  Wire.begin();        //Inicia comunicacion I2C
  Serial.begin(9600);  //Inicia comunicacion serial
}

void loop() {
  if(Serial.available()>0){       //Verificar que exista datos
    dato=Serial.read();           //Almacena el dato en la variable
    Wire.beginTransmission(4);    //Empieza la comunicacion I2C
    Wire.write(dato); 
    Wire.endTransmission();       //Termina la comunicacion I2C
    Wire.beginTransmission(5);    //Empieza la comunicacion I2C
    Wire.write(dato); 
    Wire.endTransmission();       //Termina la comunicacion I2C
    Wire.beginTransmission(6);    //Empieza la comunicacion I2C
    Wire.write(dato);             //Envio dato
    Wire.endTransmission();       //Termina la comunicacion I2C
  }
}
