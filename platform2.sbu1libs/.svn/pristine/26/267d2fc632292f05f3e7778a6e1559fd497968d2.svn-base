#ifndef __MASTER_SYMBOL_TABLE_H__
#define __MASTER_SYMBOL_TABLE_H__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "SymbolTable.h"
#include "ConnectionList.h"

using namespace std;

/// Class MasterTable
class MasterTable
{
	public:
		/** Creates new MasterTable object. */
		MasterTable();
		~MasterTable();

		/** Instance for quote symbol table. */
		SymbolTable * l1SymbolTable;
		/** Instance for market depth symbol table. */
		SymbolTable * l2Symboltable;
		/** Instance for trade symbol table. */
		SymbolTable * tradeSymbolTable;
		/** Instance for live trade connections. */
		ConnectionList * liveTradeConns;

};

#endif /* __MASTER_SYMBOL_TABLE_H__ */
