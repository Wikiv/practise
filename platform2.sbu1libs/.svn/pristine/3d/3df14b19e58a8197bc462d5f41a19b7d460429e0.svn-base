#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class SymbolTable :
	public map<string, vector<void *> >
{
	public:
		SymbolTable();
		~SymbolTable();

		void addSymbolList(vector<string>symbolList, void *conn);
		/** returns symbols which are no longer subscribed from any connections.*/
		vector<string> removeSymbolList(vector<string>symbolList, void *conn);
		vector<void *> getConnList(string sSymbol);

	private:
		void addSymbol(string sSymbol, void *conn);
		/** returns true if no connections is subscribed for sSymbol */
		bool removeSymbol(string sSymbol, void *conn);
};

#endif /* __SYMBOL_TABLE_H__ */
