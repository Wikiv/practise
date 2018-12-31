#include <iostream>
#include <vector>

#include "WebSocketPushServer.h"

#include <ubacipc/Thread.h>

#include <ubacutils/IFHelper.h>

#include <jsonparser/JsonParser.h>

using namespace std;
using namespace UBACIPC;

void * start_thread(void * data)
{

    IFHelper ifHelper;

    WebSocketPushServer * server 
        = static_cast<WebSocketPushServer *>(data);

    char * symbols[10] = { 
        "AUD/USD", "BUMI", "HADE", 
        "JKON", "KRAS", "MDRN", 
        "TRAM", "ZBRA", "PNSE", "PTBA"
    };  


    while (1)
    {

        int i = rand() % 1;

        JsonObject obj;

        obj["open"] = ifHelper.formatDouble(rand() % 100 , 2);

        obj["low"] = ifHelper.formatDouble(rand() % 100 , 2);
        obj["high"] = ifHelper.formatDouble(rand() % 100 , 2);
        obj["volume"] = ifHelper.formatDouble( rand() % 1000, 0);

        obj["last"] = ifHelper.formatDouble(rand() % 100 , 2);

        obj["change"] = ifHelper.formatDouble(rand() % 100 , 2);

        obj["changePercent"] = ifHelper.formatDouble(rand() % 100 , 2);
        obj["c"] = ifHelper.formatDouble(rand() % 100 , 2);

        obj["time"] = "14337";

        string symbol(symbols[i]);

        obj["symbol"] = symbol;

        //cout  << "Response " << obj.toString() << endl;

       // string s(76, 'a');
        string s(65486, 'a');

        JsonObject data;
        data["data"] = s;

        server->sendLevel1(symbol , & data);

        sleep (1);
    }

}


int main()
{
    IFSubscriptions ifSubscriptions;

    EventFax fax;

    WebSocketPushServer * server = new WebSocketPushServer(8443, 10000, &ifSubscriptions);
    server->setEventFax(& fax);

    server->setEventFax( & fax);
    fax.addTCPServer(server);

    pthread_t tid;
    pthread_create(&tid, NULL, start_thread, (void *)server);

    fax.run();
}

// 
// g++ -I include/ test/test_websocket_pushserver.cpp  src/* -l:libubacipc.so.1.2.5 -l:libubacjsonparser.so.1.2.2 -l:libubacutils.so.1.2.2
