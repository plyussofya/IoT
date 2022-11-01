import paho.mqtt.client as mqtt_client
import random
import time
import serial
from statistics import mean

values = []
unique_id = 444

def get_connection(port):
    ser = serial.Serial(port, timeout=1)
    return ser

def on_message(client, userdata, message):
    data = int(message.payload.decode("utf-8"))
    values.append(data)
    if len(values) >= 100:
        print(mean(values[:50]), " ", mean(values[50:]))
        if (mean(values[:50]) > mean(values[50:])):
            ser.write(bytearray([1]))
        else:
            ser.write(bytearray([0]))
        values.clear()

broker = "broker.emqx.io"

client = mqtt_client.Client(f'lab_{random.randint(10000, 99999)}')
client.on_message = on_message

try:
    client.connect(broker)
except Exception:
    print('Failed to connect. Check network.')
    exit()

client.loop_start()

client.subscribe(f"lab/{unique_id}/photo/instant")
print("Subscribing")
ser = get_connection('COM7')
time.sleep(600)
client.disconnect()
client.loop_stop()
print('Stop communcation')