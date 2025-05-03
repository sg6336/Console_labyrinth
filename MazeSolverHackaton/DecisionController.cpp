#include "DecisionController.h"

Des DecisionController::getDes(DesSt& st)
{
  st = DesSt::COMMON;

  if (m_isPrevDesAllowed) 
  { 
    return desById(m_desId); 
  }

  const int desAmount = 4;

  if (m_badDesAmount == desAmount) 
  { 
    st = DesSt::FORCED;

    return invDesById(m_pdesId);
  }

  m_desId = (m_desId + 1) % desAmount; // change id to next decision

  return desById(m_desId);
}

void DecisionController::saveInfo(Des des, bool isAllowed)
{
  if (isAllowed) 
  { 
    m_badDesAmount = 0; 
    m_pdesId = m_desId;
  }
  else 
  { 
    ++m_badDesAmount; 
  }

  m_isPrevDesAllowed = isAllowed;
}

Des DecisionController::desById(int desId)
{
  if (desId == 0) { return Des::MOVE_LEFT; }
  if (desId == 1) { return Des::MOVE_RIGHT; }
  if (desId == 2) { return Des::MOVE_FORWARD; }
  if (desId == 3) { return Des::MOVE_BACKWARD; }

  return Des::UNKNOWN;
}

Des DecisionController::invDesById(int desId)
{
  if (desId == 0) { return Des::MOVE_RIGHT; }
  if (desId == 1) { return Des::MOVE_LEFT; }
  if (desId == 2) { return Des::MOVE_BACKWARD; }
  if (desId == 3) { return Des::MOVE_FORWARD; }

  return Des::UNKNOWN;
}