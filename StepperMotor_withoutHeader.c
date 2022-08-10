int IN1 = 3;
int IN2 = 4;
int IN3 = 6;
int IN4 = 7;
//int ENA = 9;   //EnableA를 아두이노와 연결했을 때, 변수 정의 때문에 활성화가 좋음
//int ENB = 10;  //EnableB를 아두이노와 연결했을 때, 변수 정의 때문에 활성화가 좋음

int speedDelay = 10; //모터 속도를 위한 딜레이로 낮을 수록 빠름

void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  //pinMode(ENA,OUTPUT);    
  //pinMode(ENB,OUTPUT);
  //digitalWrite(ENA,HIGH);   //EnableA를 점퍼 핀 연결한 환경과 동일하게
  //digitalWrite(ENB,HIGH);   //EnableB를 점퍼 핀 연결한 환경과 동일하게
  //analogWrite(ENA, 50);     //0~255 값으로 속도를 조절하고자 할 때
  //analogWrite(ENB, 50);     //0~255 값으로 속도를 조절하고자 할 때
}
void loop(){  
  //counter clockwise
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(speedDelay);
    
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(speedDelay);
      
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(speedDelay);
      
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(speedDelay); 
  
  //clockwise
  /*
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(speedDelay);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(speedDelay);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(speedDelay);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(speedDelay);
  */
}
