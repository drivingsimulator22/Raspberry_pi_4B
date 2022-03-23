import RPi.GPIO as GPIO
from time import sleep

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

led_1 = 17
led_2 = 27
led_3 = 22
led_4 = 23
cycle = 10
freq = 100

GPIO.setup(led_1, GPIO.OUT)
GPIO.setup(led_2, GPIO.OUT)
GPIO.setup(led_3, GPIO.OUT)
GPIO.setup(led_4, GPIO.OUT)

pwm_1 = GPIO.PWM(led_1, freq)
pwm_2 = GPIO.PWM(led_2, freq)
pwm_3 = GPIO.PWM(led_3, freq)
pwm_4 = GPIO.PWM(led_4, freq)

while (True) :    
    pwm_1.start(cycle)
    pwm_2.start(cycle)
    pwm_3.start(cycle)
    pwm_4.start(cycle)
    sleep (0.01)
    cycle += 1

    if cycle >= 100 :
        cycle = 0





    

