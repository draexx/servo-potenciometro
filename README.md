# Control de Servomotor con Potenciómetro

## Simulación
[Ver proyecto en Tinkercad](https://www.tinkercad.com/things/6Uzkt2CCmyD-servo-analogpin)

## Descripción
Proyecto Arduino que permite controlar la posición de un servomotor utilizando un potenciómetro conectado a una entrada analógica.

## Componentes
- Arduino UNO
- Servomotor
- Potenciómetro
- Cables de conexión

## Conexiones
- Servomotor → Pin 3
- Potenciómetro → Pin A0
- Alimentación 5V y GND

## Código Explicado
```cpp
#include <Servo.h>      // Librería para control del servomotor
Servo servo;            // Objeto servo

int pinOut = 3;         // Pin de control del servo
int angulo;            // Variable para el ángulo del servo

void setup() {
  Serial.begin(9600);   // Iniciar comunicación serial
  servo.attach(pinOut); // Asignar pin al servo
  servo.write(0);       // Posición inicial: 0 grados
  Serial.println("Prueba de Servo");
}

void loop() {
  // Lectura del potenciómetro
  int potencia = analogRead(A0);
  
  // Conversión del valor (0-1023) a ángulo (0-180)
  angulo = map(potencia, 0, 1023, 0, 180);
  
  // Mover servo a la posición
  servo.write(angulo);
  
  // Mostrar información en monitor serial
  Serial.print("Potenciometro: ");
  Serial.print(potencia);
  Serial.print(" Angulo: ");
  Serial.println(angulo);
  
  delay(20);  // Pequeña pausa para estabilidad
}
```

## Características
- Control analógico de posición
- Rango de movimiento: 0-180 grados
- Monitoreo en tiempo real
- Anti-rebote implementado

## Funcionamiento
1. El potenciómetro proporciona una señal analógica (0-1023)
2. Se convierte la señal a ángulos (0-180)
3. El servo se mueve a la posición correspondiente
4. Los valores se muestran en el monitor serial

## Personalización
- Modificar pin del servo (`pinOut`)
- Ajustar rango de movimiento en función `map()`
- Cambiar velocidad de actualización (`delay`)

## Licencia
Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

## Autor
[Pedro Carranza](https://github.com/draexx)
