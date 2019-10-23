import processing.serial.*;
import ddf.minim.*;

Serial mySerial;

Minim minim;

AudioPlayer sound;

boolean flagRewind = false;

String myString = null;
int nl = 10;
float myVal;


void setup() {
  size(10, 10);
  background(0);

  String myPort = Serial.list()[1];
  mySerial = new Serial(this, myPort, 9600);

  minim = new Minim(this); 
  sound = minim.loadFile("1.wav",2048);
}


void draw() {
  if(myVal == 1){
    sound.play();
    flagRewind = false;
  } else if(myVal == 0 && flagRewind == false){
    sound.rewind();
    flagRewind = true;
  } 

  while (mySerial.available()>0) {
    myString = mySerial.readStringUntil(nl);
    if (myString != null) {
      myVal = float(myString);
      println(myVal);
    }
  }
}
