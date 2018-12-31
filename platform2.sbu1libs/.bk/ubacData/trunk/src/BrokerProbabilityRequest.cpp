#include "UBACData.h"

BrokerProbabilityRequest::BrokerProbabilityRequest(string data)
{
	this->setMobileRequest(data);
	parse(data);
}

BrokerProbabilityRequest::~BrokerProbabilityRequest()
{
}

string BrokerProbabilityRequest::getMobileRequest()
{
	return this->sMobileRequest;
}

void BrokerProbabilityRequest::setMobileRequest(string mobileRequest)
{
	this->sMobileRequest = mobileRequest;
}

uint8_t BrokerProbabilityRequest::getInstrumentType()
{
	return u_securityType;
}

void BrokerProbabilityRequest::setInstrumentType(string m_instrumentType)
{
	if( (strncasecmp(m_instrumentType.c_str(), "EQUITY", 6) == 0) || (strncasecmp(m_instrumentType.c_str(), "STOCK", 5) == 0)){
		u_securityType = InstrumentType_EQUITY;
	} else if(strncasecmp(m_instrumentType.c_str(), "OPTION", 6) == 0) {
		u_securityType = InstrumentType_OPTIONS;
	} else if(strcasecmp(m_instrumentType.c_str(), "FUNDS") == 0) {
		u_securityType = InstrumentType_FUNDS;
	} else if(strcasecmp(m_instrumentType.c_str(), "FOREX") == 0) {
		u_securityType = InstrumentType_FOREX;
	} else if(strcasecmp(m_instrumentType.c_str(), "FUTURE_OPTIONS") == 0) {
		u_securityType = InstrumentType_FUTURE_OPTIONS;
	} else if(strncasecmp(m_instrumentType.c_str(), "FUTURES", 6) == 0) {
		u_securityType = InstrumentType_FUTURES;
	} else if(strcasecmp(m_instrumentType.c_str(), "MINIOPTION") == 0) {
		u_securityType = InstrumentType_MINIOPTION;
	}
	cout << "u_securityType: " << ( (u_securityType==InstrumentType_FUTURE_OPTIONS)? "futuretoptions": "failedsssssssssssss" ) << endl;
}

void BrokerProbabilityRequest::addLeg(ProbabilityCalcLeg leg)
{
	this->push_back( leg );
}

void BrokerProbabilityRequest::setOrderAction(string s_action){
	if (strcasecmp(s_action.c_str(), "ADD")==0){
		u_orderAction = OrderAction_ADD;
	} else if (strcasecmp(s_action.c_str(), "EDIT") ==0 ) {
		u_orderAction = OrderAction_EDIT;
	} else {
		u_orderAction = OrderAction_UNKNOWN;
	}
}

uint8_t BrokerProbabilityRequest::getOrderAction(){

	return u_orderAction;
}


void BrokerProbabilityRequest::parse(string data)
{
	size_t i;
	string buffer = "", name = "";
	int state = 0;
	for(i = 0;i < data.length(); i++) {
		if ( ( state < 1 ) && ( data[i] == '|' ) ) {
			switch(state) {
				case 0: setInstrumentType( buffer );
					break;
			}
			buffer.clear();
			state++;	
		} else if (state == 1 && data[i] == '|') {
			setOrderAction(buffer);
			buffer.clear();
			state++;
		} else if(data[i] == '&') {
			ProbabilityCalcLeg leg( buffer );
			addLeg( leg );
			buffer.clear();
		} else {
			buffer.append(&data[i], 1);
		}
	}
	if(buffer.length() > 0) {
		ProbabilityCalcLeg leg( buffer );
		addLeg( leg );
	}
}

