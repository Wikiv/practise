#include "UBACData.h"

SymbolSearchRequest::SymbolSearchRequest(string request) : string(request)
{
	parse( request );
}

SymbolSearchRequest::~SymbolSearchRequest()
{
}

void SymbolSearchRequest::parse( string request )
{
	string name, tmpBuffer;
	for ( size_t i = 0; i<request.length(); i++ ) {
		if ( ( request[i] == '|' ) || ( request.length() == i+1 ) ) {
			if ( request.length() == i+1 )
				tmpBuffer.append(&request[i],1);
			setValues( name, tmpBuffer );
			name.clear();
			tmpBuffer.clear();
		} else if ( request[i] == '=' ) {
			name.append( tmpBuffer );
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&request[i],1);
		}
	}
}

void SymbolSearchRequest::setValues( string name, string value )
{
	if ( strcasecmp( name.c_str() , "SEARCH" ) == 0 ) {
		searchString.append( value );
	} else if ( strcasecmp( name.c_str() , "EXCHANGE" ) == 0 ) {
		exchange.append( value );
	} else if ( strcasecmp( name.c_str() , "ASSETTYPE" ) == 0 ) {
		assetType.append( value );
	} else if ( strcasecmp( name.c_str() , "LIMIT" ) == 0 ) {
		limit.append( value );
	} else if ( strcasecmp( name.c_str() , "STRIKEPRICE" ) == 0 ) {
		strikePrice.append( value );
	} else if ( strcasecmp( name.c_str() , "OPTIONTYPE" ) == 0 ) {
		optionType.append( value );
	} else if ( strcasecmp( name.c_str() , "EXPIRY" ) == 0 ) {
		expiry.append( value );
	} else {
		otherParams.insert( make_pair( name , value ) );
	}
}

string SymbolSearchRequest::getSearchString()
{
	return searchString;
}

string SymbolSearchRequest::getExchange()
{
	return exchange;
}

string SymbolSearchRequest::getAssetType()
{
	return assetType;
}

string SymbolSearchRequest::getLimit()
{
	return limit;
}

string SymbolSearchRequest::getStrikePrice()
{
	return strikePrice;
}

string SymbolSearchRequest::getOptionType()
{
	return optionType;
}

string SymbolSearchRequest::getExpiry()
{
	return expiry;
}

string SymbolSearchRequest::getOtherParams( string name )
{
	string value;
	map<string, string>::iterator iOtherParams;
	for( iOtherParams = otherParams.begin(); iOtherParams != otherParams.end(); iOtherParams++ ) {
		string nameInReq( iOtherParams->first );
		if ( strcasecmp( nameInReq.c_str(), name.c_str() ) == 0 ) {
			value.append( iOtherParams->second );
			break;
		}
	}
	return value;
}

string SymbolSearchRequest::toString()
{
	string s("372 <");
	s = s + (*this) + ">";
	return s;
}
