###
# Code Created By 'Lankash'
#   @12/3/2022
# Description : CSPI Communication between
#      Raspberry PI4 (Embedded Linux_Python)
#      and AVR (Embedded_C)
###


from time import sleep
import RPi.GPIO as GPIO
import spidev as SPI


# Configure the raspibery pi pins :-
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)  # or GPIO.BOARD
spi_bus = 0             # SPI data bus number (0 or 1)
SCLK = 11               # Serial Clock
#TXD = 14
#RXD = 15
MOSI = 10               # Master I/P
MISO = 9                # Master O/P
CE_0 = 0                # Chip Enable 0
CE_1 = 1                # Chip enable 1
spi_speed = 500000

# Configure the SPI :-
spi = SPI.SpiDev(spi_bus, CE_0)            # Creat object from the class SPI.
spi.open(spi_bus, CE_0)       #
spi.max_speed_hz = spi_speed    # 500 KHz
spi.mode = 0                  #

#spi.xfer([1], spi_speed, 300)
v = 0

try:
    while (True):
        send = [v, v+1]
        print("TX: ", send)
        print("RX: ", spi.xfer(send))
        print(".............")
        sleep(1)
        if v >= 254:
            v = 0
        else:
            v = (v+2)

finally:
    spi.close()

