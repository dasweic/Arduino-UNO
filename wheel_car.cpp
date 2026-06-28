// WORKING

#include <Arduino.h>

// Right Motor
const int ENA = 5;      //RIGHT MOTOR
const int IN1 = 6;
const int IN2 = 7;

const int irPin1 = A0;       //LEFT SENSOR
const int irPin2 = A1;       //RIGHT SENSOR

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

void RightWheel(int x) {
    if (x<0)
    {
        /* BACKWARD */
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, 255);
    }
    else if (x>0)
    {
        /* FORWARD */
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 255);
    }
    else if (x==0)
    {
        // BRAKE
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 0);
    }
}

void LeftWheel(int x) {
    if (x<0)
    {
        /* BACKWARD */
        digitalWrite(IN4, LOW);
        digitalWrite(IN3, HIGH);
        analogWrite(ENB, 255);
    }
    else if (x>0)
    {
        /* FORWARD */
        digitalWrite(IN4, HIGH);
        digitalWrite(IN3, LOW);
        analogWrite(ENB, 255);
    }
    else if (x==0)
    {
        // BRAKE
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, 0);
    }
}

void brake(){
    RightWheel(0);
    LeftWheel(0);
}

void loop()
{
    int left  = irsense_1();
    int right = irsense_2();

    // Black = LOW, White = HIGH

    if (left == HIGH && right == HIGH)
    {
        // Dono white -> line beech me hai
        LeftWheel(1);
        RightWheel(1);
    }
    else if (left == LOW && right == HIGH)
    {
        // Left sensor black
        LeftWheel(0);
        RightWheel(1);
    }
    else if (left == HIGH && right == LOW)
    {
        // Right sensor black
        LeftWheel(1);
        RightWheel(0);
    }
    else
    {
        // Dono black
        brake();
    }
}
