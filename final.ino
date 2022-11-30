#include <Servo.h> 
#include <Stepper.h>

int enablePinA = 5;
int enablePinB = 6;
int dcMotorPinA1 = 22;
int dcMotorPinA2 = 25;
int dcMotorPinB1 = 26;
int dcMotorPinB2 = 29;
int dcSpeed = 100;

int servoPinC = 8;
int servoPinD = 9;
Servo servoC;
Servo servoD;
int angleC = 0; // servo position in degrees 
int angleD = 0;

const int SPR = 100; // =StepsPerRevolution, 360/angle, +:clockwise, -:counterClockwise
Stepper stepperMotor(SPR,41,38,37,34);  // IN4, IN3, IN2, IN1 

char command;

void setup() { 
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);
  pinMode(dcMotorPinA1, OUTPUT);
  pinMode(dcMotorPinA2, OUTPUT);
  pinMode(dcMotorPinB1, OUTPUT);
  pinMode(dcMotorPinB2, OUTPUT);
  servoC.attach(servoPinC); 
  servoD.attach(servoPinD); 
  stepperMotor.setSpeed(50); //0~255

  Serial.begin(9600);
  Serial.println("Hello");
} 


void loop() { 
  if(Serial.available()>0){
    command = Serial.read(); 
    switch(command){
      case 'w':
        forward();
        Serial.println(command);
        break;
      case 's':
        backward();
        Serial.println(command);
        break;
      case 'a':
        left();
        Serial.println(command);
        break;
      case 'd':
        right();
        Serial.println(command);
        break;
      case 'f':
        stop();
        Serial.println(command);
        break;
      case 'u':
        stepperMotor.step(-SPR);
        break;
      case 'j':
        stepperMotor.step(SPR);
        break;
    }
  }
}

void forward(){
  angleC = 25; // 직진
  servoC.write(angleC);
  angleD = 25; // 직진
  servoD.write(angleD);
  delay(100); //바로 돌면 방향이 틀어짐
  analogWrite(enablePinA, dcSpeed); 
  analogWrite(enablePinB, dcSpeed); 
  digitalWrite(dcMotorPinA1,LOW);
  digitalWrite(dcMotorPinA2,HIGH);
  digitalWrite(dcMotorPinB1,HIGH);
  digitalWrite(dcMotorPinB2,LOW);
}

void backward(){
  angleC = 25; // 직진
  servoC.write(angleC);
  angleD = 25; // 직진
  servoD.write(angleD);
  delay(100);
  analogWrite(enablePinA, dcSpeed); 
  analogWrite(enablePinB, dcSpeed); 
  digitalWrite(dcMotorPinA1,HIGH);
  digitalWrite(dcMotorPinA2,LOW);
  digitalWrite(dcMotorPinB1,LOW);
  digitalWrite(dcMotorPinB2,HIGH);
}

void left(){
  angleC = 90; // DC모터와 수직
  servoC.write(angleC);
  angleD = 90; // DC모터와 수직
  servoD.write(angleD);
  delay(100);
  analogWrite(enablePinA, dcSpeed); 
  analogWrite(enablePinB, dcSpeed); 
  digitalWrite(dcMotorPinA1,HIGH);
  digitalWrite(dcMotorPinA2,LOW);
  digitalWrite(dcMotorPinB1,HIGH);
  digitalWrite(dcMotorPinB2,LOW);
}

void right(){
  angleC = 90; // DC모터와 수직
  servoC.write(angleC);
  angleD = 90; // DC모터와 수직
  servoD.write(angleD);
  delay(100);
  analogWrite(enablePinA, dcSpeed); 
  analogWrite(enablePinB, dcSpeed); 
  digitalWrite(dcMotorPinA1,LOW);
  digitalWrite(dcMotorPinA2,HIGH);
  digitalWrite(dcMotorPinB1,LOW);
  digitalWrite(dcMotorPinB2,HIGH);
}

void stop(){
  servoC.write(angleC);
  servoD.write(angleD);
  analogWrite(enablePinA, 0); 
  analogWrite(enablePinB, 0); 
  digitalWrite(dcMotorPinA1,LOW);
  digitalWrite(dcMotorPinA2,LOW);
  digitalWrite(dcMotorPinB1,LOW);
  digitalWrite(dcMotorPinB2,LOW);
}

void up(){
  stepperMotor.step(-SPR);
}

void down(){
  stepperMotor.step(SPR);
}

void stopUpDown{
  stepperMotor.step(0);
}
//servoMotor
    /*
    angleC = 25; // 직진
    servoC.write(angleC);
    angleD = 25; // 직진
    servoC.write(angleD);
    delay(1000);
    angleC = 90; // DC모터와 수직
    servoC.write(angleC);
    angleD = 90; // DC모터와 수직
    servoD.write(angleD);
    delay(1000);
    angleC = 153; // 후진
    servoC.write(angleC);
    angleD = 153; // 후진
    servoD.write(angleD);
    delay(1000);
    */
