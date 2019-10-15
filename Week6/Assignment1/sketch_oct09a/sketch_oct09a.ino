#define P1A 2 
#define P2A 7 
#define EN12 8 
#define ButtonPin 4

boolean ButtonState;

void setup() {
  Serial.begin(9600);
  pinMode(P1A, OUTPUT);
  pinMode(P2A, OUTPUT);
  pinMode(EN12, OUTPUT);
  pinMode(ButtonPin, INPUT_PULLUP); 
}

void loop() {
    ButtonState = digitalRead(ButtonPin);
    if(ButtonState == HIGH){
    Serial.println("CW");
    digitalWrite(EN12 ,HIGH);
    digitalWrite(P1A,HIGH);
    digitalWrite(P2A,LOW);   
    }else{
    Serial.println("CCW");  
    digitalWrite(EN12 ,HIGH);     
    digitalWrite(P1A,LOW);
    digitalWrite(P2A,HIGH);
    }
  delay(100);
}
