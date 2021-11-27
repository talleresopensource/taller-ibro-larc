const int entrada = A0;
int frec_muestreo = 100; //Frec de muestreo en Hz

void setup() {
    analogReference(DEFAULT); //Referencia del conversor AD
    pinMode(entrada, INPUT);
    Serial.begin(9600);
}

void loop() {
  int signal = analogRead(entrada);
  Serial.print("Señal:");
  Serial.print(signal);
  Serial.print(",");
  Serial.println("Max:1023,Min:0");
   
  int ts = (1000/frec_muestreo);
  delay(ts);
}
