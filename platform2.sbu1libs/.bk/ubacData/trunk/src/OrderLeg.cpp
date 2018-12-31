#include "UBACData.h"

OrderLeg::OrderLeg(string data)
{
	b_Plus = false;
	sLegString.append( data );
	u_timeInForce = TimeInForce_UNKNOWN;
	u_orderSide = OrderSide_UNKNOWN;
	u_orderType = OrderType_UNKNOWN;
	u_spinInstruction = SpinInstruction_NONE;
	parse(data);
}

OrderLeg::OrderLeg()
{
}

void OrderLeg::setSymbol(string m_symbol)
{
	CONVERT_TO_STRING(m_symbol, symbol);
}

string OrderLeg::getSymbol()
{
	return symbol;
}

bool OrderLeg::isPlus(){
	return b_Plus;
	
}

uint8_t OrderLeg::getExectionOrderType(){
	return u_ExecutionOrderType;
}

uint8_t OrderLeg::getBasicOrderType(){
	return u_BasicOrderType;
}

void OrderLeg::setSide(string m_side)
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
	} else if( strcasecmp( m_side.c_str(), "sip" ) == 0 ) {
		u_orderSide = OrderSide_SIP;
	} else if( strcasecmp( m_side.c_str(), "swp" ) == 0 ) {
                u_orderSide = OrderSide_SWP;
	} else if( strcasecmp( m_side.c_str(), "partialswitch" ) == 0 ) {
		u_orderSide = OrderSide_PARTIAL_SWITCH;
	} else if( strcasecmp( m_side.c_str(), "fullswitch" ) == 0 ) {
                u_orderSide = OrderSide_FULL_SWITCH;
        } else if( strcasecmp( m_side.c_str(), "sellall" ) == 0 ) {
                u_orderSide = OrderSide_SELL_ALL;
        } else if( strcasecmp( m_side.c_str(), "shortex" ) == 0 ) {
		u_orderSide = OrderSide_SHORT_EX;
	}
}

uint8_t OrderLeg::getSide()
{
	return u_orderSide;
}

void OrderLeg::getSide(string & m_side)
{
	CONVERT_TO_STRING(side, m_side);
}

void OrderLeg::setOrderType(string m_orderType)
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
	} else if( strcasecmp( m_orderType.c_str(), "mit" ) == 0 ) {
		u_orderType = OrderType_MIT;
	} else if( strcasecmp( m_orderType.c_str(), "lit" ) == 0 ) {
		u_orderType = OrderType_LIT;
	} else if( strcasecmp( m_orderType.c_str(), "its" ) == 0 ) {
		u_orderType = OrderType_ITS;
	} else if( strcasecmp( m_orderType.c_str(), "gtc_limit" ) == 0 ) {
		u_orderType = OrderType_GTC_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "gtc_stop_limit" ) == 0 ) {
		u_orderType = OrderType_GTC_STOP_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "gtc_stop" ) == 0 ) {
		u_orderType = OrderType_GTC_STOP;
	} else if( strcasecmp( m_orderType.c_str(), "gtd_market" ) == 0 ) {
                u_orderType = OrderType_GTD_MARKET;
	} else if( strcasecmp( m_orderType.c_str(), "gtd_limit" ) == 0 ) {
		u_orderType = OrderType_GTD_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "gtd_stop_limit" ) == 0 ) {
		u_orderType = OrderType_GTD_STOP_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "gtd_stop" ) == 0 ) {
		u_orderType = OrderType_GTD_STOP;
	} else if( strcasecmp( m_orderType.c_str(), "gtt_market" ) == 0 ) {
                u_orderType = OrderType_GTT_MARKET;
	} else if( strcasecmp( m_orderType.c_str(), "gtt_limit" ) == 0 ) {
                u_orderType = OrderType_GTT_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "gtt_stop_limit" ) == 0 ) {
                u_orderType = OrderType_GTT_STOP_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "gtt_stop" ) == 0 ) {
                u_orderType = OrderType_GTT_STOP;
	} else if( strcasecmp( m_orderType.c_str(), "stop_limit_fak" ) == 0 ) {
		u_orderType = OrderType_STOP_LIMIT_FAK;
	} else if( strcasecmp( m_orderType.c_str(), "stop_limit_fok" ) == 0 ) {
		u_orderType = OrderType_STOP_LIMIT_FOK;
	} else if( strcasecmp( m_orderType.c_str(), "limit_fak" ) == 0 ) {
		u_orderType = OrderType_LIMIT_FAK;
	} else if( strcasecmp( m_orderType.c_str(), "limit_fok" ) == 0 ) {
		u_orderType = OrderType_LIMIT_FOK;
	} else if( strcasecmp( m_orderType.c_str(), "best_limit" ) == 0 ) {
		u_orderType = OrderType_BEST_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "market_fak" ) == 0 ) {
		u_orderType = OrderType_MARKET_FAK;
	} else if( strcasecmp( m_orderType.c_str(), "market_fok" ) == 0 ) {
		u_orderType = OrderType_MARKET_FOK;
	} else if( strcasecmp( m_orderType.c_str(), "market_limit_fak" ) == 0 ) {
		u_orderType = OrderType_MARKET_LIMIT_FAK;
	} else if( strcasecmp( m_orderType.c_str(), "market_limit_fok" ) == 0 ) {
		u_orderType = OrderType_MARKET_LIMIT_FOK;
	} else if( strcasecmp( m_orderType.c_str(), "market_to_limit" ) == 0 ) {
		u_orderType = OrderType_MARKET_TO_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "rfqi" ) == 0 ) {
		u_orderType = OrderType_RFQI;
	} else if( strcasecmp( m_orderType.c_str(), "rfqt" ) == 0 ) {
		u_orderType = OrderType_RFQT;
	} else if( strcasecmp( m_orderType.c_str(), "rfq" ) == 0 ) {
		u_orderType = OrderType_RFQ;
	} else if( strcasecmp( m_orderType.c_str(), "rsvd_qty" ) == 0 ) {
		u_orderType = OrderType_RSVD_QTY;
	} else if( strcasecmp( m_orderType.c_str(), "aa" ) == 0 ) {
		u_orderType = OrderType_AA;
	} else if( strcasecmp( m_orderType.c_str(), "basis" ) == 0 ) {
		u_orderType = OrderType_BASIS;
	} else if( strcasecmp( m_orderType.c_str(), "block" ) == 0 ) {
		u_orderType = OrderType_BLOCK;
	} else if( strcasecmp( m_orderType.c_str(), "cross" ) == 0 ) {
		u_orderType = OrderType_CROSS;
	} else if( strcasecmp( m_orderType.c_str(), "efs" ) == 0 ) {
		u_orderType = OrderType_EFS;
	} else if( strcasecmp( m_orderType.c_str(), "tas_strat" ) == 0 ) {
		u_orderType = OrderType_TAS_STRAT;
	} else if( strcasecmp( m_orderType.c_str(), "xeurex" ) == 0 ) {
		u_orderType = OrderType_XEUREX;
	} else if( strcasecmp( m_orderType.c_str(), "sso_close" ) == 0 ) {
		u_orderType = OrderType_SSO_CLOSE;
	} else if( strcasecmp( m_orderType.c_str(), "sso_open" ) == 0 ) {
		u_orderType = OrderType_SSO_OPEN;
	} else if( strcasecmp( m_orderType.c_str(), "funari" ) == 0 ) {
		u_orderType = OrderType_FUNARI;
	} else if( strcasecmp( m_orderType.c_str(), "oco" ) == 0 ) {
		u_orderType = OrderType_OCO;
	} else if( strcasecmp( m_orderType.c_str(), "best" ) == 0 ) {
	 	u_orderType = OrderType_BEST;
	} else if( strcasecmp( m_orderType.c_str(), "summary" ) == 0 ) {
		u_orderType = OrderType_SUMMARY;
	} else if( strcasecmp( m_orderType.c_str(), "summary_edit" ) == 0 ) {
		u_orderType = OrderType_SUMMARY_EDIT;
	} else if( strcasecmp( m_orderType.c_str(), "RESERVE" ) == 0 ) {
		u_orderType = OrderType_RESERVE;
	} else if( strcasecmp( m_orderType.c_str(), "DISCRETIONARY" ) == 0 ) {
		u_orderType = OrderType_DESCRET;
	} else if( strcasecmp( m_orderType.c_str(), "DISCRETIONARY_RESERVE" ) == 0 ) {
		u_orderType = OrderType_RESERVE_DESCRET;
	} else if( strcasecmp( m_orderType.c_str(), "MARKET_PLUS_TRAIL") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_MARKET;
		u_ExecutionOrderType = OrderType_ITS;
		u_orderType = OrderType_MARKET_PLUS_TRAIL;
	} else if( strcasecmp( m_orderType.c_str(), "MARKET_PLUS_TTO") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_MARKET;
		u_ExecutionOrderType = OrderType_TTO;
		u_orderType = OrderType_MARKET_PLUS_TTO;
	} else if( strcasecmp( m_orderType.c_str(), "LIMIT_PLUS_TRAIL") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_LIMIT;
		u_ExecutionOrderType = OrderType_ITS;
		u_orderType = OrderType_LIMIT_PLUS_TRAIL;
	} else if( strcasecmp( m_orderType.c_str(), "LIMIT_PLUS_STOP") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_LIMIT;
		u_ExecutionOrderType = OrderType_STOP;
		u_orderType = OrderType_LIMIT_PLUS_STOP;
	} else if( strcasecmp( m_orderType.c_str(), "LIMIT_PLUS_TTO") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_LIMIT;
		u_ExecutionOrderType = OrderType_TTO;
		u_orderType = OrderType_LIMIT_PLUS_TRAIL;
	} else if( strcasecmp( m_orderType.c_str(), "MARKET_PLUS_STOP") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_MARKET ;
		u_ExecutionOrderType = OrderType_STOP;
		u_orderType = OrderType_LIMIT_PLUS_TTO;
	} else if( strcasecmp( m_orderType.c_str(), "STOP_PLUS_LIMIT") == 0){
		u_BasicOrderType = OrderType_STOP;
		u_ExecutionOrderType = OrderType_LIMIT;
		b_Plus = true;
		u_orderType = OrderType_STOP_PLUS_LIMIT;
	} else if( strcasecmp( m_orderType.c_str(), "STOP_PLUS_TTO") == 0){
		b_Plus = true;
		u_orderType = OrderType_STOP;
		u_BasicOrderType = OrderType_STOP;
		u_ExecutionOrderType = OrderType_TTO;
	} else if( strcasecmp( m_orderType.c_str(), "STOP_PLUS_TRAIL") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_STOP ;
		u_ExecutionOrderType = OrderType_ITS;
		u_orderType = OrderType_STOP_PLUS_TRAIL;
	} else if( strcasecmp( m_orderType.c_str(), "STOP_LIMIT_PLUS_TTO") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_STOP_LIMIT ;
		u_ExecutionOrderType = OrderType_TTO ;
		u_orderType = OrderType_STOP_LIMIT_PLUS_TTO;
	} else if( strcasecmp( m_orderType.c_str(), "STOP_LIMIT_PLUS_TRAIL") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_STOP_LIMIT;
		u_ExecutionOrderType = OrderType_ITS;
		u_orderType = OrderType_STOP_LIMIT_PLUS_TRAIL;
	} else if( strcasecmp( m_orderType.c_str(), "RESERVE_TTO") == 0){
		b_Plus = true;
		u_BasicOrderType = OrderType_RESERVE;
		u_ExecutionOrderType = OrderType_TTO;
		u_orderType = OrderType_RESERVE_PLUS_TTO;
	} else if( strcasecmp( m_orderType.c_str(), "on_stop" ) == 0 ){
                u_orderType = OrderType_ON_STOP;
	} else if (strcasecmp ( m_orderType.c_str(), "walk_limit_debit") == 0 ) {	
		u_orderType = OrderType_WALKLIMIT_DEBIT;
	} else if (strcasecmp ( m_orderType.c_str(), "walk_limit_credit") == 0 ) {	
		u_orderType = OrderType_WALKLIMIT_CREDIT;
 	} else if (strcasecmp( m_orderType.c_str(), "market_next") == 0 ) {
                u_orderType = OrderType_MARKET_NEXT;
	}
}

void OrderLeg::setStrategy(string sStrategyName)
{
	if( sStrategyName[0] == '=' ) 
		sStrategyName = sStrategyName.substr(1, sStrategyName.length() - 1);
	u_strategyType = Strategy_UNKNOWN;
	this->sStrategy.append( sStrategyName );
	const char *c_strategy_name = sStrategyName.c_str();
	if( strcasecmp(c_strategy_name, "spread") == 0 ) {
		u_strategyType = Strategy_SPREAD;
	} else if( strcasecmp(c_strategy_name, "combo") == 0 ) {
		u_strategyType = Strategy_COMBO;
	} else if( strcasecmp(c_strategy_name, "straddle") == 0 ) {
		u_strategyType = Strategy_STRADDLE;
	} else if( strcasecmp(c_strategy_name, "strangle") == 0 ) {
		u_strategyType = Strategy_STRANGLE;
	} else if( strcasecmp(c_strategy_name, "covered_call") == 0 ) {
		u_strategyType = Strategy_COVERED_CALL;
	} else if( ( strcasecmp(c_strategy_name, "protective_put") == 0 ) || ( strcasecmp(c_strategy_name, "married_put") == 0 ) ) {
		u_strategyType = Strategy_PROTECTIVE_PUT;
	} else if( strcasecmp(c_strategy_name, "collar") == 0 ) {
		u_strategyType = Strategy_COLLAR;
	} else if( strcasecmp(c_strategy_name, "condor") == 0 ) {
		u_strategyType = Strategy_CONDOR;
	} else if( strcasecmp(c_strategy_name, "iron_condor") == 0 ) {
		u_strategyType = Strategy_IRON_CONDOR;
	} else if( strcasecmp(c_strategy_name, "butterfly") == 0 ) {
		u_strategyType = Strategy_BUTTERFLY;
	} else if( strcasecmp(c_strategy_name, "iron_butterfly") == 0 ) {
		u_strategyType = Strategy_IRON_BUTTERFLY;
	}
}

void OrderLeg::getStrategy(string & sStrategy)
{
	sStrategy.append( this->sStrategy );
}

uint8_t OrderLeg::getStrategy()
{
	return u_strategyType;
}

uint8_t OrderLeg::getOrderType()
{
	return u_orderType;
}

void OrderLeg::getOrderType(string & m_orderType)
{
	CONVERT_TO_STRING(orderType, m_orderType);
}

void OrderLeg::setTimeInForce(string m_timeInForce)
{
	timeInForce.append( m_timeInForce );
	if( ( strcasecmp( m_timeInForce.c_str(), "day" ) == 0 ) || ( strcasecmp( m_timeInForce.c_str(), "gfd" ) == 0 ) ) {
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
	} else if ( ( strcasecmp( m_timeInForce.c_str(), "AM" ) == 0 ) || ( strcasecmp( m_timeInForce.c_str(), "EXT_AM" ) == 0) ) {
		u_timeInForce = TimeInForce_AM;
	} else if ( ( strcasecmp( m_timeInForce.c_str(), "PM" ) == 0 ) || ( strcasecmp( m_timeInForce.c_str(), "EXT_PM" ) == 0) ) {
		u_timeInForce = TimeInForce_PM;
	} else if( strcasecmp( m_timeInForce.c_str(), "GTD" ) == 0 ) {
		u_timeInForce = TimeInForce_GTD;
	} else if( strcasecmp( m_timeInForce.c_str(), "GTD_EXT" ) == 0 ) {
		u_timeInForce = TimeInForce_GTD_EXT;
	} else if( strcasecmp( m_timeInForce.c_str(), "GTT" ) == 0 ) {
                u_timeInForce = TimeInForce_GTT;
	} else if( strcasecmp( m_timeInForce.c_str(), "OPG" ) == 0 ) {
		u_timeInForce = TimeInForce_OPG;
	} else if( strcasecmp( m_timeInForce.c_str(), "CLO" ) == 0 ) {
		u_timeInForce = TimeInForce_CLO;
	} else if( strcasecmp( m_timeInForce.c_str(), "MINUTE" ) == 0 ) {
		u_timeInForce = TimeInForce_MINUTE;
	} else if( strcasecmp( m_timeInForce.c_str(), "EOS" ) == 0 ) {
		u_timeInForce = TimeInForce_EOS;
	}
}

uint8_t OrderLeg::getTimeInForce()
{
	return u_timeInForce;
}

void OrderLeg::getTimeInForce(string & m_timeInFoce)
{
	CONVERT_TO_STRING(timeInForce, m_timeInFoce);
}
void OrderLeg::setSpinInstructions(string m_spinInstructions)
{
	spinInstructions.append( m_spinInstructions );
	u_spinInstruction = SpinInstruction_NONE;
	if( strcasecmp(m_spinInstructions.c_str(), "AON") == 0 ) {
		u_spinInstruction = SpinInstruction_AON;
	} else if( strcasecmp(m_spinInstructions.c_str(), "FOK") == 0 ) {
		u_spinInstruction = SpinInstruction_FOK;
	} else if( strcasecmp(m_spinInstructions.c_str(), "DNR") == 0 ) {
		u_spinInstruction = SpinInstruction_DNR;
	} else if( strcasecmp(m_spinInstructions.c_str(), "AON_DNR") == 0 ) {
		u_spinInstruction = SpinInstruction_AON_DNR;
	}
}

uint8_t OrderLeg::getSpinInstructions()
{
	return u_spinInstruction;
}

void OrderLeg::getSpinInstructions(string & m_spinInstructions)
{
	CONVERT_TO_STRING(spinInstructions, m_spinInstructions);
}

void OrderLeg::setLimitPrice(string m_limitPrice)
{
	CONVERT_TO_STRING(m_limitPrice, limitPrice);
}

string OrderLeg::getLimitPrice()
{
	return limitPrice;
}

void OrderLeg::setStopPrice(string m_stopPrice)
{
	CONVERT_TO_STRING(m_stopPrice, stopPrice);
}

string OrderLeg::getStopPrice()
{
	return stopPrice;
}

void OrderLeg::setTrailingStopParam(string m_tslParam)
{
	CONVERT_TO_STRING( m_tslParam, tslParam );
}

string OrderLeg::getTrailingStopPrice()
{
	return tslParam;
}

void OrderLeg::setAccountID(string m_accountID)
{
	CONVERT_TO_STRING( m_accountID, accountID );
}

string OrderLeg::getAccountID()
{
	return accountID;
}

void OrderLeg::setUsername(string m_username)
{
	CONVERT_TO_STRING( m_username, username );
}

string OrderLeg::getUsername()
{
	return username;
}

void OrderLeg::setOrderID(string m_orderID)
{
	CONVERT_TO_STRING( m_orderID, orderID );
}

string OrderLeg::getOrderID()
{
	return orderID;
}

void OrderLeg::setSpreadID( string m_spreadID )
{
	CONVERT_TO_STRING( m_spreadID, sSpreadID );
}

string OrderLeg::getSpreadID()
{
	return sSpreadID;
}

void OrderLeg::setQuantity(string m_quantity)
{
	CONVERT_TO_STRING( m_quantity, quantity );
}

string OrderLeg::getQuantity()
{
	return quantity;
}

void OrderLeg::setParam(string name, string value)
{
	IFHelper helper;
	helper.upcase(name);
	otherParams.insert( make_pair(name, value) );
}

string OrderLeg::getParam(string name)
{
	map<string, string>::iterator iParam = otherParams.find( name );
	return ( (iParam == otherParams.end()) ? "" : iParam->second);
}

string OrderLeg::getUpperTTO()
{
	return sUpperTTO;
}

string OrderLeg::getLowerTTO()
{
	return sLowerTTO;
}

void OrderLeg::parse(string data)
{
	symbol.clear(); side.clear(); orderType.clear(); timeInForce.clear(); accountID.clear(); username.clear(); orderID.clear(); route.clear(); limitPrice.clear(); stopPrice.clear(); tslParam.clear(); quantity.clear();
	expiryDay.clear(); expiryMonth.clear(); expiryYear.clear(); spinInstructions.clear(); quantityType.clear(); password.clear(); exchange.clear(); disclosedQuantity.clear(); amoFlag .clear(); originalQuantity.clear(); originalLimitPrice.clear(); deliveryFlag.clear();
	otherParams.clear();
	sUpperTTO.clear(); sLowerTTO.clear();

	//cout << "Parsing: " << data << endl;
	string name, value;
	bool isName = true;
	for(size_t i = 0; i < data.length(); i++) {
		if( data[i] == '=' ) {
			if( isName ) 
				isName = false;
			else
				value.append("=");
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

void OrderLeg::setNameValue(string name, string value)
{
	//cout << "name = " << name << ", value = " << value << endl;
	const char *c_name = name.c_str();
	IFHelper helper;

	if( strcasecmp(c_name, "SYMBOL") == 0 ) {
		setSymbol( value );
	} else if( strcasecmp(c_name, "QUANTITY") == 0 ) {
		stringstream qStream;
		qStream << atoi( value.c_str() );
		setQuantity( qStream.str() );
	} else if( strcasecmp(c_name, "STRATEGY") == 0 ) {
		setStrategy( value );
	} else if( strcasecmp(c_name, "ACTION") == 0 ) {
		setSide( value );
	} else if( strcasecmp(c_name, "ORDER_TYPE") == 0 ) {
		setOrderType( value );
	} else if( strcasecmp(c_name, "EXPIRY") == 0 ) {
		setTimeInForce( value );
	} else if( (strcasecmp(c_name, "ACCOUNT_ID") == 0) || (strcasecmp(c_name, "ACCOUNTID") == 0) ) {
		setAccountID( value );
	} else if( strcasecmp(c_name, "USERNAME") == 0 ) {
		setUsername( value );
	} else if( strcasecmp(c_name, "LIMIT_PRICE") == 0 ) {
		setLimitPrice( value );
	} else if ( ( strcasecmp(c_name, "ACTION_PRICE") == 0 ) || ( strcasecmp(c_name, "STOP_PRICE" ) == 0 ) ) {
		setStopPrice( value );
	} else if( strcasecmp(c_name, "TSL_PARAM") == 0 ) {
		setTrailingStopParam( value );
	} else if( strcasecmp(c_name, "ORDER_ID") == 0 ) {
		setOrderID( value );
	} else if( strcasecmp(c_name, "SPREAD_ID") == 0 ) {
		setSpreadID( value );
	} else if( strcasecmp(c_name, "ROUTE") == 0 ) {
		setRoute( value );
	} else if( strcasecmp(c_name, "EXPIRY_DAY") == 0 ) {
		setExpiryDay( value );
	} else if( strcasecmp(c_name, "EXPIRY_MONTH") == 0 ) {
		setExpiryMonth( value );
	} else if( strcasecmp(c_name, "EXPIRY_YEAR") == 0 ) {
		setExpiryYear( value );
	} else if( strcasecmp(c_name, "SPIN_INSTRUCTIONS") == 0 ) {
		setSpinInstructions( value );
	} else if ( strcasecmp(c_name, "QUANTITY_TYPE") == 0 ) {
		setQuantityType( value );
	} else if ( strcasecmp(c_name, "PASSWORD") == 0 ) {
		setPassword( value );
	} else if ( strcasecmp(c_name, "MARKET_EXCHANGE" ) == 0 ) {
		setExchange( value );
	} else if ( strcasecmp(c_name, "DISCLOSED_QUANTITY" ) == 0 ) {
		setDisclosedQuantity( value );
	} else if ( strcasecmp(c_name, "AMO_FLAG" ) == 0 ) {
		setAMOFlag( value );
	} else if ( strcasecmp(c_name, "ORIGINAL_QUANTITY" ) == 0 ) {
		setOriginalQuantity( value );
	} else if ( strcasecmp(c_name, "ORIGINAL_LIMIT_PRICE" ) == 0 ) {
		setOriginalLimitPrice( value );
	} else if ( strcasecmp(c_name, "DELIVERY_FLAG" ) == 0 ) {
		setDeliveryFlag( value );
	} else if( strcasecmp(c_name, "UPPER_TTO_PRICE") == 0 ) {
		sUpperTTO.append( value );
	} else if( strcasecmp(c_name, "LOWER_TTO_PRICE") == 0 ) {
		sLowerTTO.append( value );
	} else if( strcasecmp(c_name, "CONDITION_SYMBOL") == 0 ) {
		sConditionSymbol.append( value );
	} else if( strcasecmp(c_name, "CONDITION_PRICE") == 0 ) {
		sConditionPrice.append( value );
	} else if( strcasecmp(c_name, "CONDITION_TYPE") == 0 ) {
		sConditionType.append( value );
	} else {
		setParam(name, value);
//		otherParams.insert( make_pair(name, value) );
//		otherParams[name] = value;
	}
}

void OrderLeg::setRoute( string m_route )
{
	route.append( m_route );
}

void OrderLeg::setExpiryDay( string m_expiryDay )
{
	expiryDay.append(m_expiryDay);
}

void OrderLeg::setExpiryMonth(string m_expiryMonth )
{
	expiryMonth.append(m_expiryMonth);
}

void OrderLeg::setExpiryYear( string m_expiryYear)
{
	expiryYear.append(m_expiryYear);
}

string OrderLeg::getRoute()
{
	return route;
}

string OrderLeg::getExpiryDay()
{
	return expiryDay;
}

string OrderLeg::getExpiryMonth()
{
	return expiryMonth;
}

string OrderLeg::getExpiryYear()
{
	return expiryYear;
}

void OrderLeg::setQuantityType(string m_quantityType)
{
	quantityType.append( m_quantityType );
}

string OrderLeg::getQuantityType()
{
	return quantityType;
}

void OrderLeg::setPassword( string m_password )
{
	password.append( m_password );
}

string OrderLeg::getPassword()
{
	return password;
}

void OrderLeg::setExchange( string m_exchange )
{
	exchange.append( m_exchange );
}

string OrderLeg::getExchange()
{
	return exchange;
}

void OrderLeg::setDisclosedQuantity( string m_disclosedQuantity )
{
	disclosedQuantity.append( m_disclosedQuantity );
}

string OrderLeg::getDisclosedQuantity()
{
	return disclosedQuantity;
}

void OrderLeg::setAMOFlag( string m_amoFlag )
{
	amoFlag.append( m_amoFlag );
}

string OrderLeg::getAMOFlag()
{
	if ( atoi( amoFlag.c_str() ) == 1 )
		return "Y";
	return "N";
}

void OrderLeg::setOriginalQuantity( string m_originalQuantity )
{
	originalQuantity.append( m_originalQuantity );
}

string OrderLeg::getOriginalQuantity()
{
	return originalQuantity;
}

void OrderLeg::setOriginalLimitPrice( string m_originalLimitPrice )
{
	originalLimitPrice.append( m_originalLimitPrice );
}

string OrderLeg::getOriginalLimitPrice()
{
	return originalLimitPrice;
}

void OrderLeg::setDeliveryFlag( string m_deliveryFlag )
{
	deliveryFlag.append( m_deliveryFlag );
}

string OrderLeg::getDeliveryFlag()
{
	return deliveryFlag;
}

string OrderLeg::getLegString()
{
	return sLegString;
}

OrderLeg & OrderLeg::operator<<(OrderLeg & leg)
{
	this->sLegString.append( leg.getLegString() );
	parse( sLegString );
	return *this;
}

string OrderLeg::getConditionSymbol()
{
	return sConditionSymbol;
}

string OrderLeg::getConditionType()
{
	return sConditionType;
}

string OrderLeg::getConditionPrice()
{
	return sConditionPrice;
}
