#include "UBACData.h"

PortfolioGroupListActionRequest::PortfolioGroupListActionRequest(string data)
{
	parse( data );
}

PortfolioGroupListActionRequest::~PortfolioGroupListActionRequest()
{
}

void PortfolioGroupListActionRequest::parse( string request )
{
	int state = 0;
	string name, tmpBuffer;
	for ( size_t i = 0; i<request.length(); i++ ) {
		if ( ( request[i] == '|' ) || ( request.length() == i+1 ) ) {
			if ( request.length() == i+1 )
				tmpBuffer.append(&request[i],1);
			if ( state == 0 ) {
				action.append( tmpBuffer );
			} else {
				setValues( name, tmpBuffer );
			}
			name.clear();
			tmpBuffer.clear();
			state++;
		} else if ( request[i] == '=' ) {
			name.append( tmpBuffer );
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&request[i],1);
		}
	}
}

void PortfolioGroupListActionRequest::setValues( string name, string value )
{
	if ( strcasecmp( name.c_str() , "ACCOUNTID" ) == 0 ) {
		accountID.append( value );
	} else if ( strcasecmp( name.c_str() , "USERID" ) == 0 ) {
		userID.append( value );
	} else if ( strcasecmp( name.c_str() , "GROUPNAME" ) == 0 ) {
		groupName.append( value );
	} else if ( strcasecmp( name.c_str() , "GROUPID" ) == 0 ) {
		groupID.append( value );
	} else if ( strcasecmp( name.c_str() , "GROUPNEWNAME" ) == 0 ) {
		groupNewName.append( value );
	} else if ( strcasecmp( name.c_str() , "PORTFOLIOID" ) == 0 ) {
		portfolioID.append( value );
	} else if ( strcasecmp( name.c_str() , "INDEX" ) == 0 ) {
		index.append( value );
	} else if ( strcasecmp( name.c_str() , "SYMBOLS" ) == 0 ) {
		symbolStr.append( value );
		setSymbolToVector( value );
	}
}

void PortfolioGroupListActionRequest::setSymbolToVector( string mSymbol )
{
	string tempSymbol;
	for(size_t i = 0; i < mSymbol.length(); i++) {
		if ( mSymbol[i] == ',' ) {
			symbols.push_back( tempSymbol );
			tempSymbol.clear();
		} else {
			tempSymbol.append( &mSymbol[i], 1 );
		}
	}

	if ( tempSymbol.length() > 0 )
		symbols.push_back( tempSymbol );
}
			
void PortfolioGroupListActionRequest::getSymbolVector( vector<string> & mSymbols )
{
	mSymbols.assign( symbols.begin(), symbols.end() );
}

string PortfolioGroupListActionRequest::getSymbolStr()
{
	return symbolStr;
}

string PortfolioGroupListActionRequest::getAccountID()
{
	return accountID;
}

string PortfolioGroupListActionRequest::getUserID()
{
	return userID;
}

string PortfolioGroupListActionRequest::getAction()
{
	return action;
}

string PortfolioGroupListActionRequest::getGroupID()
{
	return groupID;
}

string PortfolioGroupListActionRequest::getGroupName()
{
	return groupName;
}

string PortfolioGroupListActionRequest::getGroupNewName()
{
	return groupNewName;
}

string PortfolioGroupListActionRequest::getPortfolioID()
{
	return portfolioID;
}

string PortfolioGroupListActionRequest::getIndex()
{
	return index;
}
