#include "UBACData.h"

BrokerSwitchAccountResponse::BrokerSwitchAccountResponse()
{
}

void BrokerSwitchAccountResponse::addField(string sName, string sValue)
{
	this->insert( make_pair(sName, sValue) );
}

void BrokerSwitchAccountResponse::toString(string & sResponse)
{
	map<string, string>::iterator iNameValueMap;
	sResponse.append("442 <");

	// Temporary fix for OPX - to be removed
	if(sSession.length() > 0) {
		sResponse.append("SessionID=" + sSession + "|");
	}
	if(sSuccess.length() > 0) {
		sResponse.append("success=" + sSuccess + "|");
	}
	// Fix ends

	for( iNameValueMap = this->begin(); iNameValueMap != this->end(); iNameValueMap++ ) {
		sResponse.append( iNameValueMap->first );
		sResponse.append( "=" );
		sResponse.append( iNameValueMap->second );
		sResponse.append( "|" );
	}
	IFHelper helper;
	helper.rstrip(sResponse, '|');
	sResponse.append(">");
}

// Temporary fix for OPX - to be removed
void BrokerSwitchAccountResponse::setSession(string m_session)
{
	sSession = m_session;
}

void BrokerSwitchAccountResponse::setSuccess(string m_success)
{
	sSuccess = m_success;
}
