#include "UBACData.h"

GainerLoserVolumeRequest::GainerLoserVolumeRequest(string sRequest) : string(sRequest)
{
	parse(sRequest);
}

string GainerLoserVolumeRequest::getExchange()
{
	return sExchange;
}

string GainerLoserVolumeRequest::getCountryCode()
{
	return sCountryCode;
}

string GainerLoserVolumeRequest::getSymbol()
{
	return sSymbol;
}

string GainerLoserVolumeRequest::getRequestType()
{
	return sRequestType;
}

string GainerLoserVolumeRequest::getParam(string sKey)
{
	upcase(sKey);
	map<string, string>::iterator iParam = otherParams.find( sKey );
	if(iParam == otherParams.end())
		return "";
	else
		return iParam->second;
}

void GainerLoserVolumeRequest::parse(string sRequest)
{
	int state = 0;
	string sBuffer, sName;
	for(size_t i = 0; i < sRequest.length(); i++) {
		if( sRequest[i] == '|' ) {
			if( state == 0 ) {
				sCountryCode.append( sBuffer );
			} else {
				setOtherParam(sName, sBuffer);
			}
			sName.clear(); sBuffer.clear();
			state++;
		} else if( sRequest[i] == '=' ) {
			sName.append( sBuffer );
			sBuffer.clear();
		} else {
			sBuffer.append(&sRequest[i], 1);
		}
	}
	if( state == 0 ) {
		sCountryCode.append( sBuffer );
	} else {
		setOtherParam(sName, sBuffer);
	}
}

void GainerLoserVolumeRequest::setOtherParam(string sName, string sValue)
{
	cout << "Name = " << sName << ", Exchange = " << sValue << endl;
	if( strcasecmp(sName.c_str(), "type") == 0 ) {
		sRequestType.append( sValue );
	} else if( strcasecmp(sName.c_str(), "symbol") == 0 ) {
		sSymbol.append( sValue );
	} else if( strcasecmp(sName.c_str(), "exchange") == 0 ) {
		sExchange.append( sValue );
	} else {
		upcase(sName);
		otherParams.insert( make_pair(sName, sValue) );
	}
}

string GainerLoserVolumeRequest::toString()
{
	stringstream sRequest;
	sRequest << UBACData::Protocol_GAINER_LOSER_VOLUME << " <" << (*this) << ">";
	return sRequest.str();
}
