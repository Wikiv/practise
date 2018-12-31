#include "UBACData.h"

IndexResponse::IndexResponse()
{
}

IndexResponse::~IndexResponse()
{
}

void IndexResponse::addIndex(string mIndex)
{
	indexList.push_back( mIndex );
}

void IndexResponse::toString(string & response)
{
	stringstream responseStream;
	responseStream << "338 <";
	vector<string>::iterator i;
	for(i = indexList.begin(); i != indexList.end(); i++ ) {
		responseStream << (*i) << "|";
	}
	response.append( responseStream.str() );
	rstrip( response, '|' );
	response.append( ">" );
}
