#include "UBACData.h"

BrokerOptionsChainRequest::BrokerOptionsChainRequest(string data, int i_protocolCode)
{
	protocolCode = i_protocolCode;
	//symbol.append( data );
	parse(data);
}

BrokerOptionsChainRequest::~BrokerOptionsChainRequest()
{
}

int BrokerOptionsChainRequest::getProtocolCode()
{
	return protocolCode;
}

string BrokerOptionsChainRequest::getSymbol()
{
	return symbol;
}

string BrokerOptionsChainRequest::getParam(string sKey)
{
	IFHelper helper;
	helper.upcase(sKey);
	map<string, string>::iterator iParam = otherParams.find( sKey );
	if(iParam == otherParams.end())
		return "";
	else
		return iParam->second;
}

string BrokerOptionsChainRequest::getChainType()
{
	return chainType;
}

void BrokerOptionsChainRequest::parse(string data)
{
	int state = 0;
	string name, buffer;
	for(size_t i = 0; i < data.length(); i++) {
		if(data[i] == '=') {
			name.append(buffer);
			buffer.clear();
		} else if(data[i] == '|') {
			if(state == 0)
				symbol.append(buffer);
			else {
				setOtherParam(name, buffer);
				name.clear();
			}
			state++;
			buffer.clear();
		} else {
			buffer.append(&data[i], 1);
		}
	}
	if(state == 0)
		symbol.append(buffer);
	else
		setOtherParam(name, buffer);
}

void BrokerOptionsChainRequest::setOtherParam(string sName, string sValue)
{
	IFHelper helper;
	cout << "Name = " << sName << ", Exchange = " << sValue << endl;
	if( strcasecmp(sName.c_str(), "type") == 0 ) {
		chainType.append( sValue );
	} else {
		helper.upcase(sName);
		otherParams.insert( make_pair(sName, sValue) );
	}
}
