#include <Arduino.h>

// Left Display
int seg10Pins[7] = {2, 3, 4, 5, 6, 7, 8};

// Right Display
int seg1Pins[7] = {9, 10, 11, A0, A1, A2, A3};

// Common Cathode Pins
int left_ssd_cc = A4;
int right_ssd_cc = A5;

// Digits (a,b,c,d,e,f,g)
byte digits[10][7] =
{
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};

void displayDigitL(int digit)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(seg10Pins[i], digits[digit][i]);
  }
}

void displayDigitR(int digit)
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(seg1Pins[i], digits[digit][i]);
  }
}

void displayNumber(int num)
{
  int tens = num / 10;
  int ones = num % 10;

  displayDigitL(tens);
  displayDigitR(ones);
}

void setup()
{
  // Left display pins
  for (int i = 0; i < 7; i++)
  {
    pinMode(seg10Pins[i], OUTPUT);
  }

  // Right display pins
  for (int i = 0; i < 7; i++)
  {
    pinMode(seg1Pins[i], OUTPUT);
  }

  pinMode(left_ssd_cc, OUTPUT);
  pinMode(right_ssd_cc, OUTPUT);

  // Enable Common Cathode displays
  digitalWrite(left_ssd_cc, LOW);
  digitalWrite(right_ssd_cc, LOW);
}

void loop()
{
  displayNumber(72);
  delay(1000);
  for(int i = 0; i <= 99; i++)
  {
    displayNumber(i);
    delay(5);
  }
  
}
