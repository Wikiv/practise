#include "UBACData.h"

BrokerLoginResponse::BrokerLoginResponse()
{
}

BrokerLoginResponse::BrokerLoginResponse(string data)
{
	parse(data);
}

BrokerLoginResponse::~BrokerLoginResponse()
{
}

void BrokerLoginResponse::setSessionID(string m_sessionID)
{
	CONVERT_TO_STRING( m_sessionID, sessionID );
}

string BrokerLoginResponse::getSessionID()
{
	return sessionID;
}

void BrokerLoginResponse::parse(string data)
{
	string tmpBuffer;
	int state = 0;
	size_t i;
	
        if (data.find("FAIL") != string::npos){
                this->setLoginStatus(false);
        } else if (data.find("OK") != string::npos) {
                this->setLoginStatus(true);
        }

	for(i = 0 ;i < data.length(); i++) {
		if(data[i] == '|') {
			if(state == 1) 
				sessionID.append(tmpBuffer);
			tmpBuffer.clear();
			state++;
		} else if(data[i] == '&') {
			AccountDetails account( tmpBuffer );
			addAccount( account );
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&data[i], 1);
		}
	}
	AccountDetails account( tmpBuffer );
	addAccount( account );
}

void BrokerLoginResponse::getDefaultAccount(string & accountId)
{
	vector<AccountDetails>::iterator i = accountList.begin();
	if(i != accountList.end()) {
		accountId.append( (*i).getAccountID() );
	}
}

void BrokerLoginResponse::getAllAccounts(vector<AccountDetails> & allAccounts)
{
	vector<AccountDetails>::iterator i;
	for( i = accountList.begin(); i != accountList.end(); i++) {
		allAccounts.push_back( (*i) );
	}
}

void BrokerLoginResponse::setLoginStatus(bool flag)
{
	loginStatus = flag;
}

bool BrokerLoginResponse::getLoginStatus()
{
	return loginStatus;
}

void BrokerLoginResponse::toString(string & response)
{
	if(!loginStatus) {
		response.append("436 <FAIL");
		if( errorMsg.length() > 0 ) {
			response.append( "|" );
			response.append(errorMsg);
		}
		response.append(">");
		return;
	}
	vector<AccountDetails>::iterator i;
	response.append("436 <OK|");
	response.append(sessionID);
	response.append("|");
	for(i = accountList.begin(); i != accountList.end(); i++) {
		(*i).toString( response );
		response.append("&");
	}
	if( (response[response.length() - 1] == '&') || (response[response.length() - 1] == ',') )
		response[response.length() - 1] = '>';
}

void BrokerLoginResponse::addAccount(AccountDetails details)
{
	accountList.push_back( details );
}

int BrokerLoginResponse::getNoOfAccounts()
{
	return accountList.size();
}

bool BrokerLoginResponse::checkPrimaryKey( string & accountid )
{
	bool flag = false;
	int j=0;
	vector<AccountDetails>::iterator i;
	for( i = accountList.begin(); i != accountList.end(); i++) {
		if ( j == 0 ) {
			if ( (*i).getPrimaryValue() ) {
				flag = true;
				break;
			}
		} else {
			if ( (*i).getPrimaryValue() )
				accountid.append( (*i).getAccountNumber() );
		}
		j++;
	}
	return flag;
}

void BrokerLoginResponse::reorderAccountDetails()
{
	vector<AccountDetails>::iterator i;
	for( i = accountList.begin(); i != accountList.end(); i++) {
		if ( (*i).getPrimaryValue() ) {
			AccountDetails accDet = ( AccountDetails ) *i;
			accountList.erase( i );
			accountList.insert( accountList.begin(), accDet );
			break;
		}
	}
}

AccountDetails & BrokerLoginResponse::getDefaultAccount()
{
	vector<AccountDetails>::iterator i = accountList.begin();
	return (*i);
}

void BrokerLoginResponse::resetDefaultAccountValue(string accountId, string name, string value)
{
	string accId;
	vector<AccountDetails>::iterator i;
	for( i = accountList.begin(); i != accountList.end(); i++) {
		accId.append( (*i).getAccountID() );
		if (strcasecmp( accId.c_str(), accountId.c_str())==0)
			(*i).resetValue( name, value);
		accId.clear();
	}
}

