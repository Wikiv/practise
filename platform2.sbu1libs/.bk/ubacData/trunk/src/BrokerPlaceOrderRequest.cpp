#include "UBACData.h"

BrokerPlaceOrderRequest::BrokerPlaceOrderRequest(string data)
{
	u_securityType = InstrumentType_UNKNOWN;
	sOrigRequest = data;
	setOrderAction( OrderAction_UNKNOWN );
	parse(data);
}

BrokerPlaceOrderRequest::~BrokerPlaceOrderRequest()
{
}

uint8_t BrokerPlaceOrderRequest::getOrderAction()
{
	return u_orderAction;
}

void BrokerPlaceOrderRequest::getInstrumentType(string & sSecurityType)
{
	sSecurityType = this->sSecurityType;
}

uint8_t BrokerPlaceOrderRequest::getInstrumentType()
{
	return u_securityType;
}

void BrokerPlaceOrderRequest::setOrderAction(string m_orderAction)
{
	if(strcasecmp(m_orderAction.c_str(), "ADD") == 0) {
		setOrderAction( OrderAction_ADD );
	} else if(strcasecmp(m_orderAction.c_str(), "EDIT") == 0) {
		setOrderAction( OrderAction_EDIT );
	} else if(strcasecmp(m_orderAction.c_str(), "ADD_OCO") == 0) {
		setOrderAction( OrderAction_ADD_OCO );
	} else if(strcasecmp(m_orderAction.c_str(), "EDIT_OCO") == 0) {
		setOrderAction( OrderAction_EDIT_OCO );
	}
}

void BrokerPlaceOrderRequest::setOrderAction(uint8_t m_orderAction)
{
	u_orderAction = m_orderAction;
}

void BrokerPlaceOrderRequest::setInstrumentType(string m_instrumentType)
{
	this->sSecurityType = m_instrumentType;
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
	} else if(strcasecmp(m_instrumentType.c_str(), "DEBT") == 0) {
		u_securityType = InstrumentType_DEBT;
	}
}

void BrokerPlaceOrderRequest::addOrderLeg(OrderLeg leg)
{
	this->push_back( leg );
}

void BrokerPlaceOrderRequest::parse(string data)
{
	size_t i;
	string buffer = "", name = "";
	int state = 0;
	for(i = 0;i < data.length(); i++) {
		if( (state < 2) && (data[i] == '|') ) {
			switch(state) {
				case 0: setInstrumentType( buffer );
					break;
				case 1: setOrderAction( buffer );
					break;
			}
			buffer.clear();
			state++;
		} else if(data[i] == '&') {
			OrderLeg leg( buffer );
			addOrderLeg( leg );
			buffer.clear();
		} else {
			buffer.append(&data[i], 1);
		}
	}
	if(buffer.length() > 0) {
		OrderLeg leg( buffer );
		addOrderLeg( leg );
	}
}

bool BrokerPlaceOrderRequest::isSymbolValid(string m_symbol)
{
	return (m_symbol.length() > 0);
}

bool BrokerPlaceOrderRequest::isQuantityValid(string m_quantity)
{
	char *endptr;
	int32_t int_qty = strtol(m_quantity.c_str(), &endptr, 0);
	cout << "int_qty = " << int_qty << ", endptr = " << endptr << endl;
	bool flag = ( (int_qty > 0) && (*endptr == '\0'));
	return flag;
}

bool BrokerPlaceOrderRequest::isPriceValid(string m_price)
{
	char *endptr;
	double d = strtod(m_price.c_str(), &endptr);
	cout << "d = " << d << ", endptr = " << endptr << endl;
	bool flag = ( (d > (double)0) && (*endptr == '\0') );
	return flag;
}

bool BrokerPlaceOrderRequest::isSingleLeg()
{
	return (this->size() == 1);
}

bool BrokerPlaceOrderRequest::isAccountIDValid(string m_accountID)
{
	return (m_accountID.length() > 0);
}

string BrokerPlaceOrderRequest::toString()
{
	stringstream sRequest;
	sRequest << UBACData::Protocol_BROKER_PLACE_ORDER << " <" << sOrigRequest << ">";
	return sRequest.str();
}
