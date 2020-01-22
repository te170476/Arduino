#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(int pin
              ,int standardVoltage
              ,int resolution
              ,int minVoltage
              ,int maxVoltage
              ,int minValue
              ,int maxValue
  ) {
  m_pin = pin;
  m_standardVoltage = standardVoltage;
  m_resolution = resolution;
  m_minVoltage = minVoltage;
  m_maxVoltage = maxVoltage;
  m_minValue = minValue;
  m_maxValue = maxValue;
  
  // TODO: Step換算だと誤差が広がる.
  m_voltageStep = (m_maxVoltage - m_minVoltage) / (m_maxValue - m_minValue);
  m_voltageWhenZero = m_minVoltage + (m_voltageStep * (0 - m_minValue));
}

int Sensor::read(){
  int voltageState = analogRead(m_pin);
  double inputVoltage = (double)voltageState / m_resolution * m_standardVoltage;

  int inputValue = (inputVoltage - m_voltageWhenZero) / m_voltageStep;
  return inputValue;
}

