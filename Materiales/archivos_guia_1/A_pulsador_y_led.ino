//Salidas
const int led = x;

//Entradas
const int pulsador = x;

//Variables auxiliares
int estado = 0; //estado del pulsador

void setup()
{
  pinMode(led,OUTPUT);     //defino pin de led como salida
  pinMode(pulsador,INPUT); //defino pin de pulsador como entrada
  digitalWrite(led, LOW);  //arranco con estado LOW la salida LED
}

void loop()
{
  estado = digitalRead(pulsador); //leo estado del puls.
  if(estado == 1)   //pregunto por el estado del pulsador
  {
    digitalWrite(led, HIGH); //si esta pulsado, prendo el LED
  }
  else
  {
    digitalWrite(led,LOW); //caso contrario, mantengo apagado LED
  }
}