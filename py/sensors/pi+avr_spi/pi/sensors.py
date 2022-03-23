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
spi_speed = 500000    # 500 KHz

# Configure the SPI :-
spi = SPI.SpiDev()            # Creat object from the class SPI.
spi.open(spi_bus, CE_0)       #
spi.max_speed_hz = spi_speed    # 4 GHz
spi.mode = 0                  #

spi.xfer([1], spi_speed, 300)

while (True):

    dist = spi.xfer2([2], spi_speed, 200)
    print("Sensor 1 : {} mm".format(dist[0]))
    sleep(1)

    dist = spi.xfer2([3], spi_speed, 200)
    print("Sensor 2 : {} mm".format(dist[0]))
    sleep(1)

    dist = spi.xfer2([4], spi_speed, 200)
    print("Sensor 3 : {} mm".format(dist[0]))
    sleep(1)

    dist = spi.xfer2([5], spi_speed, 200)
    print("Sensor 4 : {} mm".format(dist[0]))
    sleep(1)

    dist = spi.xfer2([6], spi_speed, 200)
    print("Sensor 5 : {} mm".format(dist[0]))
    sleep(1)

    dist = spi.xfer2([1], spi_speed, 200)
    print("Sensor 6 : {} mm".format(dist[0]))
    sleep(1)
    print(".............................................................................................................")
