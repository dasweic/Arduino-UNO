#include<Arduino.h>
const int irPin = 8;

void setup(){
  pinMode(8, INPUT);

  Serial.begin(9600);

}

void irsense(){
  int value = digitalRead(irPin);
  if (value == 1){
    Serial.println("Colour Is Reflecting");
  }
  else
  {
    Serial.println("Colour Is Not Reflecting");
  }
  
  delay(500);
}

void loop(){
  irsense();
}
