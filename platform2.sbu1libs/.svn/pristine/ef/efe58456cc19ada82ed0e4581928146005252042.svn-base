#include "UBACData.h"

BrokerInitializationRequest::BrokerInitializationRequest(string data) : string(data)
{
	parse(data);
}

BrokerInitializationRequest::~BrokerInitializationRequest()
{
}

void BrokerInitializationRequest::parse(string data)
{
	size_t i, state = 0;
	IFHelper helper;
	string tmp_buffer = "";
	for(i = 0; i < data.length(); i++) {
		if(data[i] == '|') {
			vector<string> splitList;
			helper.split(tmp_buffer, "=", splitList);
			if( splitList.size() == 1 )
				splitList.push_back("");
			string sKey = splitList[0];
	                helper.upcase(sKey);
			otherParams.insert( make_pair( sKey, splitList[1] ) );
			state++;
			tmp_buffer.clear();
		} else {
			tmp_buffer.append(&data[i], 1);
		}
	}
	if( tmp_buffer.find('=') != string::npos ) {
		vector<string> splitList;
        	helper.split(tmp_buffer, "=", splitList);
		string sKey = splitList[0];
		helper.upcase(sKey);
               	otherParams.insert( make_pair( sKey, splitList[1] ) );
	}
}


string BrokerInitializationRequest::getParam(string sKey)
{
	map<string, string>::iterator iOtherParams = otherParams.find(sKey);
	if(iOtherParams != otherParams.end())
		return iOtherParams->second;
	else
		return "";
}

string BrokerInitializationRequest::toString()
{
	stringstream sInitializationRequest;
	sInitializationRequest << UBACData::Protocol_BROKER_INITIALIZATION << " <" << (*this) << ">";
	return sInitializationRequest.str();
}
