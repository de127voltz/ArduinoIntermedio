#include <LiquidCrystal.h>                                    // Librería para controlar nuestro LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   // Constantes de conexion con los pines del LCD
const int BtnDown=8;                                // Pin BtnDown relacionado con pin 6 para reducir el contador
const int BtnUp=9;                                  // Pin BtnUp relacionado con pin 7 para aumentar el contador
int Contador=0;                                     // Variable Contador iniciada en 0
byte CaraFeliz[8] = {                               // Array para carita feliz 
 B00000,
 B01010,
 B01010,
 B01010,
 B00000,
 B10001,
 B01110,
 B00000
};
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);          // Relacion de constantes para el LCD
void setup() 
{
  pinMode(BtnDown, INPUT);          // BtnDown como entrada digital
  pinMode(BtnUp, INPUT);            // BtnUp como entrada digital
  lcd.createChar(1,CaraFeliz);      // Creamos un Char con nuestra estructura de Carita feliz con valor de referencia 1
  lcd.begin(16, 2);                 // Inicializacion del LCD delimitando la cantidad de caracteres por linea (16)
                                    // y cantidad de lineas (2)
  lcd.setCursor(3, 0);              // Ponemos cursor en la posicion 3,0 (posicion 3 de primer fila)
  lcd.print("127Voltz.mx");         // Escribimos el texto de bienvenida
  delay(2000);                      // delay de 2 segundos
  for(int i=0; i<=2; i++)           // Para la variable i=0, i<=2,i++...
  {
    lcd.setCursor(i,1);             // Nos posicionamos en el valor de i en el lcd
    lcd.write(1);                   // imprimimos en el lcd la carita feliz
    delay(1000);                    // delay de 1 segundo
  }
  lcd.clear();                      // borramos todo el contenido del lcd
  lcd.setCursor(3, 0);              // Ponemos cursor en la posicion 3,0 (posicion 3 de primer fila)
  lcd.print("127Voltz.mx");         // Escribimos el texto de bienvenida
}
void loop() 
{
  if(digitalRead(BtnDown)==HIGH)      // Sí BtnDown es presionado...
  {
    Contador=Contador-1;              // Reducimos el valor de Contador
    lcd.clear();                      // borramos todo el contenido del lcd
    lcd.setCursor(3, 0);              // Ponemos cursor en la posicion 3,0 (posicion 3 de primer fila)
    lcd.print("127Voltz.mx");         // Escribimos el texto de bienvenida
    lcd.setCursor(0, 1);              // Nos posicionamos en 0,1 (posicion 0 de segunda fila) 
    lcd.print("Contador = ");         // Escribimos Contador =
    lcd.setCursor(11, 1);             // Vamos a una nueva posicion para escribir el valor del contador
    lcd.print(Contador);              // Escribimos el valor del contador
    delay(200);                       // Delay para nueva pulsacion
  }
  if(digitalRead(BtnUp)==HIGH)        // Sí BtnUp es presionado...
  {
    Contador=Contador+1;              // Aumentamos el valor de Contador
    lcd.clear();                      // borramos todo el contenido del lcd
    lcd.setCursor(3, 0);              // Ponemos cursor en la posicion 3,0 (posicion 3 de primer fila)
    lcd.print("127Voltz.mx");         // Escribimos el texto de bienvenida
    lcd.setCursor(0, 1);              // Nos posicionamos en 0,1 (posicion 0 de segunda fila) 
    lcd.print("Contador = ");         // Escribimos Contador =
    lcd.setCursor(11, 1);             // Nos posicionamos en 0,1 (segunda fila) 
    lcd.print(Contador);              // Escribimos el valor del contador
    delay(200);                       // Delay para nueva pulsacion
  }
}
