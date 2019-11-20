#ifndef Toggler_h
#define Toggler_h
#include "Pulser.h"

class Toggler{
  public:
    Toggler(int pin);
    Toggler(Pulser pulser);
    bool toggle();
    
  private:
    Pulser m_pulser;
    bool m_state;
    bool tryToggle(bool beforeState);
};

#endif

