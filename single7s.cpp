#include <Arduino.h>

int segPins[7] = {2,3,4,5,6,7,8};

byte digits[10][7] =
{
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

void displayDigit(int num)
{
  for (int i=0; i<7; i++)
  {
    digitalWrite(segPins[i], digits[num][i]);

  }
  
}

void setup()
{
    for(int i = 0; i < 7; i++)
    {
        pinMode(segPins[i], OUTPUT);
    }
}

void loop()
{
  for (int i=9; i>0; i--){
    displayDigit(i);
    delay(1000);
    
  
  }
}
