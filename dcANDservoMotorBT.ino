#include <Servo.h> 
#include <SoftwareSerial.h>

SoftwareSerial BSerial(50, 51); //TX to 2, RX to 3 메가는 PWM에 하면 안됨

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

  pinMode(13, OUTPUT);

  Serial.begin(9600);
  Serial.println("Hello");

  BSerial.begin(9600);
} 


void loop() { 
  if(BSerial.available()>0){
    command = BSerial.read(); 
    switch(command){
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        stop();
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
