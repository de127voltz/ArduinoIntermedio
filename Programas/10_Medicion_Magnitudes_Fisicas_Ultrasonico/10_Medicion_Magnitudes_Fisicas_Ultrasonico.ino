const int Trigger = 4;   //Pin 2 para el Trigger del sensor
const int Echo = 5;      //Pin 3 para el Echo del sensor
int Verde=6;
int Rojo=7;
void setup() 
{
  Serial.begin(9600);           /* Inicio de la funcion de comunicacion serial y realizacion 
                                   de la velocidad de transmision entre el Arduino y la 
                                   Computadora, la velocidad de Baudios debe ser la misma en 
                                   ambos sistemas para que las instrucciones puedan ser 
                                   enviadas y recibidas.
                                */
  pinMode(Trigger, OUTPUT);     // Declaramos el pin del Trigger como salida
  pinMode(Echo, INPUT);         // Declaramos el pin del Echo como entrada
  pinMode(Verde,OUTPUT);
  pinMode(Rojo,OUTPUT);
  digitalWrite(Trigger, LOW);   // Inicializamos el Trigger con 0 logico
}
void loop()
{
  long t;           // Variable tipo long t para obtener el tiempo que demora en llegar el eco
  long d;           // Variable tipo long d para obtener la distancia en centimetros
  digitalWrite(Trigger, HIGH);    // Enviamos un valor en alto al Trigger
  delayMicroseconds(10);          // Delay de 10us
  digitalWrite(Trigger, LOW);     // Enviamos un valor en bajo al Trigger
  
  t = pulseIn(Echo, HIGH);        // Obtenemos cuanto tiempo tarda en detectar en eco
  d = t/59;                       /* Escalamos el tiempo que tarda en llegar el sonido a una distancia en cm (la velocidad del sonido es de 340m/s),
                                     entonces con la conversion y el despeje de la formula de v=(d/t) se veria como d=(t/s) siendo d en cm, t en us
                                     y s como el tiempo referencial
                                  */ 
  Serial.print("Distancia: ");    // Escribimos en el puerto serial Distancia
  Serial.print(d);                // Escribimos el valor obtenido
  Serial.println("cm");           // Escribimos la magnitud
  delay(100);                     // Delay de 100ms (el sensor requiere un Delay de minimo 60ms)
}
