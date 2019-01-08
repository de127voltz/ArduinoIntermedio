float a;          // Variable flotante "a" para obtener numero a obtener tabla de multiplicar 
int b;            // variable tipo entera "b" para multiplicar dato "a"
void setup() 
{
  Serial.begin(9600);        /* Inicio de la funcion de comunicacion serial y realizacion de la velocidad de transmision entre el Arduino
                              * y la Computadora, la velocidad de Baudios debe ser la misma en ambos sistemas para que las instrucciones 
                              * puedan ser enviadas y recibidas.
                              */
}
void loop() 
{
  a=Serial.parseFloat();      // Asignación de lectura del puerto serial como flotante (solo reconoce datos flotantes, no caractéres)
  if(a!=0)                    // Sí a es diferente a 0... (como todo número multiplicado por 0 da 0 omitimos esa operacion)
  {
    for(b=1; b<11; b++)       // Para b siendo igual 1, b siendo menor a 11, entonces aumento gradual de +1 en b
    {
      Serial.print(a);        // Escritura en puerto serial de valor de a
      Serial.print(" x ");    // Escritura en puerto serial de texto " x "
      Serial.print(b);        // Escritura en puerto serial de valor de b
      Serial.print(" = ");    // Escritura en puerto serial de texto " 0 "
      Serial.println(a*b);    // Escritura en puerto serial de resultado de multiplicación de a x b con salto de linea
    }
    Serial.println();         // Escritura en puerto serial de un salto de linea para nuevas operaciones
  }
}
