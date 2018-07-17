import warnings
import serial
import serial.tools.list_ports

counter = 0

arduino_ports = [
	p.device
	for p in serial.tools.list_ports.comports()
	if 'CH340' in p.description
]
if not arduino_ports:
	raise IOError("No Arduino found")
if len(arduino_ports) > 1:
	warnings.warn('Multiple Arduinos found - using the first')

ser = serial.Serial(arduino_ports[0], 9600, timeout=0.02)
ports = list(serial.tools.list_ports.comports())

print ('Started...')
	
while True:
	command = ser.readline()
	#if command:
	#	print (command)
	
	if command == b'0':
		counter += 1
		print ("counter = " + str(counter))
	
	if command == b'255':
		counter -= 1
		print ("counter = " + str(counter))