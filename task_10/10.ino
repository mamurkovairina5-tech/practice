#include <Servo.h>

Servo servo;
const int servoPin = 3;
int currentAngle = 0;

void setup() {
  servo.attach(servoPin);
  servo.write(currentAngle);
  Serial.begin(9600);
  Serial.println("Введите угол от 0 до 180 градусов:");
}

void loop() {
  if (Serial.available() > 0) {
    
    int targetAngle = Serial.parseInt();

    while (Serial.available() > 0) {
      Serial.read(); 
    }

    Serial.print("Получено значение: ");
    Serial.println(targetAngle);

    if (targetAngle >= 0 && targetAngle <= 180) {
      if (targetAngle != currentAngle) {

        if (targetAngle > currentAngle) {
          for (int pos = currentAngle; pos <= targetAngle; pos++) {
            servo.write(pos);
            delay(15);
          }
        } else {
          for (int pos = currentAngle; pos >= targetAngle; pos--) {
            servo.write(pos);
            delay(15);
          }
        }

        currentAngle = targetAngle;
        
      } else {
        Serial.print("Сервопривод уже находится в положении ");
        Serial.print(targetAngle);
        Serial.println("°.");
      }
      
    } else {
      Serial.println("Ошибка: Некорректное значение");
    }
    
    Serial.println("Ожидание следующей команды");
  }
}