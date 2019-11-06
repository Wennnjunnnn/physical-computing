#include <Servo.h>

#include <Ultrasonic.h>

int sensor;
int angle;
Ultrasonic ultrasonic(9, 10);
Servo myservo;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  myservo.attach(8);
}

void loop() {
  sensor = ultrasonic.distanceRead();
  if (sensor<100){
    //Serial.println(sensor);

   Serial.write(sensor);
    }
//   angle = Serial.read();
//   Serial.println(angle, DEC);
//   myservo.write(angle);
  delay(300);
}
