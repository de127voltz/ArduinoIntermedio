#include <EEPROM.h>           // Incluimos la libreria para el uso de la memoria EEPROM
int LED=2;                    // Variable entera LED relacionado al pin 2
int a=0;                      // Variable entera a inicializado en 0 para hacer conteo de uso del circuito
void setup() 
{
  pinMode(LED,OUTPUT);        // LED como salida
  a=EEPROM.read(0);           // Valor de a igual a la lectura de la memoria EEPROM en la localidad 0
}
void loop() 
{
  while(a<3)                  // Mientras a sea menor a 3 (3 veces de uso del circuito)
  {
    a++;                      // a aumenta su valor en 1
    digitalWrite(LED,HIGH);   // Encendemos LED
    delay(500);               // Retardo de 500ms
    digitalWrite(LED,LOW);    // Apagamos LED
    delay(500);               // Retardo de 500ms
    EEPROM.write(0,a);        // Escribimos en la localidad 0 de la memoria EEPROM el valor de a
  }
 
}
