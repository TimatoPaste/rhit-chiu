#include <Servo.h>
Servo myservo;

//pinMode(pin,mode) sets mode of specified pin; output, input, 

//digital read reads from digital pin while analog read reads from analog pin
//digital = HIGH or LOW only (on/off, can use PWM alternating currents to pretend there's a lower voltage)
//analog = range of numbers

//tools>Serial Plotter or Serial Monitor to check info that is printed or reported back from the board

//ask: why do we need resistors to ground some components? I don't really get that. What are the inner workings?
//does enabling pull-up resistor mode do this for us? does this imply that it is in input mode?
//make sure to ground everything by connecting them to ground. Either gives extra voltage back to circuit or dissipates to prevent damage or unsafe discharge or noise
//why does the circuit try to be infinite or burn components out if there is not enough resistance? Is it because the components have a max current that they can handle?
//how strong is the built-in pull-up resistor?
//what is the difference between a pull-up resistor and other types of resistors?
current = voltage/resistance

//noise happens when an incomplete circuit "bleeds" charge into the atmosphere and can cause random activation of other uncompleted circuits
//floating (not connected) wires can get current this way, making pins read "arbitrary" values (sometimes high, sometimes low, etc)

int EMGvalue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myservo.attach(3);
  myservo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  EMGvalue = analogRead(A1);//reads val from analog pin
  //Serial.println(EMGvalue);
  if(EMGvalue > 500){
    for(int angle = 0;angle<181;angle++){
      myservo.write(angle);
    }
  }
  else{
    myservo.write(0);
  }
  delay(50);//ms

}
