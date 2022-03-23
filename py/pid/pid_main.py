import pid as PID
import RPi.GPIO as GPIO
from time import sleep
#import matplot
import numpy


#
# Define pins
#
relay1_open = 0
relay2_open = 1
relay3_open = 2
relay4_open = 3
relay5_open = 4
relay6_open = 5

relay1_close = 6
relay2_close = 7
relay3_close = 8
relay4_close = 9
relay5_close = 10
relay6_close = 11


#
# Configure Raspberry Pi Pins
#
GPIO.setWarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(relay1_open, GPIO.OUT)
GPIO.setup(relay2_open, GPIO.OUT)
GPIO.setup(relay3_open, GPIO.OUT)
GPIO.setup(relay4_open, GPIO.OUT)
GPIO.setup(relay5_open, GPIO.OUT)
GPIO.setup(relay6_open, GPIO.OUT)

GPIO.setup(relay1_open, GPIO.OUT)
GPIO.setup(relay2_open, GPIO.OUT)
GPIO.setup(relay3_open, GPIO.OUT)
GPIO.setup(relay4_open, GPIO.OUT)
GPIO.setup(relay5_open, GPIO.OUT)
GPIO.setup(relay6_open, GPIO.OUT)


#
# Initialize variables
#
sensor_1 = 0
sensor_2 = 0
sensor_3 = 0
sensor_4 = 0
sensor_5 = 0
sensor_6 = 0


#
# Configure SPI connection for sensor readings
#


#
# Initialize the 6 Pistons PID Parameters
#
piston_1 = PID.pid
piston_2 = PID.pid
piston_3 = PID.pid
piston_4 = PID.pid
piston_5 = PID.pid
piston_6 = PID.pid

piston_1.kp = 0.0
piston_1.kd = 0.0
piston_1.ki = 0.0

piston_2.kp = 0.0
piston_2.kd = 0.0
piston_2.ki = 0.0

piston_3.kp = 0.0
piston_3.kd = 0.0
piston_3.ki = 0.0

piston_4.kp = 0.0
piston_4.kd = 0.0
piston_4.ki = 0.0

piston_5.kp = 0.0
piston_5.kd = 0.0
piston_5.ki = 0.0

piston_6.kp = 0.0
piston_6.kd = 0.0
piston_6.ki = 0.0


#
# Invers kinematics equations
#
setPoint_1 = 0.0
setPoint_2 = 0.0
setPoint_3 = 0.0
setPoint_4 = 0.0
setPoint_5 = 0.0
setPoint_6 = 0.0


while (True):
    #
    # Receive the Sesnsor Readings via SPI
    #


    #
    # Inizialize thw PWM variables
    #
    freq = 100
    pwm_1  = GPIO.PWM(relay1_open, freq)
    pwm_2  = GPIO.PWM(relay2_open, freq)
    pwm_3  = GPIO.PWM(relay3_open, freq)
    pwm_4  = GPIO.PWM(relay4_open, freq)
    pwm_5  = GPIO.PWM(relay5_open, freq)
    pwm_6  = GPIO.PWM(relay6_open, freq)
    pwm_7  = GPIO.PWM(relay1_close, freq)
    pwm_8  = GPIO.PWM(relay2_close, freq)
    pwm_9  = GPIO.PWM(relay3_close, freq)
    pwm_10 = GPIO.PWM(relay4_close, freq)
    pwm_11 = GPIO.PWM(relay5_close, freq)
    pwm_12 = GPIO.PWM(relay6_close, freq)

    
    #
    # Compute PID parameters
    #
    piston1_pwm = PID.PID_update(piston_1, setPoint_1, sensor_1)
    piston2_pwm = PID.PID_update(piston_2, setPoint_2, sensor_2)
    piston3_pwm = PID.PID_update(piston_3, setPoint_3, sensor_3)
    piston4_pwm = PID.PID_update(piston_4, setPoint_4, sensor_4)
    piston5_pwm = PID.PID_update(piston_5, setPoint_5, sensor_5)
    piston6_pwm = PID.PID_update(piston_6, setPoint_6, sensor_6)

    #
    # PWM Output
    #
    if (setPoint_1 - sensor_1) > 0:
        pwm_1.start(piston1_pwm)
    elif (setPoint_1 - sensor_1) < 0:
        pwm_7.start(piston1_pwm)

    if (setPoint_2 - sensor_2) > 0:
        pwm_2.start(piston2_pwm)
    elif (setPoint_2 - sensor_2) < 0:
        pwm_8.start(piston2_pwm)

    if (setPoint_3 - sensor_3) > 0:
        pwm_3.start(piston3_pwm)
    elif (setPoint_3 - sensor_3) < 0:
        pwm_9.start(piston3_pwm)

    if (setPoint_4 - sensor_4) > 0:
        pwm_4.start(piston4_pwm)
    elif (setPoint_4 - sensor_4) < 0:
        pwm_10.start(piston4_pwm)

    if (setPoint_5 - sensor_5) > 0:
        pwm_5.start(piston5_pwm)
    elif (setPoint_5 - sensor_5) < 0:
        pwm_11.start(piston5_pwm)

    if (setPoint_6 - sensor_6) > 0:
        pwm_6.start(piston6_pwm)
    elif (setPoint_6 - sensor_6) < 0:
        pwm_12.start(piston6_pwm)

