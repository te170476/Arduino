#include "Arduino.h"
#include "Pro.h"

void pinMode(int pins[], uint8_t value){
  for (int index = 0; index < sizeof(pins); index++) {
    pinMode(pins[index], value);
  }
}
void digitalWrite(int pins[], uint8_t value){
  for (int index = 0; index < sizeof(pins); index++) {
    digitalWrite(pins[index], value);
  }
}
