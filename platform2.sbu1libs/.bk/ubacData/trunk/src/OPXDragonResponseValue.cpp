#include "UBACData.h"

OPXDragonResponseValue::OPXDragonResponseValue()
{
}

OPXDragonResponseValue::~OPXDragonResponseValue()
{
}

void OPXDragonResponseValue::addDetail(string xmlKey, string name, string value)
{
	map<string, vector<string> >::iterator i = dragonDetails.find( name );
	//IFHelper helper;
	//helper.gsubSpecialCharacters(value);
	if( i == dragonDetails.end() ) {
		xmlKeyPair.insert( make_pair(xmlKey, name) );
		dragonDetails[name].push_back( value );
	} else {

		i->second.push_back( value );
	}
}

void OPXDragonResponseValue::validate()
{
	size_t maxLength = 0;
	map<string, vector<string> >::iterator i;
	for(i = dragonDetails.begin(); i != dragonDetails.end();i++)
		maxLength = (maxLength > i->second.size()) ? maxLength : i->second.size();
	for(i = dragonDetails.begin(); i != dragonDetails.end();i++) {
		size_t count = i->second.size();
		if( count != maxLength )
			cout << "Filling header: " << i->first << ", count = " << count << ", maxLength = " << maxLength <<  endl;
		while(count < maxLength) {
			string s("");
			i->second.push_back(s);
			count++;
		}
	}
}

void OPXDragonResponseValue::toString(string &response, vector<string>keyOrder)
{
	vector<string>::iterator iOrder, iEntry, iResponseEntry;
	map<string, string>::iterator iXmlKeyPair;
	map<string, vector<string> >::iterator iDragon;
	vector<string>entries;
	size_t maxLength = 0, count;
	for(iDragon = dragonDetails.begin(); iDragon != dragonDetails.end();iDragon++)
		maxLength = (maxLength > iDragon->second.size()) ? maxLength : iDragon->second.size();
	for(count = 0; count <= maxLength; count++) {
		string s("");
		entries.push_back( s );
	}
	for(iOrder = keyOrder.begin(); iOrder != keyOrder.end(); ) {
		iXmlKeyPair = xmlKeyPair.find( (*iOrder) );
		if( iXmlKeyPair != xmlKeyPair.end() ) {
			iDragon = dragonDetails.find( iXmlKeyPair->second );
			if(iDragon != dragonDetails.end()) {
				iResponseEntry = entries.begin();
				(*iResponseEntry).append( iDragon->first );
				(*iResponseEntry).append( "," );
				iResponseEntry++;
				for(iEntry = iDragon->second.begin(); iEntry != iDragon->second.end(); iResponseEntry++, iEntry++) {
					(*iResponseEntry).append( (*iEntry) );
					(*iResponseEntry).append( "," );
				}
				dragonDetails.erase( iDragon );
				keyOrder.erase(iOrder);
			} else {
				iOrder++;
				if( iOrder == keyOrder.end() ) break;
			}
		} else {
			iOrder++;
			if( iOrder == keyOrder.end() ) break;
		}
		if(keyOrder.size() == 0) break;
	}
	for(iDragon = dragonDetails.begin(); iDragon != dragonDetails.end(); iDragon++) {
		iResponseEntry = entries.begin();
		(*iResponseEntry).append( iDragon->first );
		(*iResponseEntry).append( "," );
		iResponseEntry++;
		for(iEntry = iDragon->second.begin(); iEntry != iDragon->second.end(); iResponseEntry++, iEntry++) {
			(*iResponseEntry).append( (*iEntry) );
			(*iResponseEntry).append( "," );
		}
	}
	response.append("468 <");
	for(iEntry = entries.begin(); iEntry != entries.end(); iEntry++) {
		response.append( (*iEntry) );
		if(response[response.length() - 1] == ',')
			response[response.length() - 1] = '|';
	}
	if(response[response.length() - 1] == '|') {
		string::iterator j = response.end();
		j--;
		response.erase( j );
	}
	response.append(">");
}
