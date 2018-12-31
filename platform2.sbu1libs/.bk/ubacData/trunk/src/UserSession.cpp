#include "UserSession.h"

UserSession::UserSession(string m_session)
{
	sessionID.append( m_session );
}

UserSession::~UserSession()
{
}

void UserSession::getAccountNumberFromAccountID(string accountID, string & accountNumber)
{
	vector<string>::iterator iAccountID = accountIDList.begin();
	vector<string>::iterator iAccountNumber = accountNumberList.begin();
	while(iAccountID != accountIDList.end()) {
		if( (*iAccountID).compare( accountID ) == 0 ) {
			accountNumber.append( (*iAccountNumber) );
			break;
		}
		iAccountID++;
		iAccountNumber++;
	}
}

void UserSession::setAllAccounts(vector<AccountDetails> allAccounts)
{
	vector<AccountDetails>::iterator i;
	for( i = allAccounts.begin(); i != allAccounts.end(); i++) {
		accountList.push_back( (*i) );
	}
}

AccountDetails & UserSession::getAccountDetails( string accountId )
{
	unsigned int place=0;
	string accId;
	vector<AccountDetails>::iterator i;
	for( i = accountList.begin(); i != accountList.end(); i++) {
		accId.append( (*i).getAccountID() );  
		cout << "place =" << place << " , accId =" << accId << "accountId = " << accountId <<  endl;
#ifdef _WIN32
		if ( _strcmpi( accId.c_str(), accountId.c_str() ) == 0 )
#else
		if ( strcasecmp( accId.c_str(), accountId.c_str() ) == 0 )
#endif
			break;
		place=place+1;
		accId.clear();
	}
	if ( place == accountList.size() )
		place=0;
	cout << "final place =" << place << endl;
	return accountList.at(place);
}

void UserSession::setDefaultAccountID(string m_accountID)
{
	defaultAccountID.append( m_accountID );
	setLinkedAccountID(m_accountID);
}

void UserSession::setLinkedAccountID(string m_accountID)
{
	accountIDList.push_back( m_accountID );
}

void UserSession::setDefaultAccountNumber(string m_accountNumber)
{
	defaultAccountNumber.append( m_accountNumber );
	setLinkedAccountNumber(m_accountNumber);
}

void UserSession::setLinkedAccountNumber(string m_accountNumber)
{
	accountNumberList.push_back( m_accountNumber );
}

void UserSession::setDisplayName(string m_displayName)
{
	displayName.append( m_displayName );
}

void UserSession::setUniqueID(string m_uniqueID)
{
	uniqueID.append( m_uniqueID );
}

string UserSession::getUniqueID()
{
	return uniqueID;
}

string UserSession::getDefaultAccountID()
{
	return defaultAccountID;
}

string UserSession::getDefaultAccountNumber()
{
	return defaultAccountNumber;
}

string UserSession::getSessionID()
{
	return sessionID;
}

string UserSession::getDisplayName()
{
	return displayName;
}

vector<string> UserSession::getAccountIDList()
{
	return accountIDList;
}

vector<string> UserSession::getAccountNumberList()
{
	return accountNumberList;
}
