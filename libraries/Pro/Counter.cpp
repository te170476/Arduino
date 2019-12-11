#include "Counter.h"

Counter Counter::FromStepSize(int start, int end, int stepSize){
  return FromStepSize(start, end, stepSize, false);
}
Counter Counter::FromStepSize(int start, int end, int stepSize, bool rotation){
  return Counter(start, end, (end - start) / stepSize, rotation);
}
Counter::Counter(int start, int end, int stepLength)
        : Counter(start, end, stepLength, false) {}
Counter::Counter(int start, int end, int stepLength, bool rotation){
  m_start = start;
  m_end   = end;
  m_stepLength = stepLength;
  m_step = 0;
  m_rotation = rotation;
}
void Counter::inc(){
  step(1);
}
void Counter::dec(){
  step(-1);
}
void Counter::step(int value){
  m_step += value;
  if (m_step >= m_end)
    if(m_rotation)
      m_step = 0;
    else
      m_step = m_end;
  else if (m_step < 0)
    if(m_rotation)
      m_step = m_end;
    else
      m_step = 0;
  setState();
}
double Counter::setState(){
  state = m_start + m_step * ((double)(m_end - m_start) / m_stepLength);
}

