import time
import paho.mqtt.client as paho
import serial

broker="broker.emqx.io"

def get_connection(port):
    ser = serial.Serial(port,timeout=1)
    return ser

def send(ser, message, mesg_len):
    ser.write(message)
    time.sleep(0.1)
    if mesg_len != 0:
        data = ser.readline()
        result = data.decode()
        result = result.strip()
        return (result)

ser = get_connection("COM10")

def on_message(client, userdata, message):
    time.sleep(1)
    data = str(message.payload.decode("utf-8"))
    print("received message =", data)
    if(float(data) > float(30)):
        send(ser, 'd'.encode(), 0)
    else:
        send(ser, 'u'.encode(), 0)

client = paho.Client("isulab44444") 
client.on_message=on_message

print("Connecting to broker",broker)
client.connect(broker) 
client.loop_start() 
print("Subcribing")
client.subscribe("esp8266-E8E8/range")
time.sleep(1800)
client.disconnect()
client.loop_stop()