# servo control 15.12.2016
 
# 1) user set servo position in python
# 2) position is sent to arduino
# 3) arduino moves servo to position
# 4) arduino send confirmation message back to python
# 5) message is printed in python console
 
import serial                                           # import serial library
import time
arduino = serial.Serial('COM4', 9600,timeout=1)   # create serial object named arduino
while True:                                             # create loop
 
        command = str(input ("Servo position: "))       # query servo position
        arduino.write(str.encode(command))                # write position to serial port
        reachedPos = str(arduino.readline())            # read serial port for arduino echo
        print (reachedPos)                               # print arduino echo to console