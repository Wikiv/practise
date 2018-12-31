#include "CSVCommon.h"

CSVData::CSVData()
{
	isSnoInCSVData = false;
}

CSVData::CSVData(string sData)
{
	isSnoInCSVData = false;
	parse(sData);
}

CSVData::~CSVData()
{
	columnMap.clear();
}

void CSVData::setSNOFlagInCSVData( bool mIsSnoInCSVData )
{
	isSnoInCSVData = mIsSnoInCSVData;
}

void CSVData::addRow(CSVRow row)
{
	this->push_back( row );
}

void CSVData::toString(string & sData, char delimiter )
{
	int i = 0;
	char tmpBuf[100];
	vector<CSVRow>::iterator iCSVRow;
	for ( iCSVRow = this->begin(); iCSVRow != this->end(); iCSVRow++) {
		CSVRow row = ( CSVRow ) *iCSVRow;
		if ( isSnoInCSVData ) {
			if ( i == 0 ) {
				row.insert( row.begin() , "ID" );
			} else {
				string id;
				sprintf(tmpBuf, "%d", i);
				id.append(tmpBuf, strlen(tmpBuf));
				row.insert( row.begin() , id );
				memset(tmpBuf, '\0', sizeof(tmpBuf));
			}
			i++;
		}
		row.toString( sData );
		sData.append( &delimiter, 1 );
	}
	IFHelper helper;
	helper.rstrip( sData , delimiter );
}

vector<string> CSVData::operator[](string sKey)
{
	map<string, vector<string> >::iterator iColumn = columnMap.find( sKey );
	if( iColumn == columnMap.end() ) {
		vector<string>tmpColumn;
		columnMap.insert(make_pair(sKey, tmpColumn));
	}
	iColumn = columnMap.find( sKey );
	return iColumn->second;
}

void CSVData::parse(string sData)
{
	bool isHeader = true;
	size_t iHeader = 0;
	string sBuffer;
	for(size_t i = 0; i < sData.length(); i++) {
		if( sData[i] == ',' ) {
			cout << __LINE__ << ": iHeader = " << iHeader << ", sBuffer = " << sBuffer << endl;
			if( isHeader ) {
				headerList.push_back(sBuffer);
			} else {
				map<string, vector<string> >::iterator iColumn = columnMap.find(headerList[iHeader]);
				if( iColumn == columnMap.end() ) {
					vector<string> tmpColumn;
					columnMap.insert( make_pair(headerList[iHeader], tmpColumn) );
				}
				iColumn = columnMap.find(headerList[iHeader]);
				iColumn->second.push_back( sBuffer );
				iHeader++;
			}
			sBuffer.clear();
		} else if( sData[i] == '|') {
			cout << __LINE__ << ": iHeader = " << iHeader << ", sBuffer = " << sBuffer << endl;
			if( isHeader ) {
				headerList.push_back(sBuffer);
			} else {
				map<string, vector<string> >::iterator iColumn = columnMap.find(headerList[iHeader]);
				if( iColumn == columnMap.end() ) {
					vector<string> tmpColumn;
					columnMap.insert( make_pair(headerList[iHeader], tmpColumn) );
				}
				iColumn = columnMap.find(headerList[iHeader]);
				iColumn->second.push_back( sBuffer );
				iHeader++;
			}
			sBuffer.clear();
			iHeader = 0;
			isHeader = false;
		} else {
			sBuffer.append(&sData[i], 1);
		}
	}
	cout << __LINE__ << ": iHeader = " << iHeader << ", sBuffer = " << sBuffer << endl;
	if( isHeader ) {
		headerList.push_back(sBuffer);
	} else {
		map<string, vector<string> >::iterator iColumn = columnMap.find(headerList[iHeader]);
		if( iColumn == columnMap.end() ) {
			vector<string> tmpColumn;
			columnMap.insert( make_pair(headerList[iHeader], tmpColumn) );
		}
		iColumn = columnMap.find(headerList[iHeader]);
		iColumn->second.push_back( sBuffer );
	}
	print();
}

void CSVData::print()
{
	size_t iHeader, iColumnLength = 0;
	bool isEnd = false;
	while( 1 ) {
		for(iHeader = 0;iHeader < headerList.size(); iHeader++) {
			map<string, vector<string> >::iterator iColumn = columnMap.find( headerList[iHeader] );
			if( iColumn != columnMap.end() ) {
				if( iColumnLength == iColumn->second.size() ) {
					isEnd = true;
				} else {
					printf("%s,", iColumn->second[iColumnLength].c_str());
				}
			}
		}
		printf("\n");
		iColumnLength++;
		if( isEnd )
			break;
	}
}
