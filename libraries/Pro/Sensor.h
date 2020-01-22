#ifndef Sensor_h
#define Sensor_h
#include "Sensor.h"

class Sensor{
  public:
    Sensor(int pin
          ,int standardVoltage
          ,int resolution
          ,int minVoltage
          ,int maxVoltage
          ,int minValue
          ,int maxValue
          );
    int read();
    
  private:
    int m_pin;
    int m_standardVoltage;
    int m_resolution;
    int m_minVoltage;
    int m_maxVoltage;
    int m_minValue;
    int m_maxValue;
    
    int m_voltageStep;
    int m_voltageWhenZero;
};

#endif

