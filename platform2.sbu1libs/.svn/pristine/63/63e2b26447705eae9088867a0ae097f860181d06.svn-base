
#include "MasterTable.h"

MasterTable::MasterTable()
{
	this->l1SymbolTable = new SymbolTable();
	this->l2Symboltable = new SymbolTable();
	this->tradeSymbolTable = new SymbolTable();
	this->liveTradeConns = new ConnectionList();
}

MasterTable::~MasterTable()
{
	delete this->l1SymbolTable;
	delete this->l2Symboltable;
	delete this->tradeSymbolTable;
	delete this->liveTradeConns;
}
