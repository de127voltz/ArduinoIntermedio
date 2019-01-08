#include <EEPROM.h>           // Incluimos libreria para el uso de la EEPROM
void setup() 
{
  for(int a=0;a<1025;a++)     // Para la variable a=0, a menor a 1025, aumenta el valor de a
  {
    EEPROM.write(a,0);        /* Escribimos en la memoria EEPROM el valor de 0 en la localidad a
                               * el valor lo ponemos de un rango de 0 a 1025 debido a que el tamaño
                               * de la memoria EEPROM es de 1024 bits, al escribir un 0 en la memoria nos
                               * aseguramos de borrar todo lo escrito dentro de nuestra memoria (en caso de escribir
                               * anteriormente en nuestra memoria)
                                */  
  }
}
void loop() 
{

}
