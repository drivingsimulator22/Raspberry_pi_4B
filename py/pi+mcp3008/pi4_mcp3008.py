###
# Code Created By 'Lankash'
#   @22/3/2022
# Description : SPI Communication between
#      Raspberry PI4 (Embedded Linux_Python)
#      and MCP3008 Chip
###

import Adafruit_GPIO as GPIO
import Adafruit_MCP3008 as MCP
import Adafruit_GPIO.SPI as SPI
import time


# Software SPI Configuration
#
#CLK = 23
#MISO = 19
#MOSI = 21
#CS = 24
#mcp = MCP.MCP3008(clk=CLK, cs=CS, miso=MISO, mosi=MOSI)

# Hardware SPI configuration:
SPI_PORT   = 0
SPI_DEVICE = 0
mcp = MCP.MCP3008(spi=SPI.SpiDev(SPI_PORT, SPI_DEVICE))


print('Reading MCP3008 values, press Ctrl-C to quit...')
# Print nice channel column headers.
print('| {0:>4} | {1:>4} | {2:>4} | {3:>4} | {4:>4} | {5:>4} | {6:>4} | {7:>4} |'.format(*range(8)))
print('-' * 57)
# Main program loop.
while True:
    # Read all the ADC channel values in a list.
    values = [0]*8
    for i in range(8):
        # The read_adc function will get the value of the specified channel (0-7).
        values[i] = mcp.read_adc(i)

    #values[0] = (1.923 * values[7]) - 84        #Sensor_1 Mapping + Calibration of Zero Error  //1851 mm
    #values[1] = (0.488888 * values[0]) - 40     #Sesnor_2 Mapping + Calibration of Zero Error  //460 mm
    #values[2] = (0.488288 * values[2]) - 0     #Sesnor_3 Mapping + Calibration of Zero Error  //500 mm
    #values[3] = (0.488288 * values[2]) - 0     #Sesnor_4 Mapping + Calibration of Zero Error  //500 mm
    #values[4] = (0.488288 * values[2]) - 0     #Sesnor_5 Mapping + Calibration of Zero Error  //500 mm
    #values[5] = (0.488288 * values[2]) - 0     #Sesnor_6 Mapping + Calibration of Zero Error  //500 mm

    Values = [int(values) for values in values]
    # Print the ADC values.
    print('| {0:>4} | {1:>4} | {2:>4} | {3:>4} | {4:>4} | {5:>4} | {6:>4} | {7:>4} |'.format(*Values))
    # Pause for half a second.
    time.sleep(0.5)

