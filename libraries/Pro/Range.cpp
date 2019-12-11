#include "Range.h"

Range::Range(int start, int end){
  m_start = start;
  m_end   = end;
  length  = end - start;
}

void Range::inc(){
  return step(1);
}
void Range::dec(){
  return step(-1);
}
void Range::step(int value){
  state += value;
  if (state > m_end)
    state = m_end;
  else if (state < 0)
    state = 0;
}

