#include "Robot.h"

Robot rb;

void setup() 
{
  Serial.begin(9600);

  rb.moveAuto(0);
  rb.moveAuto(1);
  rb.moveAuto(0);
}

void loop() 
{
}
