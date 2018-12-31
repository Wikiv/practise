#!/usr/bin/env python 

""" 
A simple echo client 
""" 

import socket
import time

host = 'localhost' 
port = 20001
size = 1024 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
s.connect((host,port)) 

while 1:
    data = s.recv(size)
    if not data: break
    print data
    time.sleep(1.0 / 1000.0 )

s.close() 
print 'Received:', data
