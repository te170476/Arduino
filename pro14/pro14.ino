#include "Toggler.h"

int led = 5;
int sw = 11;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sw , INPUT);
}

Toggler toggler(sw);
void loop() {
  boolean swState = toggler.toggle();
  digitalWrite(led, swState);
}

