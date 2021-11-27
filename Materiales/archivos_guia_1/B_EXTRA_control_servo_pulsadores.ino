#include <Servo.h> //llama a la libreria para manejar el servo

Servo mi_servo;  // crea el objeto mi_servo

//Salidas
const int led_rojo = 7;
const int led_azul = 8;

//Entradas
const int pulsador1 = 2;
const int pulsador2 = 3;

//Variables auxiliares
int estado_p1 = 0; //estado del pulsador1
int estado_p2 = 0; //estado del pulsador2
int angulo = 90;   //valor de posicion del servo


void setup() {
  pinMode(led_rojo,OUTPUT); //define el pin del led rojo como salida
  pinMode(led_azul,OUTPUT); //define el pin del led azul como salida
  pinMode(pulsador1,INPUT); //define el pin del pulsador1 como entrada
  pinMode(pulsador2,INPUT); //define el pin del pulsador2 como entrada
  
  digitalWrite(led_rojo,LOW); //comienza con el led rojo apagado
  digitalWrite(led_azul,LOW); //comienza con el led azul apagado
   
  mi_servo.attach(12);  // vincula el servo al pin digital 12
  mi_servo.write(angulo); //posicion el servo inicialmente en la mitad(90º)
}
void loop() {
  estado_p1 = digitalRead(pulsador1); //lee el estado del pulsador1
  estado_p2 = digitalRead(pulsador2); //lee el estado del pulsador2
  
  //Aumenta el angulo y enciende el led azul mientras se mantiene presionado el pulsador1 hasta que llega a 180º
  if(estado_p1 == 1)
  {
    angulo = angulo + 1; //incrementa el valor del angulo que va a tomar el servo
    digitalWrite(led_rojo,LOW); //apago el rojo si habia sido encendido al llegar a alguno de los extremos del servo
    digitalWrite(led_azul,HIGH); //enciende el led azul
    if(angulo >= 180)
    {
      angulo =180;  //el angulo no aumenta mas alla de 180 grados
      digitalWrite(led_rojo,HIGH); //cuando llega a 180 grados se enciende el led rojo
      digitalWrite(led_azul,LOW); //apaga el led azul

    }
  }
  else if (estado_p1 == 0 && estado_p2 == 0) //verifico si los dos pulsadores estan sin presionar 
  {
    digitalWrite(led_azul,LOW);//cuando suelto el pulsador apago el led azul
  }
  
  
  //Disminuye el angulo y enciende el led azul mientras se mantiene presionado el pulsador2 hasta que llega a 0º
  if(estado_p2 == 1)
  {
    angulo = angulo - 1; //disminuye el valor del angulo que va a tomar el servo
    digitalWrite(led_rojo,LOW); //apago el rojo si habia sido encendido al llegar a alguno de los extremos del servo
    digitalWrite(led_azul,HIGH); //enciende el led azul
    if(angulo <= 0)
    {
      angulo =0;  //el angulo no disminuye mas alla de 0 grados
      digitalWrite(led_rojo,HIGH); //cuando llega a 0 grados se enciende el led rojo
      digitalWrite(led_azul,LOW); //apaga el led azul
    }
  }
   else if (estado_p2 == 0 && estado_p1 == 0) //verifico si los dos pulsadores estan sin presionar
  {
    digitalWrite(led_azul,LOW);//cuando suelto el pulsador apago el led azul
  }
  mi_servo.write(angulo); //              
  delay(10);                       
 
   
}
