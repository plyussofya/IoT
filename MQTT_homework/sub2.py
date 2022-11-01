from ast import Not
from http import client
import time
from xmlrpc.client import MAXINT
import paho.mqtt.client as mqtt_client
import random
import serial
from statistics import mean

values = []
unique_id = 444
max_value = 0
min_value = 0

def get_connection(port):
    ser = serial.Serial(port, timeout=1)
    return ser

def on_message(client, userdata, message):
    global min_value
    global max_value
    data = int(message.payload.decode("utf-8"))
    topic = message.topic
    if topic == (f"lab/{unique_id}/photo/max"):
        max_value = data
    if topic == (f"lab/{unique_id}/photo/min"):
        min_value = data
    if topic == (f"lab/{unique_id}/photo/instant"):
        if data > (min_value + max_value) / 2:
            ser.write(bytearray([1]))
        else:
            ser.write(bytearray([0]))

broker = "broker.emqx.io"

client = mqtt_client.Client(f'lab_{random.randint(10000, 99999)}')
client.on_message = on_message

try:
    client.connect(broker)
except Exception:
    print('Failed to connect. Check network.')
    exit()

client.loop_start()
client.subscribe(f"lab/{unique_id}/photo/max")
client.subscribe(f"lab/{unique_id}/photo/min")
client.subscribe(f"lab/{unique_id}/photo/instant")

print("Subscribing")
ser = get_connection('COM7')

time.sleep(600)
client.disconnect()
client.loop_stop()
print('Stop communcation')