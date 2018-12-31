#include "CSVCommon.h"

CSVFile::CSVFile() 
{
}

CSVFile::~CSVFile()
{
}

void CSVFile::setHeader(vector<string>mHeaderList)
{
	vector<string>::iterator iList = mHeaderList.begin();
	while( iList != mHeaderList.end() ) {
		setHeader( *iList );
		iList++;
	}
}

void CSVFile::setHeader(string mHeader)
{
	headerList.push_back(mHeader);
}

void CSVFile::setData(string mHeader, string mValue)
{
	dataMap.insert( make_pair(mHeader, mValue) );
}

void CSVFile::syncHeader()
{
	vector<string>::iterator iList = headerList.begin();
	while( iList != headerList.end() ) {
		setData( *iList, *iList );
		iList++;
	}
	sync(false);
}

void CSVFile::sync(bool checkShift)
{
/*	if( shift() )
		syncHeader();
	CSVRow row;
	vector<string>::iterator iList = headerList.begin();
	while( iList != headerList.end() ) {
		map<string, string>::iterator iMap = dataMap.find( *iList );
		if( iMap != dataMap.end() ) {
			cout << "Adding " << iMap->second << endl;
			row.addColumn( iMap->second );
		} else {
			row.addColumn( "" );
		}
		iList++;
	}
	string s;
	row.toString(s);
	s.append("\n");
	writeToFile(s);
	dataMap.clear();*/
}
