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
    ser = get_connection("COM8")
    while True:
        print("u - turn on, \nd - turn off, \na - on/off according to sensor readings, \nl - enable data transfer, \nb - brightness")      
        inp = input("Enter one of the commands:")
        if inp == "u" or inp == "d" :
            send(ser, inp.encode(), lengths[inp])
        elif inp == "a":
            while True:
                com = "s"
                val = send(ser, com.encode(), lengths[com])
                if val:
                    if int(val) > 800:
                        send(ser, 'd'.encode(), 0)
                    else:
                        send(ser, 'u'.encode(), 0)
        elif inp == "l":
            while True:
                com = "s"
                val = send(ser, com.encode(), lengths[com])
                if val:
                    values.append(val)
                    if len(values) == 10:
                        print(values)
                        break     
        elif inp == "b":
            while True: 
                com = "f"
                val = send(ser, com.encode(), lengths[com])
                if val:
                    if int(val) > 800:
                        send(ser, 'f'.encode(), 0)
                        brightness = send(ser, '10'.encode(),1)
                    else:
                        send(ser, 'f'.encode(), 0)
                        brightness = send(ser, '255'.encode(),1)
        else:
            print("Unknown command. Repeat the input.")
