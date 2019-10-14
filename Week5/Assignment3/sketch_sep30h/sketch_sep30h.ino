/*
   This sketch was modified by the first and the second easing code examples
   created by Phillip David Stearns
   for Phsical Computing Week 5 class.
   https://github.com/phillipdavidstearns/PGTE_5585_F2019/blob/master/notes/week5/arduino/easing/easing.ino
*/
#define LED_PIN 5
#define BUTTON_PIN 4

unsigned int trigger_time;
float progress, ease_time;
int value1, value2;
int value;

void setup() {
  Serial.begin(9600);

  trigger_time = 0;
  ease_time = 2500.0;
  progress = 0.0;
  value = 0;
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int current_time = millis();

  if (buttonIsPressed() || progress > (PI * 3 / 2)) {
    trigger_time = current_time;
    progress = 0;
  }

  progress = (current_time - trigger_time) / ease_time;

  value1 = int(255 * (pow(progress, 2)));
  value2 = int(255 * (0.5 * sin(progress) + 0.5));

  //  Serial.println(value1);
  //  Serial.println(value2);

  if (progress <= 0.96) {
    value = value1;
  }

  if (progress > 0.96) {
    value = value2;
  }

  analogWrite(LED_PIN, value);

  Serial.println(progress);
  Serial.println(value);


}

bool buttonIsPressed() {
  boolean button_state = digitalRead(BUTTON_PIN);
  boolean button;

  if (button_state == LOW) {
    button = true;
  }
  if (button == HIGH) {
    button = false;
  }

  return button;

}
