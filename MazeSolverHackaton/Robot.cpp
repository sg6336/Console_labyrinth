#include "Robot.h"

#include "Utils.h"

static int debugCounter = 0;

void Robot::moveAuto(int debugId)
{
  while(1)
  {
    //-----DEBUG-----
    Serial.println("DEBUG COUNTER: " + String(debugCounter));
    //---------------

    DesSt st; // тип 'вибору'. Може бути звичайний (СOMMON) або примусовий (FORCED)

    Des des = getDes(st, debugId); // отримати 'вибір' і його 'тип'

    bool isAllowed = checkDes(des, st, debugId); // робимо запит на прийняття вибору

    //-----DEBUG-----
    Serial.println("Decision: " + Utils::desToStr(des));
    Serial.println("isAllowed: " + String(isAllowed));
    //---------------

    if (isAllowed)
    {
      Dir dir = parseDes(des); // перетворюємо вибір у напрямок
      
      //-----DEBUG-----
      Serial.println("Direction: " + Utils::dirToStr(dir));
      //---------------

      if (askMove(dir)) // передаємо напрямок
      {
        saveDesInfo(des, isAllowed);
        break;
      }
    }

    saveDesInfo(des, isAllowed);
  }
}

bool Robot::checkDes(Des des, DesSt st, int debugId)
{
  int ss = sc.getState(debugId);

  //-----DEBUG-----
  Serial.println("Debug id: " + String(debugId));
  Serial.println("Sensor state: " + String(ss));
  //---------------

  if (des == Des::MOVE_FORWARD) 
  {
    if (ss == 0 || st == DesSt::FORCED) { return true; }
    if (ss == 2 || st == DesSt::FORCED) { return true; }
  }
  if (des == Des::MOVE_RIGHT) 
  {
    if (ss == 1 || st == DesSt::FORCED) { return true; }
  }
  if (des == Des::MOVE_LEFT) 
  {
    if (ss == 1 || st == DesSt::FORCED) { return true; }
    if (ss == 2 || st == DesSt::FORCED) { return true; }
  }

  return false;
}

Des Robot::getDes(DesSt& status, int debugId)
{
  //-----DEBUG-----
  Serial.println("getDes()::Debug id: " + String(debugId));
  //---------------

  Des des = dc.getDes(status, debugId);

  return des;
}

Dir Robot::parseDes(Des des)
{
  if (des == Des::MOVE_FORWARD) { return Dir::FORWARD; }
  if (des == Des::MOVE_BACKWARD) { return Dir::BACKWARD; }
  if (des == Des::MOVE_LEFT) { return Dir::LEFT; }
  if (des == Des::MOVE_RIGHT) { return Dir::RIGHT; }
}

bool Robot::askMove(Dir dir)
{
  if (mc.move(dir)) { return true; }

  return false;
}

void Robot::saveDesInfo(Des des, bool isValid)
{
  dc.saveInfo(des, isValid);

  //-----DEBUG-----
  Serial.println("In saveDecisionInfo()");
  Serial.println("Decision: " + Utils::desToStr(des));
  Serial.println("IsValid: " + String(isValid));
  //---------------
}