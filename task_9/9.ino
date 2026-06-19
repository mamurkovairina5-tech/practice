const int redLed = 9;
const int greenLed = 5;
const int ldrPin = A0;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(ldrPin, INPUT);
  
  Serial.begin(9600);

  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  Serial.println("Система запущена. Дверь закрыта.");
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  if (ldrValue > 512) {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    Serial.print("Дверь открыта. Датчик: ");
    Serial.println(ldrValue);
    
    delay(3000);
    
    int checkValue = analogRead(ldrPin);
    
    while (checkValue > 512) {
      Serial.print("Дверь остается открытой. Датчик: ");
      Serial.println(checkValue);
      delay(1000);
      checkValue = analogRead(ldrPin);
    }
    
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    Serial.println("Дверь закрыта.");
  }
  
  delay(100);
}