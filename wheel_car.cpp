// ==========================
// 2 IR Sensor Line Follower
// Arduino UNO + L298N
// ==========================
#include <Arduino.h>
// IR Sensors
const int LEFT_SENSOR  = 2;
const int RIGHT_SENSOR = 3;

// L298N Motor Driver
const int ENA = 5;
const int IN1 = 8;
const int IN2 = 9;

const int ENB = 6;
const int IN3 = 10;
const int IN4 = 11;

// Motor Speed (0-255)
const int SPEED = 170;

void setup()
{
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);

  Serial.begin(9600);
}

// =====================
// Motor Functions
// =====================

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft()
{
  // Left motor stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight()
{
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor stop
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// =====================
// Main Loop
// =====================

void loop()
{
  bool left  = digitalRead(LEFT_SENSOR);
  bool right = digitalRead(RIGHT_SENSOR);

  Serial.print("L=");
  Serial.print(left);
  Serial.print("  R=");
  Serial.println(right);

  // Black = LOW
  // White = HIGH

  if (left == LOW && right == LOW)
  {
    forward();
  }
  else if (left == LOW && right == HIGH)
  {
    turnLeft();
  }
  else if (left == HIGH && right == LOW)
  {
    turnRight();
  }
  else
  {
    stopMotors();
  }

  delay(5);
}
