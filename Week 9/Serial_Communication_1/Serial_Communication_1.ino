#define knob 0

int knobValue;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  knobValue = analogRead(knob);
  int value = map(knobValue,0,1023,0,180);
  Serial.write(value);
  delay(300);

  if(Serial.available()){
    int receive = Serial.read();
    Serial.println(receive,DEC);

    if(receive>0&&receive<10){
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
    }else if(receive>=10&&receive<20){
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
    } else if(receive>=20&&receive<30){
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    } else if(receive>=30&&receive<40){
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
  }
}
