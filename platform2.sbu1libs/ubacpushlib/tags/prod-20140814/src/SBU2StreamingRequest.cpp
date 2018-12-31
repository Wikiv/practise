#include "SBU2StreamingRequest.h"

const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_Unknown = 255;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_Level1 = 1;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_Level2 = 2;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_Positions = 3;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_Orders = 4;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_Alerts = 5;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_TradeSymbols = 6;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_LiveTrades = 7;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_Balances = 8;
const uint8_t SBU2StreamingRequest::SBU2StreamingRequest_AccountUpdate = 9;

SBU2StreamingRequest::SBU2StreamingRequest(string sRequest)
{
	this->subscription = this->unSubscription = false;
	this->iStreamingRequestType = SBU2StreamingRequest_Unknown;

	parse(sRequest);
}

SBU2StreamingRequest::~SBU2StreamingRequest()
{
}

uint8_t SBU2StreamingRequest::getRequestType()
{
	return iStreamingRequestType;
}

vector<string> SBU2StreamingRequest::getSymbolList()
{
	return symbolList;
}

string SBU2StreamingRequest::getAccountID()
{
	return sAccountID;
}

string SBU2StreamingRequest::getSessionID()
{
	return sSessionID;
}

bool SBU2StreamingRequest::setRequestType()
{
	const char * requestType =  reqObject["request"]["request_type"].c_str();

	if ( 0 == strcmp(requestType, "subscribe") ) {
		this->subscription = true;
		return true;

	} else if ( 0 == strcmp(requestType, "unsubscribe")) {
		this->unSubscription = true;
		return true;
	}

	return false;
}

void SBU2StreamingRequest::setStreamingType()
{

	string sStreamingType = reqObject["request"]["streaming_type"];

	if( strcasecmp(sStreamingType.c_str(), "quote") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_Level1;

	} else if( strcasecmp(sStreamingType.c_str(), "quote2") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_Level2;

	} else if( strcasecmp(sStreamingType.c_str(), "positions") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_Positions;

	} else if( strcasecmp(sStreamingType.c_str(), "orders") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_Orders;

	} else if( strcasecmp(sStreamingType.c_str(), "alerts") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_Alerts;

	} else if( strcasecmp(sStreamingType.c_str(), "tradeSymbols") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_TradeSymbols;

	} else if( strcasecmp(sStreamingType.c_str(), "liveTrades") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_LiveTrades;

	} else if( strcasecmp(sStreamingType.c_str(), "balances") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_Balances;

	} else if( strcasecmp(sStreamingType.c_str(), "accountUpdate") == 0 ) {
		iStreamingRequestType = SBU2StreamingRequest_AccountUpdate;
    }

}

void SBU2StreamingRequest::setAccountID()
{
	JsonObject data_block = reqObject["request"]["data"];
	string sAccountID = data_block["account_id"];
}


bool SBU2StreamingRequest::isSubscribe()
{
	return this->subscription;
}

bool SBU2StreamingRequest::isUnSubscribe()
{
	return this->unSubscription;
}

void SBU2StreamingRequest::parse(string sRequest)
{
	JsonParser parser(sRequest);

	if ( ! parser.isValidJson() )
		return;

	reqObject = parser.getJsonObject();

	// not proceeding further
	// if neither subscription nor unsubcription
	if (! setRequestType() )
		return;

	setStreamingType();

	setAccountID();

	sSessionID = reqObject["request"]["session"];

	string requestType = reqObject["request"]["request_type"];

	JsonObject data_block = reqObject["request"]["data"];

	vector<JsonObject>vSymbol( data_block["symbols"] );

	if( vSymbol.size() == 0 )
		return;

	for(size_t i = 0; i < vSymbol.size(); i++) {
		symbolList.push_back( vSymbol[i]["symbol"] );
	}
}
