#include "UBACData.h"

CommissionLeg::CommissionLeg(string data)
{
	parse(data);
}


CommissionLeg::CommissionLeg()
{
}

CommissionLeg::~CommissionLeg()
{
}

void CommissionLeg::setNameValue(string name, string value)
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
	} else if (strcasecmp(tmp, "CONDITION_TYPE" ) == 0 ) {
		setConditionType(value) ;
	} else if (strcasecmp(tmp, "CONDITION_PRICE" ) == 0 ) {
		setConditionPrice(value);
	} else if (strcasecmp(tmp, "CONDITION_SYMBOL") == 0 ) {	
		setConditionSymbol(value);
        } else {
		setParam(name, value);
	}
}


void CommissionLeg::setConditionType(string value ) 
{
	sConditionType = value;
}

void CommissionLeg::setConditionPrice(string value)
{
	sConditionPrice = value ;
}

void CommissionLeg::setConditionSymbol(string value ) 
{
	sConditionSymbol = value ;
}
void CommissionLeg::setStrategy(string sStrategy){
	strategy = sStrategy;
		
	if (strcasecmp(sStrategy.c_str(),"spread")==0){
		u_strategy = CommissionLeg::Strategy_SPREAD;	
	} else if (strcasecmp(sStrategy.c_str(),"combo")==0){
		u_strategy = CommissionLeg::Strategy_COMBO;
	} else if (strcasecmp(sStrategy.c_str(),"straddle")==0){
		u_strategy = CommissionLeg::Strategy_STRADDLE;
	} else if (strcasecmp(sStrategy.c_str(),"strangle")==0){
		u_strategy = CommissionLeg::Strategy_STRANGLE;
	} else if (strcasecmp(sStrategy.c_str(), "covered_call") == 0){
		u_strategy = CommissionLeg::Strategy_COVERED_CALL;	
	} else if (strcasecmp(sStrategy.c_str(), "protective_put") == 0) {
		u_strategy = CommissionLeg::Strategy_PROTECTIVE_PUT;
	} else if (strcasecmp(sStrategy.c_str(), "married_put") == 0){
		u_strategy = CommissionLeg::Strategy_PROTECTIVE_PUT;
	} else if (strcasecmp(sStrategy.c_str(), "collar") == 0){
		u_strategy = CommissionLeg::Strategy_COLLAR;
	} else if (strcasecmp(sStrategy.c_str(), "condor") == 0){
		u_strategy = CommissionLeg::Strategy_CONDOR;
	} else if (strcasecmp(sStrategy.c_str(), "iron_condor") == 0){
		u_strategy = CommissionLeg::Strategy_IRON_CONDOR;
	} else if (strcasecmp(sStrategy.c_str(), "butterfly") == 0){
		u_strategy = CommissionLeg::Strategy_BUTTERFLY;
	} else if (strcasecmp(sStrategy.c_str(), "iron_butterfly") == 0){
		u_strategy = CommissionLeg::Strategy_IRON_BUTTERFLY;
	} else {
		u_strategy = CommissionLeg::Strategy_UNKNOWN;
	}
}

uint8_t CommissionLeg::getStrategy(){
	return u_strategy;
}

void CommissionLeg::getStrategy(string &sStrategy ){
	sStrategy.clear();
	sStrategy.append(strategy);
}

void CommissionLeg::setSpreadId(string spreadId){
	s_SpreadId = spreadId;
}

string CommissionLeg::getSpreadId(){
	return 	s_SpreadId;
}

void CommissionLeg::setOrderId(string order_id){
	cout << "in set orderid" << endl;
	s_orderId = order_id;
}

string CommissionLeg::getOrderId(){
	cout  << "returning orderid" << endl;
	return s_orderId;
}
void CommissionLeg::setSymbol(string m_symbol)
{
	CONVERT_TO_STRING( m_symbol, symbol );
}

string CommissionLeg::getSymbol()
{
	return symbol;
}

void CommissionLeg::setSide(string m_side)
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

uint8_t CommissionLeg::getSide()
{
	return u_orderSide;
}

void CommissionLeg::getSide(string & m_side)
{
	m_side = side;
}

void CommissionLeg::setOrderType(string m_orderType)
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
	} else if (strcasecmp ( m_orderType.c_str(), "walk_limit_debit") == 0 ) {	
		u_orderType = OrderType_WALKLIMIT_DEBIT;
	} else if (strcasecmp ( m_orderType.c_str(), "walk_limit_credit") == 0 ) {	
		u_orderType = OrderType_WALKLIMIT_CREDIT;
	}
}

uint8_t CommissionLeg::getOrderType()
{
	return u_orderType;
}

void CommissionLeg::getOrderType(string & m_orderType)
{
	CONVERT_TO_STRING(orderType, m_orderType);
}

void CommissionLeg::setLimitPrice(string m_limitPrice)
{
	CONVERT_TO_STRING(m_limitPrice, limitPrice)
}

string CommissionLeg::getLimitPrice()
{
	return limitPrice;
}

void CommissionLeg::setStopPrice(string m_stopPrice)
{
	CONVERT_TO_STRING(m_stopPrice, stopPrice);
}

string CommissionLeg::getStopPrice()
{
	return stopPrice;
}

void CommissionLeg::setExpiryDay(string m_expiryDay)
{
	expiryDay.append(m_expiryDay);
}

string CommissionLeg::getExpiryDay()
{
	return expiryDay;
}

string CommissionLeg::getConditionType()
{
	return this->sConditionType;

}

string CommissionLeg::getConditionSymbol()
{
	return this->sConditionSymbol;
}

string CommissionLeg::getConditionPrice()
{
	return this->sConditionPrice;
}

void CommissionLeg::setExpiryMonth(string m_expiryMonth)
{
	expiryMonth.append(m_expiryMonth);
}

string CommissionLeg::getExpiryMonth()
{
	return expiryMonth;
}

void CommissionLeg::setExpiryYear(string m_expiryYear)
{
	expiryYear.append(m_expiryYear);
}

string CommissionLeg::getExpiryYear()
{
	return expiryYear;
}

void CommissionLeg::setParam(string name, string value)
{
	IFHelper helper;
	helper.upcase(name);
	otherParams.insert( make_pair(name, value) );
}

string CommissionLeg::getParam(string name)
{
	map<string, string>::iterator iParam = otherParams.find(name);
	return ( (iParam == otherParams.end()) ? "" : iParam->second);
}

void CommissionLeg::setQuantity(string m_quantity)
{
	CONVERT_TO_STRING( m_quantity, quantity );
}

string CommissionLeg::getQuantity()
{
	return quantity;
}

void CommissionLeg::setAccountID(string m_accountID)
{
	CONVERT_TO_STRING( m_accountID, accountId );
}

string CommissionLeg::getAccountID()
{
	return accountId;
}

void CommissionLeg::setTimeInForce(string m_timeInForce)
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

uint8_t CommissionLeg::getTimeInForce()
{
	return u_timeInForce;
}

void CommissionLeg::getTimeInForce(string & m_timeInFoce)
{
	CONVERT_TO_STRING(timeInForce, m_timeInFoce);
}

void CommissionLeg::parse(string data)
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

