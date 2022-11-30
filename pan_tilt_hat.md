# 리눅스 코드

> 1.  sudo raspi-config 
> 2.  Select Interfacing Options -> I2C ->yes Enable i2C Kernel Module

> 1.	sudo reboot

> 1. wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz
2. tar zxvf bcm2835-1.68.tar.gz 
3. cd bcm2835-1.68/
4. sudo ./configure && sudo make && sudo make check && sudo make install
5. # For more information, please refer to：http://www.airspayce.com/mikem/bcm2835/

1. sudo apt-get install wiringpi
2. # For Raspberry Pi system after may 2019, an upgrade is required.
3. wget https://project-downloads.drogon.net/wiringpi-latest.deb
4. sudo dpkg -i wiringpi-latest.deb
5. gpio -v
6. # run gpio -v version 2.52 will appear, if not, installtion error happens

1. sudo apt-get install p7zip-full
2. wget http://www.waveshare.net/w/upload/9/96/Pan-Tilt_HAT_code.7z
3. 7z x Pan-Tilt_HAT_code.7z -r -o./Pan-Tilt_HAT_code
4. sudo chmod 777 -R  Pan-Tilt_HAT_code
5. cd Pan-Tilt_HAT_code/RaspberryPi/

1. cd test
2. make clean
3. make
4. sudo ./main

1. #Execute the following actions under the directory Pan-Tilt-HAT/RaspberryPi/:
2. #Execute this if using ambient light
3. cd Light_Sensor/
4. #Execute this if using pan servo
5. cd Servo_Driver

1. cd bcm2835
2. make clean
3. make
4. sudo ./main

1. cd wiringpi
2. make clean
3. make
4. sudo ./main

1. cd python
2. sudo python main.py

1. sudo raspi-config
2. Select Enable Camera, select YES
