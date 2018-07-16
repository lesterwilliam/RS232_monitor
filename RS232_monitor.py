import serial

ser = serial.Serial("COM1", 9600, timeout=0.02)

while True:
	command = ser.readline()
	if command:
		print (command)