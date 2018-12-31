#include "UBACData.h"

IntradayDataRequest::IntradayDataRequest(string request)
{
	parse( request );
}

IntradayDataRequest::~IntradayDataRequest()
{
}

string IntradayDataRequest::getSymbol()
{
	return symbol;
}

string IntradayDataRequest::getStringResolution()
{
	return strResolution;
}

int IntradayDataRequest::getResolution()
{
	return resolution;
}

void IntradayDataRequest::parse(string request)
{
	bool isSymbol = true;
	string tmpBuffer;
	for(size_t i = 0; i < request.length(); i++) {
		if( request[i] == '|' ) {
			isSymbol = false;
		} else {
			(isSymbol) ? symbol.append(&request[i], 1) : tmpBuffer.append(&request[i], 1);
		}
	}
	if ( tmpBuffer.length() > 0 ) {
		strResolution = tmpBuffer;
		resolution = atoi( tmpBuffer.c_str() );
	}
}

void IntradayDataRequest::getRequest( string & mRequest )
{
	mRequest.append( "390 <" );
	mRequest.append( symbol );
	if ( strResolution.length() > 0 ) {
		mRequest.append( "|" );
		mRequest.append( strResolution );
	}
	mRequest.append( ">" );
}

