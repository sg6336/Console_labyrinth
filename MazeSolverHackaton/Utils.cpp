#include "Utils.h"

namespace Utils
{
  String desToStr(Des des)
  {
    if (des == Des::MOVE_FORWARD) { return "MOVE_FORWARD"; }
    if (des == Des::MOVE_BACKWARD) { return "MOVE_BACKWARD"; }
    if (des == Des::MOVE_LEFT) { return "MOVE_LEFT"; }
    if (des == Des::MOVE_RIGHT) { return "MOVE_RIGHT"; }
  }

  String dirToStr(Dir dir)
  {
    if (dir == Dir::FORWARD) { return "FORWARD"; }
    if (dir == Dir::BACKWARD) { return "BACKWARD"; }
    if (dir == Dir::LEFT) { return "LEFT"; }
    if (dir == Dir::RIGHT) { return "RIGHT"; }
  }
}