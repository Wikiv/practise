#include <iostream>
#include "PushServer.h"

int main()
{

	IFSubscriptions ifSubscriptions;

	EventFax fax;

	PushServer * server = new PushServer(11001, 3600,
		&ifSubscriptions);

	fax.addTCPServer(server);

	fax.run();
}

