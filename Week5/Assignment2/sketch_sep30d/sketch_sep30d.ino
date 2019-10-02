/*
   This sketch was Modified by the second easing code example
   created by Phillip David Stearns
   for Phsical Computing Week 5 class.
   https://github.com/phillipdavidstearns/PGTE_5585_F2019/blob/master/notes/week5/arduino/easing/easing.ino
*/

#define LED_PIN 5
#define SENSOR_PIN A0

float progress;
int value;

void setup() {
  Serial.begin(9600);

  progress = 0.0;
  value = 0;
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensor = analogRead(SENSOR_PIN);

//  int current_time = millis();

  if (sensor > 500) {
    value = int(255 * (0.5 * sin(progress) + 0.5));
    progress+=0.2;
  }
  analogWrite(LED_PIN, value);

  Serial.println(progress);
  Serial.println(value);

  delay(100);

}
