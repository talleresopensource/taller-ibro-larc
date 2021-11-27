const int entrada = A0;
int frec_muestreo = x; //Frec de muestreo en Hz
int led = 7;

void setup() {
    analogReference(DEFAULT); //Referencia del conversor AD
    pinMode(entrada, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  int signal = analogRead(entrada);
  Serial.print("Señal:");
  Serial.print(signal);
  Serial.print(",");
  Serial.println("Max:1023,Min:0");
  if(signal>=670)
  {
    digitalWrite(led,HIGH);
    delay(10);
    digitalWrite(led,LOW);
  }
   
  int ts = (1000/frec_muestreo);
  delay(ts);
}
