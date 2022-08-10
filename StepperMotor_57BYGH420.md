# Datasheet
**57BYGH420** <br>
![image](https://user-images.githubusercontent.com/65582244/183921388-462170b5-561d-4d30-a649-567f80878752.png)
![image](https://user-images.githubusercontent.com/65582244/183921094-4b8ae34f-95df-4fc3-9bca-9469ec604e90.png)
![image](https://user-images.githubusercontent.com/65582244/183921151-6d4354a8-290b-45e9-a31d-48215045ca20.png)

# code
https://github.com/Arduriz/StandByMe/blob/main/StepperMotor_withoutHeader.c <br>

**참고** <br>
https://m.blog.naver.com/roboholic84/220851897579 <br>
https://zifmfmphantom.tistory.com/143

# etc.
12V 2A의 전원을 L298n에 연결해야 잘 작동함, 5V는 부족 <br>

***
# ref.
## 6leads stepper motor 배선
![image](https://user-images.githubusercontent.com/65582244/183924109-a7f589ec-b4c3-4bcd-b7e8-5d62b3bcce29.png) <br>
https://buildbotics.com/wiring-stepper-motors/

## 스텝 모터 정격 전압
스텝모터의 정격전압은 일반 모터의 정격전압과 의미가 다르다. 스텝모터의 정격전압은 정격전류에서 코일 저항을 곱한 값이다. <br>
일반적으로 스텝모터 구동전압은 정격전압의 10~24배를 사용한다. 정격전압보다 높은 전압을 사용할 때는 전류제한 회로를 사용하여 전류가 정격전류를 넘지 않도록 해야 한다. <br>
스텝모터가 회전할때 코일에 걸리는 전압을 스위칭할 때 코일의 인덕턴스에 의해 흐르는 전류는 시상수만큼 지연된다. 전압을 높이면 시상수가 줄어들어 더 높은 속도로 회전할 수 있고 더 많은 토크와 출력을 낼수 있다. <br>
하지만, 전압을 높이면 각 스텝마다 딱딱하게 회전하고 진동할 수 있다. <br>
https://gammabeta.tistory.com/3372?category=177287

## NEMA
스텝모터에서 NEMA(National Electrical Manufacturers Association)를 말할 때는 보통 NEMA에서 표준화한 스텝모터 크기를 의미한다.<br>
NEMA에서 스텝 모터를 크기를 표준화하여 NEMA 표준인 스텝모터는 제조사가 달라도 서로 교체하여 설치할 수 있다. 하지만, NEMA에서 표준화한 것은 기계적인 크기이기 때문에 전기적으로는 제조사마다 서로 다를 수 있다.<br>
**57BYGH420은 NEMA23**<br>
https://gammabeta.tistory.com/3349?category=177287


