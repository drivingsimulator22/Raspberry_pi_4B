###
# Code Created By 'Yousef ayman'
#   @19/3/2022
# Description : calculation the length of stewart platform legs by inverse kinematics
#
import numpy as np

# Coordinates of the points where the rods 
# are attached to the base.


Base = np.array( [ 
    [ 42.53585743,828.8790286,0],
    [ 739.1023057,-377.6610181,0],
    [696.6661185,-451.2819517,0],
    [-696.618678,-451.1913206,0],
    [-739.1012846,-377.6628879,0],
    [ -42.48607053,828.9118768,0] ])
Base = np.transpose(Base)
    
# Coordinates of the points where the rods 
# are attached to the platform.
Platform = np.array([ 
    [333.9848185,242.098462,0],
    [376.4888746,168.479082, 0],
    [42.50440403,-410,0],
    [-42.50440403,-410, 0],
    [-376.4888746,168.479082, 0],
    [-333.9848185, 242.098462, 0] ])
Platform = np.transpose(Platform)


# #########################################################################################


# # # Definition of the platform home position.
home_pos= np.array([0, 0, 997])

# Allocate for variables
len = np.zeros((3,6))
pistonlength = np.zeros((6))

# Rotation matrices used later
def rotX(theta):
    rotx = np.array([
        [1,     0    ,    0    ],
        [0,  np.cos(theta), -np.sin(theta)],
        [0,  np.sin(theta), np.cos(theta)] ])
    return rotx

def rotY(theta):    
    roty = np.array([
        [np.cos(theta), 0,  np.sin(theta) ],
        [0         , 1,     0       ],
        [-np.sin(theta), 0,  np.cos(theta) ] ])   
    return roty
    
def rotZ(theta):    
    rotz = np.array([
        [ np.cos(theta),-np.sin(theta), 0 ],
        [ np.sin(theta), np.cos(theta), 0 ],
        [   0        ,     0      , 1 ] ])   
    return rotz

###########################################################################################

# Given input trans, rotation
trans = np.transpose(np.array([0,0,0])) # X, Y, Z
rotation = np.transpose(np.array([0,0,0])) # yaw roll pitch

# Get rotation matrix of platform. RotZ* RotY * RotX -> matmul
# R = np.matmul( np.matmul(rotZ(rotation[2]), rotY(rotation[1])), rotX(rotation[0]) )
R = np.matmul( np.matmul(rotX(rotation[0]), rotY(rotation[1])), rotZ(rotation[2]) )

# Get leg length for each leg
# leg =( (translation vector + (rotational matrix * platform coordinates)) - base coordinates )
len = np.repeat(trans[:, np.newaxis], 6, axis=1) + np.repeat(home_pos[:, np.newaxis], 6, axis=1) + np.matmul(R, Platform) - Base 
pistonlength = ( np.linalg.norm(len, axis=0)-892)


print('Leg lengths to command in order to achieve desired position of plate: \n', pistonlength)



# def mapRange(value, inMin, inMax, outMin, outMax):
#     return outMin + (((value - inMin) / (inMax - inMin)) * (outMax - outMin))
