int col[]={2,3,4,5,6};            //Array de pines para las columnas de la matriz (5 columnas)
int fila[]={7,8,9,10,11,12,13};   //Array de pines para las filas de la matriz (7 filas)
void setup() 
{
  for(int i=0;i<=4;i++)
  {
    pinMode(col[i],OUTPUT);       //Declaracion de pines de Array de columnas como salidas
  }
  for(int i=0;i<=6;i++)
  {
    pinMode(fila[i],OUTPUT);      //Declaracion de pines de Array de filas como salidas
  }

  for(int i=0;i<=4;i++)
  {
    digitalWrite(col[i],LOW);     //Inicializacion de columnas apagadas (columnas encienden con 1 logico)
  }
  for(int i=0;i<=6;i++)
  {
    digitalWrite(fila[i],HIGH);   //Inicializacion de filas apagadas (filas encienden con 0 logico)
  }
}
void loop() 
{
  for(int i=0;i<=50;i++)      //ciclo for para llamar void uno
  {
    uno();
  }
  for(int i=0;i<=50;i++)      //ciclo for para llamar void dos
  {
    dos();
  }
  for(int i=0;i<=75;i++)      //ciclo for para llamar void siete
  {
    siete();
  }
  for(int i=0;i<=100;i++)      //ciclo for para llamar void V
  {
    V();
  }
  for(int i=0;i<=125;i++)      //ciclo for para llamar void o
  {
    o();
  }
  for(int i=0;i<=125;i++)      //ciclo for para llamar void l
  {
    l();
  }
  for(int i=0;i<=100;i++)      //ciclo for para llamar void t
  {
    t();
  }
  for(int i=0;i<=100;i++)      //ciclo for para llamar void z
  {
    z();
  }
}
void uno()
{
  digitalWrite(col[0],LOW);       //apagamos columna 0
  digitalWrite(col[1],HIGH);      //encendemos columna 1
  digitalWrite(fila[1],LOW);      //encendemos fila 1, se enciende led 1,1
  delay(1);                       //delay 1ms
  digitalWrite(fila[1],HIGH);     //apagamos fila 1

  digitalWrite(col[1],LOW);       //apagamos columna 1
  digitalWrite(col[0],HIGH);      //encendemos columna 0
  digitalWrite(fila[2],LOW);      //encendemos fila 2, se enciende led 0,2
  delay(1);                       //delay 1ms
  digitalWrite(fila[2],HIGH);     //apagamos fila 2
  for(int i=0;i<=4;i++)           //ciclo for para encender toda una fila por corrimiento de bits
  {
    digitalWrite(fila[6],LOW);    //encendemos fila 6
    digitalWrite(col[i],HIGH);    //encendemos columna del valor del ciclo for
    delay(1);                     //delay 1ms
    digitalWrite(col[i],LOW);     //apagamos columna recien activada
  }
  for(int i=0;i<=6;i++)           //ciclo for para encender toda una columna por corrimiento de bits
  {
    digitalWrite(col[2],HIGH);    //encendemos columna 2
    digitalWrite(fila[i],LOW);    //encendemos fila del valor del ciclo for
    delay(1);                     //delay 1ms
    digitalWrite(fila[i],HIGH);   //apagamos fila recien activada
  }
}
void dos()
{
  digitalWrite(col[0],HIGH);
  digitalWrite(fila[0],HIGH);
  digitalWrite(fila[1],LOW);
  delay(1);
  digitalWrite(fila[1],HIGH);

  digitalWrite(col[1],HIGH);
  digitalWrite(col[0],LOW);
  digitalWrite(col[2],LOW);
  digitalWrite(col[3],LOW);
  digitalWrite(col[4],LOW);
  digitalWrite(fila[5],LOW);
  delay(1);
  digitalWrite(fila[5],HIGH);

  digitalWrite(col[2],HIGH);
  digitalWrite(col[0],LOW);
  digitalWrite(col[1],LOW);
  digitalWrite(col[3],LOW);
  digitalWrite(col[4],LOW);
  digitalWrite(fila[4],LOW);
  delay(1);
  digitalWrite(fila[4],HIGH);

  digitalWrite(col[3],HIGH);
  digitalWrite(col[0],LOW);
  digitalWrite(col[1],LOW);
  digitalWrite(col[2],LOW);
  digitalWrite(col[4],LOW);
  digitalWrite(fila[3],LOW);
  delay(1);
  digitalWrite(fila[3],HIGH);
  for(int i=1;i<=3;i++)
  {
    digitalWrite(fila[0],LOW);
    digitalWrite(col[0],LOW);
    digitalWrite(col[i],HIGH);
    delay(1);
    digitalWrite(col[i],LOW);
  }
  for(int i=0;i<=4;i++)
  {
    digitalWrite(fila[0],HIGH);
    digitalWrite(fila[6],LOW);
    digitalWrite(col[i],HIGH);
    delay(1);
    digitalWrite(col[i],LOW);
  }
  for(int i=1;i<=2;i++)
  {
    digitalWrite(col[0],LOW);
    digitalWrite(col[1],LOW);
    digitalWrite(col[2],LOW);
    digitalWrite(col[3],LOW);
    digitalWrite(col[4],HIGH);
    digitalWrite(fila[i],LOW);
    delay(1);
    digitalWrite(fila[i],HIGH);
  }
}
void siete()
{
  digitalWrite(col[3],HIGH);
  digitalWrite(col[1],LOW);
  digitalWrite(fila[3],LOW);
  delay(1);
  digitalWrite(col[3],LOW);
  digitalWrite(fila[3],HIGH);
  
  digitalWrite(col[2],HIGH);
  digitalWrite(col[1],LOW);
  digitalWrite(fila[4],LOW);
  delay(1);
  digitalWrite(col[2],LOW);
  digitalWrite(fila[4],HIGH);
  for(int i=0;i<=4;i++)
  {
    digitalWrite(fila[0],LOW);
    digitalWrite(col[i],HIGH);
    delay(1);
    digitalWrite(col[i],LOW);
  }
  for(int i=1;i<=2;i++)
  {
    digitalWrite(col[4],HIGH);
    digitalWrite(fila[i],LOW);
    delay(1);
    digitalWrite(fila[i],HIGH);
  }
  for(int i=5;i<=6;i++)
  {
    digitalWrite(col[1],HIGH);
    digitalWrite(col[4],LOW);
    digitalWrite(fila[3],HIGH);
    digitalWrite(fila[4],HIGH);
    digitalWrite(fila[i],LOW);
    delay(1);
    digitalWrite(fila[i],HIGH);
  }
}
void V()
{
  digitalWrite(fila[5],HIGH);     //apagamos fila 5
  digitalWrite(fila[6],LOW);      //encendemos fila 6
  digitalWrite(col[0],LOW);       //apagamos columna 0
  digitalWrite(col[1],LOW);       //apagamos columna 1
  digitalWrite(col[3],LOW);       //apagamos columna 3
  digitalWrite(col[4],LOW);       //apagamos columna 4
  digitalWrite(col[2],HIGH);      //encendemos columna 2, se enciende led 2,6
  delay(1);                       //delay 1ms
  digitalWrite(col[2],LOW);       //apagamos columna 2
  
  digitalWrite(col[0],LOW);       //apagamos columna 0
  digitalWrite(col[1],LOW);       //apagamos columna 1
  digitalWrite(col[4],LOW);       //apagamos columna 4
  digitalWrite(fila[6],HIGH);     //apagamos fila 6
  digitalWrite(fila[5],LOW);      //encendemos fila 5
  digitalWrite(col[1],HIGH);      //encendemos columna 1, se enciende led 1,5
  digitalWrite(col[3],HIGH);      //encendemos columna 3, se enciende led 3,5
  delay(1);                       //delay 1ms
  digitalWrite(col[1],LOW);       //apagamos columna 1
  digitalWrite(col[3],LOW);       //apagamos columna 3
  
  for(int i=0;i<=4;i++)           //ciclo for para encender dos columnas por corrimiento de bits
  {
    digitalWrite(fila[5],HIGH);   //apagamos fila 5
    digitalWrite(col[0],HIGH);    //encendemos columna 0
    digitalWrite(col[4],HIGH);    //encendemos columna 4
    digitalWrite(fila[i],LOW);    //encendemos fila del valor del ciclo for
    delay(1);                     //delay 1ms
    digitalWrite(fila[i],HIGH);   //apagamos fila recien encendida
  }
}
void o()
{
  for(int i=1;i<=3;i++)           //ciclo for para encender dos filas por corrimiento de bits
  {
    digitalWrite(fila[2],LOW);    //encendemos fila 2
    digitalWrite(fila[6],LOW);    //encendemos fila 6
    digitalWrite(col[i],HIGH);    //encendemos columna del valor del ciclo for
    delay(1);                     //delay 1ms
    digitalWrite(col[i],LOW);     //apagamos columna recien activada
    digitalWrite(fila[2],HIGH);   //apagamos fila 2
    digitalWrite(fila[6],HIGH);   //apagamos fila 6
  }
  for(int i=3;i<=5;i++)           //ciclo for para encender dos columnas por corrimiento de bits
  {
    digitalWrite(col[0],HIGH);    //encendemos columna 0
    digitalWrite(col[4],HIGH);    //encendemos columna 4
    digitalWrite(fila[i],LOW);    //encendemos fila del valor del ciclo for
    delay(1);                     //delay 1ms
    digitalWrite(fila[i],HIGH);   //apagamos fila recien encendida
    digitalWrite(col[0],LOW);     //apagamos columna 0
    digitalWrite(col[4],LOW);     //apagamos columna 4
  }
}
void l()
{
  for(int i=0;i<=6;i++)
  {
    digitalWrite(col[2],HIGH);
    digitalWrite(fila[i],LOW);
    delay(1);
    digitalWrite(fila[i],HIGH);
  }
}
void t()
{
    digitalWrite(col[3],HIGH);
  digitalWrite(col[2],LOW);
  digitalWrite(fila[6],LOW);
  delay(1);
  digitalWrite(col[3],LOW);
  digitalWrite(fila[6],HIGH);
  for(int i=0;i<=5;i++)
  {
    digitalWrite(col[2],HIGH);
    digitalWrite(fila[i],LOW);
    delay(1);
    digitalWrite(fila[i],HIGH);
  }
  for(int i=1;i<=3;i++)
  {
    digitalWrite(fila[1],LOW);
    digitalWrite(col[i],HIGH);
    delay(1);
    digitalWrite(col[i],LOW);
    digitalWrite(fila[1],HIGH);
  }
}
void z()
{
  digitalWrite(col[3],HIGH);
  digitalWrite(fila[3],LOW);
  delay(1);
  digitalWrite(col[3],LOW);
  digitalWrite(fila[3],HIGH);
  
  digitalWrite(col[2],HIGH);
  digitalWrite(fila[4],LOW);
  delay(1);
  digitalWrite(col[2],LOW);
  digitalWrite(fila[4],HIGH);

  digitalWrite(col[1],HIGH);
  digitalWrite(fila[5],LOW);
  delay(1);
  digitalWrite(col[1],LOW);
  digitalWrite(fila[5],HIGH);
  for(int i=0;i<=4;i++)
  {
    digitalWrite(fila[2],LOW);
    digitalWrite(fila[6],LOW);
    digitalWrite(col[i],HIGH);
    delay(1);
    digitalWrite(col[i],LOW);
  }
}

