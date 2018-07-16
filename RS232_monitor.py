import serial

serialport = serial.Serial("COM1", 9600, timeout=0.5)

while True:    
    command = serialport.read()
    print (command)
