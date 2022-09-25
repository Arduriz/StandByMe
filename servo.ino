#include <Servo.h> 
 
int servoPin1 = 8;
int servoPin2 = 9;

Servo servo1; 
Servo servo2;

int angle1 = 0; // servo position in degrees 
int angle2 = 0;

void setup() 
{ 
    servo1.attach(servoPin1); 
    servo2.attach(servoPin2); 
} 


void loop() 
{ 
    angle1 = 25; // 직진
    servo1.write(angle1);
    angle2 = 25; // 직진
    servo2.write(angle2);
    delay(1000);
    angle1 = 90; // DC모터와 수직
    servo1.write(angle1);
    angle2 = 90; // DC모터와 수직
    servo2.write(angle2);
    delay(1000);
    angle1 = 153; // 후진
    servo1.write(angle1);
    angle2 = 153; // 후진
    servo2.write(angle2);
    delay(1000);
}
