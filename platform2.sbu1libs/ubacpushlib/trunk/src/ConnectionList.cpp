#include "ConnectionList.h"

ConnectionList::ConnectionList()
{
}

ConnectionList::~ConnectionList()
{
}

void ConnectionList::addConn(void * conn)
{
	if ( std::find(begin(), end(), conn) == end() ) {
		push_back(conn);
	}
}

void ConnectionList::removeConn(void * conn)
{
	erase(std::remove(begin(), end(), conn), end());
}
