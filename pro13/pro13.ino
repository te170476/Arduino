#include "Pro.h"

int leds[] = {5, 6};
int switchs[] = {10, 11};
int switchLength = 2;

void setup() {
  pinMode(leds, OUTPUT);
  pinMode(switchs, INPUT);
}

void loop() {
  for(int index = 0; index < switchLength; index++){
    int switchState = digitalRead(switchs[index]);
    digitalWrite(leds[index], switchState);
  }
}
