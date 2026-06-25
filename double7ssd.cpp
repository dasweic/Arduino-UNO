#include <Arduino.h>

int seg10Pins[7] = {2,3,4,5,6,7,8};   //Left 7ssd 
/*
2 a
3 b
4 c
5 d
6 e
7 f
8 g
*/

int seg1Pins[7] = {9,10,11,A0,A1,A2,A3};  //Right 7ssd
/*
9 a
10 b
11 c
A0 d
A1 e
A2 f
A3 g
*/
byte digits[10][8] =
{
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0}  //9
};

void displayDigitL(int tens)
{
  for(int i=0; i<=7; i++)
  {
    digitalWrite(seg10Pins[i], digits[tens][i]);
  }
}

void displayDigitR(int ones)
{
  for(int i=0; i<=7; i++)
  {
    digitalWrite(seg1Pins[i], digits[ones][i]);
  }
}

void displayNumber(int num)     //code to display double digit number.
{
  int t = num / 10;
  int o = num % 10;
  displayDigitL(t);
  displayDigitR(o);
}

void setup()
{
  for(int i=0; i<8; i++)
  {
    pinMode(seg1Pins[i], OUTPUT);
  }
  for(int i=0; i<8; i++)
  {
    pinMode(seg10Pins[i], OUTPUT);
  }
  pinMode(A5, OUTPUT);  // Right ssd common cathode
  pinMode(A4, OUTPUT);  // Left ssd common cathode

}

void loop()
{
  //  for example :   
  displayNumber(72);
  
  
}
