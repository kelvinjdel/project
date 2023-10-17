#include <AFMotor.h>

AF_DCMotor motor(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Motor test start");
  motor.setSpeed(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("tick");

  motor.run(FORWARD);
  delay(1000);

  Serial.print("tock");
  motor.run(BACKWARD);
  delay(1000);

  Serial.print("tack");
  motor.run(RELEASE);
  delay(1000);
}
