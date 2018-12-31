#include "UBACData.h"
//#include <Base64.h>

void UBACData::maskLogin(string message, string & maskedMessage)
{
	int code;
	string sData, sExtMod, sEncodedStr;
	crack(message, code, sData, sExtMod);
	createLogMessage( maskedMessage, code, sData );
	maskedMessage.append( sExtMod ) ;
}

void UBACData::createLogMessage(string &log_request, int code, string data)
{
	stringstream logMessage;
	string tempData;
	logMessage << code << "<";
	IFHelper helper;
	if ( code == 434 ) {
		vector<string> list;
		helper.split( data, "|", list);
		int state = 0;
		vector<string>::iterator it = list.begin();
		while( it != list.end() ) {
			if ( state == 1 ) {
				tempData.append("*****");
			} else {
				tempData.append(*it);
			}
			tempData.append("|");
			state++;
			it++;
		}
		helper.rstrip(tempData,'|');
	} else if ( code == 540  || code == 544 || code == 582 || code == 448 ) {
                vector<string> list;
                helper.split( data, "|", list);
                vector<string>::iterator it = list.begin();
                while( it != list.end() ) {
			string temp_data(*it);
#ifdef _WIN32
			/* TODO - IMP - change strstr() to strcasestr() */
			if( (strstr( temp_data.c_str(), "password" ) == NULL ) && (strstr( temp_data.c_str(), "PASSWORD" ) == NULL ) ) {
#else
			if(strcasestr( temp_data.c_str(), "password" ) == NULL ) {
#endif
				tempData.append(*it);
			} else {
				tempData.append("Password=******");
			}
			tempData.append("|");
			it++;
		}			
	} else {
		tempData = data;
	}
	logMessage << tempData << ">";
	log_request = logMessage.str();
}

void UBACData::crack(string message, int & code, string & data, string & extModBuf) {
	string tmpBuf;
	for(size_t i = 0; i < message.length(); i++) {
		if( message[i] == '<' ) {
			code = atoi(tmpBuf.c_str());
			tmpBuf.clear();
		} else if( message[i] == '>' ) {
			data.append( tmpBuf );
			tmpBuf.clear();
		} else {
			tmpBuf.append(&message[i], 1);
		}
	}
	IFHelper helper;
	helper.lstrip( tmpBuf, '#' );
	helper.lstrip( tmpBuf, '#' );
	helper.rstrip( tmpBuf, '\n' );
	helper.rstrip( tmpBuf, '\r' );
	helper.rstrip( tmpBuf, '#' );
	helper.rstrip( tmpBuf, '#' );
	extModBuf.append(tmpBuf);
}
