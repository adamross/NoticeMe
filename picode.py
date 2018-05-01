import paho.mqtt.client as mqtt #import the client1
import time
import serial
import syslog

port = '/dev/ttyAMA0'
ard = serial.Serial(port, 9600,  timeout=5) #initialise serial monitor on baud rate 9600

#text = input("Enter text to send to screen: ")
screen = "" #initialisation of variable to store message

def on_message(client, userdata, message):
    screen = str(message.payload.decode("utf-8") #decode data received from broker
    print screen
    ard.write(screen) #write to arduino serial monitor
    time.sleep(4)
    #print"message topic = ", message.topic
    #print("message qos = ", message.qos)
    #print("message retain flag = ", message.retain)

#while(1):
broker_address="192.168.1.104" #broker_address="ip address of the server"
print"creating new instance"
client = mqtt.Client("RossScreen") #create new instance

print"connecting to broker"
client.connect(broker_address) #connect to broker
client.loop_start() #start the loop
print"Subscribing to topic","RossLT"
client.subscribe("RossLT")
client.on_message = on_message #attach function to callback
time.sleep(4) #wait

if( screen != ""):
    print"Publishing message to topic","RossResp"
    client.publish("RossLT","OK")
    #client.loop_stop() #stop loop
    #leave loop open to be activiely listening for a message from broker             

