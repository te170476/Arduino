
int led = 6;
int temperatureSensor = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int targetTemprature = 28;
  int tempratureSensorState = analogRead(temperatureSensor);
  int m_minVoltage = 300;
  int m_maxVoltage = 1600;
  int m_minTemprature = -30;
  int m_maxTemprature = 100;
  int m_voltageStep = (m_maxVoltage - m_minVoltage) / (m_maxTemprature - m_minTemprature);
  int m_voltageWhenZeroTemprature = m_minVoltage + (m_voltageStep * (0 - m_minTemprature));

  int standardVoltage = 5000;
  int m_resolution = 1023;
  double inputVoltageStep = (double)standardVoltage / m_resolution;
  double inputVoltage = tempratureSensorState * inputVoltageStep;
  int inputTemprature = (inputVoltage - m_voltageWhenZeroTemprature)/ m_voltageStep;
  Serial.print(tempratureSensorState);
  Serial.print("  ");
  Serial.println(inputTemprature);
  delay(500);
  if(inputTemprature > targetTemprature)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
    
}
