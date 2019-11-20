#include "Toggler.h"
#include "Pulser.h"

Toggler::Toggler(int pin)
        : m_pulser(Pulser(pin)) {}
Toggler::Toggler(Pulser pulser)
        : m_pulser(pulser) {}

bool Toggler::toggle(){
  m_state = tryToggle(m_state);
  return m_state;
}
bool Toggler::tryToggle(bool beforeState){
  PulseState pulseState = m_pulser.pulse();
  if(pulseState != PulseState::Pulse) return beforeState;
  return !beforeState;
}

