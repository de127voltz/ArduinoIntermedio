int LEDR = 10;                  // Pin de LED Rojo para mostrar que se ha detectado movimiento
int Sensor = 2;                 // Pin para recibir la señal del sensor PIR
int EstadoSensor = LOW;         // Iniciamos el sensor como en no deteccion
int Valor = 0;                  // Variable para el estado del sensor
void setup() 
{
  pinMode(LEDR, OUTPUT);      // Declarar LED Rojo como salida
  pinMode(Sensor, INPUT);     // Declrar sensor como entrada
  Serial.begin(9600);         /* Inicio de la funcion de comunicacion serial y realizacion de la velocidad de transmision entre el Arduino
                                 y la Computadora, la velocidad de Baudios debe ser la misma en ambos sistemas para que las instrucciones
                                 puedan ser enviadas y recibidas.
                              */
}
void loop()
{
  Valor = digitalRead(Sensor);                        // Leemos el valor del Sensor y lo guardamos en Valor
  if (Valor == HIGH)                                  // Si el valor es alto (deteccion)
  {
    digitalWrite(LEDR, HIGH);                         // Encendemos LED Rojo
    if (EstadoSensor == LOW)                          // Si el estado del sensor es bajo (memoria)
    {
      Serial.println("Se ha detectado movimiento");   // Escritura en puerto serial de deteccion de movimiento
      EstadoSensor = HIGH;                            // Cambio de EstadoSensor a alto (memoria)
    }
  } 
  else                                                // De otro modo... (si no hay deteccion)
  {
    digitalWrite(LEDR, LOW);                          // Apagamos LED Rojo 
    if (EstadoSensor == HIGH)                         // Si EstadoSensor es alto (memoria)
    {
      Serial.println("Sin movimiento");               // Mensaje de no detección
      EstadoSensor = LOW;                             // Cambio de EstadoSensor a bajo (memoria)
    }
  }
}
