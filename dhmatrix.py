import numpy as np
import math
def tand(x):
    return math.tan(x * math.pi / 180)

def sind(x):
    return math.sin(x * math.pi / 180)

def cosd(x):
    return math.cos(x * math.pi / 180)

def dh(theta,d,a,alpha):
    dhm=np.array([[cosd(theta),-sind(theta)*cosd(alpha),sind(theta)*sind(alpha),a*cosd(theta)],
    [sind(theta),cosd(theta)*cosd(alpha),-cosd(theta)*sind(alpha),a*sind(theta)],
    [0,sind(alpha),cosd(alpha),d],
    [0,0,0,1]])
    return dhm

def pinv(m):
    return np.linalg.pinv(m)

def jacobian():
    return

def FKDraw(j1,j2,j3):
    j4=360-(j2+j3)
    j=np.array([[j1, j2, j3, j4],
                [17.5, 0, 0, 0],
                [3, 22.3, 31.5, 14],
                [90, 0, 0, 0]])
    return j

def DHKine(j):
    #collum 1=joint angle, 2=joint offset, 3=link lenght, 4=twist angle
    T01=dh(j(1,1),j(2,1),j(3,1),j(4,1))
    T12=dh(j(1,2),j(2,2),j(3,2),j(4,2))
    T23=dh(j(1,3),j(2,3),j(3,3),j(4,3))
    T34=dh(j(1,4),j(2,4),j(3,4),j(4,4))
    
    T02=T01*T12
    T03=T02*T23
    T04=T03*T34
    return np.array([T01, T02, T03, T04])

#def XYZKine