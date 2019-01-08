#include <Adafruit_GFX.h>               //Incluimos libreria de Adafruit para dibujar graficos
#include <Adafruit_SSD1306.h>           //Incluimos libreria de Adafruit para manejo de texto
#define OLED_ADDR 0x3C                  //Definimos la pantalla OLED, 0x3C define que usamos solo una pantalla
Adafruit_SSD1306 display(-1);           // -1 define que no tiene pin de reset
void setup () 
{
  Serial.begin(9600);
  display.begin (SSD1306_SWITCHCAPVCC, OLED_ADDR);    //Inicializamos nuestro display
  display.clearDisplay();            //Limpiamos la pantalla
  display.display();                 //Arrancamos funciones del display

  display.fillRect(0, 0, 128, 32, WHITE);
  display.display();                 //Actualiza la pantalla con todos los gráficos anteriores
  delay(2000);
  display.clearDisplay();            //Limpiamos la pantalla
  display.display();                 //Actualiza la pantalla con todos los gráficos anteriores
  display.setTextSize(2);            //setTextSize es un factor de escala que permite acercar o alejar el texto
  display.setTextColor(WHITE);       //setTextColor nos permite seleccionar el color del texto
  display.setCursor(1,1);            //setCursor permite posicionarnos dentro de la pantalla por pixel (x,y)
  display.print("Hola mundo");       //Escribimos un texto
  display.display();                 //Actualiza la pantalla con todos los gráficos anteriores
  delay(3000);
  display.clearDisplay();            //Limpiamos la pantalla
  display.display();                 //Actualiza la pantalla con todos los gráficos anteriores
}
 
void loop () 
{
  if(Serial.available())
  {
    int Dato=Serial.read();       //Leemos texto de puerto serial
    if(Dato=='|')
    {
      display.clearDisplay();     //Limpiamos la pantalla
      display.display();          //Actualiza la pantalla con todos los gráficos anteriores
    }
    else
    {
      display.setTextSize(2);     //setTextSize es un factor de escala que permite acercar o alejar el texto
      char Texto= char(Dato);     //Convertimos lo leido a char para que sea identificado por la OLED
      display.print(Texto);       //Escribimos un texto
      display.display();          //Actualiza la pantalla con todos los gráficos anteriores
    }   
  }
}
