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
		void removeSymbolList(vector<string>symbolList, void *conn);
		vector<void *> getConnList(string sSymbol);

	private:
		void addSymbol(string sSymbol, void *conn);
		void removeSymbol(string sSymbol, void *conn);
};

#endif /* __SYMBOL_TABLE_H__ */
