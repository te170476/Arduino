#ifndef Pulser_h
#define Pulser_h

enum struct PulseState {
  Pulse,
  AlreadyPulsed,
  OFF
};

class Pulser{
  public:
    Pulser(int pin);
    Pulser(int pin, int turnOffDelay);
    PulseState pulse();
    
  private:
    int m_pin;
    int m_turnOffDelay; //Chattering prevention
    PulseState state;
    PulseState tryPulse(int inputPin, PulseState beforeState);
};

#endif
