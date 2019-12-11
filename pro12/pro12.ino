#include <Pro.h>
#include <Counter.h>

int leds[] = {5, 6, 7};
int ledLength = sizeof(leds);
Counter counter(0, 3, 3, true); //= Counter::FromStepSize(0, 3, 1);
void setup() {
  pinMode(leds, OUTPUT);
  counter.dec();
  Serial.begin(9600);
}


void loop() {
  int before = counter.state;
  counter.inc();
  int current = counter.state;
  digitalWrite(leds[before] , LOW );
  digitalWrite(leds[current], HIGH);
  delay(1000);
  Serial.println(current);
}

