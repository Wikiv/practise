#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/// Class SymbolTable maintains the map of symbol list along with the connection information. */
class SymbolTable :
	public map<string, vector<void *> >
{
	public:
		SymbolTable();
		~SymbolTable();

		/** Adds the symbol to the symbol list. */
		void addSymbolList(vector<string>symbolList, void *conn);
		/** Returns true if the 'symbol' is subscribed for any connection. */
                bool isSubscribed(string sSymbol);
		/** For a specific connection it will remove the 'symbolList' and it will 
                * return the list of symbols which are no longer subscribed for any connection.*/
		vector<string> removeSymbolList(vector<string>symbolList, void *conn);
		/** Retrieves the connection list. */
		vector<void *> getConnList(string sSymbol);

	private:
		void addSymbol(string sSymbol, void *conn);
		/** returns true if no connections is subscribed for sSymbol */
		bool removeSymbol(string sSymbol, void *conn);
};

#endif /* __SYMBOL_TABLE_H__ */
