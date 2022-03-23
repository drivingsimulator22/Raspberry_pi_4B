##################################################
# Code Created by "Lankash"
#  @5/2/2022
# File Contents: 2 PID Functions + PID Class
# /

# import pid
import time
import os.path
from dataclasses import dataclass


# Initializing the class for PID Conroller.
class pid:
    kp = 0.0
    ki = 0.0
    kd = 0.0

    limMax = 0.0
    limMin = 0.0

    limMax_init = 0.0
    limMin_init = 0.0

    taw = 0.0
    T = 0.0

    setPoint = 0.0

    integ = 0.0
    diff = 0.0
    prop = 0.0
    prevError = 0.0
    prevMeasurement = 0.0

    outPut = 0.0
#........................Class End.........................#


# Function Updates the PID Parameters.
def PID_update(lankash, setPoint, measurement):
    #
    # Calculating error signal
    #
    error = setPoint - measurement
    #
    # Calculating proportional term
    #
    lankash.prop = lankash.kp * error
    #
    # Calculating Integral Term
    #
    lankash.integ = lankash.integ + \
        (0.5 * lankash.ki * lankash.T * (error + lankash.prevError))
    #
    # Anti windUp + Clamp the Integrator
    #
    if (lankash.integ > lankash.limMax_init):
        lankash.integ = lankash.limMax_init
    elif (lankash.integ < lankash.limMin_init):
        lankash.integ = lankash.limMin_init
    #
    # Derivativ (Band Limit) + Low Pass Filter
    #
    lankash.diff = ((2.0 * lankash.kd) * (measurement - lankash.prevMeasurement) +
                    (2 * (lankash.taw - lankash.T) * lankash.diff)) / (2 * lankash.taw + lankash.T)
    #
    # Compare O/P and Apply clipping limits
    #
    lankash.outPut = lankash.proportional + lankash.integ + lankash.diff

    if (lankash.outPut > lankash.limMax):
        lankash.outPut = lankash.limMax
    elif (lankash.output < lankash.limMin):
        lankash.outPut = lankash.limMin
    #
    # Store the new values: Error & Measurements
    #
    lankash.prevError = error
    lankash.prevMeasurement = measurement
    #
    # Return PID O/P
    #
    return lankash.outPut
# ...........................Function End........................#

