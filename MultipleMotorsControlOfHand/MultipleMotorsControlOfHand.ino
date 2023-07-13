#include <Servo.h>
  Servo thumb_Servo; //Control motors for thumb, the name rule will be used for code after
  Servo indexfinger_Servo;
  Servo middlefinger_Servo;
  Servo ringfinger_Servo;
  Servo littlefinger_Servo;
  int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  thumb_Servo.attach(3);//ID for thumb to little finger in orders is 1 to 5. Set up the attach port (control cable), the port named in numbers
  indexfinger_Servo.attach(5);
  middlefinger_Servo.attach(6);
  ringfinger_Servo.attach(9);
  littlefinger_Servo.attach(10);

  //pinMode(3, INPUT); //Set port 3 as the input


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(3)+"\n");
  //if (digitalRead(3) == HIGH) {// if port 3 read of voltage is high
    for (pos = 0; pos <=180; pos+=1){ // for (0,180,1)
      thumb_Servo.write(pos);
      indexfinger_Servo.write(pos);
      middlefinger_Servo.write(pos);
      ringfinger_Servo.write(pos);
      littlefinger_Servo.write(pos);
      delay(15); // 15 interval, unit is ms
    
    }
    for (pos = 180; pos>=0; pos -=1){ // for (180,0,-1)
      thumb_Servo.write(pos);
      indexfinger_Servo.write(pos);
      middlefinger_Servo.write(pos);
      ringfinger_Servo.write(pos);
      littlefinger_Servo.write(pos);
      delay(15);// unit is ms
    }
  //}

}
