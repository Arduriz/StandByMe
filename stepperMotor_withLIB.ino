#include <Stepper.h>

const int SPR = 200; // =StepsPerRevolution, 360/angle, +:clockwise, -:counterClockwise

Stepper stepperMotor(SPR,4,5,6,7);  // IN4, IN3, IN2, IN1         
void setup() {
  stepperMotor.setSpeed(50); //0~255
}

void loop() {
  stepperMotor.step(SPR);
}
