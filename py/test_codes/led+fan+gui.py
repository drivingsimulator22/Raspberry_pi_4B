import tkinter as tk
from tkinter import filedialog, Text
#import os
#from PIL import Image, ImageTk
from time import sleep
import RPi.GPIO as GPIO

##############################################

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)  # or GPIO.BCM
#btn = 36
#pull = GPIO.PUD_UP
led = 3
fan = 8

#GPIO.setup(btn, GPIO.IN, pull)
GPIO.setup(led, GPIO.OUT)
GPIO.setup(fan, GPIO.OUT)

#btn_state = False
#fan_state = False

##############################################


def led_off():
    GPIO.output(led, GPIO.LOW)
    led_btn_on = tk.Button(frame, text='LED on', padx=35,
                           pady=15, fg="white", bg='black', height=2,
                           width=2, command=led_on)
    led_btn_on.place(x=50, y=100)
    
    led_btn_off = tk.Button(frame, text='LED on', padx=35,
                           pady=15, fg="white", bg='orange', height=2,
                           width=2, command=led_on)
    led_btn_off.place(x=50, y=180)
    sleep(1)


def led_on():
    GPIO.output(led, GPIO.HIGH)
    led_btn_on = tk.Button(frame, text='LED on', padx=35,
                           pady=15, fg="white", bg='orange', height=2,
                           width=2, command=led_on)
    led_btn_on.place(x=50, y=100)
    led_btn_off = tk.Button(frame, text='LED off', padx=35,
                            pady=15, fg="white", bg='black', height=2,
                            width=2, command=led_off)
    led_btn_off.place(x=50, y=180)
    sleep(1)


def fan_off():
    GPIO.output(fan, GPIO.HIGH)
    fan_btn_on = tk.Button(frame, text='FAN on', padx=35,
                           pady=15, fg="white", bg='black', height=2,
                           width=2, command=fan_on)
    fan_btn_on.place(x=250, y=100)

    fan_btn_off = tk.Button(frame, text='FAN off', padx=35,
                            pady=15, fg="white", bg='orange', height=2,
                            width=2, command=fan_off)
    fan_btn_off.place(x=250, y=180)
    sleep(1)


def fan_on():
    GPIO.output(fan, GPIO.LOW)
    fan_btn_on = tk.Button(frame, text='FAN on', padx=35,
                           pady=15, fg="white", bg='orange', height=2,
                           width=2, command=fan_on)
    fan_btn_on.place(x=250, y=100)

    fan_btn_off = tk.Button(frame, text='FAN off', padx=35,
                            pady=15, fg="white", bg='black', height=2,
                            width=2, command=fan_off)
    fan_btn_off.place(x=250, y=180)
    sleep(1)


def exit():
    GPIO.cleanup()
    window.destroy()

##############################################


window = tk.Tk()  # Create the main window
window.title("LED+FAN Controller")
window.geometry("500x500+150+200")
window.resizable(False, False)
window.configure()

canvas = tk.Canvas(window, height=700, width=700, bg="#263D42")
canvas.pack()

frame = tk.Frame(window, bg="white")
frame.place(relwidth=0.8, relheight=0.8, relx=0.1, rely=0.1)

led_btn_on = tk.Button(frame, text='LED on', padx=35,
                       pady=15, fg="white", bg='black', height=2,
                       width=2, command=led_on)
led_btn_on.place(x=50, y=100)

led_btn_off = tk.Button(frame, text='LED off', padx=35,
                        pady=15, fg="white", bg='black', height=2,
                        width=2, command=led_off)
led_btn_off.place(x=50, y=180)


fan_btn_on = tk.Button(frame, text='FAN on', padx=35,
                       pady=15, fg="white", bg='orange', height=2,
                       width=2, command=fan_on)
fan_btn_on.place(x=250, y=100)

fan_btn_off = tk.Button(frame, text='FAN off', padx=35,
                        pady=15, fg="white", bg='black', height=2,
                        width=2, command=fan_off)
fan_btn_off.place(x=250, y=180)


exit_btn = tk.Button(frame, text='EXIT', padx=25,
                     pady=10, fg="white", bg='red', height=2,
                     width=2, command=exit)
exit_btn.place(x=160, y=300)


window.mainloop()  # Like while loop to continue showing the main window


# backgroundImage = ImageTK.PhotoImages(
#    "/mnt/sdb1/courses/embedded_systems/embedded_linux_mo3tassem/exercises/vs_code/raspi.png")
#backgroundLabel = root.Label(parent, image=backgroundImage)
#backgroundLabel.place(x=0, y=0, relWidth=1, relHeight=1)
# self.canvas.pack()

