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
}

void iMove(int increment){
  if(iAngle + increment >= 0 && iAngle + increment <= 180){
    iAngle += increment;
  }
}

void mMove(int increment){
  if(mAngle + increment >= 0 && mAngle + increment <= 180){
    mAngle += increment;
  }
}

void rMove(int increment){
  if(rAngle + increment >= 0 && rAngle + increment <= 180){
    rAngle += increment;
  }
}

void pMove(int increment){
  if(pAngle + increment >= 0 && pAngle + increment <= 180){
    pAngle += increment;
  }
}

void moveAll(int increment){
  tMove(increment);
  iMove(increment);
  mMove(increment);
  rMove(increment);
  pMove(increment);
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
  mAngle = angle;
  rAngle = angle;
  pAngle = angle;
}

void writeOpen(){
  writeAll(up,up);
}

void writeClose(){
  writeAll(up,down);
}

void setOpen(){
  setAll(up,up);
}

void setClose(){
  setAll(up,down);
}

void update(){
  thumb.write(tAngle);
  index.write(iAngle);
  middle.write(mAngle);
  ring.write(rAngle);
  pinky.write(pAngle);
}

void loop() {
  
  if(digitalRead(2) == HIGH){//check condition of pin 2
    setClose();
  }
  else{
    setOpen();
  }
  update();
}
