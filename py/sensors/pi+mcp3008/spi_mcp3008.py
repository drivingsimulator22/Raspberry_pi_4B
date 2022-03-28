###
# Code Created By 'Lankash'
#   @22/3/2022
# Description : SPI Communication between
#      Raspberry PI4 (Embedded Linux_Python)
#      and MCP3008 Chip
###


#####################_USED_LIBRARY_###############################
import Adafruit_MCP3008 as MCP
import Adafruit_GPIO.SPI as SPI
################################################################

######################Variable_decleration#######################
#list of the sensors zero error 
Sensor_Zero_Errors=[7,0,0,0,0,0]   
################################################################

#######################Functions_definitions####################

# ###############################################################
# Function Name: Sensor_map
# Description: Function for Sensor Readings Mapping
# Inputs:  value-->> the value to be mapped on new range
#          inMin-->> the mim value in the old range
#          inMax-->> the max value in the old range
#          outMin-->> the mim value in the new range
#          outMin-->> the max value in the new range
# Output:  the mapped value within the new range
#################################################################

def sensor_map(value, inMin, inMax, outMin, outMax):
    return outMin + (((value - inMin) / (inMax - inMin)) * (outMax - outMin))

##################################################################
# Function Name: SPI_MCP3008_Init()
# description: Hardware SPI configuration 
###################################################################

def SPI_MCP3008_Init():
    global mcp                                                 # to be created as object from the MCP class
    SPI_PORT = 0                                               # SPI0 module in Raspberry Pi 
    SPI_DEVICE = 0                                             # SPI0.0 first and only slave     
    mcp = MCP.MCP3008(spi=SPI.SpiDev(SPI_PORT, SPI_DEVICE))    # configure the MCP class

####################################################################
# Function Name: ADC_MCP3008_Readings()
# description: takes reading from all 6 wire potentiometers from the 
#              MCP3008 ADC module channels then map the reading from
#              0 ---> 1023  
# output : list of all the 6 sensors current readings 
#####################################################################

def ADC_MCP3008_Readings():
    # Read all the 8 ADC channel values in a list.
    Sensor_Readings = [0]*8
    for i in range(8):
        # The read_adc function will get the value of the specified channel (0-7).
        Sensor_Readings[i] = mcp.read_adc(i)

   
# mapping and calibration of every reading 
    Sensor_Readings[0] = sensor_map(Sensor_Readings[0], 39,  980, 0, 1851) - Sensor_Zero_Errors[0]
    Sensor_Readings[1] = sensor_map(Sensor_Readings[1], 78, 1023, 0,  466) - Sensor_Zero_Errors[1]
    Sensor_Readings[2] = sensor_map(Sensor_Readings[2],  0, 1023, 0,  520) - Sensor_Zero_Errors[2]
    Sensor_Readings[3] = sensor_map(Sensor_Readings[3],  0, 1023, 0,  500) - Sensor_Zero_Errors[3]
    Sensor_Readings[4] = sensor_map(Sensor_Readings[4],  0, 1023, 0,  500) - Sensor_Zero_Errors[4]
    Sensor_Readings[5] = sensor_map(Sensor_Readings[5],  0, 1023, 0,  500) - Sensor_Zero_Errors[5]

# convert all reading from floats to integers and save them in new list
    Values = [int(values) for values in Sensor_Readings]
    
    return Values
    
