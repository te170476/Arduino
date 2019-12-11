#include <Pro.h>
#include <Pulser.h>
#include <Counter.h>

int led = 5;
int incSwitch = 10;
int decSwitch = 11;

void setup() {
  int inputs[] = { incSwitch, decSwitch };
  pinMode(led, OUTPUT);
  pinMode(inputs, INPUT);
  Serial.begin(9600);
}

Pulser incPulser(incSwitch);
Pulser decPulser(decSwitch);
Counter counter(0, 255, 10);
void loop() {
  PulseState incState = incPulser.pulse();
  PulseState decState = decPulser.pulse();
  if (incState == PulseState::Pulse){
    counter.inc();
    analogWrite(led, counter.state);
  }
  if (decState == PulseState::Pulse){
    counter.dec();
    analogWrite(led, counter.state);
  }
  Serial.println(counter.state);
}
