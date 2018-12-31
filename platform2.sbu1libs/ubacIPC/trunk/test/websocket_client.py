#!/usr/bin/python

# sudo pip install websocket-client
# sudo apt-get install python-pip

import websocket
import thread
import time
import random

MAX_CONNECTION = 1
    
def on_message(ws, message):
    print message

def on_error(ws, error):
    print error;

def on_close(ws):
    #pass
    print "### closed ###"

def on_open(ws):
    print "## Open ##"
    #ws.send('{"request":{"streaming_type":"liveTrades","request_type":"subscribe","response_format":"json","session":"__session__"}}\n')
    ws.send('{"request":{"streaming_type":"quote","request_type":"subscribe","response_format":"json","session":"CB704C10E5B84DDAAD0FA5763297FD20","data":{"symbols":[{"symbol":"ESM16"},{"symbol":"CNY/IDR"}]}}}\n')


def createWebSocket():
    #websocket.enableTrace(True)
    
    #ws = websocket.WebSocketApp("ws://127.0.0.1:8443/",
    #                            on_message = on_message,
    #                            on_error = on_error,
    #                            on_close = on_close)
    ws = websocket.WebSocketApp("ws://nsewow-uat.marketsimplified.com:8443/",
                                on_message = on_message,
                                on_error = on_error,
                                on_close = on_close)
    
    ws.on_open = on_open
    return ws;

def task(ws):
    ws.run_forever();


def startNWebSockets(N, wsConnections):
    for i in range(0, N):
        ws = createWebSocket()
        wsConnections.append(ws)
        thread.start_new_thread( task, (ws, ))
    
if __name__ == "__main__":
    #createWebSocket()
    wsConnections = []
    startNWebSockets(MAX_CONNECTION, wsConnections)
    
    while 1:
        #RANDOM_CLOSE_CONNECTION = random.randint(1, MAX_CONNECTION)
        #n = 0;
        #for ws in wsConnections:
        #    if n < RANDOM_CLOSE_CONNECTION:
        #        ws.close()
        #        wsConnections.pop(n)
        #        n = n + 1
        
        #startNWebSockets(RANDOM_CLOSE_CONNECTION, wsConnections)
        
        time.sleep(5)
        
