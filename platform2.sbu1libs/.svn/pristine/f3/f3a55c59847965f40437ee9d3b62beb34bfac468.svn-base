#include "ExtMod.h"

ExtMod::ExtMod(string data) : string(data)
{
	parse(data);
}
ExtMod::ExtMod()
{
}

ExtMod::~ExtMod()
{
	name_value_pair.clear();
}

bool ExtMod::hasKeyIgnoreCase(string sKey)
{
	map<string, string>::iterator iName;
	for(iName = name_value_pair.begin(); iName != name_value_pair.end(); iName++) {
		if( strcasecmp(sKey.c_str(), iName->first.c_str()) == 0 )
			return true;
	}
	return false;
}

void ExtMod::toString(string & response)
{
	response.append("##");
	response.append( (*this) );
	response.append("##");
}

void ExtMod::addAnotherExtModtoThis( string data )
{
	string name = "", value = "";
	int state = 0;
	size_t i = 0;
	for(;i < data.length(); i++) {
		if(data[i] == ',') {
			setValue( name, value );
			name.clear(); value.clear();
			state = 0;
		} else if(data[i] == '=') {
			state++;
		} else {
			if(state == 0)
				name.append(&data[i], 1);
			else
				value.append(&data[i], 1);
		}
	}
	if(name.length() > 0)
		setValue( name, value );
	name.clear();value.clear();
}

void ExtMod::make()
{
	this->clear();
	map<string, string>::iterator iNameValue;
	stringstream extModStream;
	for( iNameValue = name_value_pair.begin(); iNameValue != name_value_pair.end(); iNameValue++ )
		extModStream << iNameValue->first << "=" << iNameValue->second << ",";
	this->append( extModStream.str() );
	rstrip( (*this), ',' );
}

bool ExtMod::deleteValue(string name)
{
	map<string, string>::iterator i = name_value_pair.find( name );
	if( i != name_value_pair.end() ) {
		name_value_pair.erase( i );
		make();
		return true;
	} else {
		return false;
	}
}
void ExtMod::setValue(string name, double value)
{
	stringstream value_stream;
	value_stream << value;
	setValue(name,value_stream.str());
}

void ExtMod::setValue(string name, string value)
{
	deleteValue( name );
	name_value_pair.insert( make_pair(name, value) );
	make();
}

void ExtMod::getValue(string name, string &value, bool bIgnoreCase)
{
	map<string, string>::iterator i;
	for(i = name_value_pair.begin(); i != name_value_pair.end(); i++) {
		if( bIgnoreCase ) {
			if(strcasecmp(i->first.c_str(), name.c_str()) == 0) {
				value.append(i->second);
				break;
			}
		} else {
			if(strcmp(i->first.c_str(), name.c_str()) == 0) {
				value.append(i->second);
				break;
			}
		}
	}
}

void ExtMod::print_all()
{
	map<string, string>::iterator i;
	if(name_value_pair.size() == 0) return;
	for(i = name_value_pair.begin(); i != name_value_pair.end(); i++) {
		printf("Name = %s, Value = %s\n", i->first.c_str(), i->second.c_str());
	}
}

void ExtMod::parse(string data)
{
	string name = "", value = "";
	int state = 0;
	size_t i = 0;
	for(;i < data.length(); i++) {
		if(data[i] == ',') {
			name_value_pair.insert( make_pair(name, value) );
			name.clear(); value.clear();
			state = 0;
		} else if(data[i] == '=') {
			state++;
		} else {
			if(state == 0)
				name.append(&data[i], 1);
			else
				value.append(&data[i], 1);
		}
	}
	if(name.length() > 0) {
		name_value_pair.insert( make_pair(name, value) );
	}
	name.clear();value.clear();
}

ExtMod ExtMod::operator+(ExtMod extMod)
{
	map<string, string>::iterator i;
	if(name_value_pair.size() == 0) return extMod;
	for(i = name_value_pair.begin(); i != name_value_pair.end(); i++) {
		extMod.setValue(i->first, i->second);
	}
	return extMod;
}

map<string, string> ExtMod::getAllKeyValues()
{
	return name_value_pair;
}
