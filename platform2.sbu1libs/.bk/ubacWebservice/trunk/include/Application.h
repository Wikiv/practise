#ifndef __UBAC_APPLICATION_H__
#define __UBAC_APPLICATION_H__

#include <list>
#include <ubacdata/UBACData.h>
//#include "PushServerData.h"
//#include "Properties.h"
#include <ubacyaml/YamlConfig.h>
#include <ubacutils/Exceptions.h>
#include <ubacutils/IFHelper.h>
#ifndef WIN32
#include <ubacsslinterface/Digest.h>
#endif

#define INVOKE_HANDLER(type, varname, data, extMod, reply, argument) 	\
	type varname##Request(data);					\
	onMessage( & varname##Request, extMod, reply, argument );

#define INVOKE_HANDLER_FOR_OPTION_CHAIN(type, varname, data, extMod, reply, argument, code) 	\
	type varname##Request(data, code);							\
	onMessage( & varname##Request, extMod, reply, argument );

/** This is the application framework abstraction layer.
  * Any broker component or an application backend will have to inherit
  * this class and implement the virtual functions to handle the
  * specific requests.
  */

class Application
{
	public:
		/** Create Application without properties. */
		Application();
		/** Create Application with default yaml config. */
		Application(YamlConfig *yamlConfig);
		/** Create Application with default properties. */
		//Application(Properties *property);
		~Application();

		/** implement to handle probability charts request ***/
		virtual void onMessage (BrokerProbabilityRequest * ubacRequest,
								ExtMod * extMod, string & reply, void *argument) {};
		/** Implement this method to handle Trade requests. */
		virtual void onMessage (BrokerPlaceOrderRequest * orderRequest,
								ExtMod * extMod, string & reply, void *argument) {};
		/** Implement this method to handle Strategy Fetch requests. */
		virtual void onMessage (BrokerStrategyFetchRequest * orderRequest,
								ExtMod * extMod, string & reply, void *argument) {};
		/** Implement this method to handle Research Request for a symbol*/
		virtual void onMessage (BrokerResearchRequest * researchRequest,
								ExtMod * extMod, string & reply, void *argument) {};
		/** Implement this method to handle Broker Login request. */
		virtual void onMessage (BrokerLoginRequest * loginRequest, ExtMod * extMod,
								string & reply, void *argument) {};
		/** Implement this method to handle a request to Switch Accounts. */
		virtual void onMessage (BrokerSwitchAccountRequest *
								brokerSwitchAccountRequest, ExtMod * extMod, string & reply,
								void *argument) {};
		/** Implement this method to handle Login Response. */
		virtual void onMessage (BrokerLoginResponse * loginResponse, ExtMod * extMod,
								string & reply, void *argument) {};
		/** Implement this method to handle a Cancel Order request. */
		virtual void onMessage (BrokerCancelOrderRequest * cancelOrderRequest,
								ExtMod * extMod, string & reply, void *argument) {};
		/** Implment this method to handle a Balances Request. */
		virtual void onMessage (BrokerBalancesRequest * balancesRequest,
								ExtMod * extMod, string & reply, void *argument) {};
		/** Implement this method to handle a OrderBook Request. OrderBook is same as Pending Orders, Trade Book or View Orders. */
		virtual void onMessage (BrokerOrderStatusRequest * orderStatusRequest,
								ExtMod * extMod, string & reply, void *argument) {};
		/** Implement this method to handle a session Logout request. */
		virtual void onMessage (BrokerLogoutRequest* logoutRequest, ExtMod * extMod,
								string & reply, void *argument) {};
		/** Implement this method to handle a Quote snapshot request. */
		virtual void onMessage (SingleQuoteRequest * singleQuoteRequest,
								ExtMod * extMod, string & reply, void *argument) {};
		/** Implment this method to handle Option Chain request. */
		virtual void onMessage (BrokerOptionsChainRequest* optionsChainRequest,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a Customer Profile request. */
		virtual void onMessage (BrokerCustomerProfileRequest* custProfileRequest,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a Symbol Data request. */
		virtual void onMessage (SymbolDataRequest * symbolDataRequest, ExtMod * extMod,
								string & reply, void *argument ) {};
		/** Implment this method to handle a request to get Wathclist Symbols. */
		virtual void onMessage (BrokerGetWatchListRequest * getWatchListRequest,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request for Adding/Deleting a Watchlist group. */
		virtual void onMessage (BrokerWatchListActionRequest *watchListAction,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Please do not this method. */
		virtual void onMessage (TDABrokerWatchListActionRequest *watchListAction,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request for Positions/Portfolio. */
		virtual void onMessage (BrokerPortfolioRequest *portfolioRequest,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request for Summary of Positions. */
		virtual void onMessage (BrokerPositionSummaryRequest * positionSummaryRequest,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request for Intraday data. */
		virtual void onMessage (IntradayDataRequest *intradayRequest, ExtMod *extMod,
								string & reply, void *argument ) {};
		/** Implement this method to handle a request for Market Index data. */
		virtual void onMessage (IndexRequest *indexRequest, ExtMod *extMod,
								string & reply, void *argument ) {};
		/** Implement this method to handle a request for Dragon parameters for optionsXpress. */
		virtual void onMessage (OPXDragonRequestParam *dragonRequestParam,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request for Dragon values for optionsXpress. */
		virtual void onMessage (OPXDragonRequestValue *dragonRequestValue,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request for News. */
		virtual void onMessage (NewsRequest * newsRequest, ExtMod * extMod,
								string & reply, void *argument ) {};
		/** Implement this method to handle a request for Commissions. */
		virtual void onMessage (BrokerCommissionRequest * commissionRequest,
								ExtMod * extMod, string & reply, void *argument ) {};
		/** Implment this method to handle a request for Gainers/Losers and Top volumes. This is a generic request and can be extended. */
		virtual void onMessage (GainerLoserVolumeRequest *gainerLoserVolumeRequest,
								ExtMod *extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a Symbol/Stock/Name search request. */
		virtual void onMessage (SymbolSearchRequest *symbolSearchRequest,
								ExtMod *extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request for getting Watchlist groups. */
		virtual void onMessage (GetBrokerWatchlistRequest *getBrokerWatchlistRequest,
								ExtMod *extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request for Adding/Deleting a Watchlist group. */
		virtual void onMessage (BrokerWatchlistActionRequest
								*brokerWatchlistActionRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a request for getting Symbols in a Watchlist. */
		virtual void onMessage (GetBrokerWatchlistSymbolsRequest
								*getBrokerWatchlistSymbolsRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a request for Adding/Deleting a symbol in a Watchlist group. */
		virtual void onMessage (BrokerWatchlistDataActionRequest
								*brokerWatchlistDataActionRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a User Registration request. Specific Brokers do have an API for this. */
		virtual void onMessage (BrokerUserRegistrationRequest
								*brokerUserRegistrationRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a request for Technical Indicator List. */
		virtual void onMessage (TechnicalIndicatorListRequest
								*technicalIndicatorListRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a request for Technical Indicators. */
		virtual void onMessage (TechnicalIndicatorValueRequest
								*technicalIndicatorValueRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a request for Historical Data. */
		virtual void onMessage (HistoryDataRequest *historyDataRequest, ExtMod *extMod,
								string & reply, void *argument ) {};
		/** Implement this method to handle a request to get group list */
		virtual void onMessage (GetPortfolioGroupListRequest
								*getPortfolioGroupListRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a request to act uop Portfolio group */
		virtual void onMessage (PortfolioGroupListActionRequest
								*portfolioGroupListActionRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a request to add dummy portfolio. */
		virtual void onMessage (BrokerSetPortfolioRequest *setPortfolioRequest,
								ExtMod *extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request to add details of accept disclaimer with broker api **/
		virtual void onMessage (AcceptDisclaimerRequest *acceptDisclaimerRequest,
								ExtMod *extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request to handle password change request **/
		virtual void onMessage(BrokerPasswordChangeRequest
							   *brokerPasswordChangeRequest, ExtMod *extMod, string & reply,
							   void *argument ) {};
		/** Implement this method to handle a request to handle User validate request **/
		virtual void onMessage (ValidateUserRequest *validateUserRequest,
								ExtMod *extMod, string & reply, void *argument ) {};
		/** Implement this method to handle request to handle AuthLoginRequest **/
		virtual void onMessage (AuthLoginRequest *authLoginRequest, ExtMod *extMod,
								string & reply, void *argument ) {};
		/** Implement this method to handle ValidateOtpRequest **/
		virtual void onMessage (ValidateOtpRequest *validateOtpRequest, ExtMod *extMod,
								string & reply, void *argument ) {};
		/** Implement this method to handle a common csv Request*/
		virtual void onMessage (CommonCsvRequest *commonCsvRequest, ExtMod *extMod,
								string & reply, void *argument ) {};
		/** Implement this method to handle a request to provide positions in CSV format **/
		virtual void onMessage( NewBrokerPortfolioRequest *newBrokerPortfolio,
								ExtMod *extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a request to provide order status in CSV format **/
		virtual void onMessage( NewBrokerOrderStatusRequest
								*newBrokerOrderStatusRequest, ExtMod *extMod, string & reply,
								void *argument ) {};
		/** Implement this method to handle a request to provide global markets info */
		virtual void onMessage( GlobalMarketsRequest *globalMarketsRequest,
								ExtMod *extMod, string & reply, void *argument ) {};
		/** Implement this method to handle a Subscription request from Push Server. */
		virtual void subscribe (PushServerRequest *pushServerRequest,
								ExtMod *extMod) {};
		/** Implement this method to handle a Un-Subscription request from Push Server. */
		virtual void unsubscribe (PushServerRequest *pushServerRequest,
								  ExtMod *extMod) {};
		/** Broker Initialization request **/
		virtual void onMessage (BrokerInitializationRequest *initializationRequest,
								ExtMod *extMod, string & reply, void *argument ) {};

		/** Handle extmod errors. This is a virtual method and broker applications will
		  * need to implement this method. The flag `bContinue' is to identify if the application
		  * needs to continue to handle the message or not. If bContinue is set to true, the application
		  * will need to handle the request.
		 */
		virtual void onExtModError(ExtMod *extMod, string sKey, string & reply,
								   void *argument, bool & bContinue) {};


		/**
		  *To Handle invalid protocol
		          */
		virtual void onInvalidProtocol(ExtMod *extMod, int code, string & reply,
									   void * argument, bool & bContinue) {};

		/** This method will call the appropriate handle for the protocol 'code'. */
		void call(int code, string data, string extModBuf, string & reply,
				  void *argument);



		/** This is a generic method to make error responses. For iErrorType, please
		  * refer class 'BrokerErrorMessage' in the 'UBACData' namespace. */
		void makeBrokerErrorMessage( uint32_t iErrorType, string customMessage,
									 string & errorMessage);
		/** Validate extended modifiers. */
		bool validate(ExtMod *extMod, string & sKey);
		/** Validate Protocols. */
		bool validateProtocol( int code );

		/** enable protocol validation by passing the boolean flag**/

		void setProtocolValidation( bool flag);

		string Need_Bc;

	private:
		vector<string>validationKeyList;
		list<int>validProtocolList;

		void initProtocolList(vector<string> );
		bool b_protocol_validation;
};
#endif /* __UBAC_APP_LOADER_H__ */
