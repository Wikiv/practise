#include "UBACData.h"

WatchListGroup::WatchListGroup()
{
}

WatchListGroup::~WatchListGroup()
{
}

void WatchListGroup::setName(string mName)
{
	watchListName.append( mName );
}

void WatchListGroup::getName(string & mName)
{
	mName.append(watchListName);
}

void WatchListGroup::setId(string mId)
{
	watchListId.append(mId);
}

void WatchListGroup::getId(string & mId)
{
	mId.append(watchListId);
}

void WatchListGroup::addWatchListEntry(WatchListEntry entry)
{
	watchListEntries.push_back( entry );
}

void WatchListGroup::getAllSymbols(vector<string> & symbolList)
{
	vector<WatchListEntry>::iterator i;
	for(i = watchListEntries.begin(); i != watchListEntries.end(); i++) {
		string symbol;
		(*i).getSymbol( symbol );
		symbolList.push_back( symbol );
	}
}

WatchListEntry & WatchListGroup::getFirstEntry()
{
	cout << "Hash " << watchListEntries.size() << " entries." << endl;
	entryIterator = watchListEntries.begin();
	return (*entryIterator);
}

WatchListEntry & WatchListGroup::getNextEntry()
{
	entryIterator++;
	return (*entryIterator);
}

bool WatchListGroup::hasEntry()
{
	return (entryIterator == watchListEntries.end());
}

void WatchListGroup::toString(string & response)
{
	response.append(watchListName);
	response.append("|");
	response.append(watchListId);
	response.append("|");
	vector<WatchListEntry>::iterator i;
	for(i = watchListEntries.begin(); i != watchListEntries.end(); i++) {
		(*i).toString(response);
		response.append("|");
	}
	if(response[response.length()-1] == '|') {
		string::iterator j = response.end();
		j--;
		response.erase(j);
	}
}
