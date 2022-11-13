#include <Servo.h> 

int enablePinA = 5;
int enablePinB = 6;
int dcMotorPinA1 = 22;
int dcMotorPinA2 = 23;
int dcMotorPinB1 = 24;
int dcMotorPinB2 = 25;
int dcSpeed = 100;

int servoPinC = 8;
int servoPinD = 9;
Servo servoC;
Servo servoD;
int angleC = 0; // servo position in degrees 
int angleD = 0;

void setup() { 
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);
  pinMode(dcMotorPinA1, OUTPUT);
  pinMode(dcMotorPinA2, OUTPUT);
  pinMode(dcMotorPinB1, OUTPUT);
  pinMode(dcMotorPinB2, OUTPUT);
  servoC.attach(servoPinC); 
  servoD.attach(servoPinD); 

  pinMode(13, OUTPUT);
} 


void loop() { 
  forward(); // 바로 돌면 방향이 틀어짐
  digitalWrite(13, HIGH);
  delay(1000);
  stop();
  delay(500);
  backward();
  digitalWrite(13, LOW);
  delay(1000);
  stop();
  delay(500);
  left();
  delay(1000);
  stop();
  delay(500);
  right();
  delay(1000);
  stop();
  delay(500);
  stop();
  delay(500);
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
