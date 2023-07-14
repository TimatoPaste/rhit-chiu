#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 gyro(Wire);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  gyro.begin();
  gyro.calcGyroOffsets(true);

}

void loop() {
  gyro.update();
  Serial.print("x: ");
  Serial.print(gyro.getGyroAngleX());
  Serial.print(" y: ");
  Serial.print(gyro.getGyroAngleY());
  Serial.print(" z: ");
  Serial.println(gyro.getGyroAngleZ());
  

  // put your main code here, to run repeatedly:

}

//check how to calc/ calibrate
