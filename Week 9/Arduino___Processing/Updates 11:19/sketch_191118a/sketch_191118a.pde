import processing.serial.*;
import processing.video.*;
import ddf.minim.*;

Movie movie;

Serial mySerial;

Minim minim;
AudioInput in;

AudioPlayer noise;

String myString = null;
int nl = 10;
float myVal;

float soundVal;

int mode1, mode2, mode;

void setup() {
  size(displayWidth, displayHeight);
  background(0);

  movie = new Movie(this, "ASMR Video.mp4");
  movie.loop();

  movie.loadPixels();

  String myPort = Serial.list()[1];
  mySerial = new Serial(this, myPort, 9600);

  minim = new Minim(this);
  in = minim.getLineIn(Minim.MONO);
  
  noise = minim.loadFile("1.mp3",2048);
  noise.pause();

  mode1 = 0;
  mode2 = 0;
  mode = 0;
}

void movieEvent(Movie m) {
  m.read();
}

void draw() {
  image(movie, 0, 0, width, height);

  if (myVal>0) {
    if (myVal<5) {
      mode1 = 4;
    } else if (myVal>5&&myVal<=10) {
      mode1 = 3;
    } else if (myVal>10&&myVal<=15) {
      mode1 = 2;
    } else if (myVal>15&&myVal<=20) {
      mode1 = 1;
    } else {
      mode1 = 0;
    }
  }

  soundVal = 0;

  for (int i = 0; i <in.bufferSize()-1; i++) {
    soundVal += ((abs(in.left.get(i))+abs(in.right.get(i))))/in.bufferSize();
  }

  soundVal = soundVal*100; 
  //println(soundVal);

  if (soundVal>10&&soundVal<=15) {
    mode2 = 1;
  } else if (soundVal>15&&soundVal<=20) {
    mode2 = 2;
  } else if (soundVal>20&&soundVal<=40) {
    mode2 = 3;
  } else if (soundVal>40) {
    mode2 = 4;
  } else
  {
    mode2 = 0;
  }

  if (mode1 == 1 || mode2 == 1) {
    mode = 1;
  } else if (mode1 == 2 || mode2 == 2) {
    mode = 2;
  } else if (mode1 == 3 || mode2 == 3) {
    mode = 3;
  } else if (mode1 == 4 || mode2 == 4) {
    mode = 4;
  } else {
    mode = 0;
  }
  
  if(mode == 0){
    noise.pause();
    movie.loop();
  }else if(mode>0){
    noise.loop();
    movie.pause();
    println(noise.getVolume());
  }
    
  if (mode == 1) {
    for (int i = 0; i<height; i+=random(0, 5)) {
      for (int j = 0; j<width; j+=random(0, 70)) {
        noStroke();
        color pix = get(j, i);
        fill(pix);
        float a = random(0, 30);
        float b = random(0, 5);
        rect(j, i, a, b);
      }
    }    
  //noise.setGain(0);
  }

  if (mode == 2) {
    for (int i = 0; i<height; i+=random(0, 5)) {
      for (int j = 0; j<width; j+=random(0, 70)) {
        noStroke();
        color pix = get(j, i);
        fill(pix);
        float a = random(0, 50);
        float b = random(0, 5);
        rect(j, i, a, b);
      }
    }
    //noise.setGain(20);
  }
  if (mode == 3) {
    for (int i = 0; i<height; i+=random(0, 15)) {
      for (int j = 0; j<width; j+=random(0, 50)) {
        noStroke();
        color pix = get(j, i);
        float c = random(0, 2);
        if (c>1.5) {
          fill(random(255), random(255), random(255));
        } else {
          fill(pix);
        }
        float a = random(0, 50);
        float b = random(5, 15);
        rect(j, i, a, b);
      }
    }
    //noise.setGain(60);
  }
  if (mode == 4) {
    for (int i = 0; i<height; i+=random(0, 15)) {
      for (int j = 0; j<width; j+=random(0, 50)) {
        noStroke();
        //color pix = get(j, i);
        //float c = random(0,2);

        fill(random(255), random(255), random(255));

        float a = random(0, 50);
        float b = random(5, 15);
        rect(j, i, a, b);
      }
    }
    //noise.setGain(100);
  }

  while (mySerial.available()>0) {
    myString = mySerial.readStringUntil(nl);
    if (myString != null) {
      myVal = float(myString);
      //println(myVal);
    }
  }
  
  if(myVal<20){
    mySerial.write('H');
    println(myVal);
  }else{
    mySerial.write('L');
  }
}
