from machine import UART
import uos

class Car:
    def __init__(self):
        self.uart = UART(0, 115200)                         
        self.uart.init(115200, bits=8, parity=None, stop=1) 
        uos.dupterm(None, 1)

    def forward(self):
        self.uart.write('f')

    def backward(self):
        self.uart.write('b')

    def rotate_right(self):
        self.uart.write('r')

    def rotate_left(self):
        self.uart.write('l')
    
    def stop(self):
        self.uart.write('s')

c = Car()