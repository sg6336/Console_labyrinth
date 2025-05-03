#pragma once

const int ENA = 7;
const int ENB = 8;
const int IN1 = 3;
const int IN2 = 4; 
const int IN3 = 5; 
const int IN4 = 6;

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
  void forward();
  void rotLeft();
  void rotRight();
  
  const int lm1 = IN1;
  const int lm2 = IN2;
  const int lmS = ENA;

  const int rm1 = IN3;
  const int rm2 = IN4;
  const int rmS = ENB;
};