#include "UBACData.h"

OPXDragonResponseParam::OPXDragonResponseParam()
{
}

OPXDragonResponseParam::~OPXDragonResponseParam()
{
}

void OPXDragonResponseParam::addParam(string param)
{
	parameters.push_back(param);
}

void OPXDragonResponseParam::toString(string & response)
{
	vector<string>::iterator i;
	response.append("464 <");
	for(i = parameters.begin(); i != parameters.end(); i++) {
		response.append( (*i) );
		response.append("|");
	}
	if(response[response.length() - 1] == '|') {
		string::iterator j = response.end();
		j--;
		response.erase( j );
	}
	response.append(">");
}
