int Dato;               // Variable tipo entera llamada Dato para obtener lectura de puerto serial
int Motor=3;            // Variable tipo entera llamada Motor referenciada al pin 3 del Arduino Uno (PWM)
void setup() 
{
  pinMode(Motor, OUTPUT);         // Declaracion del pin 3 Motor como salida digital
  Serial.begin(9600);             /* Inicio de la funcion de comunicacion serial y realizacion de la velocidad de transmision entre el Arduino
                                     y la Computadora, la velocidad de Baudios debe ser la misma en ambos sistemas para que las instrucciones
                                     puedan ser enviadas y recibidas.
                                  */
  Serial.println("A==> Arranque Directo, B==> Parar, C==> 50% de velocidad, D==> 70% de velocidad"); // Escritura de comandos para escribir en el monitor serie
}
void loop() 
{
  if(Serial.available())                      // Si el puerto serial se encuentra diponible...
  {
    Dato=Serial.read();                       // Lectura del puesto rerial y asignacion del dato leidoa la variable Dato
    switch(Dato)                              // Switch case con referencia al valor de la variable Dato
    {
      case 'A':                               // Caso donde variable Dato es "A"
        Serial.println("Arranque directo");   // Escritura en puerto serial de arranque directo del motor
        analogWrite(Motor, 255);              // Arranque directo (255=100%)
        break;                                // Ruptura de caso A
      case 'B':                               // Caso donde variable Dato es "B"
        Serial.println("Paro");               // Escritura en puerto serial de de paro de motor
        analogWrite(Motor, 0);                // Apagar motor
        break;                                // Ruptura de caso B
      case 'C':                               // Caso donde variable Dato es "C"
        Serial.println("50% de velocidad");   // Escritura en puerto serial de 30% de velocidad del motor
        analogWrite(Motor, 128);              // Arranque a 30% de velocidad (255=100% por lo tanto 30%= 76.5~77)
        break;                                // Ruptura de caso C
      case 'D':                               // Caso donde variable Dato es "D"
        Serial.println("70% de velocidad");   // Escritura en puerto serial de 70% de velocidad
        analogWrite(Motor, 179);              // Arranque a 70% de velocidad (255=100% por lo tanto 70%=178.5~179)
        break;                                // Ruptura de caso D
    }
  }
}
