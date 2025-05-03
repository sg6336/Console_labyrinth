#pragma once

enum class Dir
{
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

class MovementController
{
public:
  bool move(Dir dir);

private:
  
};