#include <Servo.h>
Servo myservo;//init servo instance

//make sure that com port is set to the motherboard (tools>port)
void setup() {
  Serial.begin(9600);
  // pinMode(pin,mode);
  //digitalRead(pin) returns the state of the pin (HIGH or LOW)
  myservo.attach(3);//sets pin for servo
  myservo.write(0);//sets angle of servo motor
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(1));
  if(digitalRead(1)==HIGH){
    for(int angle = 0;angle<=180;angle++){
      myservo.write(angle);
      delay(15);//ms
    }
  }


}
