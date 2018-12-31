#include "UBACData.h"

NewsRequest::NewsRequest(string request)
{
	parse( request );
}

NewsRequest::~NewsRequest()
{
}

void NewsRequest::getSymbol( vector<string> & mSymbolList )
{
	mSymbolList.assign( symbolList.begin(), symbolList.end() );
}

string NewsRequest::getSymbolList()
{
	string symbollist;
	vector<string>::iterator it;
	for ( it=symbolList.begin() ; it < symbolList.end(); it++ ) {
		symbollist.append( *it );
		symbollist.append( "," );
	}
	rstrip(symbollist, ',');
	return symbollist;
}

void NewsRequest::getOutputFormat( vector<string> & mOutputString )
{
	mOutputString.assign( outputString.begin(), outputString.end() );
}

string NewsRequest::getCountryCode()
{
	return cc;
}

string NewsRequest::getID()
{
	return id;
}

string NewsRequest::getCategory()
{
	return category;
}

bool NewsRequest::isMarketNews()
{
	//if( strcasecmp(symbol.c_str(), "MARKET") == 0 ) return true;
	//if ( symbolList.size() == 0 ) return true;
	if ( ( symbolList.size() == 0 ) && ( !isFullNews() ) ) return true;
	return false;
}

bool NewsRequest::isFullNews()
{
	if ( id.length() > 0 ) return true;
	return false;
}

string NewsRequest::getParam(string sKey)
{
	map<string, string>::iterator iParam = otherParams.find( sKey );
	if(iParam == otherParams.end())
		return "";
	else
		return iParam->second;
}

void NewsRequest::setValuesWithNameInPair(string nameVal, string tmpBuffer)
{
	if ( strcasecmp(nameVal.c_str(), "symbol" ) == 0 ) {
		symbolList.push_back(tmpBuffer);
	} else if ( strcasecmp(nameVal.c_str(), "country" ) == 0 ) {
		cc.append(tmpBuffer);
	} else if ( strcasecmp(nameVal.c_str(), "id" ) == 0 ) {
		id.append(tmpBuffer);
	} else if ( strcasecmp(nameVal.c_str(), "category" ) == 0 ) {
		category.append(tmpBuffer);
	} else {
		upcase( nameVal );
		otherParams.insert( make_pair( nameVal, tmpBuffer) );
	}

}

void NewsRequest::addOutputParam( string outputParam )
{
	outputString.push_back( outputParam );
}

void NewsRequest::parse(string data)
{
	size_t i = 0;
	string type= "", tmpBuffer = "", nameVal= "";
	for( ; i < data.length(); i++) {
		if(data[i] == ':') {
			if ( strcasecmp(type.c_str(), "filter" ) == 0 ) {
				nameVal.append( tmpBuffer );
			} else if ( strcasecmp(type.c_str(), "output" ) == 0 ) {
				addOutputParam( tmpBuffer );
			}
			tmpBuffer.clear();
		} else if ( data[i] == ';') {
			setValuesWithNameInPair( nameVal, tmpBuffer );
			nameVal.clear();
			tmpBuffer.clear();
		} else if ( data[i] == '|') {
			if ( strcasecmp(type.c_str(), "filter" ) == 0 ) {
				setValuesWithNameInPair( nameVal, tmpBuffer);
			} else if ( strcasecmp(type.c_str(), "output" ) == 0 ) {
				addOutputParam( tmpBuffer );
			}
			type.clear();
			nameVal.clear();
			tmpBuffer.clear();
		} else if ( data[i] == '=') {
			type.append(tmpBuffer);			
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&data[i], 1);
		}
	}
	if ( i == data.length() ) {
		if ( strcasecmp(type.c_str(), "filter" ) == 0 ) {
			setValuesWithNameInPair( nameVal, tmpBuffer);
		} else if ( strcasecmp(type.c_str(), "output" ) == 0 ) {
			addOutputParam( tmpBuffer );
		}
	}
}

