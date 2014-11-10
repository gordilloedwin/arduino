# Comunicacion con el puerto serial
# Se envian datos a la placa Arduino

from time import sleep
import serial

puerto = serial.Serial('/dev/ttyACM0',9600)
contador = 1

while True:
	contador = 1
	#puerto.write(str(chr(contador)))
	puerto.write('1')
	print "Encender----------------------------------"
	sleep(3)
	#Encender y apagar led
	#contador = 0
	puerto.write('0')
	print "Apagar"
	sleep(3)
