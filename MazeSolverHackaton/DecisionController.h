#pragma once

enum class Des
{
  MOVE_LEFT,
  MOVE_RIGHT,
  MOVE_FORWARD,
  MOVE_BACKWARD,

  UNKNOWN
};

enum class DesSt
{
  COMMON,
  FORCED
};

class DecisionController
{
public:
  Des getDes(DesSt& st);
  void saveInfo(Des des, bool isValid);

private:
  Des desById(int desId);
  Des invDesById(int desId);

  int m_desId = 0;
  int m_pdesId = 0;

  int m_badDesAmount = 0;

  bool m_isPrevDesAllowed = true;
  bool m_isLastDesForced = false;
};