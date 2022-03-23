#from multiprocessing.connection import wait
#from gpiozero import LED, Button
#from signal import pause
from time import sleep
import RPi.GPIO as GPIO


GPIO.setmode(GPIO.BOARD)
btn = 36
pull = GPIO.PUD_UP
led = 37
fan = 40

GPIO.setup(btn, GPIO.IN, pull)
GPIO.setup(led, GPIO.OUT)
#GPIO.setup(fan, GPIO.OUT)

btn_state = False

while (1):
    if GPIO.input(btn) == 1:
        print("Button is Pressed")
        if btn_state == False:
            GPIO.output(led, True)
            print("LED is ON")
            btn_state = True
            sleep(1)
        else:
            GPIO.output(led, False)
            print("LED is OFF")
            btn_state = False
            sleep(1)
        while GPIO.input(btn) == 1:
            pass

