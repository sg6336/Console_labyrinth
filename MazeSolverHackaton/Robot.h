#pragma once

#include "MovementController.h"
#include "SensorController.h"
#include "DecisionController.h"

class Robot
{
public:
  void moveAuto();

private:
  Des getDes(DesSt& status);
  bool checkDes(Des des, DesSt st);
  Dir parseDes(Des des);
  bool askMove(Dir dir);
  void saveDesInfo(Des des, bool isValid);

  MovementController mc;
  SensorController sc;
  DecisionController dc;
};