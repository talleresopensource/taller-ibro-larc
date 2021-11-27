const int led = 7;
const int pulsador = 2;

int salida = 0;         //estado del led
int estadoanterior = 0; //estado anterior del pulsador
int estado = 0;         //estado del pulsador

void setup()
{
  pinMode(led,OUTPUT);     //defino pin de led como salida
  pinMode(pulsador,INPUT); //defino pin de pulsador como entrada
  digitalWrite(led, LOW); //arranco con estado LOW la salida LED
}

void loop()
{
  estado = digitalRead(pulsador); //leo estado actual del puls.
  if(estado == HIGH && estadoanterior == LOW)
  {
    salida = 1 - salida; //cambia 1<-->0
    delay(20); //DEBOUNCE
  }
  estadoanterior = estado;
  if(salida == 1)
  {
    digitalWrite(led, HIGH); 
  }
  else
  {
    digitalWrite(led,LOW);
  }
}