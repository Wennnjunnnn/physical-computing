#define relayPin 7
#define trigPin 9
#define echoPin 10
#define buttonPin 4

long duration;
int distance;

boolean flag = false;

int flag1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == LOW) {
    if (flag == false) {
      flag = true;
    }
  }

  if (flag == true) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    //  Serial.print("Distance: ");
    //  Serial.println(distance);

    if (distance < 100 && flag1 == 0) {

      flag1 = 1;
      Serial.println(flag1);
      //     delay(800);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(7, LOW);
      flag1 = 2;

    }

    if (distance > 150 && distance < 400) {
      digitalWrite(7, LOW);
      flag1 = 0;
      Serial.println(flag1);
    }
  }
//   Serial.println(digitalRead(buttonPin));
//   Serial.println(flag);

}
