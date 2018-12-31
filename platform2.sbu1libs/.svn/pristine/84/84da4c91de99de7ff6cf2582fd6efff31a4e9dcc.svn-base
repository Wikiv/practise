#include <iostream>

#include "TLSPushServer.h"

int main(int argc, char * argv[])
{

    IFSubscriptions ifSubscriptions;

    EventFax fax;

    TLSPushServer * server = new TLSPushServer(12001, 3600, PushServer::DataType_SBU2, 
            &fax, &ifSubscriptions, argv[1], argv[2]);

    fax.addTCPServer(server);

    fax.run();
}

// g++ -I include test/test_push_server.cpp src/* -lubacipc++ -lubacdata++ -ljsonparser+
