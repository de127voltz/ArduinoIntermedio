volatile int Velocidad=20;                         // Variable entera de velocidad (debe ser volatile por que cambiara en 
                                                   // cualquier momento del programa cuando sea llamada esta variable
const int VMin = 1000;                             // Constante entera de velocidad minima (1 segundo)
const int VMax = 20;                               // Constante entera de velocidad maxima (20 ms)
const int Cambio = 20;                             // Constante de cuanto aumenta o disminuye la velocidad de encendido de luces
int LEDS[8] = {5, 6, 7, 8, 9, 10, 11, 12};         // Array con los números de los pines donde están conectados
void setup() 
{
  for (int i = 0; i < 8; i++)       // Para cuando la variable entera i es igual a 0, i es menor a 8, i aumenta su valor +1
  {
    pinMode(LEDS[i], OUTPUT);       // Declaramos los pines relacionados al Array LEDS como salidas
    digitalWrite(LEDS[i], LOW);     // Iniciamos los pines relacionados al Array LEDS en estado bajo (apagados)
  }
  Velocidad = VMin;                                               // Asignamos la velocidad mínima (1 segundo)
  attachInterrupt(digitalPinToInterrupt(2), VelLenta, RISING);    // Configuramos pin 2 de interrupcion para que detectar
                                                                  // un cambio de bajo a alto y lo llamamos VelLenta
  attachInterrupt(digitalPinToInterrupt(3), VelRapida, RISING);   // Configuramos pin 3 de interrupcion para que detectar
                                                                  // un cambio de bajo a alto y lo llamamos VelRapida
}
void loop() 
{
  for (int i = 0; i < 8; i++)               /* Primer bucle, recorre el array de izquierda a derecha. Solo para el segundo pin 
                                               y consecutivos apagamos el pin anterior. En el caso de 0 no hace falta ya que 
                                               por defecto está apagado. Cuidado que nos salimos del rango del array 0-1=-1 
                                               no existe este elemento.
                                            */
  {
    if (i > 0)                              // Si i es mayor a 0
    {
      digitalWrite(LEDS[i - 1], LOW);       // Apagamos el LED a la izquierda
    }
    digitalWrite(LEDS[i], HIGH);            // Encendemos en el LED en el que estamos
    delay(Velocidad);                       // Esperamos el tiempo marcado por velocidad
  }
  digitalWrite(LEDS[7], LOW);               // Apagamos el último LED encendido, el elemento 9 del Array LEDS
 
  for (int i = 8; i >= 0; i--)              /* Recorremos el Array de derecha a izquierda. En el primer caso como ya está 
                                               apagado el LED no hacemos nada. Cuidado que nos salimos del rango del array 
                                               10+1=11 no existe este elemento.
                                             */
  {
    if (i < 8)                              // Si i es menor a 8
    {
      digitalWrite(LEDS[i + 1], LOW);       // Apagamos el LED a la derecha
    }
    digitalWrite(LEDS[i], HIGH);            // Encendemos en el LED en el que estamos
    delay(Velocidad);                       // Esperamos el tiempo marcado por velocidad
  }
  digitalWrite(LEDS[0], LOW);               // Apagamos el último LED encendido, el elemento 0 del Array 
}
void VelRapida()                      // ISR pin 2, aumenta la velocidad
{
  Velocidad = Velocidad - Cambio;     // Disminuimos el valor establecido 
  if (Velocidad < VMax)               // Si Velocidad es menor a Vmax (20ms)
  {
    Velocidad = VMax;                 // Velocidad llega a rango maximo
  }
}
void VelLenta()                       //ISR pin 3, disminuye la velocidad
{
  Velocidad = Velocidad + Cambio;     // Aumentamos el valor establecido
  if (Velocidad > VMin)               // Si Velocidad es mayor a VMin
  {
    Velocidad = VMax;                 // Velocidad llega a rango minimo
  }
}
