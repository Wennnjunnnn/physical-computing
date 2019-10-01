#define LED_PIN 3

#define PIN_TRIG 12
#define PIN_ECHO 11

float cm;
float temp;

float currentValue;
float targetValue;
float easingAmount;

void setup() {
  currentValue = 0;
  easingAmount = .225;
  
  Serial.begin(9600);

  pinMode(PIN_TRIG, OUTPUT);  
  pinMode(PIN_ECHO, INPUT);  
}

void loop() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  
  temp = float(pulseIn(PIN_ECHO, HIGH));
  cm = (temp * 17 )/1000;

  Serial.println(cm);

  if(cm>30){
    easingOff();
  }else{
    easingOn();
  }
  
  delay(300);
}

void easingOn() {
  targetValue = 255;
  currentValue += easingAmount * ( targetValue - currentValue );
  analogWrite(LED_PIN, (int) currentValue);
  delay(250);
  //  Serial.print("currentValue: ");
  //  Serial.print(currentValue);
  //  Serial.print("\t targetValue: ");
  //  Serial.println(targetValue);
}

void easingOff() {
  targetValue = 0;
  currentValue -= easingAmount * ( currentValue - targetValue );
  analogWrite(LED_PIN, (int) currentValue);
  delay(250);
  //  Serial.print("currentValue: ");
  //  Serial.print(currentValue);
  //  Serial.print("\t targetValue: ");
  //  Serial.println(targetValue);
}
