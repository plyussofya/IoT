import time
import paho.mqtt.client as mqtt_client
import random
import serial

def get_connection(port):
   ser = serial.Serial(port, timeout=1)
   return ser

broker = "broker.emqx.io"

client = mqtt_client.Client(f'lab_{random.randint(10000, 99999)}')

try:
   client.connect(broker)
except Exception:
   print("Failed to connect. Check network")
   exit()

ser = get_connection('COM9')

values = []
unique_id = 444

while True:
    if ser.in_waiting > 0:
        data = ser.read(1)
        client.publish(f"lab/{unique_id}/photo/instant", data[0])
        values.append(data[0])
        if len(values) >= 100:
            client.publish(f"lab/{unique_id}/photo/averge", sum(values)/len(values))
            client.publish(f"lab/{unique_id}/photo/max", max(values))
            client.publish(f"lab/{unique_id}/photo/mix", min(values))
            values = []
    time.sleep(0.01)