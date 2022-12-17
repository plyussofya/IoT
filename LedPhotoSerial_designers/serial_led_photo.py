import serial
import time

lengths = {'s': 3,
           'u': 0,
           'd': 0,
           'f': 0}
values = []

def get_connection(port):
    ser = serial.Serial(port,timeout=1)
    return ser

def send(ser,message, mesg_len):
    ser.write(message)
    time.sleep(0.1)
    if mesg_len != 0:
        data = ser.readline()
        result = data.decode()
        result = result.strip()
        return (result)
        
if __name__ == '__main__':
    ser = get_connection("COM6")
    while True:
        print("Введите одну из команд: \nu - turn on, \nd - turn off, \na - on/off according to sensor readings, \nl - enable data transfer, \nf - brightness")      
        inp = input()
        if inp == "u" or inp == "d" :
            send(ser, inp.encode(), lengths[inp])
        elif inp == "a":
            while True:
                com = "s"
                val = send(ser, com.encode(), lengths[com])
                if val:
                    val = int(val)
                    print(val)
                    if val > 900:
                        send(ser, 'd'.encode(), 0)
                    else:
                        send(ser, 'u'.encode(), 0)
        elif inp == "l":
            while True: 
                com = "s"
                val = send(ser, com.encode(), lengths[com])
                if val:
                    values.append(val)
                print (values)
        elif inp == "f":
            while True: 
                com = "s"
                val = send(ser, com.encode(), lengths[com])
                if val:
                    val = int(val)
                    print(val)
                    if val > 900:
                        send(ser, 'f'.encode(), 0)
                        brightness = send(ser, '50'.encode(),1)
                    else:
                        send(ser, 'f'.encode(), 0)
                        brightness = send(ser, '255'.encode(),1)
        else:
            print("Unknown command. Repeat the input.")
