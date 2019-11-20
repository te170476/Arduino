#include <Pro.h>

int leds[] = {5, 6, 7};
int ledLength = sizeof(leds);

void setup() {
  // put your setup code here, to run once;
  pinMode(leds, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly;
  digitalWrite(leds, HIGH);
  delay(2000);
  digitalWrite(leds, LOW);
  delay(2000);
}

