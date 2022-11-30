# 리눅스 코드

> 1.  sudo raspi-config 
> 2.  Select Interfacing Options -> I2C ->yes Enable i2C Kernel Module

> 1.	sudo reboot

> 1. wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz
> 2. tar zxvf bcm2835-1.68.tar.gz 
> 3. cd bcm2835-1.68/
> 4. sudo ./configure && sudo make && sudo make check && sudo make install
> 5. # For more information, please refer to：http://www.airspayce.com/mikem/bcm2835/

> 1. sudo apt-get install wiringpi
> 2. # For Raspberry Pi system after may 2019, an upgrade is required.
> 3. wget https://project-downloads.drogon.net/wiringpi-latest.deb
> 4. sudo dpkg -i wiringpi-latest.deb
> 5. gpio -v
> 6. # run gpio -v version 2.52 will appear, if not, installtion error happens

> 1. sudo apt-get install p7zip-full
> 2. wget http://www.waveshare.net/w/upload/9/96/Pan-Tilt_HAT_code.7z
> 3. 7z x Pan-Tilt_HAT_code.7z -r -o./Pan-Tilt_HAT_code
> 4. sudo chmod 777 -R  Pan-Tilt_HAT_code
> 5. cd Pan-Tilt_HAT_code/RaspberryPi/

> 1. cd test
> 2. make clean
> 3. make
> 4. sudo ./main

> 1. #Execute the following actions under the directory Pan-Tilt-HAT/RaspberryPi/:
> 2. #Execute this if using ambient light
> 3. cd Light_Sensor/
> 4. #Execute this if using pan servo
> 5. cd Servo_Driver

> 1. cd bcm2835
> 2. make clean
> 3. make
> 4. sudo ./main

> 1. cd wiringpi
> 2. make clean
> 3. make
> 4. sudo ./main

> 1. cd python
> 2. sudo python main.py

> 1. sudo raspi-config
> 2. Select Enable Camera, select YES

> 1.	sudo nano /etc/modules
> 2.	
> 1.	bcm2835-v4l2
> 2.

> 1. sudo reboot
> 2. ls /dev/video*

> 1. sudo apt-get update
> 2. sudo apt-get install libjpeg8-dev cmake
> 3. cd Pan-Tilt-HAT/RaspberryPi/web_Python
> 4. git clone https://github.com/jacksonliam/mjpg-streamer
> 5. cd mjpg-streamer/mjpg-streamer-experimental/
> 6. sudo make clean all
> 7. sudo ./start.sh

> 1. sudo apt-get install python-bottle
> 2. cd Pan-Tilt-HAT/RaspberryPi/web_Python/
> 3. sudo python main.py
> 1. sudo apt-get update
> 2. sudo apt-get install python3-pip
> 3. sudo pip3 install Jetson.GPIO
> 4. sudo groupadd -f -r gpio
> 5. sudo usermod -a -G gpio your_user_name
> 6. sudo cp /opt/nvidia/jetson-gpio/etc/99-gpio.rules /etc/udev/rules.d/
> 7. sudo udevadm control --reload-rules && sudo udevadm trigger

> 1.	sudo apt-get install python-smbus

> 1. sudo apt-get install python3-pil
> 2. sudo apt-get install python3-numpy

> 1. sudo apt-get install p7zip
> 2. wget http://www.waveshare.net/w/upload/9/96/Pan-Tilt_HAT_code.7z
> 3. 7zr x Pan-Tilt_HAT_code.7z -r -o./Pan-Tilt_HAT_code
> 4. sudo chmod 777 -R  Pan-Tilt_HAT_code
> 5. cd Pan-Tilt/HAT_Code/Pan-Tilt-HAT/

> 1. sudo git clone https://github.com/waveshare/Pan-Tilt-HAT
> 2. cd Pan-Tilt-HAT/JetsonNano/

> 1. sudo git clone https://github.com/waveshare/Pan-Tilt-HAT
> 2. cd Pan-Tilt-HAT/JetsonNano/

> 1. # Execute this if using ambient light 
> 2. cd 1_Light_Sensor/
> 3. #Execute this if using pan servo
> 4. cd 2_Servo_Driver/

> 1. #python2
> 2. cd python2
> 3. sudo python main.py
> 4. #python3
> 5. cd python3
> 6. sudo python3 main.py

> 1.	DISPLAY=:0.0 gst-launch-1.0 nvarguscamerasrc ! \'video/x-raw(memory:NVMM), width=1920, height=1080, format=(string)NV12, framerate=(fraction)30/1\' ! nvoverlaysink –e

> 1. cd 3_Pan-Tilt+CAM
> 2. sudo python main.py
