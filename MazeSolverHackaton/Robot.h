#pragma once

#include "MovementController.h"
#include "SensorController.h"
#include "DecisionController.h"

class Robot
{
public:
  void moveAuto(int debutId);

private:
  Des getDes(DesSt& status, int debugId);
  bool checkDes(Des des, DesSt st, int debugId);
  Dir parseDes(Des des);
  bool askMove(Dir dir);
  void saveDesInfo(Des des, bool isValid);

  MovementController mc;
  SensorController sc;
  DecisionController dc;
};