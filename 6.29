#include <Stepper.h>
#include <SoftwareSerial.h> // 블루투스

char command; // 블루투스
SoftwareSerial BTSerial(2, 3);

const int stepsPerRevolution = 200; // 모터
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  BTSerial.begin(9600); // 블루투스
  myStepper.setSpeed(60);
}

void loop() {
  if(BTSerial.available()>0){ // 블루투스   
    command = BTSerial.read(); 
    switch(command){
      case 'U':
        up();
        break;
      case 'D':
        down();
        break;
    }
  }
}

void up() { // 카드 스와이프
  myStepper.step(stepsPerRevolution); // clockwise
  delay(300);
  myStepper.step(0);
}

void down() { // 카드 되돌리기
  myStepper.step(-stepsPerRevolution); // counterclockwise
  delay(300);
  myStepper.step(0);
}
