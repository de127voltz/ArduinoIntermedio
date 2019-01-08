int LEDR1=2;          // Variable entera para luz Roja de la via 1 asociada al pin 2
int LEDA1=3;          // Variable entera para luz Amarilla de la via 1 asociada al pin 3
int LEDV1=4;          // Variable entera para luz Verde de la via 1 asociada al pin 4
int LEDR2=5;          // Variable entera para luz Roja de la via 2 asociada al pin 5
int LEDA2=6;          // Variable entera para luz Amarilla de la via 2 asociada al pin 6
int LEDV2=7;          // Variable entera para luz Verde de la via 2 asociada al pin 7
void setup() 
{
  pinMode(LEDR1,OUTPUT);      // Pin para LEDR1 como salida
  pinMode(LEDA1,OUTPUT);      // Pin para LEDA1 como salida
  pinMode(LEDV1,OUTPUT);      // Pin para LEDV1 como salida
  pinMode(LEDR2,OUTPUT);      // Pin para LEDR2 como salida
  pinMode(LEDA2,OUTPUT);      // Pin para LEDA2 como salida
  pinMode(LEDV2,OUTPUT);      // Pin para LEDV2 como salida
}
void loop() 
{
  digitalWrite(LEDV1,HIGH);     // Encendemos la luz verde de la via 1
  digitalWrite(LEDR2,HIGH);     // Encendemos la luz roja de la via 2
  delay(4000);                  // Retardo 4 segundos
  digitalWrite(LEDV1,LOW);      // Apagamos la luz verde de la via 1 (sigue encendida la luz roja de la via 2)
  digitalWrite(LEDA1,HIGH);     // Encendemos la luz amarilla de la via 1 (parpadeo)
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA1,LOW);      // Apagamos la luz amarilla de la via 1
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA1,HIGH);     // Encendemos la luz amarilla de la via 1
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA1,LOW);      // Apagamos la luz amarilla de la via 1
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA1,HIGH);     // Encendemos la luz amarilla de la via 1
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA1,LOW);      // Apagamos la luz amarilla de la via 1
  digitalWrite(LEDR2,LOW);      // Apagamos la luz roja de la via 2
  
  digitalWrite(LEDR1,HIGH);     // Encendemos la luz roja de la via 1 (cambio de rutina para la otra via)
  digitalWrite(LEDV2,HIGH);     // Encendemos la luz verde de la via 2
  delay(4000);                  // Retardo 4 segundos
  digitalWrite(LEDV2,LOW);      // Apagamos la luz verde de la via 2 (sigue encendido luz roja 1)
  digitalWrite(LEDA2,HIGH);     // Encendemos la luz amarilla de la via 2 (parpadeo)
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA2,LOW);      // Apagamos la luz amarilla de la via 2
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA2,HIGH);     // Encendemos la luz amarilla de la via 2
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA2,LOW);      // Apagamos la luz amarilla de la via 2
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA2,HIGH);     // Encendemos la luz amarilla de la via 2
  delay(200);                   // Retardo 200ms
  digitalWrite(LEDA2,LOW);      // Apagamos la luz amarilla de la via 2
  digitalWrite(LEDR1,LOW);      // Apagamos la luz roja de la via 1
}
