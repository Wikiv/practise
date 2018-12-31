#include "UBACData.h"

const char Portfolio::entry_delimiter = ',';

Portfolio::Portfolio()
{
}

Portfolio::~Portfolio()
{
}

string Portfolio::getDataField( string mName )
{
	map<string,string>::iterator i = fieldMap.find( mName );
	if ( i != fieldMap.end() )
		return i->second;
	return "";
}

void Portfolio::setOtherParams( string sName, string sValue )
{
	if(this->length() > 0)
		this->append(&this->entry_delimiter, 1);
	stringstream reform;
	reform << sName << "=" << sValue;
	(*this).append(reform.str());
	fieldMap[sName] = sValue;
}
