#include "Pro.h"

int leds[] = {5, 6, 7};
int ledLength = sizeof(leds);

void setup() {
  // put your setup code here, to run once:
  pinMode(leds, OUTPUT);
}

int pinIndex = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int pinBeforeIndex = getBeforeIndex(pinIndex);
  digitalWrite(leds[pinBeforeIndex], LOW );
  digitalWrite(leds[pinIndex]      , HIGH);
  pinIndex = getIncedIndex(pinIndex);
  delay(1000);
}
int getBeforeIndex(int index){
  int before = index -1;
  if (before < 0)
    before += ledLength;
  return before;
}
int getIncedIndex(int index){
  int inced = index + 1;
  if (inced >= ledLength)
    inced -= ledLength;
  return inced;
}

