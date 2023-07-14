#include <Servo.h>

//make sure that com port is set to the motherboard (tools>port)
Servo thumb;
Servo index;
Servo middle;
Servo ring;
Servo pinky;

int up = 180;
int down = 0;
int tUp = down;
int tDown = up;

int tAngle = tUp;
int iAngle = up;
int mAngle = up;
int rAngle = up;
int pAngle = up;

bool setAngle = false;

void setup() {

  Serial.begin(9600);
  // pinMode(pin,mode);
  //digitalRead(pin) returns the state of the pin (HIGH or LOW)
  thumb.attach(3);//sets pin for servo
  index.attach(5);
  middle.attach(6);
  ring.attach(9);
  pinky.attach(10);
 
}

void tMove(int increment){
  if(tAngle + increment >= 0 && tAngle + increment <= 180){
    tAngle += increment;
  }
  setAngle = true;
}

void iMove(int increment){
  if(iAngle + increment >= 0 && iAngle + increment <= 180){
    iAngle += increment;
  }
  setAngle = true;
}

void mMove(int increment){
  if(mAngle + increment >= 0 && mAngle + increment <= 180){
    mAngle += increment;
  }
  setAngle = true;
}

void rMove(int increment){
  if(rAngle + increment >= 0 && rAngle + increment <= 180){
    rAngle += increment;
  }
  setAngle = true;
}

void pMove(int increment){
  if(pAngle + increment >= 0 && pAngle + increment <= 180){
    pAngle += increment;
  }
  setAngle = true;
}

void moveAll(int increment){
  tMove(increment);
  iMove(increment);
  mMove(increment);
  rMove(increment);
  pMove(increment);
  setAngle = true;
}

void writeAll(int maxAngle, int angle){//thumb val is complemented
  thumb.write(maxAngle-angle);
  index.write(angle);
  middle.write(angle);
  ring.write(angle);
  pinky.write(angle);
}

void setAll(int maxAngle, int angle){//thumb val is complemented
  tAngle = maxAngle - angle;
  iAngle = angle;
  rAngle = angle;
  pAngle = angle;
  setAngle = true;
}

void writeOpen(){
  writeAll(up,up);
}

void writeClose(){
  writeAll(up,down);
}

void setOpen(){
  setAll(up,up);
  setAngle = true;
}

void setClose(){
  setAll(up,down);
  setAngle = true;
}

void update(){
  thumb.write(tAngle);
  index.write(iAngle);
  middle.write(mAngle);
  ring.write(rAngle);
  pinky.write(pAngle);
}

//for fun
void fingerThing(int iters, int del){
  for(int i = 0;i < iters; i++){
    if(i%2 == 0){
      thumb.write(tUp);
      delay(del);
      index.write(up);
      delay(del);
      middle.write(up);
      delay(del);
      ring.write(up);
      delay(del);
      pinky.write(up);
      delay(del);
    }else{
      thumb.write(tDown);
      delay(del);
      index.write(down);
      delay(del);
      middle.write(down);
      delay(del);
      ring.write(down);
      delay(del);
      pinky.write(down);
      delay(del);
    }
  }
}
void scissor(){
  index.write(up);
  middle.write(up);
  thumb.write(tDown);
  ring.write(down);
  pinky.write(down);
}
void rps(){
  long choice = floor(random(0,3));
  writeAll(up,down);
  index.write(up);
  delay(1000);
  middle.write(up);
  delay(1000);
  ring.write(up);
  delay(1000);
  if(choice == 0){
    writeClose();
  }
  else if(choice == 1){
    writeOpen();
  }
  else if (choice==2){
    scissor();
  }
  delay(1000);
}

void loop() {
  rps();
  if(setAngle){
    update();
    setAngle = false;
  }
  delay(500);
}
