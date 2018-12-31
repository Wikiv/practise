#include "UBACData.h"

WatchListEntry::WatchListEntry()
{
}

WatchListEntry::~WatchListEntry()
{
}

void WatchListEntry::setUnderlying(string mUnderlying)
{
	if( underlying.length() > 0 ) 
		underlying.clear();
	underlying.append( mUnderlying );
}

void WatchListEntry::setSymbol(string mSymbol)
{
	if(symbol.length() > 0)
		symbol.clear();
	symbol.append(mSymbol);
}

void WatchListEntry::setDescription(string mDescription)
{
	if(description.length() > 0)
		description.clear();
	description.append(mDescription);
}

void WatchListEntry::setAssetType(string mAssetType)
{
	if(assetType.length() > 0)
		assetType.clear();
	assetType.append(mAssetType);
}

void WatchListEntry::setNameValue(string name, string value)
{
	nameValuePair[name] = value;
}

void WatchListEntry::getSymbol(string & mSymbol)
{
	mSymbol.append( symbol );
}

void WatchListEntry::setOptionDescription( string mOptionDescription )
{
	if ( optionDescription.length() > 0 )
		optionDescription.clear();
	optionDescription.append( mOptionDescription );
}

void WatchListEntry::getValue(string name, string & value)
{
	map<string, string>::iterator i;
	for(i = nameValuePair.begin(); i != nameValuePair.end(); i++) {
		if( strcasecmp(i->first.c_str(), name.c_str()) == 0 ) {
			value.append(i->second);
			break;
		}
	}
}

void WatchListEntry::toString(string & response)
{
	if ( assetType.length() > 0 ) {
		response.append("ASSET-TYPE=");
		response.append(assetType);
		response.append(",");
	}
	response.append("SYMBOL=");
	response.append(symbol);
	response.append(",");
	if ( description.length() > 0 ) {
		response.append("NAME=");
		response.append(description);
		response.append(",");
	}
	if ( optionDescription.length() > 0 ) {
		response.append("OptionDescription=");
		response.append( optionDescription );
		response.append(",");
	}
	if( underlying.length() > 0 ) {
		response.append("Underlying=");
		response.append( underlying );
		response.append(",");
	}
	map<string, string>::iterator i;
	for(i = nameValuePair.begin(); i != nameValuePair.end(); i++) {
		response.append(i->first);
		response.append("=");
		response.append(i->second);
		response.append(",");
	}
	if(response[response.length()-1] == ',') {
		string::iterator i = response.end();
		i--;
		response.erase(i);
	}
}
