#include "UBACData.h"

BrokerLoginRequest::BrokerLoginRequest(string data) : string(data)
{
	parse(data);
}

BrokerLoginRequest::~BrokerLoginRequest()
{
}

void BrokerLoginRequest::parse(string data)
{
	size_t i, state = 0;
	IFHelper helper;
	string tmp_buffer = "";
	for(i = 0; i < data.length(); i++) {
		if(data[i] == '|') {
			if( state == 0 ) {
				username.append(tmp_buffer);
			} else if( state == 1) {
				password.append(tmp_buffer);
			} else if( state == 2) {
				memberid.append(tmp_buffer);
			} else {
				vector<string> splitList;
				helper.split(tmp_buffer, "=", splitList);
				otherParams.insert( make_pair( splitList[0] , splitList[1] ) );
			}
			state++;
			tmp_buffer.clear();
		} else {
			tmp_buffer.append(&data[i], 1);
		}
	}
	if ( ( state == 1 ) && ( password.length() == 0 ) ) {
		password.append(tmp_buffer);
	} else {
		secondFactor.append( tmp_buffer );
		if( tmp_buffer.find('=') != string::npos ) {
			vector<string> splitList;
        	        helper.split(tmp_buffer, "=", splitList);
                	otherParams.insert( make_pair( splitList[0] , splitList[1] ) );
		}
	}
}

string BrokerLoginRequest::getUsername()
{
	return username;
}

string BrokerLoginRequest::getPassword()
{
	return password;
}

string BrokerLoginRequest::getMemberid()
{
	return memberid;
}

string BrokerLoginRequest::getSecondFactor()
{
	return secondFactor;
}

string BrokerLoginRequest::getParam(string sKey)
{
	map<string, string>::iterator iOtherParams = otherParams.find(sKey);
	if(iOtherParams != otherParams.end())
		return iOtherParams->second;
	else
		return "";
}

string BrokerLoginRequest::toString()
{
	stringstream sLoginRequest;
	sLoginRequest << UBACData::Protocol_BROKER_LOGIN << " <" << (*this) << ">";
	return sLoginRequest.str();
}
