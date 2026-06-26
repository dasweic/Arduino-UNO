#include <Arduino.h>


const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

float uss() {       // main function= return distance output.    THIS SENSOR CAN ONLY FIND THE DISTANCE OF OBJECT.
  // Trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.0343 / 2;
  return distance;
}


void loop(){
  /*  example
  float d = uss();
  if (d>30){
    Serial.println("Distance is greater than 30");

  }
  else if (d<30)
  {
  Serial.println("Distance is less than 30");
  }
  delay(1000)
  */
}
