#include "UBACData.h"

ProbabilityCalcLeg::ProbabilityCalcLeg(string data)
{
	parse(data);
}


ProbabilityCalcLeg::ProbabilityCalcLeg()
{
}

ProbabilityCalcLeg::~ProbabilityCalcLeg()
{
}

void ProbabilityCalcLeg::setNameValue(string name, string value)
{
	const char *tmp = name.c_str();
	if( strcasecmp(tmp, "QUANTITY") == 0 ) {
		stringstream qStream;
		qStream << atoi( value.c_str() );
		setQuantity( qStream.str() );
	} else if( strcasecmp(tmp, "SPREAD_ID") == 0 ) {
		setSpreadId( value );
	} else if( strcasecmp(tmp, "ORDER_ID") == 0 ) {
		setOrderId( value );
	} else if( strcasecmp(tmp, "EXPIRY") == 0 ) {
		setTimeInForce( value );
	} else if( strcasecmp(tmp, "ACCOUNT_ID") == 0 ) {
		accountId.append(value);
	} else if( strcasecmp(tmp, "SYMBOL") == 0 ) {
		setSymbol(value);
	} else if( strcasecmp(tmp, "ACTION") == 0 ) {
		setSide(value);
	} else if( strcasecmp(tmp, "ORDER_TYPE") == 0 ) {
		setOrderType(value);
	} else if( strcasecmp(tmp, "LIMIT_PRICE") == 0 ) {
		setLimitPrice(value);
	} else if( (strcasecmp(tmp, "STOP_PRICE") == 0) || (strcasecmp(tmp, "ACTION_PRICE") == 0) ) {
		setStopPrice(value);
	} else if( strcasecmp(tmp, "EXPIRY_DAY") == 0 ) {
		setExpiryDay(value);
	} else if( strcasecmp(tmp, "EXPIRY_MONTH") == 0 ) {
		setExpiryMonth(value);
	} else if( strcasecmp(tmp, "EXPIRY_YEAR") == 0 ) {
		setExpiryYear(value);
	} else if( strcasecmp(tmp, "STRATEGY") == 0 ) {
		setStrategy(value);
        } else {
		setParam(name, value);
	}
}

void ProbabilityCalcLeg::setStrategy(string sStrategy){
	strategy = sStrategy;
		
	if (strcasecmp(sStrategy.c_str(),"spread")==0){
		u_strategy = ProbabilityCalcLeg::Strategy_SPREAD;	
	} else if (strcasecmp(sStrategy.c_str(),"combo")==0){
		u_strategy = ProbabilityCalcLeg::Strategy_COMBO;
	} else if (strcasecmp(sStrategy.c_str(),"straddle")==0){
		u_strategy = ProbabilityCalcLeg::Strategy_STRADDLE;
	} else if (strcasecmp(sStrategy.c_str(),"strangle")==0){
		u_strategy = ProbabilityCalcLeg::Strategy_STRANGLE;
	} else if (strcasecmp(sStrategy.c_str(), "covered_call") == 0){
		u_strategy = ProbabilityCalcLeg::Strategy_COVERED_CALL;	
	} else if (strcasecmp(sStrategy.c_str(), "protective_put") == 0) {
		u_strategy = ProbabilityCalcLeg::Strategy_PROTECTIVE_PUT;
	} else if (strcasecmp(sStrategy.c_str(), "married_put") == 0){
		u_strategy = ProbabilityCalcLeg::Strategy_PROTECTIVE_PUT;
	} else if (strcasecmp(sStrategy.c_str(), "collar") == 0){
		u_strategy = ProbabilityCalcLeg::Strategy_COLLAR;
	} else if (strcasecmp(sStrategy.c_str(), "condor") == 0){
		u_strategy = ProbabilityCalcLeg::Strategy_CONDOR;
	} else if (strcasecmp(sStrategy.c_str(), "iron_condor") == 0){
		u_strategy = ProbabilityCalcLeg::Strategy_IRON_CONDOR;
	} else if (strcasecmp(sStrategy.c_str(), "butterfly") == 0){
		u_strategy = ProbabilityCalcLeg::Strategy_BUTTERFLY;
	} else if (strcasecmp(sStrategy.c_str(), "iron_butterfly") == 0){
		u_strategy = ProbabilityCalcLeg::Strategy_IRON_BUTTERFLY;
	} else {
		u_strategy = ProbabilityCalcLeg::Strategy_UNKNOWN;
	}
}

uint8_t ProbabilityCalcLeg::getStrategy(){
	return u_strategy;
}

void ProbabilityCalcLeg::getStrategy(string &sStrategy ){
	sStrategy.clear();
	sStrategy.append(strategy);
}

void ProbabilityCalcLeg::setSpreadId(string spreadId){
	s_SpreadId = spreadId;
}

string ProbabilityCalcLeg::getSpreadId(){
	return 	s_SpreadId;
}

void ProbabilityCalcLeg::setOrderId(string order_id){
	cout << "in set orderid" << endl;
	s_orderId = order_id;
}

string ProbabilityCalcLeg::getOrderId(){
	cout  << "returning orderid" << endl;
	return s_orderId;
}
void ProbabilityCalcLeg::setSymbol(string m_symbol)
{
	CONVERT_TO_STRING( m_symbol, symbol );
}

string ProbabilityCalcLeg::getSymbol()
{
	return symbol;
}

void ProbabilityCalcLeg::setSide(string m_side)
{
	side.append( m_side );
        u_orderSide = OrderSide_UNKNOWN;
        if( strcasecmp( m_side.c_str(), "buy" ) == 0 ) { 
                u_orderSide = OrderSide_BUY;
        } else if( strcasecmp( m_side.c_str(), "sell") == 0 ) { 
                u_orderSide = OrderSide_SELL;
        } else if( strcasecmp( m_side.c_str(), "sellshort") == 0 ) { 
                u_orderSide = OrderSide_SELL_SHORT;
        } else if( strcasecmp( m_side.c_str(), "buytocover") == 0 ) { 
                u_orderSide = OrderSide_BUY_TO_COVER;
        } else if( strcasecmp( m_side.c_str(), "buytoopen") == 0 ) { 
                u_orderSide = OrderSide_BUY_TO_OPEN;
        } else if( strcasecmp( m_side.c_str(), "buytoclose") == 0 ) { 
                u_orderSide = OrderSide_BUY_TO_CLOSE;
        } else if( strcasecmp( m_side.c_str(), "selltoopen") == 0 ) { 
                u_orderSide = OrderSide_SELL_TO_OPEN;
        } else if( strcasecmp( m_side.c_str(), "selltoclose") == 0 ) { 
                u_orderSide = OrderSide_SELL_TO_CLOSE;
        } else if( strcasecmp( m_side.c_str(), "subscription") == 0 ) { 
                u_orderSide = OrderSide_SUBSCRIPTION;
        } else if( strcasecmp( m_side.c_str(), "redemption") == 0 ) { 
                u_orderSide = OrderSide_REDEMPTION;
        } else if( strcasecmp( m_side.c_str(), "buymargin" ) == 0 ) { 
                u_orderSide = OrderSide_BUY_MARGIN;
        } else if( strcasecmp( m_side.c_str(), "sellmargin" ) == 0 ) { 
                u_orderSide = OrderSide_SELL_MARGIN;
        }
}

uint8_t ProbabilityCalcLeg::getSide()
{
	return u_orderSide;
}

void ProbabilityCalcLeg::getSide(string & m_side)
{
	m_side = side;
}

void ProbabilityCalcLeg::setOrderType(string m_orderType)
{
        orderType.append( m_orderType );
        u_orderType = OrderType_UNKNOWN;
        if( strcasecmp( m_orderType.c_str(), "market") == 0 ) { 
                u_orderType = OrderType_MARKET;
        } else if( strcasecmp( m_orderType.c_str(), "limit" ) == 0 ) { 
                u_orderType = OrderType_LIMIT;
        } else if( (strcasecmp( m_orderType.c_str(), "stop_market" ) == 0) || (strcasecmp( m_orderType.c_str(), "stop") == 0) ) { 
                u_orderType = OrderType_STOP;
        } else if( strcasecmp( m_orderType.c_str(), "stop_limit" ) == 0 ) { 
                u_orderType = OrderType_STOP_LIMIT;
        } else if( strcasecmp( m_orderType.c_str(), "moc" ) == 0 ) { 
                u_orderType = OrderType_MOC;
        } else if( strcasecmp( m_orderType.c_str(), "loc" ) == 0 ) { 
                u_orderType = OrderType_LOC;
        } else if( strcasecmp( m_orderType.c_str(), "moo" ) == 0 ) { 
                u_orderType = OrderType_MOO;
        } else if( strcasecmp( m_orderType.c_str(), "loo" ) == 0 ) { 
                u_orderType = OrderType_LOO;
        } else if( strcasecmp( m_orderType.c_str(), "TSTOPPERCENT" ) == 0 ) { 
                u_orderType = OrderType_TRAILING_STOP_PERCENT;
        } else if( strcasecmp( m_orderType.c_str(), "TSTOPDOLLAR" ) == 0 ) { 
                u_orderType = OrderType_TRAILING_STOP_DOLLAR;
        } else if( strcasecmp( m_orderType.c_str(), "credit" ) == 0 ) { 
                u_orderType = OrderType_CREDIT;
        } else if( strcasecmp( m_orderType.c_str(), "debit" ) == 0 ) { 
                u_orderType = OrderType_DEBIT;
        } else if( strcasecmp( m_orderType.c_str(), "even" ) == 0 ) { 
                u_orderType = OrderType_EVEN;
        } else if( strcasecmp( m_orderType.c_str(), "pegged" ) == 0 ) { 
                u_orderType = OrderType_PEGGED;
        } else if( strcasecmp( m_orderType.c_str(), "tto" ) == 0 ) { 
                u_orderType = OrderType_TTO;
	}
}

uint8_t ProbabilityCalcLeg::getOrderType()
{
	return u_orderType;
}

void ProbabilityCalcLeg::getOrderType(string & m_orderType)
{
	CONVERT_TO_STRING(orderType, m_orderType);
}

void ProbabilityCalcLeg::setLimitPrice(string m_limitPrice)
{
	CONVERT_TO_STRING(m_limitPrice, limitPrice)
}

string ProbabilityCalcLeg::getLimitPrice()
{
	return limitPrice;
}

void ProbabilityCalcLeg::setStopPrice(string m_stopPrice)
{
	CONVERT_TO_STRING(m_stopPrice, stopPrice);
}

string ProbabilityCalcLeg::getStopPrice()
{
	return stopPrice;
}

void ProbabilityCalcLeg::setExpiryDay(string m_expiryDay)
{
	expiryDay.append(m_expiryDay);
}

string ProbabilityCalcLeg::getExpiryDay()
{
	return expiryDay;
}

void ProbabilityCalcLeg::setExpiryMonth(string m_expiryMonth)
{
	expiryMonth.append(m_expiryMonth);
}

string ProbabilityCalcLeg::getExpiryMonth()
{
	return expiryMonth;
}

void ProbabilityCalcLeg::setExpiryYear(string m_expiryYear)
{
	expiryYear.append(m_expiryYear);
}

string ProbabilityCalcLeg::getExpiryYear()
{
	return expiryYear;
}

void ProbabilityCalcLeg::setParam(string name, string value)
{
	IFHelper helper;
	helper.upcase(name);
	otherParams.insert( make_pair(name, value) );
}

string ProbabilityCalcLeg::getParam(string name)
{
	map<string, string>::iterator iParam = otherParams.find(name);
	return ( (iParam == otherParams.end()) ? "" : iParam->second);
}

void ProbabilityCalcLeg::setQuantity(string m_quantity)
{
	CONVERT_TO_STRING( m_quantity, quantity );
}

string ProbabilityCalcLeg::getQuantity()
{
	return quantity;
}

void ProbabilityCalcLeg::setAccountID(string m_accountID)
{
	CONVERT_TO_STRING( m_accountID, accountId );
}

string ProbabilityCalcLeg::getAccountID()
{
	return accountId;
}

void ProbabilityCalcLeg::setTimeInForce(string m_timeInForce)
{
	timeInForce.append( m_timeInForce );
	if( strcasecmp( m_timeInForce.c_str(), "day" ) == 0 ) {
		u_timeInForce = TimeInForce_DAY;
	} else if( strcasecmp( m_timeInForce.c_str(), "gtc" ) == 0 ) {
		u_timeInForce = TimeInForce_GTC;
	} else if( strcasecmp( m_timeInForce.c_str(), "IOC" ) == 0 ) {
		u_timeInForce = TimeInForce_IOC;
	} else if( strcasecmp( m_timeInForce.c_str(), "FOK" ) == 0 ) {
		u_timeInForce = TimeInForce_FOK;
	} else if( strcasecmp( m_timeInForce.c_str(), "DAY_EXT" ) == 0 ) {
		u_timeInForce = TimeInForce_DAY_EXT;
	} else if( strcasecmp( m_timeInForce.c_str(), "MOC" ) == 0 ) {
		u_timeInForce = TimeInForce_MOC;
	} else if( strcasecmp( m_timeInForce.c_str(), "GTC_EXT" ) == 0 ) {
		u_timeInForce = TimeInForce_GTC_EXT;
	} else if( strcasecmp( m_timeInForce.c_str(), "AM" ) == 0 ) {
		u_timeInForce = TimeInForce_AM;
	} else if( strcasecmp( m_timeInForce.c_str(), "PM" ) == 0 ) {
		u_timeInForce = TimeInForce_PM;
	} else if( strcasecmp( m_timeInForce.c_str(), "GTD" ) == 0 ) { 
		u_timeInForce = TimeInForce_GTD;
	} else if( strcasecmp( m_timeInForce.c_str(), "GTD_EXT" ) == 0 ) { 
		u_timeInForce = TimeInForce_GTD_EXT;
	} else if( strcasecmp( m_timeInForce.c_str(), "OPG" ) == 0 ) { 
		u_timeInForce = TimeInForce_OPG;
	} else if( strcasecmp( m_timeInForce.c_str(), "CLO" ) == 0 ) { 
		u_timeInForce = TimeInForce_CLO;
	} else if( strcasecmp( m_timeInForce.c_str(), "MINUTE" ) == 0 ) { 
		u_timeInForce = TimeInForce_MINUTE;
	}
}

uint8_t ProbabilityCalcLeg::getTimeInForce()
{
	return u_timeInForce;
}

void ProbabilityCalcLeg::getTimeInForce(string & m_timeInFoce)
{
	CONVERT_TO_STRING(timeInForce, m_timeInFoce);
}

void ProbabilityCalcLeg::parse(string data)
{
	string name, value;
	bool isName = true;
	for(size_t i = 0; i < data.length(); i++) {
		if( data[i] == '=' ) {
			isName = false;
		} else if( data[i] == '|' ) {
			setNameValue( name, value );
			name.clear();
			value.clear();
			isName = true;
		} else {
			(isName) ? name.append(&data[i], 1) : value.append(&data[i], 1);
		}
	}
	setNameValue( name, value );
}

