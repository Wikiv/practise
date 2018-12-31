#include "PushServerData.h"

PushServerRequest::PushServerRequest(JsonObject jRequest )
{
	this->extMod = new ExtMod();
	this->handleJsonRequest( jRequest) ;
}

PushServerRequest::PushServerRequest(string sRequest)
{
	parse(sRequest);
}

void PushServerRequest::handleState(string sName, string sValue)
{
	if( strcasecmp(sName.c_str(), "mt") == 0 ) {
		u16RequestType = atoi(sValue.c_str());
	} else if( strcasecmp(sName.c_str(), "symbols") == 0 ) {
		IFHelper helper;
		helper.split(sValue, ",", symbolList);
	} else if( strcasecmp(sName.c_str(), "response_format") == 0 ) {
		sResponseFormat = sValue;
	} else if( strcasecmp(sName.c_str(), "type") == 0 ) {
		sRequestType = sValue;
	}
}

string PushServerRequest::getResponseFormat()
{
	return sResponseFormat;
}

void PushServerRequest::parse(string sRequest)
{
	string sName, sValue;
	bool isName = true;
	for(size_t i = 0; i < sRequest.length(); i++) {
		if( sRequest[i] == '&' ) {
			handleState(sName, sValue);
			sName.clear(); sValue.clear();
			isName = true;
		} else if( sRequest[i] == '=' ) {
			isName = false;
		} else {
			(isName) ? sName.append(&sRequest[i], 1) : sValue.append(&sRequest[i], 1);
		}
	}
	if(sValue.length() > 0)
		handleState(sName, sValue);
}

void PushServerRequest::handleJsonRequest(JsonObject jRequest )
{
	// set the params and generate the extMod here..
	map<string,JsonObject> data = (map<string,JsonObject>) jRequest["data"];

	cout << " data block.. " << jRequest["data"]["mt"] << endl;
	vector<JsonObject> symbolsList = jRequest["data"]["symbols"] ;

	if (symbolsList.size() > 0 ) {
		cout << "symbols not empty.. " << endl;
		vector<JsonObject>::iterator iter_symbols = symbolsList.begin();
		while(iter_symbols != symbolsList.end()){
			symbolList.push_back((*iter_symbols)["symbol"]) ;
			cout << "symbol: " << (*iter_symbols)["symbol"];
			iter_symbols++;
		}
	} else {
		cout << " unsubscribe.. " << endl;
	}
		
	if (strncmp(data["streaming_type"].c_str(), "quote" , 5 ) == 0 ){
	
		sRequestType.append("quote");

	} else if (strcmp(data["streaming_type"].c_str(), "market_depth" ) == 0 ) {

		sRequestType.append("quote2");

	} else {

		cout << "requestType --- streaming type is " << data["streaming_type"] << endl;

	}

	string response_format = data["response_format"];

	
	if (response_format.empty()){

		sResponseFormat = "json";

	} else {

		sResponseFormat = response_format;

	}

		
	string session = data["session"] ;
	
	this->extMod->setValue("BROKER_SESSION", session);

	u16RequestType = atoi(data["mt"].c_str());
	string sType = data["request_type"];

	if (sType.compare("subscribe") == 0 ) {
		code = Protocol_SUBSCRIPTION_REQUEST;
	} else if (sType.compare("unsubscribe") == 0)  {
		code = Protocol_UNSUBSCRIPTION_REQUEST;
	}

	map<string,JsonObject> echo = (map<string,JsonObject>) jRequest["echo"];

	map<string,JsonObject>::iterator iter_echo = echo.begin();

	while(iter_echo != echo.end()){
		cout << "iterating echo params.. " << endl;
		string key(iter_echo->first);
		string value(((string) iter_echo->second));

		cout << "key: " << key << ", value: " << value << endl;
		this->extMod->setValue(key, value ) ;

		iter_echo++;
	}
}

uint16_t PushServerRequest::getRequestType()
{
	return u16RequestType;
}

string PushServerRequest::getRequesttype()
{
	return sRequestType;
}

vector<string> PushServerRequest::getSymbolList()
{
	return symbolList;
}
