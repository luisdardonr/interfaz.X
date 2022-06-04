# Programa base para utilizar interfaz gráfica diseñada en QtDesigner

import sys
from PyQt5 import uic
from PyQt5.QtWidgets import QMainWindow, QApplication


import serial
a=0
b=1
c=2
d=3

class App(QMainWindow):
	def __init__(self):
		super().__init__()
		uic.loadUi("GUI_PROYECTOA.ui", self)			# Ingresar nombre de su archivo .ui
		self.ser = serial.Serial(port="COM4", baudrate=9600, timeout=1.0)
		self.ser.close()
		self.mensaje = "" 	# Variable para guardar respuesta del pic al mover la perilla

		self.servo1.valueChanged.connect( self.get_value_servo1 )
		self.servo2.valueChanged.connect( self.get_value_servo2 )
		self.servo3.valueChanged.connect( self.get_value_servo3 )
		self.servo4.valueChanged.connect( self.get_value_servo4 )

		self.boton_s1.clicked.connect( self.botton1 )
		self.boton_s2.clicked.connect( self.botton2 )
		self.boton_s3.clicked.connect( self.botton3 )
		self.boton_s4.clicked.connect( self.botton4 )

	def	get_value_servo1(self):
		value = self.servo1.value()
		self.ser.open()									# Abrimos puerto serial
		self.ser.write( chr(value).encode() )			# Enviamos valor de la perilla como caracter
		self.ser.close()								# Cerramos puerto serial
		self.lb_servo1.setText(str(self.servo1.value()))


	def	get_value_servo2(self):
		value2 = self.servo2.value()
		self.ser.open()									# Abrimos puerto serial
		self.ser.write( chr(value2).encode() )			# Enviamos valor de la perilla como caracter
		self.ser.close()								# Cerramos puerto serial

		self.lb_servo2.setText(str(self.servo2.value()))

	def	get_value_servo3(self):
		value3 = self.servo3.value()
		self.ser.open()									# Abrimos puerto serial
		self.ser.write( chr(value3).encode() )			# Enviamos valor de la perilla como caracter
		self.ser.close()								# Cerramos puerto serial

		self.lb_servo3.setText(str(self.servo3.value()))

	def	get_value_servo4(self):
		value4 = self.servo4.value()
		self.ser.open()									# Abrimos puerto serial
		self.ser.write( chr(value4).encode() )			# Enviamos valor de la perilla como caracter
		self.ser.close()								# Cerramos puerto serial

		self.lb_servo4.setText(str(self.servo4.value()))

	def botton1(self):
		b1 = chr(a).encode()
		self.ser.open()									# Abrimos puerto serial
		self.ser.write( chr(b1).encode() )			# Enviamos valor de la perilla como caracter
		self.ser.close()								# Cerramos puerto serial
	def botton2(self):
		b2 = chr(b).encode()
		self.ser.open()									# Abrimos puerto serial
		self.ser.write( chr(b2).encode() )			# Enviamos valor de la perilla como caracter
		self.ser.close()								# Cerramos puerto serial
	def botton3(self):
		b3 = chr(c).encode()
		self.ser.open()									# Abrimos puerto serial
		self.ser.write( chr(b3).encode() )			# Enviamos valor de la perilla como caracter
		self.ser.close()								# Cerramos puerto serial
	def botton4(self):
		b4 = chr(d).encode()
		self.ser.open()									# Abrimos puerto serial
		self.ser.write( chr(b4).encode() )			# Enviamos valor de la perilla como caracter
		self.ser.close()								# Cerramos puerto serial

if __name__ == '__main__':
	app = QApplication(sys.argv)
	GUI = App()
	GUI.show()
	sys.exit(app.exec_())


