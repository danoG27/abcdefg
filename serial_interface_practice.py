import serial
import time

#ser = serial.Serial('/dev/tty.usbserial', 9600)
#ser = serial.Serial('Port_#0002.Hub_#0004',9600)
ser = serial.Serial('COM3',9600, timeout=0,
                    parity=serial.PARITY_EVEN, rtscts=1)

time.sleep(5)
print 'start'

cnt = 0

while True:
    line = ser.readline()
    if line:
        print line
        cnt += 1
        if cnt > 2:
            break

time.sleep(2)
print 'GO!'

cnt = 0
lightOn = False
while cnt < 30:
    #print cnt
    time.sleep(1)

    if (lightOn == False):
        ser.write(b'2')
        lightOn = True
        print 'light on'
    else:
        ser.write(b'1')
        lightOn = False
        print 'light off'
    cnt += 1
    time.sleep(0.1)
    line = ser.readline()
    if line:
        print line
    
ser.close()
