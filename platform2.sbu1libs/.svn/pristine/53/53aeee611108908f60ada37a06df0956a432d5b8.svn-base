#include <iostream>

#include "PushServer.h"

int main()
{

    IFSubscriptions ifSubscriptions;

    EventFax fax;

    PushServer * server = new PushServer(12001, 3600, PushServer::DataType_SBU2, 
            &fax, &ifSubscriptions);

    fax.addTCPServer(server);

    fax.run();
}

// g++ -I include test/test_push_server.cpp src/* -lubacipc++ -lubacdata++ -ljsonparser+
