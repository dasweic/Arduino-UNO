#include <Arduino.h>

// Right Motor
const int ENA = 5;      //RIGHT MOTOR
const int IN1 = 6;
const int IN2 = 7;

const int irPin1 = A0;       
const int irPin2 = A1;

// Left Motor
const int ENB = 9;      //LEFT MOTOR
const int IN3 = 10;
const int IN4 = 11;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
int irsense_1()
{
    return digitalRead(irPin1);
}

int irsense_2()
{
    return digitalRead(irPin2);
}

void RB() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);
}

void LB() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);
}

void RF(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150);
}

void LF(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 150);
}
void brake(){
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

void loop() {
    if (irsense_1() == HIGH && irsense_2()==LOW)
    {
        Serial.println("Colour is White");
        LF();
        analogWrite(ENA, 0);
    
    }    
    else if (irsense_2()==HIGH && irsense_1==LOW){
        RF();
        analogWrite(ENB, 0);
    }
    else if (irsense_1()==HIGH && irsense_2()==HIGH)
    {
        LF();
        RF();
    }
    delay(100);
    
}
