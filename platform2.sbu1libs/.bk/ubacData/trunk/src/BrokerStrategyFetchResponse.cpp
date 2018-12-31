#include "UBACData.h"

BrokerStrategyFetchResponse::BrokerStrategyFetchResponse(string data){
}
BrokerStrategyFetchResponse::BrokerStrategyFetchResponse(){
}
BrokerStrategyFetchResponse::~BrokerStrategyFetchResponse(){
}

void BrokerStrategyFetchResponse::setErrorMessage(string ErrorMessage){
	error.append(ErrorMessage);
}
string BrokerStrategyFetchResponse::getErrorMessage(){
	return error;
}

string BrokerStrategyFetchResponse::toString(){
	string response;
	if (strcmp(error.c_str(),"")==0){
		CSVData *newCSV = (CSVData*) this;
		stringstream res; res << UBACData::Protocol_BROKER_STRATEGY +2 << " <";
		response = res.str() ;	
		newCSV->toString(response, '|');
		response.append(">");
		cout << "response: " << response << endl;
	
	} else {
	
		stringstream res; 
		res << UBACData::Protocol_BROKER_STRATEGY +2 << "<" << error << ">";
	       	response.append(res.str());	
	}
	return response;
}


