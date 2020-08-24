import numpy as np
import math
def tand(x):
    return math.tan(x * math.pi / 180)

def sind(x):
    return math.sin(x * math.pi / 180)

def cosd(x):
    return math.cos(x * math.pi / 180)

def dh(theta,d,a,alpha):
    dhM = np.matrix([[theta,d],[a,alpha]])
    return dhM

def pinv(m):
    return np.linalg.pinv(m)

def jacobian():
    return



