#include "UBACData.h"

TechnicalIndicatorValueResponse::TechnicalIndicatorValueResponse(size_t iLimit)
{
	this->iLimit = iLimit;
	toDate = 0; fromDate = 0;
	iToIndex = -1; iFromIndex = -1;
	doTruncate = false;
}

TechnicalIndicatorValueResponse::TechnicalIndicatorValueResponse(time_t from, time_t to)
{
	fromDate = from;
	toDate = to;
	string stoDate, sfromDate;
	IFHelper helper;
	helper.formatTime(to, "%Y/%m/%d", stoDate);
	helper.formatTime(from, "%Y/%m/%d", sfromDate);
	cout << "here from is " << sfromDate << ", to is " << stoDate << endl;
	iToIndex = -1; iFromIndex = -1;
	doTruncate = false;
}

TechnicalIndicatorValueResponse::~TechnicalIndicatorValueResponse()
{
	toDate = 0; fromDate = 0;
	iToIndex = -1; iFromIndex = -1;
}

void TechnicalIndicatorValueResponse::adjustSize(vector<string> & list)
{
	if( ( iLimit == 0 ) || (list.size() < iLimit) )
		return;
	while( list.size() > iLimit ) {
		list.erase( list.begin() );
	}
}

void TechnicalIndicatorValueResponse::setSymbol( string mSymbol )
{
	symbol.append( mSymbol );
}

void TechnicalIndicatorValueResponse::addOpenValue( string mOpen )
{
	open.push_back( mOpen );
	adjustSize( open );
}

void TechnicalIndicatorValueResponse::addHighValue( string mHigh )
{
	high.push_back( mHigh );
	adjustSize( high );
}

void TechnicalIndicatorValueResponse::addLowValue( string mLow )
{
	low.push_back( mLow );
	adjustSize( low );
}

void TechnicalIndicatorValueResponse::addCloseValue( string mClose )
{
	close.push_back( mClose );
	adjustSize( close );
}

void TechnicalIndicatorValueResponse::addVolumeValue( string mVolume )
{
	volume.push_back( mVolume );
	adjustSize( volume );
}

void TechnicalIndicatorValueResponse::addDateValue( string mDate )
{
	date.push_back( mDate );
	adjustSize( date );
}

void TechnicalIndicatorValueResponse::addIndicatorCodeValue( string mIndicatorName, string mIndicatorValue )
{
	map<string, vector<string> >::iterator i = indicatorCode.find( mIndicatorName );
	if( i == indicatorCode.end() ) {
		vector<string> values;
		values.push_back( mIndicatorValue );
		adjustSize( values );
		indicatorCode[mIndicatorName] = values;
	} else {
		i->second.push_back( mIndicatorValue );
	}
}

void TechnicalIndicatorValueResponse::setTruncateFlag(bool mFlag)
{
	doTruncate = mFlag;
}	

void TechnicalIndicatorValueResponse::setAdjustment(size_t uMaxSize)
{
	IFHelper helper;
	while( date.size() > uMaxSize ) 
		date.erase( date.begin() );	
	int fromIndex = -1, toIndex = -1;
	vector<time_t> timeValues;
	for(size_t i = 0; i < date.size(); i++) {
		string sTime(date[i]); vector<string> sDate;
		helper.split(sTime, " ", sDate);
		time_t tValue;
		helper.parseTime(sDate[0], "%Y/%m/%d", &tValue);
		timeValues.push_back(tValue);
	}
	size_t totalSize = timeValues.size();
	cout << "totalSize is " << totalSize << endl;
	bool fromFlag = false, toFlag = false;
	for(size_t i = 0, j = totalSize - 1; i < totalSize; i++, j--) {
		if( (fromDate <= timeValues[i]) && (!fromFlag) ) {
			fromIndex = i;
			fromFlag = true;
		}
		if( (toDate >= timeValues[j]) && (!toFlag) ) {
			toIndex = j;
			toFlag = true;
		}
	} 
	iFromIndex = fromIndex;
	iToIndex = toIndex;
	cout << "from index " << iFromIndex << endl;
	cout << "to index " << iToIndex << endl;
}

string TechnicalIndicatorValueResponse::getFullData( vector<string>mData , char sDelimiter , string mName, size_t uMaxSize )
{
//	reverse(mData.begin(), mData.end());
	string mFullData;
	mFullData.append( mName );
	mFullData.append("=");
	vector<string>::iterator i;
	while( mData.size() > uMaxSize ) {
		mData.erase( mData.begin() );
	}
	if( (iToIndex !=  -1) && (iFromIndex != -1) ) {
		cout << "adding data\n";
		int j = 0;
		for(j = iFromIndex; j <= iToIndex; j++) {
			mFullData.append( mData[j] );
			mFullData.append( &sDelimiter, 1 );
		}
	} else {
		for(i = mData.begin(); i != mData.end(); i++) {
			mFullData.append( *i );
			mFullData.append( &sDelimiter, 1 );
		}
	}
	rstrip( mFullData, sDelimiter );
	return mFullData;
}

string TechnicalIndicatorValueResponse::getIndicatorFullData( size_t uMaxSize )
{
	string mFullData;
	map< string,vector<string> >::iterator i;
	for(i = indicatorCode.begin(); i != indicatorCode.end(); i++ ) {
		mFullData.append( getFullData( i->second, ',', i->first, uMaxSize ) );
		mFullData.append("|");
	}
	rstrip( mFullData, '|' );
	return mFullData;
}

void TechnicalIndicatorValueResponse::toString( string & response )
{
	size_t uMaxSize = open.size();
	for(map< string,vector<string> >::iterator i = indicatorCode.begin(); i != indicatorCode.end(); i++ ) {
		uMaxSize = (uMaxSize > i->second.size()) ? i->second.size() : uMaxSize;
	}
	if(toDate > 0 && fromDate > 0)
		setAdjustment(uMaxSize);
	response.append( "814 <" );
	response.append( symbol );
	response.append( "|" );
	if ( !doTruncate ) {
		response.append( getFullData( open , ',' , "Open", uMaxSize ) );
		response.append( "|" );
		response.append( getFullData( high, ',' , "High", uMaxSize ) );
		response.append( "|" );
		response.append( getFullData( low , ',' , "Low", uMaxSize ) );
		response.append( "|" );
	}
	response.append( getFullData( close , ',' , "Close", uMaxSize ) );
	response.append( "|" );
	if ( !doTruncate ) {
		response.append( getFullData( volume , ',' , "Volume", uMaxSize ) );
		response.append( "|" );
	}
	response.append( getFullData( date , ',' , "Date", uMaxSize ) );
	response.append( "|" );
	response.append( getIndicatorFullData( uMaxSize ) );
	response.append(">");
}

void TechnicalIndicatorValueResponse::toString( string & response , string url )
{
	response.append( "814 <" );
	response.append( url );
	response.append(">");
}
