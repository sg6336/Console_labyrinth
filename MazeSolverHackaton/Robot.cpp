#include "Robot.h"

void Robot::moveAuto()
{
  while(1)
  {
    DesSt st; // тип 'вибору'. Може бути звичайний (СOMMON) або примусовий (FORCED)

    Des des = getDes(st); // отримати 'вибір' і його 'тип'

    bool isAllowed = checkDes(des, st); // робимо запит на прийняття вибору

    if (isAllowed)
    {
      Dir dir = parseDes(des); // перетворюємо вибір у напрямок

      if (askMove(dir)) // передаємо напрямок
      {
        saveDesInfo(des, isAllowed);
        break;
      }
    }

    saveDesInfo(des, isAllowed);
  }
}

bool Robot::checkDes(Des des, DesSt st)
{
  int ss = sc.getState();

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

Des Robot::getDes(DesSt& status)
{
  Des des = dc.getDes(status);

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
}