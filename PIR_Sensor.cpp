#include <Arduino.h>
//   https://youtube.com/shorts/LWYHoIOzEqI?si=ie6cA5l-_5Kp23FP
int pir_pin = 6;
int buzzer = 7;

void setup() {
  pinMode(pir_pin, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("PIR sensor is initializing...");
  delay(30000);   // PIR stabilize
  Serial.println("Sensor is ready to use.");
}

int pir() {
  return digitalRead(pir_pin);
}

void loop() {
  int mtn = pir();

  if (mtn == HIGH) {
    Serial.println("Motion is detected!");
    digitalWrite(buzzer, HIGH);
  }
  else {
    Serial.println("No Motion!");
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}
