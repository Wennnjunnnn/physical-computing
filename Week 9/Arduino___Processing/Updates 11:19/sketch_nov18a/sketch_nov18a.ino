#define PIN_TRIG 12
#define PIN_ECHO 11

#define LED_PIN 7
  
float cm;
float temp;

char LEDstate;
  
void setup() {  
  Serial.begin(9600);  
  pinMode(PIN_TRIG, OUTPUT);  
  pinMode(PIN_ECHO, INPUT);  
  pinMode(LED_PIN, OUTPUT);
}  
  
void loop() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
    
  temp = float(pulseIn(PIN_ECHO, HIGH));
  cm = (temp * 17 )/1000;

//  Serial.print("Echo = ");  
//  Serial.print(temp);
//  Serial.print(",  Distance = ");  
//  Serial.print(cm);
//  Serial.println("cm");  
//  delay(300);

  Serial.println(cm);  
  delay(100); 

  checkUART();
}

void checkUART(){
  while(Serial.available()>0){

    LEDstate = Serial.read();
    if(LEDstate == 'H'){
      digitalWrite(LED_PIN, HIGH);
    }
    if(LEDstate == 'L'){
      digitalWrite(LED_PIN,LOW);
    }
    delay(50);
  }
}
