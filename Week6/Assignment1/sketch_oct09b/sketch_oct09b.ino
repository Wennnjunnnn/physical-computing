#define P1A 3
#define P2A 7
#define EN12 8
#define KnobPin 4

boolean ButtonState;
float Speed;

void setup() {
  Serial.begin(9600);
  pinMode(P1A, OUTPUT);
  pinMode(P2A, OUTPUT);
  pinMode(EN12, OUTPUT);
  pinMode(KnobPin, INPUT);
}

void loop() {
  float Speed = analogRead(KnobPin);
  Speed = map(Speed, 0, 1024, 0, 255);

  Serial.println("CW");
  digitalWrite(EN12, HIGH);
  analogWrite(P1A , Speed);
  digitalWrite(P2A, LOW);

  Serial.println(Speed);
  delay(1000);
}
