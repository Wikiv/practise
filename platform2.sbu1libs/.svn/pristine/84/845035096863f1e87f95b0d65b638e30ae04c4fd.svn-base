#include "UBACData.h"

NewsItem::NewsItem()
{
}

NewsItem::~NewsItem()
{
}

void NewsItem::setSymbol( string mSymbol )
{
	symbol.append( mSymbol );
}

void NewsItem::setHeadLine( string mHeadLine )
{
	gsubSpecialCharacters( mHeadLine );
	headLine.append( mHeadLine );
}

void NewsItem::setDescription( string mDescription )
{
	gsubSpecialCharacters( mDescription );
	description.append( mDescription );
}

void NewsItem::setTimeStamp( string mTimeStamp )
{
	timeStamp.append( mTimeStamp );
}

void NewsItem::setGuid( string mGuid )
{
	guid.append( mGuid );
}

void NewsItem::setUrl( string mUrl )
{
	url.append( mUrl );
}

void NewsItem::setImageUrl( string mImageUrl )
{
	imageUrl.append( mImageUrl );
}

void NewsItem::setNoData(string & data)
{
	if ( data.length() == 0 )
		data.append("%");
}

void NewsItem::setDataToResponse( string outputParam ,string & response )
{
	if ( strcasecmp( outputParam.c_str(), "symbol" ) == 0 ) {
		setNoData(symbol);
		response.append( symbol );
	} else if ( strcasecmp( outputParam.c_str(), "headline" ) == 0 ) {
		setNoData(headLine);
		response.append( headLine );
	} else if ( strcasecmp( outputParam.c_str(), "description" ) == 0 ) {
		setNoData(description);
		response.append( description );
	} else if ( strcasecmp( outputParam.c_str(), "id" ) == 0 ) {
		setNoData(guid);
		response.append( guid );
	} else if ( strcasecmp( outputParam.c_str(), "date_time" ) == 0 ) {
		setNoData(timeStamp);
		response.append( timeStamp );
	} else if ( strcasecmp( outputParam.c_str(), "link" ) == 0 ) {
		setNoData(url);
		response.append( url );
	} else if ( strcasecmp( outputParam.c_str(), "image_link" ) == 0 ) {
		setNoData(imageUrl);
		response.append( imageUrl );
	} else {
		response.append("%");
	}
	response.append("|");
}

void NewsItem::toString( string & response )
{
	setDataToResponse( "symbol", response);
	setDataToResponse( "headline", response);
	setDataToResponse( "id", response);
	setDataToResponse( "description", response);
	setDataToResponse( "date_time", response);
	setDataToResponse( "link", response);
	setDataToResponse( "image_link", response);
	rstrip(response, '|');
}

void NewsItem::toString( string & response, vector<string> output)
{
	for (unsigned int i=0; i<output.size(); i++) {
		setDataToResponse( output.at(i) , response);
	}
	rstrip(response, '|');
}

void NewsItem::replaceSpecialCharacters( string & data )
{

	gsubSpecialCharacters( data );
/*	string tmpStr("");
	for(size_t i = 0; i < data.length(); i++) {
		if ( data[i] == '<' ) {
			tmpStr.append(":lt");
		} else if ( data[i] == '>' ) {
			tmpStr.append(":gt");
		} else if ( data[i] == '\'' ) {
			tmpStr.append(":sqt");
		//} else if ( data[i] == ':' ) {
		//	tmpStr.append(":col");
		} else if ( data[i] == ';' ) {
			tmpStr.append(":scol");
		} else if ( data[i] == '&' ) {
			tmpStr.append(":amp");
		} else if ( data[i] == ',' ) {
			tmpStr.append(":comma");
		} else if ( data[i] == '(' ) {
			tmpStr.append(":lp");
		} else if ( data[i] == ')' ) {
			tmpStr.append(":rp");
		} else if ( data[i] == '{' ) {
			tmpStr.append(":lb");
		} else if ( data[i] == '}' ) {
			tmpStr.append(":rb");
		} else if ( data[i] == '[' ) {
			tmpStr.append(":lsq");
		} else if ( data[i] == ']' ) {
			tmpStr.append(":rsq");
		} else if ( data[i] == '#' ) {
			tmpStr.append(":hash");
		} else if ( data[i] == '|' ) {
			tmpStr.append(":pipe");
		} else if ( data[i] == '=' ) {
			tmpStr.append(":eq");
		} else if ( data[i] == '~' ) {
			tmpStr.append(":til");
		} else {
			tmpStr.append(&data[i], 1);
		}
	}
	data.clear();
	data.append( tmpStr );
*/
}

