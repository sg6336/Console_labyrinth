#include "MovementController.h"

#include "Utils.h"

bool MovementController::move(Dir dir)
{
  //-----DEBUG-----
  Serial.println("In move()");
  Serial.println("Direction: " + Utils::dirToStr(dir));
  //---------------

  return true;
}