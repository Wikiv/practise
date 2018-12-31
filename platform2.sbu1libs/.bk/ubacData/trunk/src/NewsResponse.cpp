#include "UBACData.h"

NewsResponse::NewsResponse()
{
	flag = false;
}

NewsResponse::~NewsResponse()
{
}

void NewsResponse::setOutputParam( vector<string> mOutputParam )
{
	outputParam.assign( mOutputParam.begin(), mOutputParam.end() );
}

string NewsResponse::getNewsData()
{
	string response("");
	if( newsList.size() != 0 ) {
		vector<NewsItem>::iterator i;
		for(i = newsList.begin(); i != newsList.end(); i++) {
			string tmpStr;
			if ( outputParam.size() == 0 ) {
				(*i).toString( tmpStr );
			} else {
				(*i).toString(tmpStr, outputParam);
			}
			response.append(tmpStr);
			response.append("&");
		}
		rstrip(response, '&');
	}
	return response;
}

void NewsResponse::addNewsData(NewsItem news)
{
	newsList.push_back( news );
}

bool NewsResponse::isNewsDataEmpty()
{
	return flag;
}

void NewsResponse::toString( string & response )
{
	vector<NewsItem>::iterator i;
	response.append("396 <");
	if( newsList.size() == 0 ) {
		flag = true;
		response.append(">");
		return;
	}
	for(i = newsList.begin(); i != newsList.end(); i++) {
		string tmpStr;
		if ( outputParam.size() == 0 ) {
			(*i).toString( tmpStr );
		} else {
			(*i).toString(tmpStr, outputParam);
		}
		response.append(tmpStr);
		response.append("&");
	}
	rstrip(response, '&');
	response.append(">");
}
