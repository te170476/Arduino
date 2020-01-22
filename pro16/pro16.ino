#include <Sensor.h>

int led = 6;
int sensorPin = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

Sensor thermoSensor(sensorPin, 5000, 1023, 300, 1600, -30, 100);
void loop() {
  int targetTemprature = 28;
  int tempratureSensorState = analogRead(sensorPin);
  int inputTemprature = thermoSensor.read();
  Serial.print(tempratureSensorState);
  Serial.print("  ");
  Serial.println(inputTemprature);
  delay(500);
  if(inputTemprature > targetTemprature)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}
