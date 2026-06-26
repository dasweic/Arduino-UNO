#include <Arduino.h>
#include <Servo.h>


Servo myServo;
//  brown = GND     red = +5V     yellow/orange = Signal(output)

int motor = 7;
void setup() {
  myServo.attach(motor);   // Servo signal pin D9
}

void motor_angle(int x){
  myServo.write(x);

}

void loop() {
  motor_angle(55);
}
