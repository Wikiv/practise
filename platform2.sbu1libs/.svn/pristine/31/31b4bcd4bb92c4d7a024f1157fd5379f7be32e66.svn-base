#include "UserSessionManager.h"

UserSessionManager::UserSessionManager()
{
}

UserSessionManager::~UserSessionManager()
{
}

void UserSessionManager::createSession(string username, string sessionID)
{
	lock();
	map<string, string>::iterator iSessionToUserMap = sessionToUserMap.find( username );
	if( iSessionToUserMap != sessionToUserMap.end() ) {
		map<string, UserSession>::iterator iUserSession = this->find( iSessionToUserMap->second );
		if( iUserSession != this->end() )
			this->erase( iUserSession );
		sessionToUserMap.erase( iSessionToUserMap );
		sessionToUserMap.insert( make_pair(username, sessionID) );
	}
	UserSession userSessionData( sessionID );
	this->insert( make_pair(sessionID, userSessionData) );
	unlock();
}

void UserSessionManager::deleteSession(string sessionID)
{
	lock();
	map<string, UserSession>::iterator iUserSession = this->find( sessionID );
	if( iUserSession != this->end() )
		this->erase( iUserSession );
	unlock();
}

bool UserSessionManager::hasUserSession(string sessionID)
{
	map<string, UserSession>::iterator iUserSession = this->find( sessionID );
	return ( iUserSession != this->end() );
}

UserSession * UserSessionManager::getUserSession(string sessionID)
{
	map<string, UserSession>::iterator iUserSession = this->find( sessionID );
	if( iUserSession != this->end() )
		return &iUserSession->second;
	else
		return NULL;
}
