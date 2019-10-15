#define P1A 3
#define P2A 7
#define EN12 8
#define KnobPin 4

#define switch1Pin 12
#define switch2Pin 13

#define LEDPin 2

float knobValue;

int counter;

unsigned long delay_time = 50;
unsigned long last_time = 0;
boolean led_state = false;

unsigned long start_time = 0;
unsigned long duration = 5000;
boolean flag = false;

void setup() {
  Serial.begin(9600);
  pinMode(P1A, OUTPUT);
  pinMode(P2A, OUTPUT);
  pinMode(EN12, OUTPUT);
  pinMode(KnobPin, INPUT);
  pinMode(switch1Pin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);

  counter = 0;

  pinMode(LEDPin, OUTPUT);

}

void loop() {
  float knobValue = analogRead(KnobPin);

  if (knobValue < 500) {
    digitalWrite(EN12, HIGH);
    digitalWrite(P1A , HIGH);
    digitalWrite(P2A, LOW);
  }
  if (knobValue >= 500 && knobValue <= 550) {
    digitalWrite(EN12 , LOW);
    Serial.println(" Motor Stopped");
  }
  if (knobValue > 550) {
    digitalWrite(EN12 , HIGH);
    digitalWrite(P1A, LOW);
    digitalWrite(P2A, HIGH);
  }

  boolean switch1State = digitalRead(switch1Pin);
  boolean switch2State = digitalRead(switch2Pin);

  if (switch1State == LOW && switch2State == HIGH) {
    counter--;
  }

  if (switch1State == HIGH && switch2State == LOW) {
    counter++;
  }
  
  long current_time = millis();
  
  if (counter >= 5) {
    if(flag == false){
    start_time = current_time;
    flag = true;
    }
    if (current_time - last_time > delay_time) {
      digitalWrite(LEDPin, !led_state);
      led_state = !led_state;
      last_time = current_time;
    }
    if(current_time - start_time > duration){
      counter = 0;
      flag = false;
    }
  }else if(counter<5){
    digitalWrite(LEDPin, LOW);
  }

  Serial.println(knobValue);
  Serial.println(counter);

  delay(1000);
}
