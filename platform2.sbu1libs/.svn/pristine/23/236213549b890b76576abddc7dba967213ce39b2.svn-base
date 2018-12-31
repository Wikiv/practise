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
//    printSessionTable("addSession");
}

void *SessionTable::getSession(string sSession)
{
	map<string, void *>::iterator iConn = this->find(sSession);

	if( iConn == this->end() )
		return NULL;

	return iConn->second;
}

void SessionTable::removeSession(string sSession)
{
	this->erase( sSession );
//    printSessionTable("removeSession");
}

void SessionTable::printSessionTable(string sAction)
{
	map<string, void*>::iterator itr = this->begin();

	while(itr != this->end()) {
		itr++;
	}
}
