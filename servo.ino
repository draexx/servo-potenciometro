#include <Servo.h> // se incluye la libreria para manejo del servo
Servo servo; //se  crea el servo para poder usarlo
// C++ code
int pinOut = 3; //pin de salida del servo
int angulo;  //variable para almacenar el angulo del servo
void setup()
{
  Serial.begin(9600); //se inicia la comunicación serial
  servo.attach(pinOut); //se asigna el pin de salida al servo
  servo.write(0); //se coloca el servo en 0 grados
  Serial.println("Prueba de Servo"); //se imprime en el monitor serial
}

void loop()
{
  int potencia = analogRead(A0); //se lee el valor del potenciómetro
  angulo = map(potencia, 0, 1023, 0, 180); //se mapea el valor del potenciómetro a un angulo de 0 a 180
  servo.write(angulo); //se mueve el servo al angulo calculado
  Serial.print("Potenciometro: "); //se imprime en el monitor serial
  Serial.print(potencia); // se imprime en el monitor serial
  Serial.print(" Angulo: "); //se imprime en el monitor serial
  Serial.println(angulo); //se imprime en el monitor serial
  delay(20); //se espera 20 milisegundos
}
