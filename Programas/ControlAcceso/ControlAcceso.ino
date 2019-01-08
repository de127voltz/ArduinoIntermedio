#include <Keypad.h>               // Libreria para teclado matricial
const byte Filas=4;               // Cuatro filas de teclado
const byte Columnas=4;            // Cuatro columnas de teclado
byte PFilas[]={9,8,7,6};          // Pines del Arduino correspondientes para Filas
byte PColumnas[]={5,4,3,2};       // Pines del Arduino correspondientes para Columnas
char Teclas [Filas][Columnas]=    // valores correspondientes para cada tecla
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
char CodigoAcceso[3]={'1','2','7'};   // Clave de acceso
int Posicionador=0;                   // Posicionador para manejo de la clave
int Contador=0;                       // Contador de datos insertados
int Clave=0;                          // Clave realizar funciones si la clave es correcta o no
int LEDA=10;                          // LED Amarillo para encenderse cada que se presiona una tecla
int LEDV=11;                          // LED Verde para dar acceso
int LEDR=12;                          // LED Rojo para no permitir acceso
Keypad Teclado=Keypad(makeKeymap(Teclas),PFilas, PColumnas, Filas, Columnas);   // Realiza mapa de teclas para libreria de Keypad
void setup()
{
  pinMode(LEDA,OUTPUT);     // LEDA como salida
  pinMode(LEDV,OUTPUT);     // LEDV como salida
  pinMode(LEDR,OUTPUT);     // LEDR como salida
  digitalWrite(LEDV,LOW);   // LEDV inicia como apagado
  digitalWrite(LEDR,HIGH);  // LEDR inicia encendido
  Serial.begin(9600);       /* Inicio de la funcion de comunicacion serial y realizacion de la velocidad de transmision entre el Arduino
                               y la Computadora, la velocidad de Baudios debe ser la misma en ambos sistemas para que las instrucciones 
                               puedan ser enviadas y recibidas.
                            */
  Serial.println("Digite clave de Acceso");     // Mensaje inicial
}
void loop()
{
  char Pulsacion=Teclado.getKey();    // Obtencion de valor de tecla presionada
  if(Pulsacion!=0)                    // Si se ha pulsado una tecla
  {
    if(Pulsacion!='#' && Pulsacion!='*' && Clave==0)  // Si la tecla presionada no es #, * y Clave es igual a 0
    {
      digitalWrite(LEDA,HIGH);                        // Enciende LED Amarillo
      delay(200);                                     // Retraso de 200ms
      digitalWrite(LEDA,LOW);                         // Apaga LED Amarillo
      if(Pulsacion==CodigoAcceso[Posicionador])       // Si pulsacion es igual al Codigo de Acceso
      Posicionador++;                                 // Posicionador aumenta su valor
      if(Posicionador==3)             // Si Posicionador es igual a 3
      {
        digitalWrite(LEDA,HIGH);      // Enciende LED Amarillo
        delay(200);                   // Retraso de 200ms
        digitalWrite(LEDA,LOW);       // Apaga LED Amarillo
        delay(200);                   // Retraso de 200ms
        digitalWrite(LEDA,HIGH);      // Enciende LED Amarillo
        delay(200);                   // Retraso de 200ms
        digitalWrite(LEDA,LOW);       // Apaga LED Amarillo
        delay(200);                   // Retraso de 200ms
        digitalWrite(LEDA,HIGH);      // Enciende LED Amarillo
        delay(500);                   // Retraso de 500ms
        Clave=1;                      // Clave aceptada, permite Acceso
        Serial.println("Clave Correcta, Acceso Permitido");       // Escribimos en el puerto serial que se permite el acceso
        digitalWrite(LEDA,LOW);       // Apaga LED Amarillo
        digitalWrite(LEDV,HIGH);      // Enciende LED Verde
        digitalWrite(LEDR,LOW);       // Apaga LED Rojo
      }
      if(Contador>5)                  // Si Contador es mayor a 5
      {
        Serial.println("Clave Incorrecta, Acceso No Permitido");       // Escribimos en el puerto serial que no se permite el acceso
        Contador=0;                   // Contador igual a 0
        Posicionador=0;               // Posicionador igual a 0
        if(Clave==0)                  // Si Clave es igual a 0
        {
          digitalWrite(LEDA,HIGH);    // Enciende LED Amarillo
          delay(500);                 // Retraso de 500ms
          digitalWrite(LEDA,LOW);     // Apaga LED Amarillo
        }
      }
    }
  }
  if(Pulsacion=='*')            // Si se pulsa * (reset despues de permitir acceso)
  {
    Serial.println("Digite clave de Acceso");     // Mensaje para pedir nuevo permiso de acceso
    Posicionador=0;             // Posicionador igual a 0
    Contador=5;                 // Contador igual a 5
    Clave=0;                    // Clave igual a 0
    Posicionador=0;             // Posicionador igual a 0 (necesario para reset)
    digitalWrite(LEDV,LOW);     // Apaga LED Verde
    digitalWrite(LEDR,HIGH);    // Enciende LED Rojo
  }
}
