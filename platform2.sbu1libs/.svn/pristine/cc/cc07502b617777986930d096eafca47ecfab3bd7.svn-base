#include "UBACData.h"

const string AccountDetails::AccountMode_REAL = "Real";
const string AccountDetails::AccountMode_DEMO = "Demo";

AccountDetails::AccountDetails()
{
	marginEnabled = optionEnabled = stockEnabled = futuresEnabled = forexEnabled = streamingNews = streamingData = fundsEnabled = primaryValue = isSecurityKeyEnabled = isSecurityKeyNeeded = false;
}

AccountDetails::AccountDetails(string data)
{
	marginEnabled = optionEnabled = stockEnabled = futuresEnabled = forexEnabled = streamingNews = streamingData = fundsEnabled = primaryValue = isSecurityKeyEnabled = isSecurityKeyNeeded = false;
	parse(data);
}

void AccountDetails::setNameValue(string name, string value)
{
//	cout << "Name = " << name << ", and Value = " << value << endl;
	if( strcasecmp(name.c_str(), "AccountID") == 0 ) {
		accountID.append( value );
	} else if( strcasecmp(name.c_str(), "AccountNumber") == 0 ) {
		accountNumber.append( value );
	} else if( strcasecmp(name.c_str(), "AccountMode" ) == 0 ) {
		accountMode.append( value );
	} else if( strcasecmp(name.c_str(), "AccountType" ) == 0 ) {
		accountType.append( value );
	} else if( strcasecmp(name.c_str(), "DisplayName") == 0 ) {
		displayName.append( value );
	} else if( strcasecmp(name.c_str(), "UserName") == 0 ) {
		username.append( value );
	} else if( strcasecmp(name.c_str(), "Margin") == 0 ) {
		marginEnabled = (atoi( value.c_str()) == 1);
	} else if( strcasecmp(name.c_str(), "Option") == 0 ) {
		optionEnabled = (atoi( value.c_str()) == 1);
	} else if( strcasecmp(name.c_str(), "Stock") == 0 ) {
		stockEnabled = (atoi( value.c_str()) == 1);
	} else if( strcasecmp(name.c_str(), "Futures") == 0 ) {
		futuresEnabled = (atoi( value.c_str()) == 1);
	} else if( strcasecmp(name.c_str(), "StreamingNews") == 0 ) {
		streamingNews = (atoi( value.c_str()) == 1);
	} else if( strcasecmp(name.c_str(), "StreamingData") == 0 ) {
		streamingData = (atoi( value.c_str()) == 1);
	} else if( strcasecmp(name.c_str(), "Forex") == 0 ) {
		forexEnabled = (atoi( value.c_str()) == 1);
	} else if( strcasecmp(name.c_str(), "MutualFunds") == 0 ) {
		fundsEnabled = (atoi( value.c_str()) == 1);
	} else if ( strcasecmp(name.c_str(), "Primary" ) == 0 ) {
		primaryValue = (atoi( value.c_str()) == 1);
	} else if ( strcasecmp(name.c_str(), "SecurityKeyEnabled") == 0 ) {
		isSecurityKeyNeeded=true;
		isSecurityKeyEnabled= (atoi( value.c_str()) == 1);
	} else if ( strcasecmp(name.c_str(), "OrderTypeDetails" ) == 0 ) {
		setNameValuePairDetailsFromResponse( name, value );
	} else if ( strcasecmp(name.c_str(), "TimeRestriction" ) == 0 ) {
		setNameValuePairDetailsFromResponse( name , value );
	} else {
		size_t found,found1;
		found = value.find( ";" );
		found1 = value.find( ":" );
		if ( ( found!=string::npos ) && ( found1!=string::npos ) ) {
			setNameValuePairDetailsFromResponse( name , value );
		} else {
			setOtherParams( name, value );
		}
	}
}

void AccountDetails::setNameValuePairDetailsFromResponse( string responseName, string data )
{
	string name, tmpBuffer;
	size_t i;
	for(i = 0; i < data.length(); i++) {
		if ( ( data[i] == ';' ) || ( i+1 == data.length() ) ) {
			setNameValuePairDetails( responseName, name, tmpBuffer);
			name.clear();
			tmpBuffer.clear();
		} else if( data[i] == ':' ) {
			name.append( tmpBuffer );
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&data[i], 1);
		}
	}
}

void AccountDetails::parse(string data)
{
	string name, tmpBuffer;
	size_t i;
	for(i = 0; i < data.length(); i++) {
		if( data[i] == ',' ) {
			setNameValue(name, tmpBuffer);
			name.clear();
			tmpBuffer.clear();
		} else if( data[i] == '=' ) {
			name.append( tmpBuffer );
			tmpBuffer.clear();
		} else {
			tmpBuffer.append(&data[i], 1);
		}
	}
	setNameValue(name, tmpBuffer);
}

void AccountDetails::addField(string key, string value, string & response)
{
	response.append(key);
	response.append(value);
	response.append(",");
}

void AccountDetails::resetValue(string key, string value)
{
	setNameValue( key, value);
}

void AccountDetails::toString(string & response)
{
	addField("AccountID=", accountID, response);
	addField("DisplayName=", displayName, response);
	
	( marginEnabled ) ? addField("Margin=", "1", response) : addField("Margin=", "0", response);
	( optionEnabled ) ? addField("Option=", "1", response) : addField("Option=", "0", response);
	( stockEnabled ) ? addField("Stock=", "1", response) : addField("Stock=", "0", response);
	( futuresEnabled ) ? addField("Futures=", "1", response) : addField("Futures=", "0", response);
	( streamingNews ) ? addField("StreamingNews=", "1", response) : addField("StreamingNews=", "0", response);
	( streamingData ) ? addField("StreamingData=", "1", response) : addField("StreamingData=", "0", response);
	( forexEnabled ) ? addField("Forex=", "1", response) : addField("Forex=", "0", response);
	( fundsEnabled ) ? addField("MutualFunds=", "1", response) : addField("MutualFunds=", "0", response);

	if ( isSecurityKeyNeeded )
		( isSecurityKeyEnabled ) ? addField("SecurityKeyEnabled=", "1", response) : addField("SecurityKeyEnabled=", "0", response);

	if ( accountNumber.length() > 0 ) {
		addField("AccountNumber=", accountNumber, response);
		( primaryValue ) ? addField("Primary=", "1", response) : addField("Primary=", "0", response);	
	}
	if ( username.length() > 0 )
		addField("UserName=", username , response);
	if ( accountMode.length() > 0 )
		addField("AccountMode=", accountMode , response);
	if ( accountType.length() > 0 )
		addField("AccountType=", accountType , response);

	map<string, string>::iterator iOtherParams;
	for( iOtherParams = otherParams.begin(); iOtherParams != otherParams.end(); iOtherParams++ ) {
		string name( iOtherParams->first );
		name.append("=");
		addField(name, iOtherParams->second, response);
	}

	if ( responseNameMap.size() > 0 )
		response.append( getNameValuePairDetails() );

	if(response[response.length() - 1] == ',') {
		string::iterator i = response.end();
		i--;
		response.erase( i );
	}
}
		
string AccountDetails::getValueFromName( string name )
{
	string value;
	map<string, string>::iterator iOtherParams = otherParams.find( name );
	if( iOtherParams == otherParams.end() ) {
		value = "";
	} else {
		value = iOtherParams->second;
	}
	return value;
}	

string AccountDetails::getNameValuePairDetails()
{
	string nameValueString;
	map<string, map<string, string> >::iterator iResponseNameMapDetails;
	for ( iResponseNameMapDetails = responseNameMap.begin(); iResponseNameMapDetails != responseNameMap.end(); iResponseNameMapDetails++ ) {
		vector<string>outputFormat;
		vector<string>::iterator iOutputFormat;
		map<string, vector<string> >::iterator iResponseNameFormatDetails = responseFormatMap.find( iResponseNameMapDetails->first );
		if ( iResponseNameFormatDetails != responseFormatMap.end() )
			outputFormat = iResponseNameFormatDetails->second;
		nameValueString.append( iResponseNameMapDetails->first );
		nameValueString.append("=");
		map<string, string>::iterator iNameValuePairDetails;
		if ( outputFormat.size() > 0 ) {
				for ( iOutputFormat=outputFormat.begin(); iOutputFormat!=outputFormat.end(); iOutputFormat++ ) {
					iNameValuePairDetails = iResponseNameMapDetails->second.find( *iOutputFormat );
					if ( iNameValuePairDetails != iResponseNameMapDetails->second.end() ) {
						nameValueString.append( iNameValuePairDetails->first );
						nameValueString.append( ":" );
						nameValueString.append( iNameValuePairDetails->second );
						nameValueString.append( ";" );
					}
				}
		} else {
			for ( iNameValuePairDetails = iResponseNameMapDetails->second.begin(); iNameValuePairDetails != iResponseNameMapDetails->second.end(); iNameValuePairDetails++ ) {
				nameValueString.append( iNameValuePairDetails->first );
				nameValueString.append( ":" );
				nameValueString.append( iNameValuePairDetails->second );
				nameValueString.append( ";" );
			}
		}
		if ( nameValueString[nameValueString.length() - 1] == ';' ) {
			string::iterator i = nameValueString.end();
			i--;
			nameValueString.erase( i );
		}
		nameValueString.append( "," );
	}
	if ( nameValueString[nameValueString.length() - 1] == ',' ) {
		string::iterator i = nameValueString.end();
		i--;
		nameValueString.erase( i );
	}
	return nameValueString;
}

void AccountDetails::setAccountID(string m_accountID)
{
	CONVERT_TO_STRING(m_accountID, accountID);
}

void AccountDetails::setAccountNumber(string m_accountNumber)
{
	CONVERT_TO_STRING(m_accountNumber, accountNumber);
}

void AccountDetails::setDisplayName(string m_displayName)
{
	CONVERT_TO_STRING(m_displayName, displayName);
}

void AccountDetails::setUsername(string m_username)
{
	CONVERT_TO_STRING(m_username, username);
}

void AccountDetails::setAccountMode( string m_accountMode )
{
	CONVERT_TO_STRING(m_accountMode, accountMode);
}

void AccountDetails::setAccountType( string m_accountType )
{
	CONVERT_TO_STRING( m_accountType, accountType);
}

void AccountDetails::setPrimaryValue( bool flag )
{
	primaryValue = flag;
}

bool AccountDetails::getPrimaryValue()
{
	return primaryValue;
}

string AccountDetails::getAccountID()
{
	return accountID;
}

string AccountDetails::getDisplayName()
{
	return displayName;
}

string AccountDetails::getAccountNumber()
{
	return accountNumber;
}

string AccountDetails::getUsername()
{
	return username;
}

string AccountDetails::getAccountMode()
{
	return accountMode;
}

string AccountDetails::getAccountType()
{
	return accountType;
}

bool AccountDetails::getMarginFlag()
{
	return marginEnabled;
}

bool AccountDetails::getOptionFlag()
{
	return optionEnabled;
}

bool AccountDetails::getStockFlag()
{
	return stockEnabled;
}

bool AccountDetails::getFuturesFlag()
{
	return futuresEnabled;
}

bool AccountDetails::getForexFlag()
{
	return forexEnabled;
}

bool AccountDetails::getStreamingNewsFlag()
{
	return streamingNews;
}

bool AccountDetails::getStreamingDataFlag()
{
	return streamingData;
}

bool AccountDetails::getFundsFlag()
{
	return fundsEnabled;
}

bool AccountDetails::getIsSecurityKeyEnabled()
{
	return isSecurityKeyEnabled;
}

void AccountDetails::setIsSecurityKeyEnabled( bool m_isSecurityKeyEnabled )
{
	isSecurityKeyNeeded = true;
	isSecurityKeyEnabled=m_isSecurityKeyEnabled;
}

void AccountDetails::setMarginFlag( bool m_marginFlag )
{
	marginEnabled = m_marginFlag;
}

void AccountDetails::setOptionFlag(bool m_optionFlag )
{
	optionEnabled = m_optionFlag;
}

void AccountDetails::setStockFlag( bool m_stockFlag )
{
	stockEnabled = m_stockFlag;
}

void AccountDetails::setFuturesFlag( bool m_futuresFlag )
{
	futuresEnabled = m_futuresFlag;
}

void AccountDetails::setForexFlag( bool m_forexFlag )
{
	forexEnabled = m_forexFlag;
}

void AccountDetails::setStreamingNewsFlag( bool m_streamingNewsFlag )
{
	streamingNews = m_streamingNewsFlag;
}

void AccountDetails::setStreamingDataFlag( bool m_streamingDataFlag )
{
	streamingData = m_streamingDataFlag;
}

void AccountDetails::setFundsFlag( bool m_fundsFlag )
{
	fundsEnabled = m_fundsFlag;
}

void AccountDetails::setOtherParams(string name, string value)
{
	otherParams.insert(make_pair(name, value));
}


void AccountDetails::setNameValuePairDetails( string responseName, string name, string value )
{
	map<string, map<string, string> >::iterator i = responseNameMap.find( responseName );
	if ( i == responseNameMap.end() ) {
		map<string,string> nameValuePairDetails;
		nameValuePairDetails[name] = value;
		responseNameMap[responseName] = nameValuePairDetails;
	} else {
		i->second[name] = value;
	}
}

void AccountDetails::setNameValuePairFormatDetails( string responseName, vector <string> mResponseFormatMap  )
{
	responseFormatMap[responseName] = mResponseFormatMap;
}
