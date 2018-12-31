#include "SessionTable.h"

SessionTable::SessionTable()
{
}

SessionTable::~SessionTable()
{
}

void SessionTable::addSession(string sSession, void *conn)
{
	removeSession(sSession);
	this->insert( make_pair(sSession, conn) );
}

void *SessionTable::getSession(string sSession)
{
	return (*this)[sSession];
}

void SessionTable::removeSession(string sSession)
{
	this->erase( sSession );
}
