# Pan, Tilt, Hat Linux code

\#라즈베리파이 설정창에 들어가 i2c허용
sudo raspi-config
interfacing options에서 i2c 옵션 허용

\#i2c허용 후 리부트시켜 설정 적용
sudo reboot

\#해당링크에서 bcm2835 다운로드
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz
tar zxvf bcm2835
cd bcm2835

sudo ./configure && sudo make && sudo make check && sudo make install
\#wiring pi 다운로드
sudo apt-get install wiringpi
wget https://project-downloads.drogon.net/wiringpi-latest.deb
sudo dpkg -i wiringpi-latest.deb
gpio -v

\# run gpio -v version 2.52 will appear, if not, installtion error happens
sudo apt-get install p7zip-full
wget http://www.waveshare.net/w/upload/9/96/Pan-Tilt_HAT_code.7z
7z x Pan-Tilt_HAT_code.7z -r -o./Pan-Tilt_HAT_code
sudo chmod 777 -R Pan-Tilt_HAT_code

\#폴더 PanTilt 속 Pi로 접근하여 test파일 실행
cd PanTilt/Pi/
sudo python3 main.py

\#1-Light sensor 예제 실행
cd Light_Sensor/
sudo python3 mainLS.py

\#2-Servo Driver 예제 실행
cd Servo_Driver
cd bcm2835
sudo python3 mainSD.py

\#3-Module Execute 예제 실행
cd moduleexecute
sudo ./main

\#전 폴더 접근
cd ../

\#python 코드
cd python
sudo python main.py

\# camera 접근 권한 설정
sudo raspi-config
bcm2835-v4l2

sudo reboot
ls /dev/video*
sudo apt-get update
sudo apt-get install libjpeg8-dev cmake
cd PanTilt/Pi/web_Python
git clone https://github.com/ksonliam/mjpg-streamer
cd mjpg-streamer/mjpg-streamer-experimental/
sudo make clean all
sudo ./start.sh
sudo apt-get install python-bottle
cd PanTilt/Pi/web_Python/
sudo python main.py
sudo apt-get update

\#python3 버전 설치
sudo apt-get install python3-pip

\#Jetson 설치
sudo pip3 install Jetson.GPIO
sudo groupadd -f -r gpio
sudo usermod -a -G gpio your_user_name
sudo cp /opt/nvidia/jetson-gpio/etc/99-gpio.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger

\#smbus i2c 설치
sudo apt-get install python-smbus
sudo apt-get install python3-pil
sudo apt-get install python3-numpy
sudo apt-get install p7zip
wget http://www.waveshare.net/w/upload/9/96/Pan-Tilt_HAT_code.7z
7zr x Pan-Tilt_HAT_code.7z -r -o./Pan-Tilt_HAT_code
sudo chmod 777 -R Pan-Tilt_HAT_code
cd PanTilt/HAT_Code/Pan-Tilt-HAT/
sudo git clone https://github.com/waveshare/Pan-Tilt-HAT
cd PanTilt/JetsonNano/
sudo git clone https://github.com/waveshare/Pan-Tilt-HAT
cd PanTilt/JetsonNano/
cd 1_Light_Sensor/

\#pan servo 작동
cd 2_Servo_Driver/
sudo python main.py
cd python3
sudo python3 main.py
DISPLAY=:0.0 gst-launch-1.0 nvarguscamerasrc ! 'video/x-raw(memory:NVMM), width=1920, height=1080, format=(string)NV12, framerate=(fraction)30/1' ! nvoverlaysink –e

\#pan tilt main.py 코드 실행
cd 3_Pan-Tilt/
sudo python main.py

