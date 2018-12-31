#include "UBACData.h"

BrokerCommissionRequest::BrokerCommissionRequest(string data)
{
	parse(data);
}

BrokerCommissionRequest::~BrokerCommissionRequest()
{
}

uint8_t BrokerCommissionRequest::getInstrumentType()
{
	return u_securityType;
}

void BrokerCommissionRequest::setInstrumentType(string m_instrumentType)
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

void BrokerCommissionRequest::addCommissionLeg(CommissionLeg leg)
{
	this->push_back( leg );
}

void BrokerCommissionRequest::setOrderAction(string s_action){
	if (strcasecmp(s_action.c_str(), "ADD")==0){
		u_orderAction = OrderAction_ADD;
	} else if (strcasecmp(s_action.c_str(), "EDIT") ==0 ) {
		u_orderAction = OrderAction_EDIT;
	} else {
		u_orderAction = OrderAction_UNKNOWN;
	}
}

uint8_t BrokerCommissionRequest::getOrderAction(){

	return u_orderAction;
}


void BrokerCommissionRequest::parse(string data)
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
			CommissionLeg leg( buffer );
			addCommissionLeg( leg );
			buffer.clear();
		} else {
			buffer.append(&data[i], 1);
		}
	}
	if(buffer.length() > 0) {
		CommissionLeg leg( buffer );
		addCommissionLeg( leg );
	}
}

