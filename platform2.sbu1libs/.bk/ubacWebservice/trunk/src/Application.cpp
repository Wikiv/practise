#include "Application.h"

Application::Application()
{

}

Application::Application(YamlConfig *yamlConfig)
{
	string sValidations = (*yamlConfig)["validations"];
	string Need_Bc = (*yamlConfig)["bc_flag"];
	string sValidProtocols = (*yamlConfig)["supported_protocols"];
	IFHelper helper;
	helper.split( sValidations, ",", validationKeyList );

	vector<string> v_protocolList;
	helper.split( sValidProtocols, ",", v_protocolList );
	b_protocol_validation = false;
	initProtocolList( v_protocolList ) ;
}

/*Application::Application(Properties *property)
{
	string sValidations;
	property->getProperty("validate", sValidations);

	string sValidProtocols;
	property->getProperty("supported_protocols", sValidProtocols);

	IFHelper helper;
	helper.split( sValidations, ",", validationKeyList );

	vector<string> v_protocolList;
	helper.split( sValidProtocols, ",", v_protocolList );
	b_protocol_validation = false;
	initProtocolList( v_protocolList ) ;
}*/

void Application::initProtocolList( vector<string> v_protocolList )
{
	vector<string>::iterator iter_protocol = v_protocolList.begin();

	while( iter_protocol != v_protocolList.end()) {
		int protocol = 0 ;

		if ( (protocol = atoi(iter_protocol->c_str())) ) {
			this->validProtocolList.push_back(protocol);
		}

		iter_protocol++;
	}

	this->validProtocolList.sort();

	if (this->validProtocolList.empty()) {
		this->setProtocolValidation( false );
	}
}

void Application::setProtocolValidation( bool flag)
{
	this->b_protocol_validation = flag;
}

bool Application::validate(ExtMod *extMod, string & sKey)
{
	if( validationKeyList.size() == 0 )
		return true;

	vector<string>::iterator iList = validationKeyList.begin();

	while( iList != validationKeyList.end() ) {
		if( !extMod->hasKeyIgnoreCase( *iList ) ) {
			sKey = *iList;
			return false;
		}

		iList++;
	}

	return true;
}

bool Application::validateProtocol( int code )
{
	list<int>::iterator iList = validProtocolList.begin();

	if (!code) return false;

	while( iList != validProtocolList.end() ) {
		if ( (*iList) == code ) {
			return true;
		}

		iList++;
	}

	return false;
}

Application::~Application()
{
}

void Application::call(int code, string data, string extModBuf, string & reply,
					   void *argument)
{
	ExtMod extMod(extModBuf);
	string sKey;

	if( !validate( &extMod, sKey ) ) {
		bool bContinue = true;
		onExtModError( &extMod, sKey, reply, argument, bContinue );
		cout << "bContinue = " << bContinue << endl;

		if( !bContinue )
			return;
	}

	if ( b_protocol_validation && !validateProtocol( code ) ) {
		bool bContinue = true;
		onInvalidProtocol(&extMod, code, reply, argument, bContinue );
		cout << "bContinue = " << bContinue << endl;

		if ( !bContinue )
			return;
	}

	if( code == UBACData::Protocol_SINGLE_QUOTE ) {
		INVOKE_HANDLER( SingleQuoteRequest, singleQuote, data, &extMod, reply,
						argument );

	} else if( code == UBACData::Protocol_BROKER_INITIALIZATION ) {
		INVOKE_HANDLER(  BrokerInitializationRequest, brokerInitialization, data,
						 &extMod, reply, argument );

	} else if( code == UBACData::Protocol_BROKER_LOGIN ) {
		INVOKE_HANDLER( BrokerLoginRequest, brokerLogin, data, &extMod, reply,
						argument );

	} else if( code == UBACData::Protocol_BROKER_SWITCH_ACCOUNT ) {
		INVOKE_HANDLER( BrokerSwitchAccountRequest, brokerSwitchAccount, data, &extMod,
						reply, argument );

	} else if( code == UBACData::Protocol_BROKER_BALANCES ) {
		INVOKE_HANDLER( BrokerBalancesRequest, brokerBalances, data, &extMod, reply,
						argument );

	} else if ( code == UBACData::Protocol_BROKER_POSITIONS ) {
		INVOKE_HANDLER( BrokerPortfolioRequest, brokerPortfolio, data, &extMod, reply,
						argument );

	} else if ( code == UBACData::Protocol_BROKER_NEW_POSITIONS ) {
		INVOKE_HANDLER( NewBrokerPortfolioRequest, newBrokerPortfolioRequest, data,
						&extMod, reply, argument );

	} else if( code == UBACData::Protocol_BROKER_VIEW_ORDERS ) {
		INVOKE_HANDLER( BrokerOrderStatusRequest, brokerOrderStatus, data, &extMod,
						reply, argument );

	} else if( code == UBACData::Protocol_BROKER_PLACE_ORDER ) {
		INVOKE_HANDLER( BrokerPlaceOrderRequest, placeOrder, data, &extMod, reply,
						argument );

	} else if( code == UBACData::Protocol_BROKER_CANCEL_ORDER ) {
		INVOKE_HANDLER(BrokerCancelOrderRequest, cancelOrder, data, &extMod, reply,
					   argument );

	} else if( code == UBACData::Protocol_BROKER_LOGOUT ) {
		INVOKE_HANDLER(BrokerLogoutRequest, logout, data, &extMod, reply, argument);

	} else if( code == UBACData::Protocol_SYMBOL_DATA ) {
		INVOKE_HANDLER(SymbolDataRequest, symbolData, data, &extMod, reply, argument);

	} else if( code == UBACData::Protocol_DRAGON_PARAM ) {
		INVOKE_HANDLER(OPXDragonRequestParam, dragonParam, data, &extMod, reply,
					   argument);

	} else if( code == UBACData::Protocol_DRAGON_VALUE ) {
		INVOKE_HANDLER(OPXDragonRequestValue, dragonValue, data, &extMod, reply,
					   argument);
		/*	} else if( code == UBACData::Protocol_WATCHLIST_ACTION ) {
				string router;
				extMod.getValue("ROUTER", router);
		#ifndef WIN32
				if ( strcasecmp( router.c_str(), "AMERITRADE" ) == 0 ) {
					INVOKE_HANDLER(TDABrokerWatchListActionRequest, watchlistAction, data, &extMod, reply, argument);
				} else {
					INVOKE_HANDLER(BrokerWatchListActionRequest, watchlistAction, data, &extMod, reply, argument);
				}
		#endif*/

	} else if( code == UBACData::Protocol_GET_WATCHLIST ) {
		INVOKE_HANDLER(BrokerGetWatchListRequest, getWatchlist, data, &extMod, reply,
					   argument);

	} else if( ( code == UBACData::Protocol_GET_OPTION_CHAIN )
			   || ( code == UBACData::Protocol_NEW_GET_OPTION_CHAIN ) ) {
		INVOKE_HANDLER_FOR_OPTION_CHAIN(BrokerOptionsChainRequest, optionChains, data,
										&extMod, reply, argument, code);

	} else if( code == UBACData::Protocol_BROKER_POSITIONS_SUMMARY) {
		INVOKE_HANDLER(BrokerPositionSummaryRequest, positionSummary, data, &extMod,
					   reply, argument);

	} else if( code == UBACData::Protocol_BROKER_LOGIN_RESPONSE) {
		INVOKE_HANDLER(BrokerLoginResponse, loginResponse, data, &extMod, reply,
					   argument);

	} else if( code == UBACData::Protocol_BROKER_NEWS) {
		INVOKE_HANDLER(NewsRequest , news, data, &extMod, reply, argument);

	} else if ( code == UBACData::Protocol_INTRADAY_DATA_REQUEST ) {
		INVOKE_HANDLER(IntradayDataRequest, intradayRequest, data, &extMod, reply,
					   argument);

	} else if ( code == UBACData::Protocol_INDEX_LIST_REQUEST ) {
		INVOKE_HANDLER(IndexRequest, indexRequest, data, &extMod, reply, argument);

	} else if ( code == UBACData::Protocol_COMMISSION_REQUEST ) {
		INVOKE_HANDLER(BrokerCommissionRequest, commissionRequest, data, &extMod,
					   reply, argument );

	} else if ( code == UBACData::Protocol_GAINER_LOSER_VOLUME ) {
		INVOKE_HANDLER(GainerLoserVolumeRequest, gainerLoserVolumeRequest, data,
					   &extMod, reply, argument );

	} else if ( code == UBACData::Protocol_SYMBOL_SEARCH ) {
		INVOKE_HANDLER(SymbolSearchRequest, symbolSearchRequest, data, &extMod, reply,
					   argument);
		/*} else if ( code == PushServerData::Protocol_SUBSCRIPTION_REQUEST ) {
			PushServerRequest subscriptionRequest(data);
			subscribe(&subscriptionRequest, &extMod);*/

	} else if ( code == UBACData::Protocol_GET_WATCHLIST_DATA ) {
		INVOKE_HANDLER(GetBrokerWatchlistRequest, getBrokerWatchlistRequest , data,
					   &extMod, reply, argument);

	} else if ( code == UBACData::Protocol_WATCHLIST_SPECIFIC_ACTION ) {
		INVOKE_HANDLER( BrokerWatchlistActionRequest, brokerWatchlistActionResponse,
						data, &extMod, reply, argument);

	} else if ( code == UBACData::Protocol_GET_SYMBOLS_WATCHLIST ) {
		INVOKE_HANDLER( GetBrokerWatchlistSymbolsRequest,
						getBrokerWatchlistSymbolsRequest, data, &extMod, reply, argument);

	} else if ( code == UBACData::Protocol_WATCHLIST_DATA_ACTION ) {
		INVOKE_HANDLER( BrokerWatchlistDataActionRequest,
						brokerWatchlistDataActionRequest, data, &extMod, reply, argument);

	} else if ( code == UBACData::Protocol_BROKER_USER_REGISTRATION ) {
		INVOKE_HANDLER(BrokerUserRegistrationRequest, brokerUserRegistrationRequest,
					   data, &extMod, reply, argument );
#ifndef WIN32

	} else if ( code == UBACData::Protocol_TECHNICAL_INDICATOR_LIST_DATA ) {
		INVOKE_HANDLER(TechnicalIndicatorListRequest, technicalIndicatorListRequest,
					   data, &extMod, reply, argument );
#endif

	} else if ( code == UBACData::Protocol_TECHNICAL_INDICATOR_VALUE_DATA ) {
		INVOKE_HANDLER(TechnicalIndicatorValueRequest, technicalIndicatorValueRequest,
					   data, &extMod, reply, argument );

	} else if ( code == UBACData::Protocol_HISTORY_DATA ) {
		INVOKE_HANDLER(HistoryDataRequest, historyDataRequest, data, &extMod, reply,
					   argument );

	} else if ( code == UBACData::Protocol_PORTFOLIO_SET_REQUEST ) {
		INVOKE_HANDLER(BrokerSetPortfolioRequest, setPortfolioRequest, data, &extMod,
					   reply, argument );

	} else if ( code == UBACData::Protocol_CUSTOMER_PROFILE_REQUEST ) {
		INVOKE_HANDLER( BrokerCustomerProfileRequest, customerProfileRequest, data,
						&extMod, reply, argument );

	} else if ( code == UBACData::Protocol_GET_GROUP_LIST_REQUEST ) {
		INVOKE_HANDLER( GetPortfolioGroupListRequest, getPortfolioGroupListRequest,
						data, &extMod, reply, argument );

	} else if ( code == UBACData::Protocol_PORTFOLIO_GROUP_ACTION_REQUEST ) {
		INVOKE_HANDLER( PortfolioGroupListActionRequest,
						portfolioGroupListActionRequest, data, &extMod, reply, argument );

	} else if ( code == UBACData::Protocol_PASSWORD_CHANGE ) {
		INVOKE_HANDLER( BrokerPasswordChangeRequest, brokerPasswordChangeRequest, data,
						&extMod, reply, argument );

	} else if ( code == UBACData::Protocol_ORDER_STATUS ) {
		INVOKE_HANDLER( NewBrokerOrderStatusRequest, newBrokerOrderStatusRequest, data,
						&extMod, reply, argument );

	} else if ( code == UBACData::Protocol_GLOBAL_MARKETS ) {
		INVOKE_HANDLER( GlobalMarketsRequest, globalMarketsRequest, data, &extMod,
						reply, argument );
		/*} else if ( code == PushServerData::Protocol_UNSUBSCRIPTION_REQUEST ) {
			PushServerRequest unSubscriptionRequest(data);
			unsubscribe(&unSubscriptionRequest, &extMod);*/

	} else if ( code == UBACData::Protocol_ACCEPT_DISCLAIMER ) {
		INVOKE_HANDLER( AcceptDisclaimerRequest, acceptDisclaimerRequest, data,
						&extMod, reply, argument );

	} else if (code == UBACData::Protocol_BROKER_VALIDATEUSER_REQUEST) {
		INVOKE_HANDLER(ValidateUserRequest, validateUserRequest, data, &extMod, reply,
					   argument );

	} else if (code == UBACData::Protocol_BROKER_AUTHLOGIN_REQUEST) {
		INVOKE_HANDLER(AuthLoginRequest, authLoginRequest, data, &extMod, reply,
					   argument );

	} else if (code == UBACData::Protocol_BROKER_VALIDATEOTP_REQUEST) {
		INVOKE_HANDLER(ValidateOtpRequest, vaidateOtpRequest, data, &extMod, reply,
					   argument );

	} else if (code == UBACData::Protocol_COMMON_CSV_REQUEST) {
		INVOKE_HANDLER(CommonCsvRequest, commonCsvRequest, data, &extMod, reply,
					   argument );

	} else if ( code == UBACData::Protocol_BROKER_RESEARCH_REQUEST ) {
		INVOKE_HANDLER (BrokerResearchRequest, brokerStrategyFetchRequest, data,
						&extMod, reply, argument);

	} else if ( code == UBACData::Protocol_BROKER_PROBABILITY_CALC ) {
		INVOKE_HANDLER(BrokerProbabilityRequest, ubac_request, data, &extMod, reply,
					   argument);

	} else if ( code == UBACData::Protocol_BROKER_STRATEGY ) {
		INVOKE_HANDLER( BrokerStrategyFetchRequest , brokerStrategyFetchRequest , data,
						&extMod, reply, argument );
	}
}


void Application::makeBrokerErrorMessage( uint32_t iErrorType,
		string customMessage, string & errorMessage)
{
	BrokerErrorMessage * brokerErrorMessage;
	brokerErrorMessage = new BrokerErrorMessage(iErrorType);

	if ( customMessage.length() > 0 ) {
		brokerErrorMessage->setCustomMessage(customMessage);
	}

	string response;
	brokerErrorMessage->toString( response );
	delete brokerErrorMessage;
	errorMessage.append( response );
}

