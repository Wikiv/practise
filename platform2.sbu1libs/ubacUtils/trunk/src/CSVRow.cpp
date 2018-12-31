#include "CSVCommon.h"

CSVRow::CSVRow()
{
}

CSVRow::~CSVRow()
{
}

void CSVRow::addColumn(string sColumnData)
{
	this->push_back(sColumnData);
}

void CSVRow::addColumn(double dColumnData)
{
	stringstream dStream;
	dStream << dColumnData;
	addColumn(dStream.str());

}

void CSVRow::addColumn(time_t t)
{
	string timestamp;
	IFHelper helper;
	helper.formatTime(t, "%s", timestamp);
	addColumn(timestamp);
}

void CSVRow::toString(string & sRow)
{
	vector<string>::iterator iRows;
	for ( iRows = this->begin(); iRows != this->end(); iRows++) {
		string s = *iRows;
		IFHelper helper;
		helper.gsub(s, ",", ":comma");
		(*iRows) = s;
	}
	toString(sRow, ',');
}

void CSVRow::toString(string & sRow, char c_delimiter)
{
	vector<string>::iterator iRows;
	for ( iRows = this->begin(); iRows != this->end(); iRows++) {
		sRow.append( *iRows );
		sRow.append( &c_delimiter, 1 );
	}
	IFHelper helper;
	helper.rstrip( sRow , c_delimiter , 1);
}
