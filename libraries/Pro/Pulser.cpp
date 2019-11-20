#include "Arduino.h"
#include "Pulser.h"

Pulser::Pulser(int pin){
  m_pin = pin;
  m_turnOffDelay = 10;
}
Pulser::Pulser(int pin, int turnOffDelay){
  m_pin = pin;
  m_turnOffDelay = turnOffDelay;
}

PulseState Pulser::tryPulse(int inputPin, PulseState beforeState){
  int digitalInput = digitalRead(inputPin);
  if(digitalInput == LOW) {
    delay(m_turnOffDelay);
    return PulseState::OFF;
  }
  if(beforeState != PulseState::OFF) return PulseState::AlreadyPulsed;
  return PulseState::Pulse;
}
PulseState Pulser::pulse(){
  state = tryPulse(m_pin, state);
  return state;
}
