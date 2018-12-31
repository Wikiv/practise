#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
}

SymbolTable::~SymbolTable()
{
}

vector<void *>SymbolTable::getConnList(string sSymbol)
{
	vector<void *>tmpList;
	map<string, vector<void *> >::iterator iList = this->find( sSymbol );

	if( iList != this->end() )
		tmpList = iList->second;

	return tmpList;
}

void SymbolTable::addSymbolList(vector<string>symbolList, void *conn)
{
	vector<string>::iterator iSymbol = symbolList.begin();

	while( iSymbol != symbolList.end() ) {
		addSymbol( *iSymbol, conn );
		iSymbol++;
	}
}

void SymbolTable::removeSymbolList(vector<string>symbolList, void *conn)
{
	vector<string>::iterator iSymbol = symbolList.begin();

	while( iSymbol != symbolList.end() ) {
		removeSymbol( *iSymbol, conn );
		iSymbol++;
	}
}

void SymbolTable::addSymbol(string sSymbol, void *conn)
{
	map<string, vector<void *> >::iterator iTable = this->find(sSymbol);

	if( iTable != this->end() ) {
		iTable->second.push_back( conn );

	} else {
		vector<void *>tmpList;
		tmpList.push_back( conn );
		this->insert( make_pair( sSymbol, tmpList ) );
	}
}

void SymbolTable::removeSymbol(string sSymbol, void *conn)
{
	map<string, vector<void *> >::iterator iTable = this->find(sSymbol);

	if( iTable != this->end() ) {
		vector<void *>::iterator iConn = std::find(iTable->second.begin(),
										 iTable->second.end(), conn);

		if( iConn != iTable->second.end() )
			iTable->second.erase( iConn );

		if( iTable->second.size() == 0 )
			this->erase( iTable );
	}
}
