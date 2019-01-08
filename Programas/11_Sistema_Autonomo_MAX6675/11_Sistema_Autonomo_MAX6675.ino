#include <max6675.h>        // Libreria para MAX6675
int SO = 8;                 // Pin para SO de Max 6675
int CS = 9;                 // Pin para CS de Max 6675
int CLK = 10;               // Pin para CLOCK de Max 6675
int LEDR = 2;               // Pin para LED Rojo para mostrar que se ha sobrepasado el limite de temperatura
int LEDV = 3;               // Pin para LED Verde para mostrar que la temperatura esta dentro del limite establecido
MAX6675 Sensor(CLK, CS, SO);   // Parametros de funcionamiento para el MAX6675
void setup() 
{
  Serial.begin(9600);       /* Inicio de la funcion de comunicacion serial y realizacion de la velocidad de transmision entre el Arduino
                               y la Computadora, la velocidad de Baudios debe ser la misma en ambos sistemas para que las instrucciones
                               puedan ser enviadas y recibidas.
                            */
  pinMode(LEDR,OUTPUT);     // LEDR como salida 
  pinMode(LEDV,OUTPUT);     // LEDV como salida
  digitalWrite(LEDR,LOW);
  digitalWrite(LEDV,LOW);
  delay(500);               // Retardo para permitir la estabilizacion del sensor
}
void loop() 
{
   Serial.print("Grados C = ");                 // Escribimos Grados Celcius
   Serial.print(Sensor.readCelsius());          // Hacemos lectura del Sensor y convertimos a grados Celsius (libreria de MAX6675)
   Serial.print("\t Grados F = ");              // Escribimos Grados Fahrenheit
   Serial.println(Sensor.readFahrenheit());     // Hacemos lectura del Sensor y convertimos a grados Fahrenheit (libreria de MAX6675)
   delay(500);                                  // Retardo para nuevo muestreo
   if(Sensor.readCelsius()>28.0)               // Si la lecura del sensor en gradosCelsius supera 28 grados
   {
    digitalWrite(LEDR,LOW);                     // Enciende LED Rojo
    digitalWrite(LEDV,HIGH);                    // Apaga LED Verde
   }
   else                                         // De otro modo...
   {
    digitalWrite(LEDR,HIGH);                    // Apaga LED Rojo
    digitalWrite(LEDV,LOW);                     // Enciende LED Verde
   }
}
