#include <iostream>

#include "TLSPushServer.h"

int main(int argc, char * argv[])
{

	IFSubscriptions ifSubscriptions;

	EventFax fax;

	TLSPushServer * server = new TLSPushServer(12001, 3600,
			&fax, &ifSubscriptions, argv[1], argv[2]);

	fax.addTCPServer(server);

	fax.run();
}

// g++ -I include/ test/test_tls.cpp src/* -l:libubacipc.so.1.2.1 -l:libubacjsonparser.so.1.2.0 -l:libubacutils.so.1.2.1
