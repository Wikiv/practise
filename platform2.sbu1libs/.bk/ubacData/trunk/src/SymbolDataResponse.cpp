#include "UBACData.h"

SymbolDataResponse::SymbolDataResponse()
{
}

SymbolDataResponse::~SymbolDataResponse()
{
}

void SymbolDataResponse::addField(string name, string value)
{
	nameValuePair[name] = value;
}

void SymbolDataResponse::toString(string & response)
{
	if( !status ) {
		response.append("612 <");
		response.append( errorMessage );
		response.append(">");
		return;
	}
	response.append("304 <");
	map<string, string>::iterator i;
	for(i = nameValuePair.begin(); i != nameValuePair.end(); i++) {
		response.append(i->first);
		response.append("=");
		response.append(i->second);
		response.append("|");
	}
	if(response[response.length() - 1] == '|') {
		string::iterator i = response.end();
		i--;
		response.erase(i);
	}
	response.append(">");
}

void SymbolDataResponse::setStatus(bool flag)
{
	status = flag;
}

bool SymbolDataResponse::getStatus()
{
	return status;
}

void SymbolDataResponse::setError(string error)
{
	errorMessage.append(error);
}

void SymbolDataResponse::getField(string name, string & value)
{
	map<string, string>::iterator i = nameValuePair.find(name);
	if(i != nameValuePair.end())
		value.append(i->second);
}
