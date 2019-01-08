volatile int Contador=0;    // Variable entera volatil para conteo de objetos   
volatile int ContadorRef=0; // variable entera volatil de referencia
int LEDV=3;                 // LED Verde (avanzando motor de banda)
int LEDR=4;                 // LED Rojo (banda detenida)
int Motor=5;                // Motor
void setup() 
{
  attachInterrupt(digitalPinToInterrupt(2), Objeto, RISING);    // Configuramos pin 2 de interrupcion 
                                                                // para deteccion de objeto
  pinMode(LEDV, OUTPUT);        // Salida de led verde
  pinMode(LEDR, OUTPUT);        // Salida de led rojo
  pinMode(Motor,OUTPUT);        // Salida de motor
}
void loop() 
{
  if(Contador>ContadorRef)          // Si hay diferencia entre el contador de interrupcion y el 
                                    // contador de referencia
  {
    digitalWrite(LEDV,HIGH);        // Enciende LED verde
    digitalWrite(LEDR,LOW);         // Apaga LED rojo
    analogWrite(Motor,5);           // Reduce velocidad de motor
    delay(500);
    ContadorRef=Contador;
  }
  else                              // de otro modo
  {
    digitalWrite(LEDV,LOW);        // Apaga LED verde
    digitalWrite(LEDR,HIGH);       // Enciende LED rojo
    analogWrite(Motor,255);        // Motor a maxima velocidad
  }
}
void Objeto()           //void para deteccion por sensor
{
  Contador++;           //aumento de contador de objetos
}

