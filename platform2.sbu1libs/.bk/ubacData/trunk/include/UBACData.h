/**
  * \mainpage
  * \author Hiran Ramankutty (hiran@inxsasia.com)
  * \author Sriram Indusekar (sriram@inxsasia.com
  * \date 14th July 2010
  * \section intro_sec Introduction
  * This library is written in C++ and support basic features like logging, connections, configurations,
  * interfacing with UBAC platform, interfacing with RabbitMQ, hashing algorithms, and other programming
  * constructs.
  * \section dependencies_sec Dependencies
  * Before installation, please ensure that the following dependencies are met.
  * \subsection compiler Compilers/Platform
  * This library has been tested in Linux platform with g++ > 4.0 and Windows platforms with Visual Studio 8.0.
  * \subsection xml XML Parsing and libxml2
  * This library is packaged with libxml2, a super fast xml parsing written in C. The packaging allows, registering callback
  * methods based on XPATH. Callback functions can be custom written by developers.
  * \subsection tcp TCP Sockets
  * This supports TCP sockets with both Server and Client interfaces. An interface is provided with 'EventFax'
  * to handle non-blocking I/O. In Linux, this is implemented using epoll and in Windows it is implemented using 'select'
  * calls.
  * \subsection http HTTP/S Interface, libcURL and openSSL.
  * For integration with WebServices, we can use this call to make HTTP/S calls. This uses libcurl along with openSSL. Refer http://curl.haxx.se/
  * and http://www.openssl.org/ for more details on the dependencies.
  * \subsection memcache MemCache
  * This provides an interface to cache data in a centralized server. This uses memcached (http://memcached.org/) as the server and libmemcached (http://libmemcached.org/libMemcached.html)
  * with C based client interface.
  * \subsection rabbitmq RabbitMQ and C++ Interface
  * This provides an interface to communicated with RabbitMQ server (http://www.rabbitmq.com/). A C client 'rabbitmq-c' (http://hg.rabbitmq.com/rabbitmq-c/) is wrapped
  * in C++ with different interfaces.
  * \subsection lzo LZO and MiniLZO
  * This was integrated to handle lzo and miniLZO compressed data. The details about the compression and the libraries can be found at http://www.oberhumer.com/opensource/lzo/.
  * \subsection json JSON and C++ (Linux only)
  * This is supported only in Linux. This provides methods to parse and handle json data types. For understanding json, please refer http://www.json.org/.
  * Please download the source for json-c from http://oss.metaparadigm.com/json-c/json-c-0.9.tar.gz. We have used json-c library calls to provide an interface
  * in C++ to parse json objects.
  * Now there is another class named `JsonParser' which enables json object parsing and is dependent on `libjaula`. 
  * \subsection talib TA-Lib (Linux Only)
  * TA-Lib or Technical Analysis Library is used for computing data for charts. Please download and install from source http://ta-lib.org/hdr_dw.html.
  * \subsection libyaml Yaml Support (Linux only)
  * `libyaml' from http://pyyaml.org/wiki/LibYAML is being used to interface with Yaml files. Yaml files make it easier to have a consistent format
  * for the configuration files across Ruby and C++ components. 
  * \section install_sec Installation
  * \subsection linux Linux
  * Ensure that all the dependent packages are installed. Then:
  * - make
  * - make install (as root user)
  * - make docs
  * \subsection windows Windows
  * Open the project in Visual Studio and compile in release mode.
  * \version 1.0.0
  */

#ifndef __UBAC_DATA_H__
#define __UBAC_DATA_H__

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#else
#if ( (__GNUC__ == 4) && (__GNUC_MINOR__ > 2) )
#include <cstdio>
#include <cstdlib>
#include <cstring>
#endif
#if ( (__GNUC__ == 4) && (__GNUC_MINOR__ > 3) )
#include <stdint.h>
#endif
#endif

#include "ExtMod.h"
#include <ubacutils/IFHelper.h>
#include "PushServerData.h"
#include "QuotePacket.h"

#ifndef _WIN32
#include <ubacutils/Base64.h>
#include <ubacutils/CSVCommon.h>
#endif

using namespace std;

namespace UBACData {
	const static int Protocol_BROKER_LOGIN = 434;
	const static int Protocol_BROKER_INITIALIZATION = 800;
	const static int Protocol_BROKER_SWITCH_ACCOUNT = 440;
	const static int Protocol_BROKER_BALANCES = 454;
	const static int Protocol_BROKER_POSITIONS = 478;
	const static int Protocol_BROKER_VIEW_ORDERS = 548;
	const static int Protocol_BROKER_PLACE_ORDER = 540;
	const static int Protocol_BROKER_CANCEL_ORDER = 544;
	const static int Protocol_SINGLE_QUOTE = 310;
	const static int Protocol_BROKER_LOGOUT = 444;
	const static int Protocol_SYMBOL_DATA = 302;
	const static int Protocol_DRAGON_PARAM = 462;
	const static int Protocol_DRAGON_VALUE = 466;
	const static int Protocol_WATCHLIST_ACTION = 474;
	const static int Protocol_GET_WATCHLIST = 470;
	const static int Protocol_GET_OPTION_CHAIN = 552;
	const static int Protocol_NEW_GET_OPTION_CHAIN = 556;
	const static int Protocol_BROKER_POSITIONS_SUMMARY = 482;
	const static int Protocol_BROKER_LOGIN_RESPONSE = 436;
	const static int Protocol_INTRADAY_DATA_REQUEST =  390;
	const static int Protocol_BROKER_NEWS = 394;
	const static int Protocol_INDEX_LIST_REQUEST = 336;
	const static int Protocol_COMMISSION_REQUEST = 536;
	const static int Protocol_GAINER_LOSER_VOLUME = 850;
	const static int Protocol_BROKER_RESEARCH_REQUEST = 854;
	const static int Protocol_SYMBOL_SEARCH = 372;
	const static int Protocol_GET_WATCHLIST_DATA = 404;
	const static int Protocol_WATCHLIST_SPECIFIC_ACTION = 408;
	const static int Protocol_GET_SYMBOLS_WATCHLIST = 412;
	const static int Protocol_WATCHLIST_DATA_ACTION = 416;
	const static int Protocol_BROKER_USER_REGISTRATION = 488;
	const static int Protocol_TECHNICAL_INDICATOR_LIST_DATA = 816;
	const static int Protocol_TECHNICAL_INDICATOR_VALUE_DATA = 812;
	const static int Protocol_HISTORY_DATA = 340;
	const static int Protocol_CUSTOMER_PROFILE_REQUEST = 560;
	const static int Protocol_GET_GROUP_LIST_REQUEST = 564;
	const static int Protocol_PORTFOLIO_GROUP_ACTION_REQUEST = 568;
	const static int Protocol_PORTFOLIO_SET_REQUEST = 572;
	const static int Protocol_ACCEPT_DISCLAIMER = 492;
	const static int Protocol_PASSWORD_CHANGE  = 448;
	const static int Protocol_ORDER_STATUS  = 948;
	const static int Protocol_BROKER_NEW_POSITIONS = 978;
	const static int Protocol_GLOBAL_MARKETS = 398;
	const static int Protocol_BROKER_STRATEGY = 528;
	const static int Protocol_BROKER_VALIDATEOTP_REQUEST = 586;
	const static int Protocol_BROKER_VALIDATEOTP_RESPONSE = 588;
	const static int Protocol_BROKER_AUTHLOGIN_REQUEST = 582;
	const static int Protocol_BROKER_AUTHLOGIN_RESPONSE = 584;
	const static int Protocol_BROKER_VALIDATEUSER_REQUEST = 578;
	const static int Protocol_BROKER_VALIDATEUSER_RESPONSE = 580;
	const static int Protocol_COMMON_CSV_REQUEST = 590;
	const static int Protocol_BROKER_PROBABILITY_CALC = 532;
	const static int Protocol_BROKER_TRADE_DEFAULTS = 594;
	
	const static string UBACData_PORTFOLIO_ID = "ID";
	const static string UBACData_POSITION_ID = "PositionID";
	const static string UBACData_PAID_PRICE = "Price";
	const static string UBACData_TRANSACTION_TYPE = "Trans_type";
	const static string UBACData_TIME = "Time";
	const static string UBACData_COMMENTS = "Comments";
	const static string UBACData_ALIAS_NAME = "Alias_name";
	const static string UBACData_CURRENCY = "Currency";
	const static string UBACData_TOTAL_PAID_PRICE = "Total_paid_price";
	const static string UBACData_TOTAL_MARKET_PRICE = "Total_Market_Price";
	const static string UBACData_GAIN_LOSS_PERCENT = "GL";
	const static string UBACData_GAIN_LOSS_VALUE = "GLV";
	const static string UBACData_REALIZED = "Realized Gain";
	const static string UBACData_BASIS_PNL = "Basis PNL";
	const static string UBACData_BASIS_PNL_PERCENT = "Basis PNL Percent";
	const static string UBACData_TODAY_PNL = "Today PNL";
	const static string UBACData_TODAY_PNL_PERCENT = "Today PNL Percent";
	const static string UBACData_TOTAL_PNL = "Basis Total PNL";
	const static string UBACData_TOTAL_PNL_PERCENT = "Total PNL Percent";
	const static string UBACData_LAST_PRICE = "LAST";
	const static string UBACData_DUE_DATE = "Due Date";
	const static string UBACData_QUOTE_TIME = "QUOTE_TIME";
	const static string UBACData_DAY_GAIN_LOSS_PERCENT = "DGL";
	const static string UBACData_DAY_GAIN_LOSS_VALUE = "DGLV";
	const static string UBACData_UPDATED_TIME = "UPDATED_TIME";
	const static string UBACData_PREVIOUS_CLOSE = "PCLOSE";
	const static string UBACData_COMPANY_NAME = "CompanyName";
	const static string UBACData_PRODUCT_TYPE = "ProductType";
	const static string UBACData_FX = "Fx";
	const static string UBACData_BOOKED_PL = "BOOKED_PL";
	const static string UBACData_MTOM_PL = "MTOM_PL";
	const static string UBACData_IS_SOR = "SOR";
	const static string UBACData_SOR_URL = "SOR_URL";
	const static string UBACData_GROSS_PL = "Gross PL";
	const static string UBACData_PL = "PL";
	const static string UBACData_ROLL = "Roll";
	const static string UBACData_POSITION_TAG = "PositionTag";
	const static string UBACData_CONTINGENCY_ID = "ContingencyID";
	const static string UBACData_CONTINGENCY_TYPE = "ContingencyType";
	const static string UBACData_SQUAREOFF_FLAG = "SquareoffFlag";

        DEFINE_FIELD(SquareoffFlag,UBACData_SQUAREOFF_FLAG,string) 
	DEFINE_FIELD(SOR, UBACData_IS_SOR, string)
	DEFINE_FIELD(SORURL, UBACData_SOR_URL, string)
	DEFINE_FIELD(BookedPL, UBACData_BOOKED_PL, string)
	DEFINE_FIELD(MTOMPL, UBACData_MTOM_PL, string)
	DEFINE_FIELD(FX, UBACData_FX, string)
	DEFINE_FIELD(DueDate, UBACData_DUE_DATE, string)
	DEFINE_FIELD(PortfolioID, UBACData_PORTFOLIO_ID, string)
	DEFINE_FIELD(PaidPrice, UBACData_PAID_PRICE, string)
	DEFINE_FIELD(TransactionType, UBACData_TRANSACTION_TYPE, string)
	DEFINE_FIELD(PortfolioTime, UBACData_TIME, string)
	DEFINE_FIELD(Comments, UBACData_COMMENTS, string)
	DEFINE_FIELD(AliasName, UBACData_ALIAS_NAME, string)
	DEFINE_FIELD(Currency, UBACData_CURRENCY, string)
	DEFINE_FIELD(TotalPaidPrice, UBACData_TOTAL_PAID_PRICE, string)
	DEFINE_FIELD(TotalMarketPrice, UBACData_TOTAL_MARKET_PRICE, string)
	DEFINE_FIELD(GainLossPercent, UBACData_GAIN_LOSS_PERCENT, string)
	DEFINE_FIELD(GainLossValue, UBACData_GAIN_LOSS_VALUE, string)
	DEFINE_FIELD(BasisPNL, UBACData_BASIS_PNL, string)
	DEFINE_FIELD(BasisPNLPercent, UBACData_BASIS_PNL_PERCENT, string)
	DEFINE_FIELD(TodayPNL, UBACData_TODAY_PNL, string)
	DEFINE_FIELD(TodayPNLPercent, UBACData_TODAY_PNL_PERCENT, string)
	DEFINE_FIELD(TotalPNL, UBACData_TOTAL_PNL, string)
	DEFINE_FIELD(TotalPNLPercent, UBACData_TOTAL_PNL_PERCENT, string)
	DEFINE_FIELD(LastPrice, UBACData_LAST_PRICE, string)
	DEFINE_FIELD(QuoteTime, UBACData_QUOTE_TIME, string)
	DEFINE_FIELD(DayGainLossPercent, UBACData_DAY_GAIN_LOSS_PERCENT, string)
	DEFINE_FIELD(DayGainLossValue, UBACData_DAY_GAIN_LOSS_VALUE, string)
	DEFINE_FIELD(UpdatedTime, UBACData_UPDATED_TIME, string)
	DEFINE_FIELD(PreviousClose, UBACData_PREVIOUS_CLOSE, string)
	DEFINE_FIELD(CompanyName, UBACData_COMPANY_NAME, string)
	DEFINE_FIELD(ProductType, UBACData_PRODUCT_TYPE, string)
	DEFINE_FIELD(RealizedGL, UBACData_REALIZED, string)
	DEFINE_FIELD(GrossPL, UBACData_GROSS_PL, string)
	DEFINE_FIELD(PL, UBACData_PL, string)
	DEFINE_FIELD(Roll, UBACData_ROLL, string)
	DEFINE_FIELD(PositionTag, UBACData_POSITION_TAG, string)
	DEFINE_FIELD(PositionID, UBACData_POSITION_ID, string)
	DEFINE_FIELD(ContingencyID, UBACData_CONTINGENCY_ID, string)
	DEFINE_FIELD(ContingencyType, UBACData_CONTINGENCY_TYPE, string)

	void maskLogin(string message, string & maskedMessage);
	void createLogMessage(string &log_request, int code, string data);
	void crack(string message, int & code, string & data, string & extModBuf);

	const static string PushClientRequestType_LEVEL1 = "quote";
	const static string PushClientRequestType_LEVEL2 = "quote2";

	class PushClientRequest :
		public string
	{
		public:
			/** Set the request type for the request. Valid request types are:
			  * 'quote' and 'quote2'. */
			PushClientRequest(string m_requestType);
			~PushClientRequest();

			/** Input the symbol list before creating the streaming request. */
			void setSymbolList(vector<string> symbolList);
			/** Pass the session id and the destination to set in the request. */
			string toStreamRequest(string m_sessionID, string destination);
	};

	class BrokerErrorMessage {
		public:
			/** Pass the error type during initializing. */
			BrokerErrorMessage(uint32_t iError_Type);
			~BrokerErrorMessage();

			string custom_error;

			void toString( string & errorMessage );
			/** Set a custom message and override the default message. */
			void setCustomMessage( string customMessage );

			uint32_t iErrorType;
			enum {
				API_ERROR,
				LOGIN_ERROR,
				UPDATE_LOGIN_ERROR,
				INVALID_SESSION_ERROR,
				INVALID_SYMBOL_ERROR,
				WATCHLIST_ERROR,
				OPTION_CHAIN_ERROR,
				SPECIFIC_ERROR,
				TRADE_PASSWORD_ERROR,
				DRAGON_ERROR,
				NO_NEWS_ERROR,
				NO_DATA_AVAILABLE,
				NO_IMAGE_ERROR,
				LOGIN_QUESTION,
				AUTH_ERROR,
				INITIALIZATION_ERROR,
				PROTOCOL_ERROR
			};
		private:
			void setErrorMessage( string message_to_be_added, string & errorMessage );
	};
        class BrokerTradeDefaultsRequest                             
        {                                                            
                public:                                              
                        BrokerTradeDefaultsRequest(string data ) ;   
                        ~BrokerTradeDefaultsRequest();               
                        string getSymbol();                          
                        string getStrategy();                        
                        string getParam(string key);                 
                private:                                             
                        void handleOtherParams(string sName, string value );
                        void parse(string data);                     
                        void addKeyValue(string name, string value ); 
                        string sSymbol, sStrategy;                   
                        map<string,string> otherParams;              
        };                                                           

	class AcceptDisclaimerRequest :
		public IFHelper
	{
		public:
			AcceptDisclaimerRequest(string data);
			~AcceptDisclaimerRequest();

			string getAccountID();
		  	void getInstrumentType(string & sSecurityType);

			string getParam(string sKey);
		private:
			void handleOtherParams(string sName, string sValue);
			void parse( string data );

			string accountID;
			map <string,string> otherValues;
	};

	class AcceptDisclaimerResponse :
		public IFHelper
	{
		public:
			AcceptDisclaimerResponse();
			~AcceptDisclaimerResponse();

			void setCustomMessage( string mCustomMessage );
			void setFlag( bool mFlag );
			void toString(string & response);
		private:
			bool flag;
			string customMessage;
	};

	class ServiceCapability {
		public:
			ServiceCapability(string exchange, string key);
			~ServiceCapability();

			string toString();

		private:
			string capability;
	};

	class IndexRequest {
		public:
			IndexRequest(string data);
			~IndexRequest();

			string getCountryCode();

		private:
			string countryCode;
	};

	class IndexResponse :
		public IFHelper
	{
		public:
			IndexResponse();
			~IndexResponse();

			/** Add the index data. */
			void addIndex(string mIndex);
			/** Generate the response string and copy to 'response'. */
			void toString(string & response);

		private:
			/** List of indices. */
			vector<string>indexList;
	};

	class IntradayDataRequest {
		public:
			IntradayDataRequest(string request);
			~IntradayDataRequest();

			string getSymbol();
			string getStringResolution();
			int getResolution();
			void getRequest( string & mRequest );

		private:
			void parse(string request);

			string symbol, strResolution;
			int resolution;
	};

	class HistoryData :
		public IFHelper
	{
		public:
			HistoryData();
			~HistoryData();

			/** Set 'Symbol'. */
			void setSymbol(string mSymbol);
			/** Set Open price for the time frame. */
			void setOpen(double mOpen);
			/** Set High price for the time frame. */
			void setHigh(double mHigh);
			/** Set Low price for the time frame. */
			void setLow(double mLow);
			/** Set Close price for the time frame. */
			void setClose(double mClose);
			/** Set Volume for the time frame. */
			void setVolume(uint32_t mVolume);
			/** Set timestamp ending for the time frame. */
			void setDate(struct tm mTimestamp);

			void setOpen(string mOpen);
			void setHigh(string mHigh);
			void setLow(string mLow);
			void setClose(string mClose);
			void setVolume(string mVolume);

			void setOpen(double mOpen, int precision);
			/** Set High price for the time frame. */
			void setHigh(double mHigh, int precision);
			/** Set Low price for the time frame. */
			void setLow(double mLow, int precision);
			/** Set Close price for the time frame. */
			void setClose(double mClose, int precision);

			/** Return the symbol. */
			string getSymbol();
			/** Returns the Open price for the time frame. */
			double getOpen();
			/** Returns the High price for the time frame. */
			double getHigh();
			/** Returns the Low price for the time frame. */
			double getLow();
			/** Returns the Close price for the time frame. */
			double getClose();
			/** Returns the Volume for the time frame. */
			uint32_t getVolume();
			/** Returns the timestamp for the time frame. */
			struct tm getTime();
			/** Make the response string and append to 'response'. 'flag' determines, if the
			  * 'Symbol' has to be appended or not. While using, flag is set during the first call for IntradayData. */
			void toString(string & response, bool flag, bool isIntraday);

		private:
			string symbol;
			string open, high, low, close, volume;
			struct tm timestamp;
	};

	class IntradayDataResponse :
		public IFHelper
	{
		public:
			IntradayDataResponse();
			IntradayDataResponse(string sData);
			~IntradayDataResponse();
			void clearHistoryData();
			void addHistoryData(HistoryData histData);
			void toString(string & response);
			void toString(string & response,string url);

			size_t getNoOfElements();
			vector<HistoryData> getHistoryData();

		private:
			vector<HistoryData> dataList;
			void parse(string sData);
			void handle_state(string sBuffer, int state);
	};

/*	class CSVRow :
		public vector<string>
	{
		public:
			CSVRow();
			~CSVRow();

			void addColumn(string sColumnData);
			void addColumn(time_t time_stamp);
			void addColumn(double dColumnData);
			void toString(string & sRow);
			void toString(string & sRow, char c_delimiter);
	};

	class CSVData :
		public vector<CSVRow>
	{
		public:
			CSVData();
			CSVData(string sData);
			~CSVData();

			void setSNOFlagInCSVData( bool mIsSnoInCSVData );
			void addRow(CSVRow row);
			void toString(string & sRow, char delimiter = '|');

			vector<string>  operator[](string sKey);
		private:

			void parse(string sData);
			void print();
			map<string, vector<string> >columnMap;
			vector<string> headerList;
			bool isSnoInCSVData;
	};*/

	class HistoryDataRequest :
		public IFHelper
	{
		public:
			HistoryDataRequest( string data );
			~HistoryDataRequest();

			string getSymbol();
			string getResolution();
			string getStringFromDate();
			string getStringToDate();
			struct tm getFromDate();
			struct tm getToDate();
			time_t getFromDateInTime_T();
			time_t getToDateInTime_T();
			void getRequest( string & mRequest );
			double getFromToDateDifference();
		private:
			void parse( string request );
			string symbol, resolution, from_date, to_date;
	};

	class HistoryDataResponse :
		public IFHelper
	{
		public:
			HistoryDataResponse();
			HistoryDataResponse(string );
			~HistoryDataResponse();

			vector<HistoryData> getHistoryData();

			void clearHistoryData();
			void addHistoryData(HistoryData histData);
			void toString(string & response);
			void toString( string & response , string url );
			size_t getNoOfElements();
		private:
			vector<HistoryData> dataList;
			void parse(string sData);
			void handle_state(string sBuffer, int state);
	};

	class TechnicalIndicatorListRequest :
		public string
	{
		public:
			TechnicalIndicatorListRequest(string sRequest);
			~TechnicalIndicatorListRequest();

			string getIndicatorType();
	};

	class TechnicalIndicatorListResponse
	{
		public:
			TechnicalIndicatorListResponse();
			~TechnicalIndicatorListResponse();

			void toString(string & sResponse);
			void addIndicator(string sIndicator);

		private:
			vector<string>vIndicator;
	};

	class TechnicalIndicatorValueRequest :
		public IFHelper
	{
		public:
			TechnicalIndicatorValueRequest( string data );
			~TechnicalIndicatorValueRequest();

			string getSymbol();
			string getResolution();
//			string getIndicatorCode();
//			string getIndicatorInput();
			multimap<string, string> getIndicators();
			string getStringFromDate();
			string getStringToDate();
			struct tm getFromDate();
			struct tm getToDate();
			void getRequest( string & mRequest );
			double getFromToDateDifference();
		private:
			void parse( string request );

			string symbol, resolution, indicator_code, indicator_input, from_date, to_date;
			multimap<string, string>indicatorRequest;
	};

	class TechnicalIndicatorValueResponse :
		public IFHelper
	{
		public:
			TechnicalIndicatorValueResponse(size_t iLimit = 0);
			TechnicalIndicatorValueResponse(time_t fromDate, time_t toDate);
			~TechnicalIndicatorValueResponse();

			void setSymbol( string mSymbol );
			void setTruncateFlag(bool mFlag);
			void addOpenValue( string mOpen );
			void addHighValue( string mHigh );
			void addLowValue( string mLow );
			void addCloseValue( string mClose );
			void addVolumeValue( string mVolume );
			void addDateValue( string mDate );
			void addIndicatorCodeValue( string mIndicatorName, string mIndicatorValue );
			string getFullData( vector<string>mData , char sDelimiter , string mName, size_t uMaxSize );
			string getIndicatorFullData(size_t uMaxSize);
			void toString( string & response );
			void toString( string & response , string url );
		private:
			string symbol;
			bool doTruncate;
			vector<string>open;
			vector<string>high;
			vector<string>low;
			vector<string>close;
			vector<string>volume;
			vector<string>date;
			time_t toDate, fromDate;
			map< string, vector<string> >indicatorCode;

			size_t iLimit;
			int iFromIndex, iToIndex;

			void adjustSize(vector<string> & list);
			void setAdjustment(size_t uMaxSize);
	};

	class GetPortfolioGroupListRequest :
		public IFHelper
	{
		public:
			GetPortfolioGroupListRequest( string request );
			~GetPortfolioGroupListRequest();

			string getUserID();
		private:
			void parse( string request );
			void setValues( string name, string value );

			string userID;
	};

	class GetPortfolioGroupListResponse :
		public CSVData
	{
		public:
			GetPortfolioGroupListResponse();
			~GetPortfolioGroupListResponse();

			void toString( string & response );
		private:
	};

	class PortfolioGroupListActionRequest :
		public IFHelper
	{
		public:
			PortfolioGroupListActionRequest(string request);
			~PortfolioGroupListActionRequest();

			string getSymbolStr();
			string getAction();
			string getAccountID();
			string getUserID();
			string getGroupID();
			string getGroupName();
			string getGroupNewName();
			string getPortfolioID();
			string getIndex();
			void getSymbolVector( vector<string> & mSymbols );
		private:
			void parse( string request );
			void setSymbolToVector( string mSymbol );
			void setValues( string name, string value );

			vector<string>symbols;
			string action, userID, groupID, groupName , groupNewName, portfolioID, symbolStr, accountID, index;
	};

	class PortfolioGroupListActionResponse :
		public IFHelper
	{
		public:
			PortfolioGroupListActionResponse();
			~PortfolioGroupListActionResponse();

			void setCustomMessage(string mCustomMessage );
			void setFlag( bool mFlag );
			void toString( string & response );
		private:
			string customMessage;
			bool flag;
	};

	class GetBrokerWatchlistRequest :
		public IFHelper
	{
		public:
			GetBrokerWatchlistRequest(string request);
			~GetBrokerWatchlistRequest();

			string getAccountID();
		private:
			void parse( string request );
			void setValues( string name, string value );

			string accountID;
	};

	class GetBrokerWatchlistResponse :
		public CSVData
	{
		public:
			GetBrokerWatchlistResponse();
			~GetBrokerWatchlistResponse();

			void toString( string & response );
		private:
	};

	class BrokerWatchlistActionRequest :
		public IFHelper
	{
		public:
			BrokerWatchlistActionRequest(string request);
			~BrokerWatchlistActionRequest();

			string getAction();
			string getAccountID();
			string getWatchlistID();
			string getWatchlistName();
			string getWatchlistNewName();
			string getParam(string sKey);

		private:
			void parse( string request );
			void setValues( string name, string value );

			string action, accountID, watchlistID, watchlistName, watchlistNewName;

			map<string, string>otherParams;
	};

	class BrokerWatchlistActionResponse :
		public IFHelper
	{
		public:
			BrokerWatchlistActionResponse();
			~BrokerWatchlistActionResponse();

			void setFlag( bool mFlag );
			void toString( string & response );
			void setCustomMessage( string mCustomMessage );
		private:
			bool flag;
			string customMessage;
	};

	class GetBrokerWatchlistSymbolsRequest :
		public IFHelper,
		public string
	{
		public:
			GetBrokerWatchlistSymbolsRequest( string request );
			~GetBrokerWatchlistSymbolsRequest();

			string getAccountID();
			string getWatchlistID();
			string getWatchlistName();
			string getParam(string sKey);

			string toString();
		private:
			void parse( string request );
			void setValues( string name, string value );

			string accountID, watchlistID, watchlistName;
			map<string, string>otherParams;
	};

	class BrokerNewOptionChainResponse :
		public CSVData
	{
		public:
			BrokerNewOptionChainResponse();
			~BrokerNewOptionChainResponse();

			void toString(string & response);
	};

	class GetBrokerWatchlistSymbolsResponse :
		public CSVData
	{
		public:
			GetBrokerWatchlistSymbolsResponse();
			~GetBrokerWatchlistSymbolsResponse();

			void toString( string & response );
		private:
	};

	class BrokerWatchlistDataActionRequest :
		public IFHelper
	{
		public:
			BrokerWatchlistDataActionRequest(string request);
			~BrokerWatchlistDataActionRequest();

			string getAction();
			string getAccountID();
			string getWatchlistID();
			string getWatchlistName();
			string getSymbols();
			string getExchange();
			string getSecurityWatchlistID();

		private:
			void parse( string request );
			void setValues( string name, string value );

			string action,accountID,watchlistID,watchlistName,symbols, exchange, securityWatchlistID;
	};

	class BrokerWatchlistDataActionResponse :
		public IFHelper
	{
		public:
			BrokerWatchlistDataActionResponse();
			~BrokerWatchlistDataActionResponse();

			void setFlag( bool mFlag );
			void setCustomMessage( string mCustomMessage );
			void toString( string & response );
		private:
			string customMessage;
			bool flag;
	};

	class SymbolSearchRequest :
		public IFHelper,
		public string
	{
		public:
			SymbolSearchRequest(string request);
			~SymbolSearchRequest();

			string getSearchString();
			string getExchange();
			string getAssetType();
			string getLimit();
			string getStrikePrice();
			string getOptionType();
			string getExpiry();
			string getOtherParams( string name );

			string toString();

		private:

			void parse( string request );
			void setValues( string name, string value );

			string searchString, exchange, assetType, limit, strikePrice, optionType , expiry;
			map<string,string>otherParams;
	};

	class SymbolSearchResponse : public CSVData
	{
		public:
			SymbolSearchResponse();
			~SymbolSearchResponse();

			void toString( string & response );
	};

	class NewsRequest :
		public IFHelper
	{
		public:
			NewsRequest(string request);
			~NewsRequest();

			void getSymbol( vector<string> & mSymbolList );
			void getOutputFormat( vector<string> & mOutputString );
			string getParam(string sKey);
			string getCountryCode();
			string getSymbolList();
			string getID();
			string getCategory();
			bool isMarketNews();
			bool isFullNews();

		private:
			void setValuesWithNameInPair(string nameVal, string tmpBuffer);
			void addOutputParam( string outputParam );
			void parse(string request);

			map<string, string>otherParams;
			vector<string> symbolList;
			vector<string> outputString;
			string cc,id,category;
	};

	class NewsItem :
		public IFHelper
	{
		public:
			NewsItem();
			~NewsItem();

			void setSymbol( string mSymbol );
			void setHeadLine( string mHeadLine );
			void setDescription( string mDescription );
			void setTimeStamp( string mTimeStamp );
			void setGuid( string mGuid );
			void setUrl( string mUrl );
			void setImageUrl( string mImageUrl );

			void replaceSpecialCharacters( string & data );
			void toString( string & response );
			void toString( string & response, vector<string> output);
		private:
			void setDataToResponse( string outputParam ,string & response );
			void setNoData(string & data);
			string symbol, headLine, description, timeStamp, guid, url, imageUrl;
	};

	class NewsResponse :
		public IFHelper
	{
		public:
			NewsResponse();
			~NewsResponse();

			string getNewsData();
			void addNewsData( NewsItem news );
			void setOutputParam( vector<string> mOutputParam );
			void toString( string & response );
			bool isNewsDataEmpty();
		private:
			bool flag;
			vector<string>outputParam;
			vector<NewsItem>newsList;
	};

	class SingleQuoteRequest :
		public string
	{
		public:
			SingleQuoteRequest(string data);
			~SingleQuoteRequest();

			string getSymbol();
			string toString();

		private:
			string symbol;
	};

	class SingleQuoteResponse :
		public IFHelper
	{
		public:
			SingleQuoteResponse();
			SingleQuoteResponse(string data);
			~SingleQuoteResponse();

			void setSymbol(string m_symbol);
			void setLast(double m_lastPrice, int precision = -1);
			void setLast( string mLast );
			void setOpen(double m_openPrice, int precision = -1);
			void setOpen( string mOpen );
			void setDayHigh(double m_dayHigh, int precision = -1);
			void setDayHigh( string mDayHigh );
			void setDayLow(double m_dayLow, int precision = -1);
			void setDayLow( string mDayLow );
			void setTotalVolume(uint32_t m_volume);
			void setTotalVolume(string m_volume );
			void setDate(string dateStr);
			void setDate(struct tm tmTime);
			void setDate(time_t epoch_time);
			void setAskPrice(double m_askPrice, int precision = -1);
			void setAskPrice(string m_ask);
			void setBidPrice(double m_bidPrice, int precision = -1);
			void setBidPrice(string m_bid);
			void setAskSize(uint32_t m_askSize);
			void setAskSize( string mAskSize );
			void setBidSize(uint32_t m_bidSize);
			void setBidSize( string mBidSize );
			void setClose(double m_close, int precision = -1);
			void setClose( string mClose );
			void setYearHigh(double m_yearHigh, int precision = -1);
			void setYearHigh( string mYearHigh );
			void setYearLow(double m_yearLow, int precision = -1);
			void setYearLow( string mYearLow );
			void toString(string &response);
			/* for streaming response alone */
			void toStringWithDefaultZero(string &response);

			string getSymbol();
			string getLast();
			string getOpen();
			string getDayHigh();
			string getDayLow();
			string getTotalVolume();
			string getDate();
			string getAskPrice();
			string getBidPrice();
			string getAskSize();
			string getBidSize();
			string getClose();
			string getYearHigh();
			string getYearLow();
		private:
			string symbol, lastPrice, open, high, low, volume, dateStr, ask, bid, askSize, bidSize, prevClose, yearHigh, yearLow;

			void parse(string data);
	};

	class MarketDepthResponse :
		public IFHelper
	{
		public:
			MarketDepthResponse();
			~MarketDepthResponse();
			
			void setSymbol(string m_symbol);
			void setTotalBidQty( string m_total_bid_qty );
			void setTotalAskQty ( string m_total_ask_qty );
			void setAskBidEntry ( int no_of_entry, struct market_depth_ask_bid_entry *ask_entry, struct market_depth_ask_bid_entry *bid_entry );
			void toString(string &response);

		private:
			string symbol, totalBidQty, totalAskQty, askBidEntry;
	};

	class Level3Response :
                public IFHelper
        {
                public:
                        Level3Response();
                        ~Level3Response();

                        void setSymbol(string m_symbol);
                        void setTotalBidQty( string m_total_bid_qty );
                        void setTotalAskQty ( string m_total_ask_qty );
			void setLastUpdatedTime( int32_t m_last_updated_time, string sDateFormat );
                        void setAskBidEntry ( int no_of_entry, struct market_depth_ask_bid_entry *ask_entry, struct market_depth_ask_bid_entry *bid_entry );
                        void toString(string &response);

                private:
                        string symbol, totalBidQty, totalAskQty, askBidEntry, sTime;
        };

	class BrokerUserRegistrationRequest :
		public IFHelper
	{
		public:
			BrokerUserRegistrationRequest(string data);
			~BrokerUserRegistrationRequest();

			string getUserID();
			string getPassword();
			string getUserName();
			string getMobileNumber();
			string getEmailID();
			string getCity();
			string getDOB();
			string getOtherParam(string mKey);
		private:
			string userid, password, username, mobilenumber, emailid, city, dob;
			void setValues( string name, string value );
			void parse(string data);

			map<string, string>otherParams;
	};

	class BrokerUserRegistrationResponse {
		public:
			BrokerUserRegistrationResponse();
			~BrokerUserRegistrationResponse();

			void setFlag( bool mFlag );
			bool getFlag();
			void setErrorMessage( string mErrorMessage );
			void setCustomRegistrationMessage( string mCustomMessage );
			string getErrorMessage();
			void toString( string & response );
		private:
			string errorMessage, customMessage;
			bool flag;
	};

	class BrokerPasswordChangeRequest {
		public:
			BrokerPasswordChangeRequest( string data );
			~BrokerPasswordChangeRequest();
			// provides what password change it is
			string getRequestType();
			//provides username for which password need to be changed
			string getUsername();
			//provides current password in use
			string getOldPassword();
			//provides new password to be changed
			string getNewPassword();
			//Get other params.
			string getParam(string sKey);
			//check if both passwords are same
			bool isOldAndNewPasswordSame();
		private:
			void setNameValue( string name , string value );
			void parse( string data );

			string requestType, username, oldPassword, newPassword;
			map<string, string>otherParams;

	};

	class BrokerPasswordChangeResponse :
		public IFHelper
	{
		public:
			BrokerPasswordChangeResponse();
			~BrokerPasswordChangeResponse();

			void setFlag( bool mFlag );
			void setCustomMessage( string mCustomMessage );
			void toString( string & response );
		private:
			string customMessage;
			bool flag;
	};

	class BrokerLoginRequest :
		public string
	{
		public:
			BrokerLoginRequest(string data);
			~BrokerLoginRequest();

			// provides the user inputted username
			string getUsername();
			// provides the user inputted password
			string getPassword();
			//provide the user inputted memberid
			string getMemberid();
			// provides any other extra details needed to log if any.Specific to few brokers
			string getSecondFactor();
			string getParam(string sKey);
			string toString();

		private:
			string username, password, secondFactor, memberid;
			void parse(string data);
			map<string, string> otherParams;
	};

	class BrokerInitializationRequest :
		public string
	{
		public:
			BrokerInitializationRequest(string data);
			~BrokerInitializationRequest();
			string getParam(string sKey);
			string toString();

		private:
			void parse(string data);
			map<string,string> otherParams;
	};

	class ValidateOtpRequest :
		public string
	{
		public:
			ValidateOtpRequest(string data);
			~ValidateOtpRequest();

			string toString();
                        string getOtp();                                
		private:
			void parse(string data);
                        string otp;
	};

	class ValidateUserRequest :
                public string
        {
                public:
                        ValidateUserRequest(string data);
                        ~ValidateUserRequest();

                        /// Get the name field in the Validate User request.
                        string getOtherParams( string name );
                        string toString();
                private:
                        void parse(string data);
                        map<string,string>otherParams;
        };
	
	class CommonCsvRequest :
		public IFHelper,
                public string
        {
                public:
                        CommonCsvRequest(string data);
                        ~CommonCsvRequest();

			string getParam(string sKey);
                        string toString();
                private:
                        void parse(string data);

                        map<string,string>otherParams;
        };

	class AuthLoginRequest :
                public string
        {
                public:
                        AuthLoginRequest(string data);
                        ~AuthLoginRequest();

                        /// Get the name field in the authlogin request.
                        string getOtherParams( string name );
                        string toString();
                private:
                        void parse(string data);
                        map<string,string>otherParams;
        };

	class AccountDetails {
		public:
			AccountDetails();
			AccountDetails(string data);
			~AccountDetails() {};

			/** Converts the list of accounts to a string. */
			void toString(string & response);
			/** Reset all values in the account. */
			void resetValue(string key, string value);
			/** Set AccountID. */
			void setAccountID(string m_accountID);
			/** Set Account Number */
			void setAccountNumber(string m_accountNumber);
			/** Set DisplayName. If there are linked account, and there is no name associated with each account,
			  * then set the display name as the AccountID or AccountNumber. */
			void setDisplayName(string m_displayName);
			/** Set the userid/loginid. */
			void setUsername(string m_username);
			/** Set AccountMode. Valid values are AccountMode_DEMO and AccountMode_REAL. */
			void setAccountMode( string m_accountMode );
			/** Set AccountType. Valid values are 0, 1. */
			void setAccountType( string m_accountType );
			/** Return the AccountID. */
			string getAccountID();
			/** Return the display name. */
			string getDisplayName();
			/** Return the account number. */
			string getAccountNumber();
			/** Return the username. */
			string getUsername();
			/** Return the AccountMode. */
			string getAccountMode();
			/** Return the AccountType. */
			string getAccountType();
			/** Returns any other custom parameter set. */
			string getNameValuePairDetails();
			/**Returns value for the parameter given. */
			string getValueFromName( string name );
			/** Return the Margin flag for the account. */
			bool getMarginFlag();
			/** Return the Option flag for the account. */
			bool getOptionFlag();
			/** Return the Stock/Equity flag for the account. */
			bool getStockFlag();
			/** Return the Futures flag for the account. */
			bool getFuturesFlag();
			/** Return the Forex flag for the account. */
			bool getForexFlag();
			/** Return the Streaming News flag for the account. */
			bool getStreamingNewsFlag();
			/** Return the streaming data flag for the account. */
			bool getStreamingDataFlag();
			/** Return the Mutual Funds flag for the account. */
			bool getFundsFlag();
			/** Get flag which tells if the account is the primary account. */
			bool getPrimaryValue();
			/** Flag which determines if security key is enabled for 2-factor authentication. */
			bool getIsSecurityKeyEnabled();
			/** Set the Margin flag for the account. */
			void setMarginFlag( bool m_marginFlag );
			/** Set the Option flag for the account. */
			void setOptionFlag(bool m_optionFlag );
			/** Set the Stock flag for the account. */
			void setStockFlag( bool m_stockFlag );
			/** Set the Futures flag for the account. */
			void setFuturesFlag( bool m_futuresFlag );
			/** Set the Forex flag for the account. */
			void setForexFlag( bool m_forexFlag );
			/** Set the streaming news flag for the account. */
			void setStreamingNewsFlag( bool m_streamingNewsFlag );
			/** Set the streaming data flag for the account. */
			void setStreamingDataFlag( bool m_streamingDataFlag );
			/** Set the Mutual Fund flag for the account. */
			void setFundsFlag( bool m_fundsFlag );
			/** Set flag to try if account is a primary account. */
			void setPrimaryValue( bool flag );
			/** Set flag, if the account is 2-factor authenticated. */
			void setIsSecurityKeyEnabled( bool m_isSecurityKeyEnabled );
			/** Set custom parameters for the Account. Typically NAME=VALUE */
			void setOtherParams(string name, string value);
			/** Set other parameters for Account. Typically KEY=NAME:VALUE. */
			void setNameValuePairDetails( string responseName, string name, string value );
			/** Set other parameters for Account. Typically KEY=VALUE1:VALUE2. */
			void setNameValuePairFormatDetails( string responseName, vector <string> mResponseFormatMap );
			/** Set other parameters for Account. Typically NAME=VALUE. */
			void setNameValuePairDetailsFromResponse( string responseName, string data );
			/** AccountMode_DEMO string for demo accounts. */
			const static string AccountMode_DEMO;
			/** AccountMode_REAL string for live/real accounts. */
			const static string AccountMode_REAL;

		private:

			map<string, string>otherParams;

			//used only with kotak broker currently
			map <string , map <string , string> > responseNameMap;
			map <string , vector <string> > responseFormatMap;

			string accountID, displayName, accountNumber, username, accountMode, accountType;
			bool marginEnabled, optionEnabled, stockEnabled, futuresEnabled, forexEnabled, streamingNews, streamingData, fundsEnabled, primaryValue, isSecurityKeyEnabled, isSecurityKeyNeeded;
			void addField(string key, string value, string & response);
			void parse(string data);
			void setNameValue(string name, string value);
	};

	/** Broker Initialization Response class. */
	class BrokerInitializationResponse {
		public:

			///create BrokerInitializationResponse oblect.
			BrokerInitializationResponse();
			BrokerInitializationResponse( string data );
			~BrokerInitializationResponse();
			/** sets appid to the response. */
			void setAppID( string appID );
			/** set update_status **/
			void setUpdateStatus( int status );
			/** set data for updation **/
			void setDataForUpdation( int mandatory, string release_header, string release_notes, string version, string url );

                        void setUnencodedDataForUpdation(int mandatory,
                                                string release_header,
                                                string release_notes,
                                                string version,
                                                string url);


			void toString(string & response);
		private:
			string appID, release_header, release_notes, url, version;
			int mandatory,status;
			void parse(string data);		
	};

	/** Broker Login Response class. */
	class BrokerLoginResponse {
		public:
			/// Create BrokerLoginResponse object.
			BrokerLoginResponse();
			BrokerLoginResponse(string data);
			~BrokerLoginResponse();
			/** sets login status based on broker response. True means, successful login. */
			void setLoginStatus(bool flag);
			/** Get the login status. */
			bool getLoginStatus();
			/** Convert the login response to a string. */
			void toString(string & response);
			/** Add account details to the login response. */
			void addAccount(AccountDetails details);
			/** Sets session id for that login user if the login status is true. */
			void setSessionID(string m_sessionID);
			/** Get the session id. */
			string getSessionID();
			/** Get the default account or first account for user login account as AccountDetails object. */
			AccountDetails & getDefaultAccount();
			/** Get default account for the `accountId'. */
			void getDefaultAccount(string & accountId);
			/** Resets the default account. */
			void resetDefaultAccountValue(string accountId, string name, string value);
			/** To get all accounts for that user as a vector. */
			void getAllAccounts(vector<AccountDetails> & allAccounts);
			/** Get no. of accounts for that user account. */
			int getNoOfAccounts();
			/** Checks if there are any primary key for that account id. */
			bool checkPrimaryKey( string & accountid );
			/** To reorder the account details on specific cases. */
			void reorderAccountDetails();

		private:
			string sessionID, errorMsg;
			bool loginStatus;

			vector<AccountDetails>accountList;
			void parse(string data);

	};


	/** BrokerLogoutRequest class. */
	class BrokerLogoutRequest :
		public string
	{
		public:
			/// Create BrokerLogoutRequest object, by passing request data.
			BrokerLogoutRequest(string data);
			~BrokerLogoutRequest();

			/// Get the name field in the logout request.
			string getOtherParams( string name );
			string toString();

		private:
			void parse(string data);
			map<string,string>otherParams;
	};

	/** BrokerLogoutResponse class. */
	class BrokerLogoutResponse {
		public:
			/// Create BrokerLogoutResponse object. */
			BrokerLogoutResponse();
			~BrokerLogoutResponse();

			/// Convert object to a ubac string. */
			void toString(string & response);
                        void setCustomMessage( string mCustomMessage );

                private:
                        string customMessage;                        
	};

	/**  ValidateOtpResponse class */ 
        class ValidateOtpResponse 
	{
                public:
			///Create ValidateOtpResponse object. */
                        ValidateOtpResponse();
                        ~ValidateOtpResponse();

			/// Convert object to a ubac string. */
                        void toString(string & response);
                        void setFlag( bool mFlag );
                        void setCustomMessage( string mCustomMessage );                                
                private:
                        string customMessage;
                        bool flag;                                                              
	};

	/** ValidateUserResponse class */
	class ValidateUserResponse : public CSVData
        {
                public:
                        ///Create ValidateUserResponse object. */
                        ValidateUserResponse();
                        ~ValidateUserResponse();

                        /// Convert object to a ubac string. */
                        void toString(string & response);
        };

	/** CommonCsvResponse class */
        class CommonCsvResponse : public CSVData
        {
                public:
                        ///Create CommonCsvResponse object. */
                        CommonCsvResponse();
                        ~CommonCsvResponse();

                        /// Convert object to a ubac string. */
                        void toString(string & response);
        };
	
	/** AuthLoginResponse class */
        class AuthLoginResponse : public CSVData
        {
                public:
                        ///Create AuthLoginResponse object. */
                        AuthLoginResponse();
                        ~AuthLoginResponse();

                        /// Convert object to a ubac string. */
                        void toString(string & response);
        };

	class BrokerBalancesRequest :
		public std::string
	{
		public:
			BrokerBalancesRequest(string data);
			~BrokerBalancesRequest();
			//provides the account id for which balances is requested
			string getAccountID();
			//provides the username ( optional )
			string getUserName();
			//provides the password ( optional )
			string getPassword();
			//Get Other params;
			string getParam(string sKey);
			//provides the type of balances request ( optional )
			string getType();
			string toString();
		private:
			void handleOtherParams(string sName, string sValue);
			string accountID, sUserName, sPassword, sType;
			void parse(string data);
			map<string, string>otherParams;
	};

	class BrokerBalancesResponse {
		public:
			BrokerBalancesResponse();
			~BrokerBalancesResponse();

			// Appends to response and provides balances details
			void toString(string & response);
			// Appends to response and provides balances details in require response format order as requested
			void toString(string &response, map<string, vector<string> >responseFormat, vector<string>headerOrder);
			//provides the account id for which balances are requested
			string getAccountID();
			//sets the account id from broker response
			void setAccountID(string m_accountID);
			//used when this class is reused for position summary to reset the protocol code
			void setCode(string mCode);
			//get the balances map based on header details
			map<string, string> getBalancesMap(string m_header);
			// add balances data specific to header as name value pair
			void addBalancesData(string header, string name, string value);

		private:
			string accountID;
			string code;
			map<string, map<string, string> >balancesData;
	};

	class OrderLeg {
		public:
			OrderLeg(string data);
			OrderLeg();
			~OrderLeg() {}

			OrderLeg & operator<<(OrderLeg & leg);
			string getLegString();

			// Transaction type pre-defined constants
			const static uint8_t OrderSide_UNKNOWN = 0;
			const static uint8_t OrderSide_BUY = 1;
			const static uint8_t OrderSide_SELL = 2;
			const static uint8_t OrderSide_SELL_SHORT = 3;
			const static uint8_t OrderSide_BUY_TO_COVER = 4;
			const static uint8_t OrderSide_BUY_TO_OPEN = 5;
			const static uint8_t OrderSide_BUY_TO_CLOSE = 6;
			const static uint8_t OrderSide_SELL_TO_OPEN = 7;
			const static uint8_t OrderSide_SELL_TO_CLOSE = 8;
			const static uint8_t OrderSide_SUBSCRIPTION = 9;
			const static uint8_t OrderSide_REDEMPTION = 10;
			const static uint8_t OrderSide_BUY_MARGIN = 11;
			const static uint8_t OrderSide_SELL_MARGIN = 12;
			const static uint8_t OrderSide_SIP = 13;
			const static uint8_t OrderSide_SWP = 14;
			const static uint8_t OrderSide_PARTIAL_SWITCH = 15;
			const static uint8_t OrderSide_FULL_SWITCH = 16;
			const static uint8_t OrderSide_SELL_ALL = 17;
			const static uint8_t OrderSide_SHORT_EX = 18;

			// order type values pre-defined constants
			const static uint8_t OrderType_UNKNOWN = 0;
			const static uint8_t OrderType_MARKET = 1;
			const static uint8_t OrderType_LIMIT = 2;
			const static uint8_t OrderType_STOP = 3;
			const static uint8_t OrderType_STOP_LIMIT = 4;
			const static uint8_t OrderType_MOC = 5;
			const static uint8_t OrderType_LOC = 6;
			const static uint8_t OrderType_MOO = 7;
			const static uint8_t OrderType_LOO = 8;
			const static uint8_t OrderType_TRAILING_STOP_PERCENT = 9;
			const static uint8_t OrderType_TRAILING_STOP_DOLLAR = 10;
			const static uint8_t OrderType_PEGGED = 11;
			const static uint8_t OrderType_TTO = 12;

			const static uint8_t OrderType_CREDIT = 13;
			const static uint8_t OrderType_DEBIT = 14;
			const static uint8_t OrderType_EVEN = 15;

			const static uint8_t OrderType_MIT = 16;
			const static uint8_t OrderType_LIT = 17;
			const static uint8_t OrderType_ITS = 18;
			const static uint8_t OrderType_GTC_LIMIT = 19;
			const static uint8_t OrderType_GTC_STOP_LIMIT = 20;
			const static uint8_t OrderType_GTC_STOP = 21;
			const static uint8_t OrderType_GTD_LIMIT = 22;
			const static uint8_t OrderType_GTD_STOP_LIMIT = 23;
			const static uint8_t OrderType_GTD_STOP = 24;
			const static uint8_t OrderType_STOP_LIMIT_FAK = 25;
			const static uint8_t OrderType_STOP_LIMIT_FOK = 26;
			const static uint8_t OrderType_LIMIT_FAK = 27;
			const static uint8_t OrderType_LIMIT_FOK = 28;
			const static uint8_t OrderType_BEST_LIMIT = 29;
			const static uint8_t OrderType_MARKET_FAK = 30;
			const static uint8_t OrderType_MARKET_FOK = 31;
			const static uint8_t OrderType_MARKET_LIMIT_FAK = 32;
			const static uint8_t OrderType_MARKET_LIMIT_FOK = 33;
			const static uint8_t OrderType_MARKET_TO_LIMIT = 34;
			const static uint8_t OrderType_RFQI = 35;
			const static uint8_t OrderType_RFQT = 36;
			const static uint8_t OrderType_RFQ = 37;
			const static uint8_t OrderType_RSVD_QTY = 38;
			const static uint8_t OrderType_AA = 39;
			const static uint8_t OrderType_BASIS = 40;
			const static uint8_t OrderType_BLOCK = 41;
			const static uint8_t OrderType_CROSS = 42;
			const static uint8_t OrderType_EFS = 43;
			const static uint8_t OrderType_TAS_STRAT = 44;
			const static uint8_t OrderType_XEUREX = 45;
			const static uint8_t OrderType_SSO_CLOSE = 46;
			const static uint8_t OrderType_SSO_OPEN = 47;
			const static uint8_t OrderType_FUNARI = 48;
			const static uint8_t OrderType_OCO = 49;
			const static uint8_t OrderType_BEST = 50;
			const static uint8_t OrderType_SUMMARY = 51;
			const static uint8_t OrderType_SUMMARY_EDIT = 52;
			
			const static uint8_t OrderType_RESERVE = 53;		
			const static uint8_t OrderType_DESCRET = 54;
			const static uint8_t OrderType_RESERVE_DESCRET= 55;
			// Plus orders 
			const static uint8_t OrderType_MARKET_PLUS_TRAIL = 56;
			const static uint8_t OrderType_MARKET_PLUS_TTO = 57;
			const static uint8_t OrderType_MARKET_PLUS_STOP = 58;
			const static uint8_t OrderType_LIMIT_PLUS_STOP = 59;
			const static uint8_t OrderType_LIMIT_PLUS_TRAIL = 60;
			const static uint8_t OrderType_LIMIT_PLUS_TTO = 61;
			const static uint8_t OrderType_STOP_PLUS_TRAIL = 62;
			const static uint8_t OrderType_STOP_PLUS_TTO = 63;
			const static uint8_t OrderType_STOP_PLUS_LIMIT = 64;
			const static uint8_t OrderType_STOP_LIMIT_PLUS_TTO = 65;
			const static uint8_t OrderType_STOP_LIMIT_PLUS_TRAIL = 66;
			const static uint8_t OrderType_RESERVE_PLUS_TTO = 67;
			const static uint8_t OrderType_ON_STOP = 68;

			const static uint8_t OrderType_GTD_MARKET = 69;
			const static uint8_t OrderType_GTT_MARKET = 70;
			const static uint8_t OrderType_GTT_LIMIT = 71;
			const static uint8_t OrderType_GTT_STOP_LIMIT = 72;
			const static uint8_t OrderType_GTT_STOP = 73;
			const static uint8_t OrderType_WALKLIMIT_DEBIT = 74;
			const static uint8_t OrderType_WALKLIMIT_CREDIT = 75;
			const static uint8_t OrderType_MARKET_NEXT = 76;

			//Time In Force Pre-defined constants
			const static uint8_t TimeInForce_UNKNOWN = 0;
			const static uint8_t TimeInForce_DAY = 1;
			const static uint8_t TimeInForce_GTC = 2;
			const static uint8_t TimeInForce_IOC = 3;
			const static uint8_t TimeInForce_FOK = 4;
			const static uint8_t TimeInForce_DAY_EXT = 5;
			const static uint8_t TimeInForce_MOC = 6;
			const static uint8_t TimeInForce_GTC_EXT = 7;
			const static uint8_t TimeInForce_AM = 8;
			const static uint8_t TimeInForce_PM = 9;
			const static uint8_t TimeInForce_GTD = 10;
			const static uint8_t TimeInForce_GTD_EXT = 11;
			const static uint8_t TimeInForce_OPG = 12;
			const static uint8_t TimeInForce_CLO = 13;
			const static uint8_t TimeInForce_MINUTE = 14;
			const static uint8_t TimeInForce_EOS = 15;
			const static uint8_t TimeInForce_GTT = 16;

			//Spin instructions pre-defined constants
			const static uint8_t SpinInstruction_NONE = 1;
			const static uint8_t SpinInstruction_AON = 2;
			const static uint8_t SpinInstruction_FOK = 3;
			const static uint8_t SpinInstruction_DNR = 4;
			const static uint8_t SpinInstruction_AON_DNR = 5;

			const static uint8_t Strategy_UNKNOWN = 0;
			const static uint8_t Strategy_SPREAD = 1;
			const static uint8_t Strategy_STRANGLE = 2;
			const static uint8_t Strategy_STRADDLE = 3;
			const static uint8_t Strategy_COVERED_CALL = 4;
			const static uint8_t Strategy_PROTECTIVE_PUT = 5;
			const static uint8_t Strategy_COMBO = 6;

			const static uint8_t Strategy_COLLAR = 7;
			const static uint8_t Strategy_CONDOR = 8;
			const static uint8_t Strategy_IRON_CONDOR = 9;
			const static uint8_t Strategy_BUTTERFLY = 10;
			const static uint8_t Strategy_IRON_BUTTERFLY = 11;

			void setSymbol(string m_symbol);
			string getSymbol();

			void setSide(string m_side);
			uint8_t getSide();
			void getSide(string & m_side);

			void getStrategy(string & sStrategy);
			uint8_t getStrategy();
			void setStrategy(string sStrategyType);

			void setOrderType(string m_orderType);
			uint8_t getOrderType();
			void getOrderType(string & m_orderType);

			void setTimeInForce(string m_timeInForce);
			uint8_t getTimeInForce();
			void getTimeInForce(string & m_timeInForce);

			void setSpinInstructions(string m_spinInstructions);
			uint8_t getSpinInstructions();
			void getSpinInstructions(string & m_spinInstructions);

			void setLimitPrice(string m_limitPrice);
			string getLimitPrice();



			void setStopPrice(string m_stopPrice);
			string getStopPrice();

			void setTrailingStopParam(string m_tslParam);
			string getTrailingStopPrice();

			void setAccountID(string m_accountID);
			string getAccountID();

			void setUsername(string m_username);
			string getUsername();

			void setOrderID(string m_orderID);
			string getOrderID();

			void setSpreadID(string m_spreadID);
			string getSpreadID();

			void setQuantity(string m_quantity);
			string getQuantity();

			void setParam(string name, string value);
			string getParam(string name);

			void setQuantityType(string m_quantityType);
			string getQuantityType();

			void setPassword( string m_password );
			string getPassword();

			void setExchange( string m_exchange );
			string getExchange();

			void setDisclosedQuantity( string m_disclosedQuantity );
			string getDisclosedQuantity();

			void setAMOFlag( string m_amoFlag );
			string getAMOFlag();

			void setOriginalQuantity( string m_originalQuantity );
			string getOriginalQuantity();

			void setOriginalLimitPrice( string m_originalLimitPrice );
			string getOriginalLimitPrice();

			void setDeliveryFlag( string m_deliveryFlag );
			string getDeliveryFlag();

			void setRoute( string m_route );
			void setExpiryDay( string m_expiryDay );
			void setExpiryMonth(string m_expiryMonth );
			void setExpiryYear( string m_expiryYear);

			string getUpperTTO();
			string getLowerTTO();

			string getRoute();
			string getExpiryDay();
			string getExpiryMonth();
			string getExpiryYear();

			string getConditionSymbol();
			string getConditionPrice();
			string getConditionType();

			// used for plus or combo orders

			uint8_t getExectionOrderType();
			uint8_t getBasicOrderType();
			
			bool isPlus();
			void setNameValue(string name, string value);

		private:
			uint8_t u_orderSide, u_orderType, u_timeInForce, u_spinInstruction, u_strategyType, u_BasicOrderType, u_ExecutionOrderType;
			bool b_Plus;

			// Order Parameters.
			string sLegString;
			string symbol, side, orderType, timeInForce, accountID, username, orderID, route, limitPrice, stopPrice, tslParam, quantity;
			string expiryDay, expiryMonth, expiryYear, spinInstructions, quantityType, password, exchange, disclosedQuantity, amoFlag , originalQuantity, originalLimitPrice, deliveryFlag;

			string sUpperTTO, sLowerTTO;

			string sConditionSymbol, sConditionPrice, sConditionType;

			string sStrategy, sSpreadID;

			void reset();
			map<string, string>otherParams;

			void parse(string data);
	};

	class BrokerPlaceOrderRequest :
		public vector<OrderLeg>
	{
		public:
			BrokerPlaceOrderRequest(string data);
			~BrokerPlaceOrderRequest();

			//Some of the predefined Order action constants
			const static uint8_t OrderAction_UNKNOWN = 0;
			const static uint8_t OrderAction_ADD = 1;
			const static uint8_t OrderAction_EDIT = 2;
			const static uint8_t OrderAction_ADD_OCO = 3;
			const static uint8_t OrderAction_EDIT_OCO = 4;
			//Some of the predefined Instrument Type constants
			const static uint8_t InstrumentType_UNKNOWN = 0;
			const static uint8_t InstrumentType_EQUITY = 1;
			const static uint8_t InstrumentType_OPTIONS = 2;
			const static uint8_t InstrumentType_FUNDS = 3;
			const static uint8_t InstrumentType_FOREX = 4;
			const static uint8_t InstrumentType_FUTURES = 5;
			const static uint8_t InstrumentType_FUTURE_OPTIONS = 6;
			const static uint8_t InstrumentType_MINIOPTION = 7;
			const static uint8_t InstrumentType_DEBT = 8;

			//provides order action details
			uint8_t getOrderAction();
			//provides  Instrument Type
			uint8_t getInstrumentType();
			void getInstrumentType(string & sSecurityType);
			//sets order action from user request
			void setOrderAction(string m_orderAction);
			//sets order action as uint
			void setOrderAction(uint8_t m_orderAction);
			//adds a Order Leg
			void addOrderLeg(OrderLeg leg);
			//sets instrument details
			void setInstrumentType(string m_instrumentType);
			//checks if symbol is valid or not
			bool isSymbolValid(string m_symbol);
			//checks if quantity is valid or not
			bool isQuantityValid(string m_quantity);
			//checks if price is valid or not
			bool isPriceValid(string m_price);
			//checks if account id is valid or not
			bool isAccountIDValid(string m_accountID);
			//check if Order is a single-leg order.
			bool isSingleLeg();
			//get the original request.
			string toString();

		private:
			uint8_t u_orderAction, u_securityType;
			string sSecurityType;
			void parse(string data);
			string sOrigRequest;
	};

	class BrokerPlaceOrderResponse {
		public:
			BrokerPlaceOrderResponse();
			~BrokerPlaceOrderResponse();
			//sets status of that place order
			void setStatus(bool flag);
			//sets order id once it gets executed
			void setOrderID(string m_orderID);
			//sets order details value and append it with the string
			void toString(string &response);
			//sets error message if order fails
			void setErrorMessage(string m_errorMessage);
			//sets custom error message specific to broker
			void setCustomMessage(string m_customMessage);
			//sets third party message message specific to broker
			void setThirdPartyMessage( string m_thirdPartyMessage );
			//provides the executed order id
			string getOrderID();
			//provides the status of the order
			bool getStatus();

		private:
			string orderID, oldOrderId, errorMessage, customMessage, thirdPartyMessage;
			bool status;
	};


	class BrokerStrategyFetchRequest:
		public vector<OrderLeg>
	{
		public:
			BrokerStrategyFetchRequest(string data);
			~BrokerStrategyFetchRequest();
			vector<OrderLeg> getLegs();
			bool isSingleLeg();
			string toString();
	
			void addOrderLeg(OrderLeg leg);
		private:
			void parse(string data);
			string sOrigRequest;

	};

	class BrokerStrategyFetchResponse:
		public CSVData
		{
		public:
			BrokerStrategyFetchResponse(string data);
			BrokerStrategyFetchResponse();
			~BrokerStrategyFetchResponse();
			string getErrorMessage();
			void setErrorMessage(string s);
			string toString();
			void toString(string response);
		private:
			bool status;
			string error;
			int RequestID;
	};


	class ProbabilityCalcLeg {
		public:
			ProbabilityCalcLeg(string data);
			ProbabilityCalcLeg();
			~ProbabilityCalcLeg();

			const static uint8_t TimeInForce_UNKNOWN = 0;
			const static uint8_t TimeInForce_DAY = 1;
			const static uint8_t TimeInForce_GTC = 2;
			const static uint8_t TimeInForce_IOC = 3;
			const static uint8_t TimeInForce_FOK = 4;
			const static uint8_t TimeInForce_DAY_EXT = 5;
			const static uint8_t TimeInForce_MOC = 6;
			const static uint8_t TimeInForce_GTC_EXT = 7;
			const static uint8_t TimeInForce_AM = 8;
			const static uint8_t TimeInForce_PM = 9;
			const static uint8_t TimeInForce_GTD = 10;
			const static uint8_t TimeInForce_GTD_EXT = 11;
			const static uint8_t TimeInForce_OPG = 12;
			const static uint8_t TimeInForce_CLO = 13;
			const static uint8_t TimeInForce_MINUTE = 14;

			// Transaction type pre-defined constants
			const static uint8_t OrderSide_UNKNOWN = 0;
			const static uint8_t OrderSide_BUY = 1;
			const static uint8_t OrderSide_SELL = 2;
			const static uint8_t OrderSide_SELL_SHORT = 3;
			const static uint8_t OrderSide_BUY_TO_COVER = 4;
			const static uint8_t OrderSide_BUY_TO_OPEN = 5;
			const static uint8_t OrderSide_BUY_TO_CLOSE = 6;
			const static uint8_t OrderSide_SELL_TO_OPEN = 7;
			const static uint8_t OrderSide_SELL_TO_CLOSE = 8;
			const static uint8_t OrderSide_SUBSCRIPTION = 9;
			const static uint8_t OrderSide_REDEMPTION = 10;
			const static uint8_t OrderSide_BUY_MARGIN = 11;
			const static uint8_t OrderSide_SELL_MARGIN = 12;
			const static uint8_t OrderSide_SIP = 13;
                        const static uint8_t OrderSide_SWP = 14;

			// order type values pre-defined constants
			const static uint8_t OrderType_UNKNOWN = 0;
			const static uint8_t OrderType_MARKET = 1;
			const static uint8_t OrderType_LIMIT = 2;
			const static uint8_t OrderType_STOP = 3;
			const static uint8_t OrderType_STOP_LIMIT = 4;
			const static uint8_t OrderType_MOC = 5;
			const static uint8_t OrderType_LOC = 6;
			const static uint8_t OrderType_MOO = 7;
			const static uint8_t OrderType_LOO = 8;
			const static uint8_t OrderType_TRAILING_STOP_PERCENT = 9;
			const static uint8_t OrderType_TRAILING_STOP_DOLLAR = 10;
			const static uint8_t OrderType_PEGGED = 11;
			const static uint8_t OrderType_TTO = 12;

			const static uint8_t OrderType_CREDIT = 13;
			const static uint8_t OrderType_DEBIT = 14;
			const static uint8_t OrderType_EVEN = 15;
			
			const static uint8_t Strategy_UNKNOWN = 0;
			const static uint8_t Strategy_SPREAD = 1;
			const static uint8_t Strategy_STRANGLE = 2;
			const static uint8_t Strategy_STRADDLE = 3;
			const static uint8_t Strategy_COVERED_CALL = 4;
			const static uint8_t Strategy_PROTECTIVE_PUT = 5;
			const static uint8_t Strategy_COMBO = 6;
			const static uint8_t Strategy_COLLAR = 7;
			const static uint8_t Strategy_CONDOR = 8;
			const static uint8_t Strategy_IRON_CONDOR = 9;
			const static uint8_t Strategy_BUTTERFLY = 10;
			const static uint8_t Strategy_IRON_BUTTERFLY = 11;

			
			//sets strategy:
			void setStrategy(string m_strategy);			
			//provides the strategy value
			void getStrategy(string &strategy);
			
			uint8_t getStrategy();

			//sets quantity:
			void setQuantity(string m_quantity);
			//provides the quantity value
			string getQuantity();
			//sets account id
			void setAccountID(string m_accountID);
			//provides the account id
			string getAccountID();
			//sets time in force
			void setTimeInForce(string m_timeInForce);
			//provides time in force value
			uint8_t getTimeInForce();
			//provides time in force value as string
			void getTimeInForce(string & m_timeInForce);

			void setSymbol(string m_symbol);
			string getSymbol();

			void setSide(string m_side);
			uint8_t getSide();
			void getSide(string & m_side);


			void setOrderId(string id);
			string getOrderId();

			string s_orderId;

			void setSpreadId(string spreadId);
			string getSpreadId();
			string s_SpreadId;

			void setOrderType(string m_orderType);
			uint8_t getOrderType();
			void getOrderType(string & m_orderType);

			void setLimitPrice(string m_limitPrice);
			string getLimitPrice();

			void setStopPrice(string m_stopPrice);
			string getStopPrice();

			void setExpiryDay( string m_expiryDay );
			void setExpiryMonth(string m_expiryMonth );
			void setExpiryYear( string m_expiryYear);
			string getExpiryDay();
			string getExpiryMonth();
			string getExpiryYear();

			void setParam(string name, string value);
			string getParam(string name);



		private:


			uint8_t u_timeInForce, u_orderSide, u_orderType, u_strategy;
			string quantity, accountId, timeInForce, symbol, side, orderType, limitPrice, stopPrice, expiryDay, expiryMonth, expiryYear, strategy;
			map<string, string>otherParams;

			void setNameValue(string name, string value);
			void parse(string data);
	};


	class BrokerProbabilityRequest:
		public vector<ProbabilityCalcLeg>

	{
		public:
			BrokerProbabilityRequest(string data);
			~BrokerProbabilityRequest();
			uint8_t getInstrumentType();
			void setInstrumentType(string m_instrumentType);
			void addLeg(ProbabilityCalcLeg leg);
			void setOrderAction(string s_action);
			uint8_t getOrderAction();
			
			const static uint8_t OrderAction_UNKNOWN = 0;
			const static uint8_t OrderAction_ADD = 1;
			const static uint8_t OrderAction_EDIT = 2;

			// Instrument types
			const static uint8_t InstrumentType_UNKNOWN = 0;
			const static uint8_t InstrumentType_EQUITY = 1;
			const static uint8_t InstrumentType_OPTIONS = 2;
			const static uint8_t InstrumentType_FUNDS = 3;
			const static uint8_t InstrumentType_FOREX = 4;
			const static uint8_t InstrumentType_FUTURES = 5;
			const static uint8_t InstrumentType_FUTURE_OPTIONS = 6;
			const static uint8_t InstrumentType_MINIOPTION = 7;


			string getMobileRequest();

		private:
			string sMobileRequest;
			void setMobileRequest(string data);
			uint8_t u_orderAction, u_securityType;
			void parse(string data);
	};



	class CommissionLeg {
		public:
			CommissionLeg(string data);
			CommissionLeg();
			~CommissionLeg();

			const static uint8_t TimeInForce_UNKNOWN = 0;
			const static uint8_t TimeInForce_DAY = 1;
			const static uint8_t TimeInForce_GTC = 2;
			const static uint8_t TimeInForce_IOC = 3;
			const static uint8_t TimeInForce_FOK = 4;
			const static uint8_t TimeInForce_DAY_EXT = 5;
			const static uint8_t TimeInForce_MOC = 6;
			const static uint8_t TimeInForce_GTC_EXT = 7;
			const static uint8_t TimeInForce_AM = 8;
			const static uint8_t TimeInForce_PM = 9;
			const static uint8_t TimeInForce_GTD = 10;
			const static uint8_t TimeInForce_GTD_EXT = 11;
			const static uint8_t TimeInForce_OPG = 12;
			const static uint8_t TimeInForce_CLO = 13;
			const static uint8_t TimeInForce_MINUTE = 14;

			// Transaction type pre-defined constants
			const static uint8_t OrderSide_UNKNOWN = 0;
			const static uint8_t OrderSide_BUY = 1;
			const static uint8_t OrderSide_SELL = 2;
			const static uint8_t OrderSide_SELL_SHORT = 3;
			const static uint8_t OrderSide_BUY_TO_COVER = 4;
			const static uint8_t OrderSide_BUY_TO_OPEN = 5;
			const static uint8_t OrderSide_BUY_TO_CLOSE = 6;
			const static uint8_t OrderSide_SELL_TO_OPEN = 7;
			const static uint8_t OrderSide_SELL_TO_CLOSE = 8;
			const static uint8_t OrderSide_SUBSCRIPTION = 9;
			const static uint8_t OrderSide_REDEMPTION = 10;
			const static uint8_t OrderSide_BUY_MARGIN = 11;
			const static uint8_t OrderSide_SELL_MARGIN = 12;
			const static uint8_t OrderSide_SIP = 13;
                        const static uint8_t OrderSide_SWP = 14;

			// order type values pre-defined constants
			const static uint8_t OrderType_UNKNOWN = 0;
			const static uint8_t OrderType_MARKET = 1;
			const static uint8_t OrderType_LIMIT = 2;
			const static uint8_t OrderType_STOP = 3;
			const static uint8_t OrderType_STOP_LIMIT = 4;
			const static uint8_t OrderType_MOC = 5;
			const static uint8_t OrderType_LOC = 6;
			const static uint8_t OrderType_MOO = 7;
			const static uint8_t OrderType_LOO = 8;
			const static uint8_t OrderType_TRAILING_STOP_PERCENT = 9;
			const static uint8_t OrderType_TRAILING_STOP_DOLLAR = 10;
			const static uint8_t OrderType_PEGGED = 11;
			const static uint8_t OrderType_TTO = 12;

			const static uint8_t OrderType_CREDIT = 13;
			const static uint8_t OrderType_DEBIT = 14;
			const static uint8_t OrderType_EVEN = 15;
			const static uint8_t OrderType_WALKLIMIT_DEBIT = 16;
			const static uint8_t OrderType_WALKLIMIT_CREDIT = 17;
			
			const static uint8_t Strategy_UNKNOWN = 0;
			const static uint8_t Strategy_SPREAD = 1;
			const static uint8_t Strategy_STRANGLE = 2;
			const static uint8_t Strategy_STRADDLE = 3;
			const static uint8_t Strategy_COVERED_CALL = 4;
			const static uint8_t Strategy_PROTECTIVE_PUT = 5;
			const static uint8_t Strategy_COMBO = 6;
			const static uint8_t Strategy_COLLAR = 7;
			const static uint8_t Strategy_CONDOR = 8;
			const static uint8_t Strategy_IRON_CONDOR = 9;
			const static uint8_t Strategy_BUTTERFLY = 10;
			const static uint8_t Strategy_IRON_BUTTERFLY = 11;

			
			//sets strategy:
			void setStrategy(string m_strategy);			
			//provides the strategy value
			void getStrategy(string &strategy);
			
			uint8_t getStrategy();

			//sets quantity:
			void setQuantity(string m_quantity);
			//provides the quantity value
			string getQuantity();
			//sets account id
			void setAccountID(string m_accountID);
			//provides the account id
			string getAccountID();
			//sets time in force
			void setTimeInForce(string m_timeInForce);
			//provides time in force value
			uint8_t getTimeInForce();
			//provides time in force value as string
			void getTimeInForce(string & m_timeInForce);

			void setSymbol(string m_symbol);
			string getSymbol();

			void setSide(string m_side);
			uint8_t getSide();
			void getSide(string & m_side);


			void setOrderId(string id);
			string getOrderId();

			string s_orderId;

			void setSpreadId(string spreadId);
			string getSpreadId();
			string s_SpreadId;

			void setOrderType(string m_orderType);
			uint8_t getOrderType();
			void getOrderType(string & m_orderType);

			void setLimitPrice(string m_limitPrice);
			string getLimitPrice();

			void setStopPrice(string m_stopPrice);
			string getStopPrice();

			void setExpiryDay( string m_expiryDay );
			void setExpiryMonth(string m_expiryMonth );
			void setExpiryYear( string m_expiryYear);
			string getExpiryDay();
			string getExpiryMonth();
			string getExpiryYear();

			void setParam(string name, string value);
			string getParam(string name);
			string getConditionSymbol();
			string getConditionPrice();
			string getConditionType();

		private:
			uint8_t u_timeInForce, u_orderSide, u_orderType, u_strategy;
			string quantity, accountId, timeInForce, symbol, side, orderType, limitPrice, stopPrice, expiryDay, expiryMonth, expiryYear, strategy;
			map<string, string>otherParams;

			void setNameValue(string name, string value);
			void parse(string data);
			

			void  setConditionSymbol( string value );
			void  setConditionPrice( string value );
			void  setConditionType( string value );


			string sConditionType, sConditionSymbol, sConditionPrice;
	};

	class BrokerCommissionRequest :
		public vector<CommissionLeg>
	{
		public:
			BrokerCommissionRequest( string data );
			~BrokerCommissionRequest();
			// Broker actions
			
			const static uint8_t OrderAction_UNKNOWN = 0;
			const static uint8_t OrderAction_ADD = 1;
			const static uint8_t OrderAction_EDIT = 2;

			// Instrument types
			const static uint8_t InstrumentType_UNKNOWN = 0;
			const static uint8_t InstrumentType_EQUITY = 1;
			const static uint8_t InstrumentType_OPTIONS = 2;
			const static uint8_t InstrumentType_FUNDS = 3;
			const static uint8_t InstrumentType_FOREX = 4;
			const static uint8_t InstrumentType_FUTURES = 5;
			const static uint8_t InstrumentType_FUTURE_OPTIONS = 6;
			const static uint8_t InstrumentType_MINIOPTION = 7;

			//provides instrument type
			uint8_t getInstrumentType();
			// retrieves the order actions
			uint8_t getOrderAction();

			// sets the actions
			void setOrderAction(string m_orderaction);
			//sets the value for instrument type
			void setInstrumentType(string m_instrumentType);
			//add commision details as each leg
			void addCommissionLeg(CommissionLeg leg);

		private:

			uint8_t u_orderAction, u_securityType;
			void parse(string data);
	};

	class BrokerCommissionResponse {
		public:
			BrokerCommissionResponse();
			~BrokerCommissionResponse();

			//sets commision value for that specific order details
			void setCommission( string mCommission );
			void setCommissionData(string sName, string sValue);
			void toString(string & response);

		private:
			string commission;
			map<string, string> commission_data_map;
	};

	//Request to cancel Broker orders
	class BrokerCancelOrderRequest :
		public string
	{
		public:
			BrokerCancelOrderRequest(string data);
			~BrokerCancelOrderRequest();

			//provides the order id from cancel order request
			string getOrderID();
			//provides the account id from cancel order request
			string getAccountID();
			//provides the password specific to few brokers not all
			string getPassword();
			//provides the symbol details specific to kotak broker currently
			string getSymbol();
			//provides the exchange details specific to kotak broker currently
			string getExchange();
			//provides the instrument type specific to kotak broker currently
			string getInstrumentType();
			// get Action (BUY/SELL)
			string getSide();
			// get Username
			string getUsername();
			string getType();
			//Get Other params;
			string getParam(string sKey);
			string toString();

		private:

			string orderId, accountId, sPassword, sSymbol, sExchange, sInstrumentType, sType, sSide, sUsername;

			void handleOtherParams(string sName, string sValue);
			void parse(string data);
			void setValue(string, string);
			map<string, string>otherParams;
	};

	//Response to cancel Broker orders
	class BrokerCancelOrderResponse {
		public:
			BrokerCancelOrderResponse();
			~BrokerCancelOrderResponse();

			//sets order id for which the order is getting cancelled
			void setOrderId( string mOrderID );
			//sets error or success Message
			void setMessage( string mMessage );
			//sets status of cancel order
			void setStatus( bool mStatus );
			// provides the state of cancel order
			bool getStatus();
			//provides the exact response for cancel order by appending all the order details to response
			void toString(string & response);
		private:

			string orderId, message;
			bool status;
	};


	const static string UBACData_SYMBOL = "Symbol";
	const static string UBACData_TRADING_SYMBOL = "TradingSymbol";
	const static string UBACData_QUANTITY = "Quantity";
	const static string UBACData_REMAINING_QUANTITY = "Remaining Quantity";
	const static string UBACData_FILLED_QUANTITY = "FilledQuantity";
	const static string UBACData_ORDER_ID = "Order Id";
	const static string UBACData_SIDE = "Action";
	const static string UBACData_ORDER_TYPE = "Order Type";
	const static string UBACData_LIMIT_PRICE = "Limit Price";
	const static string UBACData_ORIGINAL_LIMIT_PRICE = "Original Limit Price";
	const static string UBACData_STOP_PRICE = "Stop Price";
	const static string UBACData_TRAILING_STOP_PARAM = "T-Stop Param";
	const static string UBACData_TRAILING_STOP_ACTIVATION_PRICE = "Trailing Activation Price";
	const static string UBACData_TIME_IN_FORCE = "Time In Force Session";
	const static string UBACData_EXPIRY_DATE = "Expiration";
	const static string UBACData_ORDER_STATUS = "Status";
	const static string UBACData_FILLS_SUMMARY = "Fills Summary";
	const static string UBACData_FILLS_DETAILS = "Fills Details";
	const static string UBACData_CANCELABLE = "Cancelable";
	const static string UBACData_EDITABLE = "Editable";
	const static string UBACData_PORTFOLIO_ASSET_TYPE = "AssetType";
	const static string UBACData_ORDER_STATUS_ASSET_TYPE = "Asset Type";
	const static string UBACData_RECEIVED_TIME = "Received Time";
	const static string UBACData_REPORTED_TIME = "Reported Time";
	const static string UBACData_CANCEL_DATE_TIME = "Cancel Date Time";
	const static string UBACData_SPECIAL_CONDITIONS = "Special Conditions";
	const static string UBACData_SPREAD_ID = "Spread ID";
	const static string UBACData_EXECUTION_PRICE = "Execution Price";
	const static string UBACData_ACCOUNT_ID = "Account ID";
	const static string UBACData_OPTION_MULTIPLIER = "Multiplier";
	const static string UBACData_PUT_OR_CALL = "Put Or Call";
	const static string UBACData_STRIKE_PRICE = "Strike Price";
	const static string UBACData_EXPIRY = "Expiry";
	const static string UBACData_TRADE_TYPE = "Trade Type";
	const static string UBACData_ORDER_NUMBER = "Order Number";
	const static string UBACData_TRAILING_STOP_METHOD = "T-Stop Method";
	const static string UBACData_DESCRIPTION = "Description";
	const static string UBACData_OPTION_DESCRIPTION = "OptionDescription";
	const static string UBACData_ORDER_REJECT_REASON = "Reject Reason";
	const static string UBACData_ORDER_DESCRIPTION = "Order Description";
	const static string UBACData_UNDERLYING = "Underlying";
	const static string UBACData_PAYMENT_MODE = "Payment Mode";
	const static string UBACData_EXCHANGE = "Exchange";
	const static string UBACData_DELIVERY_TYPE = "DeliveryType";
	const static string UBACData_BALANCE_QUANTITY = "BalanceQuantity";
	const static string UBACData_OPEN_BUY_QUANTITY = "OpenBuyQuantity";
	const static string UBACData_BUY_AVERAGE_PRICE = "BuyAveragePrice";
	const static string UBACData_SELL_AVERAGE_PRICE = "SellAveragePrice";
	const static string UBACData_OPEN_SELL_QUANTITY = "OpenSellQuantity";
	const static string UBACData_TRADED_NET_QUANTITY = "TradedNetQuantity";
	const static string UBACData_MARKET_EXCHANGE = "MarketExchange";
	const static string UBACData_INSTRUMENT_TYPE = "InstrumentType";
	const static string UBACData_DISCLOSED_QUANTITY = "DisclosedQuantity";
	const static string UBACData_BSE_SCRIP_CODE= "BSEScripCode";
	const static string UBACData_NSE_SCRIP_CODE="NSEScripCode";
	const static string UBACData_MARKET_LOT="MarketLot";
	const static string UBACData_TICK_SIZE="TickSize";
	const static string UBACData_MUTUAL_FUND_SERIES="MutualFundSeries";
	const static string UBACData_MUTUAL_FUND_AMOUNT="MutualFundAmount";
	const static string UBACData_IS_MULTI_LEG = "IsMultiLeg";
	const static string UBACData_STRATEGY_TYPE = "StrategyType";
	const static string UBACData_GROUP_ID="GroupID";
	const static string UBACData_CONDITION_SYMBOL="CONDITION_SYMBOL";
	const static string UBACData_CONDITION_PRICE="CONDITION_PRICE";
	const static string UBACData_CONDITION_TYPE="CONDITION_TYPE";
	const static string UBACData_AMOUNT="Amount";
	const static string UBACData_BID_NO="BidNo";
	const static string UBACData_APP_NO="ApplicationNo";
	const static string UBACData_CHEQUE_NO="ChequeNo";
	const static string UBACData_CUTOFF="CutOff";
	const static string UBACData_ISSUE_ID="IssueID";
	const static string UBACData_CATEGORY="Category";
	const static string UBACData_DPID="DPID";
	const static string UBACData_REFUND_TYPE="RefundType";
	const static string UBACData_UPPER_TTO_PRICE="UpperTTOPrice";
	const static string UBACData_LOWER_TTO_PRICE="LowerTTOPrice";
	const static string UBACData_MINIMUM_QUANTITY="MinimumQuantity";
	const static string UBACData_HIGH_BAND="HighBand";
	const static string UBACData_LOW_BAND="LowBand";
	const static string UBACData_52WK_HIGH="YearHigh";
	const static string UBACData_52WK_Low="YearLow";

	DEFINE_FIELD(Symbol, UBACData_SYMBOL, string)
	DEFINE_FIELD(TradingSymbol, UBACData_TRADING_SYMBOL, string)
	DEFINE_FIELD(Quantity, UBACData_QUANTITY, string)
	DEFINE_FIELD(RemainingQuantity, UBACData_REMAINING_QUANTITY, string)
	DEFINE_FIELD(FilledQuantity, UBACData_FILLED_QUANTITY, string)
	DEFINE_FIELD(OrderID, UBACData_ORDER_ID, string)
	DEFINE_FIELD(Side, UBACData_SIDE, string)
	DEFINE_FIELD(OrderType, UBACData_ORDER_TYPE, string)
	DEFINE_FIELD(LimitPrice, UBACData_LIMIT_PRICE, string)
	DEFINE_FIELD(OriginalLimitPrice, UBACData_ORIGINAL_LIMIT_PRICE, string)
	DEFINE_FIELD(StopPrice, UBACData_STOP_PRICE, string)
	DEFINE_FIELD(TrailingStopParam, UBACData_TRAILING_STOP_PARAM, string)
	DEFINE_FIELD(TrailingStopActivationPrice, UBACData_TRAILING_STOP_ACTIVATION_PRICE, string)
	DEFINE_FIELD(TimeInForce, UBACData_TIME_IN_FORCE, string)
	DEFINE_FIELD(ExpiryDate, UBACData_EXPIRY_DATE, string)
	DEFINE_FIELD(OrderStatus, UBACData_ORDER_STATUS, string)
	DEFINE_FIELD(FillsSummary, UBACData_FILLS_SUMMARY, string)
	DEFINE_FIELD(FillsDetails, UBACData_FILLS_DETAILS, string)
	DEFINE_FIELD(Cancelable, UBACData_CANCELABLE, string)
	DEFINE_FIELD(Editable, UBACData_EDITABLE, string)
	DEFINE_FIELD(PortfolioAssetType, UBACData_PORTFOLIO_ASSET_TYPE, string)
	DEFINE_FIELD(OrderStatusAssetType, UBACData_ORDER_STATUS_ASSET_TYPE, string)
	DEFINE_FIELD(ReceivedTime, UBACData_RECEIVED_TIME, string)
	DEFINE_FIELD(ReportedTime, UBACData_REPORTED_TIME, string)
	DEFINE_FIELD(CancelDate, UBACData_CANCEL_DATE_TIME, string)
	DEFINE_FIELD(SpecialConditions, UBACData_SPECIAL_CONDITIONS, string)
	DEFINE_FIELD(SpreadID, UBACData_SPREAD_ID, string)
	DEFINE_FIELD(ExecutionPrice, UBACData_EXECUTION_PRICE, string)
	DEFINE_FIELD(AccountID, UBACData_ACCOUNT_ID, string)
	DEFINE_FIELD(OptionMultiplier, UBACData_OPTION_MULTIPLIER, string)
	DEFINE_FIELD(PutOrCall, UBACData_PUT_OR_CALL, string)
	DEFINE_FIELD(StrikePrice, UBACData_STRIKE_PRICE, string)
	DEFINE_FIELD(Expiry, UBACData_EXPIRY, string)
	DEFINE_FIELD(TradeType, UBACData_TRADE_TYPE, string)
	DEFINE_FIELD(OrderNumber, UBACData_ORDER_NUMBER, string)
	DEFINE_FIELD(TrailingStopMethod, UBACData_TRAILING_STOP_METHOD, string)
	DEFINE_FIELD(Description, UBACData_DESCRIPTION, string)
	DEFINE_FIELD(OptionDescription, UBACData_OPTION_DESCRIPTION, string)
	DEFINE_FIELD(RejectReason, UBACData_ORDER_REJECT_REASON, string)
	DEFINE_FIELD(OrderDescription, UBACData_ORDER_DESCRIPTION, string)
	DEFINE_FIELD(Underlying, UBACData_UNDERLYING, string)
	DEFINE_FIELD(PaymentMode, UBACData_PAYMENT_MODE, string)
	DEFINE_FIELD(Exchange, UBACData_EXCHANGE, string)
	DEFINE_FIELD(DeliveryType, UBACData_DELIVERY_TYPE, string)
	DEFINE_FIELD(BalanceQunatity, UBACData_BALANCE_QUANTITY, string)
	DEFINE_FIELD(OpenBuyQuantity, UBACData_OPEN_BUY_QUANTITY, string)
	DEFINE_FIELD(BuyAveragePrice, UBACData_BUY_AVERAGE_PRICE, string)
	DEFINE_FIELD(SellAveragePrice, UBACData_SELL_AVERAGE_PRICE, string)
	DEFINE_FIELD(OpenSellQuantity, UBACData_OPEN_SELL_QUANTITY, string)
	DEFINE_FIELD(TradedNetQuantity, UBACData_TRADED_NET_QUANTITY, string)
	DEFINE_FIELD(MarketExchange, UBACData_MARKET_EXCHANGE, string)
	DEFINE_FIELD(InstrumentType, UBACData_INSTRUMENT_TYPE, string)
	DEFINE_FIELD(DisclosedQuantity, UBACData_DISCLOSED_QUANTITY, string);
	DEFINE_FIELD(BSEScripCode, UBACData_BSE_SCRIP_CODE, string);
	DEFINE_FIELD(NSEScripCode, UBACData_NSE_SCRIP_CODE, string);
	DEFINE_FIELD(MarketLot, UBACData_MARKET_LOT, string);
	DEFINE_FIELD(TickSize, UBACData_TICK_SIZE, string);
	DEFINE_FIELD(MutualFundSeries, UBACData_MUTUAL_FUND_SERIES, string);
	DEFINE_FIELD(MutualFundAmount, UBACData_MUTUAL_FUND_AMOUNT, string);
	DEFINE_FIELD(IsMultiLeg, UBACData_IS_MULTI_LEG, string);
	DEFINE_FIELD(StrategyType, UBACData_STRATEGY_TYPE, string);
	DEFINE_FIELD(GroupID, UBACData_GROUP_ID, string);
	DEFINE_FIELD(ConditionSymbol, UBACData_CONDITION_SYMBOL, string);
	DEFINE_FIELD(ConditionPrice, UBACData_CONDITION_PRICE, string);
	DEFINE_FIELD(ConditionType, UBACData_CONDITION_TYPE, string);
	DEFINE_FIELD(Amount, UBACData_AMOUNT, string);
	DEFINE_FIELD(BidNo, UBACData_BID_NO, string);
	DEFINE_FIELD(ApplicationNo, UBACData_APP_NO, string);
	DEFINE_FIELD(ChequeNo, UBACData_CHEQUE_NO, string);
	DEFINE_FIELD(CutOff, UBACData_CUTOFF, string);
	DEFINE_FIELD(IssueID, UBACData_ISSUE_ID, string);
	DEFINE_FIELD(Category, UBACData_CATEGORY, string);
	DEFINE_FIELD(DPID, UBACData_DPID, string);
	DEFINE_FIELD(RefundType, UBACData_REFUND_TYPE, string);
	DEFINE_FIELD(UpperTTOPrice, UBACData_UPPER_TTO_PRICE, string);
	DEFINE_FIELD(LowerTTOPrice, UBACData_LOWER_TTO_PRICE, string);
	DEFINE_FIELD(MinimumQuantity, UBACData_MINIMUM_QUANTITY, string);
	DEFINE_FIELD(HighBand, UBACData_HIGH_BAND, string);
	DEFINE_FIELD(LowBand, UBACData_LOW_BAND, string);
	DEFINE_FIELD(YearHigh, UBACData_52WK_HIGH, string);
	DEFINE_FIELD(YearLow, UBACData_52WK_Low, string);

	class NewBrokerOrderStatusRequest :
		public string
	{
		public:
			NewBrokerOrderStatusRequest(string data);
			~NewBrokerOrderStatusRequest();

			string getAccountID();
			string getDurationType();
			string getParam(string sKey);
			string toString();
		private:
			void setNameValueData( string mName, string mValue );
			void parse(string data);

			string accountID,durationType;
			map<string, string> otherParams;
	};

	class NewBrokerOrderStatusResponse : public CSVData
	{
		public:
			NewBrokerOrderStatusResponse();
			~NewBrokerOrderStatusResponse();

			void toString( string & response );
	};

	class BrokerOrderStatusRequest : public string
	{
		public:
			BrokerOrderStatusRequest(string data);
			~BrokerOrderStatusRequest();

			string getAccountID();
			string getDurationType();
			string getParam(string sKey);
			string toString();

		private:
			string accountID;
			string durationType;
			void parse(string data);
			map<string, string> otherParams;
	};

	/** This represents Pending Orders, Order Book, Trade Book etc. */
	class OrderStatusEntry :
		public string
	{
		public:
			OrderStatusEntry();
			~OrderStatusEntry();

			/** Set Product Type. */
			FIELD_SET(ProductType)
			/** Set SOR for kotak */
			FIELD_SET(SOR)
			FIELD_SET(SORURL)
			/** Set the currency in which the trade was settled. */
			FIELD_SET(Currency)
			/** Set the exchange in which the order was submitted or executed. */
			FIELD_SET(Exchange)
			/** Set the payment mode used for the trade. */
			FIELD_SET(PaymentMode)
			/** Set the bried description for the trade. */
			FIELD_SET(OrderDescription)
			/** Set the Trading Symbol for which the trade was placed. */
			FIELD_SET(TradingSymbol)
			/** Set the Symbol for which the trade was placed. */
			FIELD_SET(Symbol)
			/** Set the quantity or the lot size for the trade. */
			FIELD_SET(Quantity)
			/** Set the remaining/pending quantity, which is still waiting to be executed. Usually valid for
			  * partially filled orders. */
			FIELD_SET(RemainingQuantity)
			/** Set the filled quantity. */
			FIELD_SET(FilledQuantity)
			/** Set the OrderID. Usually a unique id, set by the exchange or the broker.
			  * This ID is usually used for editing or cancelling orders. */
			FIELD_SET(OrderID)
			/** Set the Side, transaction type for the order. Usually BUY or SELL are valid. */
			FIELD_SET(Side)
			/** Set the order type. This is implementation specific. Standard valid values are, Market, Limit, Stop Market and Stop Limit. */
			FIELD_SET(OrderType)
			/** Set the reason for rejection of the trade. */
			FIELD_SET(RejectReason)
			/** Set the limit price. */
			FIELD_SET(LimitPrice)
			/** set the original limit price. */
			FIELD_SET(OriginalLimitPrice)
			/** Set the stop loss trigger price. */
			FIELD_SET(StopPrice)
			/** Set the underlying symbol for trades placed on derivatives. */
			FIELD_SET(Underlying)
			/** Set the trailing stop loss parameter. */
			FIELD_SET(TrailingStopParam)
			/** Set the trailing stop loss activation price. */
			FIELD_SET(TrailingStopActivationPrice)
			/** Set the time in force or the expiry for the trade. */
			FIELD_SET(TimeInForce)
			/** Set the expiry date, if the broker/exchange provides one. */
			FIELD_SET(ExpiryDate)
			/** Set the order status. Valid values are Open, Queued, Pending New, Pending Canceled, Canceled, Filled, Partial Fill, Rejected.
			  * Any other status is implementation specific. */
			FIELD_SET(OrderStatus)
			/** Set the fill summary. */
			FIELD_SET(FillsSummary)
			/** Set the fill details. */
			FIELD_SET(FillsDetails)
			/** Set the cancelable flag. This suggests if the trade can be canceled or not. Usually, if OrderStatus == Open/Queued/Partial Fill,
			  * then the trade is cancelable. Otherwise it is not. Valid values are true or false. This is a mandatory parameter unless the data
			  * is a trade report. */
			FIELD_SET(Cancelable)
			/** Set the editable flag. This suggests if the trade can be edited or not. USually, if the OrderStatus == Open/Queued/Partial Fill,
			  * then the trade is editable. Otherwise it is not. Valid values are true or false. This is a mandatory parameter unless the data
			  * is a trade report. */
			FIELD_SET(Editable)
			/** Set the asset type. Valid values are Equity, Option, Future, Future_Option, Forex. */
			FIELD_SET(OrderStatusAssetType)
			/** Set the time at which the order was received. */
			FIELD_SET(ReceivedTime)
			/** Set the time at which the order was reported at the exchange. Not a mandatory parameter. */
			FIELD_SET(ReportedTime)
			/** Set the timestamp, at which the trade was canceled. */
			FIELD_SET(CancelDate)
			/** Set the special conditions like AON, FOK etc. */
			FIELD_SET(SpecialConditions)
			/** Set the SpreadID. This ID should be used to club the orders, when the report contains multi-leg orders. */
			FIELD_SET(SpreadID)
			/* This is the execution price of the trade. Sometimes it would be the average execution price. */
			FIELD_SET(ExecutionPrice)
			/** Set the account id for which the trade was placed. This could be the userid also. */
			FIELD_SET(AccountID)
			/** Set the option multipler or the lot size if the trade was placed for the derivative. */
			FIELD_SET(OptionMultiplier)
			/** Set the option type if the trade was placed for an option symbol. Not a mandatory parameter. */
			FIELD_SET(PutOrCall)
			/** Set the strike price if the trade was placed for an option symbol. Not a mandatory parameter. */
			FIELD_SET(StrikePrice)
			/** Set the expiry if the trade was placed for a derivative. Not a mandatory parameter. */
			FIELD_SET(Expiry)
			/** Set the trade type. Implementation specific. Not a mandatory parameter. */
			FIELD_SET(TradeType)
			/** Set the Order Number. Usually, this might be the same as OrderID. But in case it is different, OrderNumber is
			  * what is displayed to the user instead of OrderID. */
			FIELD_SET(OrderNumber)
			/** Set the trailing stop method. Implementation specific and not mandatory. */
			FIELD_SET(TrailingStopMethod)
			/** Set the description or the company name. */
			FIELD_SET(Description)
			/** Set the option description if the trade was for an option. */
			FIELD_SET(OptionDescription)
			/** Set the delivery type. Implementation specific. */
			FIELD_SET(DeliveryType)
			FIELD_SET(MarketExchange)
			FIELD_SET(InstrumentType)
			FIELD_SET(DisclosedQuantity)
			FIELD_SET(MarketLot)
			FIELD_SET(TickSize)
			FIELD_SET(MutualFundSeries)
			FIELD_SET(MutualFundAmount)
			/** Set Condition Price. */
			FIELD_SET(ConditionPrice)
			/** Set Condition Type. */
			FIELD_SET(ConditionType)
			/** Set Condition Symbol. */
			FIELD_SET(ConditionSymbol);
			/** Set Amount. */
			FIELD_SET(Amount);
			/** Set Bid Number. */
			FIELD_SET(BidNo);
			/** Set Application Number. */
			FIELD_SET(ApplicationNo);
			/** Set Cheque Number. */
			FIELD_SET(ChequeNo);
			/** Set Cutoff. */
			FIELD_SET(CutOff);
			/** Set IssueID. */
			FIELD_SET(IssueID);
			/** Set DPID. */
			FIELD_SET(DPID);
			/** Set Refund Type. */
			FIELD_SET(RefundType);
			/** Set Upper TTO Price. */
			FIELD_SET(UpperTTOPrice);
			/** Set Lower TTO Price. */
			FIELD_SET(LowerTTOPrice);
			/** Set Last Price. */
			FIELD_SET(LastPrice);
			/** Set Minimum Quantity. */
			FIELD_SET(MinimumQuantity);
			/** Set High Band. */
			FIELD_SET(HighBand);
			/** Set Low Band. */
			FIELD_SET(LowBand);
			FIELD_SET(Category);
			FIELD_SET(PositionID);
			FIELD_SET(ContingencyID);
			FIELD_SET(ContingencyType);
			/** spreadName fields for the order **/
			FIELD_SET(StrategyType);
			FIELD_GET(StrategyType);
			
			/** Set the Currency value. This data is specific to broker , some of them may use it and some may not */
			FIELD_GET(Currency)
			/** SOR for kotak */
           	FIELD_GET(SOR)
            FIELD_GET(SORURL)
			/** Set Exchange to which symbol belongs to. */
			FIELD_GET(Exchange)
			/** Set Payment Mode. Same not used with all brokers , specific to few ones. */
			FIELD_GET(PaymentMode)
			/** Set Order Description. Same not used with all brokers , specific to few ones. */
			FIELD_GET(OrderDescription)
			/** Set Symbol for which the order is placed */
			FIELD_GET(Symbol)
			/** Set Quantity , the amount of the order placed */
			FIELD_GET(Quantity)
			/** Set Remaining Quantity.Balance amount of order places */
			FIELD_GET(RemainingQuantity)
			/** Set Filled Quantity.Executed amount of order places */
			FIELD_GET(FilledQuantity)
			/** Set OrderID.The uniq data which is used to trace the order */
			FIELD_GET(OrderID)
			/** set Side ie BUY/SELL/BUYTOCOVER/SELLTOSHORT/BUYTOOPEN/SELLTOCLOSE */
			FIELD_GET(Side)
			/** set OrderType.Order type can be Market,Limit,Stop,StopLimit */
			FIELD_GET(OrderType)
			/** set Reject Reason.Various reasons for an order getting rejected */
			FIELD_GET(RejectReason)
			/** set Limit Price.This price will get filled only for limit orders */
			FIELD_GET(LimitPrice)
			/** get the Original limit price**/
			FIELD_GET(OriginalLimitPrice)
			/** set Stop Price.This price will get filled only for Stop orders */
			FIELD_GET(StopPrice)
			/** set Underlying symbol.It will be there only for Option symbols and it may be there for other as the same symbol for which the order is placed */
			FIELD_GET(Underlying)
			/** set Trailing Stop Param */
			FIELD_GET(TrailingStopParam)
			/** set Trailing Stop Activation Price */
			FIELD_GET(TrailingStopActivationPrice)
			/** set  Time In Force */
			FIELD_GET(TimeInForce)
			/** set Expiry Date.This data will be there for orders placed with option or future symbol */
			FIELD_GET(ExpiryDate)
			/** set Order Status.Value can be OPEN/EXPIRED/REJECTED etc */
			FIELD_GET(OrderStatus)
			FIELD_GET(FillsSummary)
			FIELD_GET(FillsDetails)
			/** set Cancelable.Flag for whether it is cancelable or not */
			FIELD_GET(Cancelable)
			/** set Editable.Flag for whether it is Editable or not */
			FIELD_GET(Editable)
			/** set  Asset Type */
			FIELD_GET(OrderStatusAssetType)
			/** set Received Time */
			FIELD_GET(ReceivedTime)
			/** set Reported Time */
			FIELD_GET(ReportedTime)
			/** set Cancel Date.Date on which order got cancelled */
			FIELD_GET(CancelDate)
			FIELD_GET(SpecialConditions)
			FIELD_GET(SpreadID)
			/** set ExecutionPrice.Price at which order got executed */
			FIELD_GET(ExecutionPrice)
			/** set AccountID */
			FIELD_GET(AccountID)
			/** set option multiplier.Only avaialble for options */
			FIELD_GET(OptionMultiplier)
			/** set put or call.Only avaialble for options */
			FIELD_GET(PutOrCall)
			/** set strike price.Only avaialble for options */
			FIELD_GET(StrikePrice)
			/** set Expiry */
			FIELD_GET(Expiry)
			/** set Trade Type */
			FIELD_GET(TradeType)
			/** set Order Number */
			FIELD_GET(OrderNumber)
			/** set TrailingStopMethod */
			FIELD_GET(TrailingStopMethod)
			/** set Description */
			FIELD_GET(Description)
			/** set OptionDescription */
			FIELD_GET(OptionDescription)
			/** set DeliveryType */
			FIELD_GET(DeliveryType)
			/** Get Product Type. */
			FIELD_GET(ProductType)
			/** Get Condition Price. */
			FIELD_GET(ConditionPrice)
			/** Get Condition Type. */
			FIELD_GET(ConditionType)
			/** Get Condition Symbol. */
			FIELD_GET(ConditionSymbol);
			/** Get Amount. */
			FIELD_GET(Amount);
			/** Get Bid Number. */
			FIELD_GET(BidNo);
			/** Get Application Number. */
			FIELD_GET(ApplicationNo);
			/** Get Cheque Number. */
			FIELD_GET(ChequeNo);
			/** Get Cutoff. */
			FIELD_GET(CutOff);
			/** Get IssueID. */
			FIELD_GET(IssueID);
			/** Get DPID. */
			FIELD_GET(DPID);
			/** Get Refund Type. */
			FIELD_GET(RefundType);
			/** Get Upper TTO Price. */
			FIELD_GET(UpperTTOPrice);
			/** Get Lower TTO Price. */
			FIELD_GET(LowerTTOPrice);
			/** Get Last Price. */
			FIELD_GET(LastPrice);
			/** Get Minimum Quantity. */
			FIELD_GET(MinimumQuantity);
			/** Get High Band. */
			FIELD_GET(HighBand);
			/** Get Low Band. */
			FIELD_GET(LowBand);
			FIELD_GET(Category);
			FIELD_GET(PositionID);
			FIELD_GET(ContingencyID);
			FIELD_GET(ContingencyType);

			const static char entry_delimiter;

		private:
			map<string, string>fieldMap;
	};

	class BrokerOrderStatusResponse :
		public vector<OrderStatusEntry>
	{
		public:
			BrokerOrderStatusResponse();
			~BrokerOrderStatusResponse();

			void setMessage(string sMessage);
			/** Add and entry for the order status. */
			void addOrderStatus( OrderStatusEntry entry );
			/** Convert the class to a string. */
			void toString(string &output);

		private:
			string sMessage;
	};

	class BrokerOptionsChainRequest {
		public:
			BrokerOptionsChainRequest(string data, int i_protocolCode = UBACData::Protocol_GET_OPTION_CHAIN);
			~BrokerOptionsChainRequest();

			string getSymbol();
			int getProtocolCode();
			string getParam(string sKey);
			string getChainType();

		private:
			void parse(string data);
			void setOtherParam(string name, string value);

			string symbol, chainType;
			map<string, string> otherParams;
			int protocolCode;
	};

	class OptionsChain {
		public:
			OptionsChain(string expiryDate, string noOfDaysToExpire);
			OptionsChain();
			~OptionsChain();

			void setExpiryDate( string mExpiryDate );
			void setLeap( string mLeap );
			void setMonthId( string mMonthId );
			void setNoOfDaysToExpire( string mNoOfDaysToExpire );
			void setStandardOption( string mStandardOption );
			void setStrikePrice( string mStrikePrice );
			void setPutSymbol( string mPutSymbol );
			void setCallSymbol( string mCallSymbol );
			void setPutLastPrice( string mPutLastPrice );
			void setCallLastPrice( string mCallLastPrice );
			void setPutOpenInterest( string mPutOpenInterest );
			void setPutVolume( string mPutVolume );
			void setCallOpenInterest( string mCallOpenInterest );
			void setCallVolume( string mCallVolume );
			void setPutOptionDescription( string mPutOptionDescription );
			void setCallOptionDescription( string mCallOptionDescription );

			string getNoOfDaysToExpire();

			void toString(string & output);

		private:
			string expiryDate, leap, monthId, noOfDaysToExpire, standardOption;
			string strikePrice, putSymbol, callSymbol, putLastPrice, callLastPrice;
			string putOpenInterest, putVolume, callOpenInterest, callVolume, putOptionDescription, callOptionDescription;

	};

	class BrokerOptionsChainResponse {
		public:
			BrokerOptionsChainResponse();
			~BrokerOptionsChainResponse();

			SingleQuoteResponse underlyingQuote;

			void trimProtocolHeaderTrailer(string & response);
			void toString(string & output);
			void toString(string & output, string expiryFromFormat, string expiryToFormat, uint8_t limit = 0);
			void addOptionsChain(string expiryDate, OptionsChain optionsChainData);

		private:
			map<string, vector<OptionsChain> >optionsChainList;
	};

	class BrokerCustomerProfileRequest {
		public:
			BrokerCustomerProfileRequest(string data);
			~BrokerCustomerProfileRequest();
			string getAccountID();

		private:
			string sAccountID;
	};

	class BrokerCustomerProfileResponse {
		public:
			BrokerCustomerProfileResponse();
			~BrokerCustomerProfileResponse();

			void setData(string sKey, string sValue);
			void toString(string &response);
		private:
			map<string, string>dataMap;
	};

	class SymbolDataRequest {
		public:
			SymbolDataRequest(string s) : symbol(s) {}
			~SymbolDataRequest() {}

			string getSymbol() { return symbol; }

		private:

			string symbol;
	};

	class SymbolDataResponse {
		public:
			SymbolDataResponse();
			~SymbolDataResponse();

			void addField(string name, string value);
			void toString(string & response);
			void setError(string error);

			void setStatus(bool flag = false);
			bool getStatus();
			void getField(string name, string & value);

		private:
			map<string, string>nameValuePair;
			string errorMessage;
			bool status;
	};

	/* Do Not Use this .Will be porting this soon to new format */
	class BrokerGetWatchListRequest {
		public:
			BrokerGetWatchListRequest(string data);
			~BrokerGetWatchListRequest();
	};

	/* Do Not Use this .This was used with old format.*/
	class WatchListEntry {
		public:
			WatchListEntry();
			~WatchListEntry();

			void setSymbol(string mSymbol);
			void setUnderlying(string mUnderlying);
			void setDescription(string mDescription);
			void setAssetType(string mAssetType);
			void setNameValue(string name, string value);
			void setOptionDescription(string mOptionDescription);
			void toString(string & response);
			void getSymbol(string & mSymbol);
			void getValue(string name, string & value);

		private:
			string symbol, description, assetType, optionDescription, underlying;
			map<string, string>nameValuePair;
	};

	/* Do Not Use this .This was used with old format.*/
	class WatchListGroup {
		public:
			WatchListGroup();
			~WatchListGroup();

			void setName(string mName);
			void setId(string mId);
			void addWatchListEntry(WatchListEntry entry);
			void toString(string & response);
			void getName(string & mName);
			void getId(string & mId);
			void getAllSymbols(vector<string> &symbolList);
			WatchListEntry & getFirstEntry();
			WatchListEntry & getNextEntry();
			bool hasEntry();

		private:
			vector<WatchListEntry>::iterator entryIterator;
			string watchListName, watchListId;
			vector<WatchListEntry>watchListEntries;
	};

	/* Do Not Use this .Will be porting this soon to new format */
	class BrokerGetWatchListResponse {
		public:
			BrokerGetWatchListResponse();
			~BrokerGetWatchListResponse();

			void setAccountID(string mAccountId);
			void addWatchListGroup(WatchListGroup list);
			void toString(string & response);

		private:
			string accountId;
			vector<WatchListGroup>groupList;
	};

	/* Do Not Use this .Will be porting this soon to new format */
	class BrokerWatchListActionRequest {
		public:
			BrokerWatchListActionRequest(string data);
			~BrokerWatchListActionRequest();

			void getWatchListName(string & name);
			void getWatchListId(string & id);
			WatchListGroup & getWLGroup();

		private:
			void parse(string data);
			void insertInput(string name, vector<string>values);
			WatchListGroup group;
	};

	/* Do Not Use this .Will be porting this soon to new format */
	class TDABrokerWatchListActionRequest :
		public IFHelper
	{
		public:
			TDABrokerWatchListActionRequest(string data);
			~TDABrokerWatchListActionRequest();

			void getList(string & mList);

		private:
			void getUniqueSymbols(string & symbolList);
			void parse(string data);
			void setListId(string watchListid);
			void setWatchlistName(string watchlistName);
			void setSymbollist(string symbolList);
			void setQuantitylist(string quantityList);
			void setMonthlist(string monthList);
			void setDaylist(string dayList);
			void setYearlist(string yearList);
			void setPricelist(string priceList);
			void setCommissionlist(string commissionList);

			string list;
	};

	/* Do Not Use this .Will be porting this soon to new format */
	class BrokerWatchListActionResponse :
		public IFHelper
	{
		public:
			BrokerWatchListActionResponse();
			~BrokerWatchListActionResponse();

			WatchListGroup & getWLGroup();
			void setAccountId(string mAccountId);
			void toString(string & response, const uint8_t type);
			void setSecurityWatchIDList(vector<string> & secWatchIDList);

			static const uint8_t DELETE_WATCHLIST = 1;

		private:
			WatchListGroup group;
			string accountId;
			vector<string>securityWatchIdList;
	};

	/* Do Not Use this .Will be porting this soon to new format */
	class  TDABrokerWatchListActionResponse {
		public:
			TDABrokerWatchListActionResponse();
			~TDABrokerWatchListActionResponse();

			void addWatchListGroup(WatchListGroup list);
			void toString(string & response, string action );
			void setWatchListName(string mWatchListName);
			void setWatchListId(string mWatchListId);
			void setAccountID(string mAccountId);

		private:

			string accountId, watchListName,watchListId;
			vector<WatchListGroup>groupList;
	};

	class Portfolio :
		public string
	{
		public:
			Portfolio();
			~Portfolio();

			/** Set Product Type. */
			FIELD_SET(ProductType)
			/** Set Exchange. */
			FIELD_SET(Exchange)
			/** Set Asset Type. Valid values are EQUITY, OPTION, FUTURE, FOREX, FUTURE_OPTION. */
			FIELD_SET(PortfolioAssetType)
			/** Set ID for the portfolio. Should be the unique ID. */
			FIELD_SET(PortfolioID)
			/** Set the Trading Symbol for which the trade was placed. */
			FIELD_SET(TradingSymbol)
			/** Set the symbol/stock/security of the portfolio. */
			FIELD_SET(Symbol)
			/** Set the quantity or the no of lots (in case of derivatives). */
			FIELD_SET(Quantity)
			/** Set the balance quantity or the no of lots (in case of derivatives). specif to Kotak */
			FIELD_SET(BalanceQunatity)
			/** Set the Buy average price. */
			FIELD_SET(BuyAveragePrice)
			/** Set the Sell average price. */
			FIELD_SET(SellAveragePrice)
			/** Set the open buy quantity or the no of lots (in case of derivatives). specif to Kotak */
			FIELD_SET(OpenBuyQuantity)
			/** Set the open sell quantity or the no of lots (in case of derivatives). specif to Kotak */
			FIELD_SET(OpenSellQuantity)
			/** Set the traded net quantity or the no of lots (in case of derivatives). specif to Kotak */
			FIELD_SET(TradedNetQuantity)
			/** Set the Cost Basis or price per quantity of the portfolio. */
			FIELD_SET(PaidPrice)
			/** Set the Side for the portfolio. Valid values are 'B' for BUY and 'S' for Sell. */
			FIELD_SET(TransactionType)
			/** Set the time at which the portfolio was created or the time when the trade got executed and
			  * it became a part of the holdings. */
			FIELD_SET(PortfolioTime)
			/** Set the comments if any. Not a mandatory parameter. */
			FIELD_SET(Comments)
			/** Set the underlying symbol if the portfolio is for a derivative. */
			FIELD_SET(Underlying)
			/** Set the alias name. Not a mandatory parameter. */
			FIELD_SET(AliasName)
			/** Set the currency in which the trade was made. */
			FIELD_SET(Currency)
			/** Set the total cost of the portfolio. Generally, it will be
			  * (CostBasis x Quantity) + Brokerage + Commission. */
			FIELD_SET(TotalPaidPrice)
			/** Set the current value of the portfolio. Generally, it is calculated as
			  * LastTradedPrice x Quantity. */
			FIELD_SET(TotalMarketPrice)
			/** Set the Gain/Loss in percentage. Usually, it is calculated as
			  * (TotalMarketPrice - TotalPaidPrice) x 100 / TotalPaidPrice. */
			FIELD_SET(GainLossPercent)
			/** Set the Gain/Loss in value for the portfolio. Usually, it is calculated as
			  * TotalMarketPrice - TotalPaidPrice. */
			FIELD_SET(GainLossValue)
			FIELD_SET(BasisPNL)
			FIELD_SET(BasisPNLPercent)
			FIELD_SET(TodayPNL)
			FIELD_SET(TodayPNLPercent)
			FIELD_SET(TotalPNL)
			FIELD_SET(TotalPNLPercent)
			/** Set the last traded price for the Symbol. */
			FIELD_SET(LastPrice)
			/** Set the last traded time for the Symbol. */
			FIELD_SET(QuoteTime)
			/** Set the Gain/Loss percentage for the day. Not a mandatory parameter. */
			FIELD_SET(DayGainLossPercent)
			/** Set the Gain/Loss in value for the day. Not a mandatory parameter. */
			FIELD_SET(DayGainLossValue)
			/** Set the updated time. Not a mandatory paramenter. */
			FIELD_SET(UpdatedTime)
			/** Set the closing price for the last trading session for the Symbol. */
			FIELD_SET(PreviousClose)
			/** Set the company name or the description for the Symbol. */
			FIELD_SET(CompanyName)
			/** Set the desctiontion or the long name for the option symbol. Used only for Options. */
			FIELD_SET(OptionDescription)
			/** Set the multiplier/lot size for the Symbol. */
			FIELD_SET(OptionMultiplier)
			/** Set the Option type for the Symbol. Not a mandatory parameter. */
			FIELD_SET(PutOrCall)
			/** Set the Strike Price for the Symbol. Not a mandatory parameter. */
			FIELD_SET(StrikePrice)
			/** Set the Expiry for the option symbol. Not a mandatory parameter. To be used only if the Symbol is an Option Symbol. */
			FIELD_SET(Expiry)
			/** Set the expiry date, if the broker/exchange provides one. */
                        FIELD_SET(ExpiryDate)
			/** Set the delivery type. Not a mandatory parameter. */
			FIELD_SET(DeliveryType)
			/** Set the due date. This is used generally for margin positions, which have a due date. Not a mandatory parameter. */
			FIELD_SET(DueDate)
			/** Set FX. Specific to KimEng. */
			FIELD_SET(FX)
			/** Set BSE Scrip Code -- specific to IIFL for now. **/
			FIELD_SET(BSEScripCode)
			/** Set NSE Scrip Code -- specific to IIFL for now. **/
			FIELD_SET(NSEScripCode)
			FIELD_SET(InstrumentType)
			FIELD_SET(RealizedGL);
			FIELD_SET(IsMultiLeg);
			FIELD_SET(StrategyType);
			FIELD_SET(GroupID);
			FIELD_SET(TickSize);
			FIELD_SET(YearHigh);
			FIELD_SET(YearLow);
			FIELD_SET(MarketLot)

			/** Set Booked Profit/Loss -- specific to IIFL for now. **/
			FIELD_SET(BookedPL);
			/** Set MTOM Profit/Loss -- specific to IIFL for now. **/
			FIELD_SET(MTOMPL);
			FIELD_SET(GrossPL);
			FIELD_SET(PL);
			FIELD_SET(Roll);
			FIELD_SET(PositionTag);
			/** Set MarketExchange. specific to Kotak. **/
			FIELD_SET(MarketExchange);
			/** Set Squareoff flag. specific to Kotak. **/
			FIELD_SET(SquareoffFlag);
			
			/** Get Product Type. */
			FIELD_GET(ProductType)
			FIELD_GET(Exchange)
			FIELD_GET(PortfolioAssetType)
			FIELD_GET(TickSize);
			/** Get Portfolio ID. */
			FIELD_GET(PortfolioID)
			FIELD_GET(TradingSymbol)
			/** Get the symbol/stock/security of the portfolio. */
			FIELD_GET(Symbol)
			/** Get the quantity or the lot size. */
			FIELD_GET(Quantity)
			FIELD_GET(MarketLot)
			/** Get the balance quantity or the no of lots (in case of derivatives). specif to Kotak */
			FIELD_GET(BalanceQunatity)
			FIELD_GET(BuyAveragePrice)
			FIELD_GET(SellAveragePrice)
			/** Get the open buy quantity or the no of lots (in case of derivatives). specif to Kotak */
			FIELD_GET(OpenBuyQuantity)
			/** Get the open sell quantity or the no of lots (in case of derivatives). specif to Kotak */
			FIELD_GET(OpenSellQuantity)
			/** Get the traded net quantity or the no of lots (in case of derivatives). specif to Kotak */
			FIELD_GET(TradedNetQuantity)
			/** Get the Side for the portfolio. Valid values are 'B' for BUY and 'S' for Sell. */
			FIELD_GET(TransactionType)
			/** Get the time at which the portfolio was created or the time when the trade got executed and
			  * it became a part of the holdings. */
			FIELD_GET(PortfolioTime)
			FIELD_GET(Comments)
			FIELD_GET(Underlying)
			FIELD_GET(AliasName)
			FIELD_GET(Currency)
			/** Get the total market price. */
			FIELD_GET(TotalMarketPrice)
			/** Get the total paid price. */
			FIELD_GET(TotalPaidPrice)
			/** Get the cost basis or the paid price per quantity. */
			FIELD_GET(PaidPrice)
			FIELD_GET(GainLossPercent)
			/** Get the gain/loss in value. */
			FIELD_GET(GainLossValue)
			FIELD_GET(BasisPNL)
			FIELD_GET(BasisPNLPercent)
			FIELD_GET(TodayPNL)
			FIELD_GET(TodayPNLPercent)
			FIELD_GET(TotalPNL)
			FIELD_GET(TotalPNLPercent)
			FIELD_GET(LastPrice)
			FIELD_GET(QuoteTime)
			FIELD_GET(DayGainLossPercent)
			FIELD_GET(DayGainLossValue)
			FIELD_GET(UpdatedTime)
			FIELD_GET(PreviousClose)
			FIELD_GET(CompanyName)
			FIELD_GET(OptionDescription)
			FIELD_GET(OptionMultiplier)
			FIELD_GET(PutOrCall)
			FIELD_GET(StrikePrice)
			FIELD_GET(Expiry)
			FIELD_GET(DeliveryType)
			/** Get the due date for the portfolio. */
			FIELD_GET(DueDate)
			/** Get FX. Specific to KimEng. */
			FIELD_GET(FX)
			FIELD_GET(BSEScripCode)
			FIELD_GET(NSEScripCode)
			FIELD_GET(InstrumentType)
			FIELD_GET(RealizedGL);
			FIELD_GET(IsMultiLeg);
			FIELD_GET(StrategyType);
			FIELD_GET(GroupID);

			/** Get Booked profit/loss -- iifl. */
			FIELD_GET(BookedPL);
			/** Get MTOM profit/loss -- iifl. */
			FIELD_GET(MTOMPL);
			FIELD_GET(GrossPL);
			FIELD_GET(PL);
			FIELD_GET(Roll);
			FIELD_GET(PositionTag);
			FIELD_GET(MarketExchange);
			FIELD_GET(SquareoffFlag);
			const static char entry_delimiter;

			string getDataField( string mName );
			void setOtherParams(string sName, string sValue);
		private:
			map<string, string>fieldMap;

	};

	// For using this New Portfolio 
	// if ( isGainToBeCalculated ) set Last, Paid , Close to calculate GL, GL % and DGL and DGL %
	//Donot change name for "LAST" , "CLOSE" , "PAIDPRICE" , "QUANTITY" , "MULTIPLIER", "TOTALMARKETPRICE", "TOTALPAIDPRICE", "GAINLOSSVALUE"
	class NewPortfolio :
		public IFHelper
	{
		public:
			NewPortfolio();
			~NewPortfolio();

			void addValue( string mName, string mValue );
			void setGainCalculationFlag( bool mFlag );
			void toString( string & response , CSVRow cCSVRow , int iID );
			string getValue( string mName );
		private:
			string convertToString( double mVal );
			void setID( int iID );
			void calculateGainAndGainPercentage();

			bool isGainToBeCalculated;
			map < string, string > nameValues;
	};

	class NewBrokerPortfolioRequest : 
		public string
	{
		public:
			NewBrokerPortfolioRequest(string data);
			~NewBrokerPortfolioRequest();

			/** Returns the account id for which the portfolio data was requested.
			  * In certain cases, this could be the userid as well. Usually, this expects the same input
			  * as returned in the AccountID field for the login response. */
			string getAccountID();
			/** Returns the request type. This is implementation specific and does not have any pre-defined
			  * values. It can be 'outstanding_positions', 'todays_positions', 'current_portfolio', 'paper_portfolio' etc. */
			string getRequestType();
			/** Returns the exchange. This is implementation specific. For example: for KimEng, this can be SGX, HKG, KLSE, NMS etc.
			  * Usually used, when the broker api support multiple exchanges. */
			string getExchange();
			/** Returns the value for the key. */
			string getParam(string sKey);
			string toString();

		private:

			void handleOtherParams(string sName, string sValue);
			string accountID, sRequestType, sExchange;
			void parse(string data);
			map<string, string>otherParams;
	};

	class BrokerPortfolioRequest : public string
	{
		public:
			BrokerPortfolioRequest(string data);
			~BrokerPortfolioRequest();

			/** Returns the account id for which the portfolio data was requested.
			  * In certain cases, this could be the userid as well. Usually, this expects the same input
			  * as returned in the AccountID field for the login response. */
			string getAccountID();
			/** Returns the request type. This is implementation specific and does not have any pre-defined
			  * values. It can be 'outstanding_positions', 'todays_positions', 'current_portfolio', 'paper_portfolio' etc. */
			string getRequestType();
			/** Returns the exchange. This is implementation specific. For example: for KimEng, this can be SGX, HKG, KLSE, NMS etc.
			  * Usually used, when the broker api support multiple exchanges. */
			string getExchange();
			/** Returns the value for the key. */
			string getParam(string sKey);
			string toString();

		private:

			void handleOtherParams(string sName, string sValue);
			string accountID, sRequestType, sExchange;
			void parse(string data);
			map<string, string>otherParams;
	};

	class BrokerPortfolioResponse :
		public vector<Portfolio>
	{
		public:
			BrokerPortfolioResponse();
			~BrokerPortfolioResponse();

			/** Add a portfolio entry 'mPortfoio'. */
			void addPortfolioEntry(Portfolio mPortfolio);
			/** Generate the string representing the packet. */
			void toString( string & response );
			/** Generate the string representing the packet. in csv format */
			void toStringInCSVFormat( CSVRow headers , string & response );

			/** DO NOT use this. */
			string getNetPaidValue();
			/** DO NOT use this. */
			string getNetMarketValue();
			/** DO NOT use this. */
			string getNetGainValue();
			/** DO NOT use this. */
			string getNetGainValuePer();

		private:
			/** DO NOT use this. */
			string netPaidValue, netMarketValue, netGainValue, netGainValuePer;
	};

	class NewBrokerPortfolioResponse :
		public vector<NewPortfolio>
	{
		public:
			NewBrokerPortfolioResponse();
			~NewBrokerPortfolioResponse();
			
			/** Add a portfolio entry 'mPortfoio'. */
			void addPortfolioEntry(NewPortfolio mPortfolio);
			/** Generate the string representing the packet. */
			void toString( CSVRow headers , string & response );

			/** DO NOT use this. */
			string getNetPaidValue();
			/** DO NOT use this. */
			string getNetMarketValue();
			/** DO NOT use this. */
			string getNetGainValue();
			/** DO NOT use this. */
			string getNetGainValuePer();

		private:
			/** DO NOT use this. */
			string netPaidValue, netMarketValue, netGainValue, netGainValuePer;
	};

	class OPXDragonRequestParam {
		public:
			OPXDragonRequestParam(string data);
			~OPXDragonRequestParam();
	};

	class OPXDragonResponseParam {
		public:
			OPXDragonResponseParam();
			~OPXDragonResponseParam();

			void addParam(string param);
			void toString(string & response);
		private:
			vector<string>parameters;
	};

	class OPXDragonRequestValue {
		public:
			OPXDragonRequestValue(string data);
			~OPXDragonRequestValue();

			string getPageID() { return dragonParam; };
			void parse(string data);
			string dragonParam;
	};

	class OPXDragonResponseValue {
		public:
			OPXDragonResponseValue();
			~OPXDragonResponseValue();

			void toString(string & response, vector<string>keyOrder);
			void addDetail(string xmlKey, string name, string value);
			void validate();

		private:
			map<string, string>xmlKeyPair;
			map<string, vector<string> >dragonDetails;
			string dragonParam;
	};

	//Request for Summary of Broker Positions
	//Will be in the same foramt like that of Balances Request
	class BrokerPositionSummaryRequest : public BrokerBalancesRequest {
		public:
			BrokerPositionSummaryRequest(string data);
			~BrokerPositionSummaryRequest();
	};

	//Summary of Broker Positions
	//Will be in the same foramt like that of Balances
	class BrokerPositionSummaryResponse : public BrokerBalancesResponse {
		public:
			BrokerPositionSummaryResponse();
			~BrokerPositionSummaryResponse();
	};

	//Request for Gainers Losers Volume data
	class GainerLoserVolumeRequest :
		public IFHelper,
		public string
	{
		public:
			GainerLoserVolumeRequest(string request);
			//Filter for Exchange in Gainers Losers Volume data
			string getExchange();
			//Filter for Country Code in Gainers Losers Volume data
			string getCountryCode();
			//provides Gainers Losers Volume data request type
			string getRequestType();
			//Get Symbol
			string getSymbol();
			string getParam(string sKey);
			string toString();

		private:
			void parse(string request);
			void setOtherParam(string sName, string sValue);

			map<string, string>otherParams;
			string sRequestType, sExchange, sCountryCode, sSymbol;
	};

	//Gainers Losers Volume data
	//provided as a CSV Data Response
	class GainerLoserVolumeResponse : public CSVData
	{
		public:
			GainerLoserVolumeResponse();
			~GainerLoserVolumeResponse();

			void toString( string & response );
	};

	//Switch account currently only used with OPX Broker only
	//specific to OPX only
	class BrokerSwitchAccountRequest {
		public:
			BrokerSwitchAccountRequest(string sRequest);
			//provides the broker session id for which switch account has to happen
			string getSessionID();
			//provides the account id from which switching has to happen
			string getAccountID();
			//provides the account number to which switching has to happen
			string getAccountNumber();
			//provides the Username that is the broker specific account details
			string getUsername();
			//provides the Password that is the broker specific account details
			string getPassword();

		private:
			void parse(string sRequest);
			void setNameValue(string sName, string sValue);

			string sSessionID, sUsername, sPassword, sAccountID, sAccountNumber;
	};

	//Switch Account response
	class BrokerSwitchAccountResponse :
		public map<string, string>
	{
		public:
			BrokerSwitchAccountResponse();
			//Add the details specific to account switching as name and values
			void addField(string sName, string sValue);
			//Provides the name value pair as a string appending with response
			void toString(string & sResponse);

			// Temporary fix for OPX
			void setSession(string m_session);
			void setSuccess(string m_success);
		private:
			string sSession, sSuccess;
			
	};

	//Portfolio Set Request
	class BrokerSetPortfolioRequest :
		public CSVData
	{
		public:
			BrokerSetPortfolioRequest(string sRequest);
			~BrokerSetPortfolioRequest();
	};

	//Portfolio Set Response
	class BrokerSetPortfolioResponse
	{
		public:
			BrokerSetPortfolioResponse();
			~BrokerSetPortfolioResponse();

			void setFlag( bool mFlag );
			void setCustomMessage( string mCustomMessage );
			void toString(string & sResponse);
		private:
			bool flag;
			string customMessage;
	};

	//Set Global Market Values
	class GlobalMarkets
	{
		public:
			GlobalMarkets();
			GlobalMarkets(string sResponse);
			~GlobalMarkets();
			
			void setDate(string sDate);
			void setIndex(string sIndex);
			void setIndexName(string sIndexName);
			void setCountryCode(string sCountryCode);
			void setLast(string slast);
			void setChange(string sChange);
			void setChangePercent(string sChangePercent);

/*			string getDate();
			string getIndex();
			string getIndexName();
			string getCountryCode();
			string getLast();
			string getChange();
			string getChangePercent(); */

			void toString(string & sResponse);

		private:
			void parse(string sResponse);
			string date, last, index, indexName, countryCode, change, changePercent;
	};

	//Global Markets Request
	class GlobalMarketsRequest
	{
		public:
			GlobalMarketsRequest();
			GlobalMarketsRequest(string sData);
			~GlobalMarketsRequest();

			string getType();

		private:
			void parse(string sData);
			string type;
	};

	//Global Markets Response
	class GlobalMarketsResponse :
		public vector<GlobalMarkets>	
	{
		public:
			GlobalMarketsResponse();
//			GlobalMarketsResponse(string sResponse);
			~GlobalMarketsResponse();

			void setType(string sType);
			void toString(string & sResponse);
			void addEntry(GlobalMarkets entry);
		private:
			string type;
	};

	class BrokerResearchRequest:
		public string,
		public map <string,string>
	{
		public:
			BrokerResearchRequest(string request);
			~BrokerResearchRequest();
			string getSymbol();
			string getType();
			string getParam(string Key);
			string toString();

		private:
			void addKeyValue(string key,string value);
			void parse(string request);
	};

	class BrokerResearchResponse
	{
		
		public:	
			BrokerResearchResponse();
			~BrokerResearchResponse();
			
			string toString();
			void toString(string &response);	
			void toString(string &response,vector<string> headers);
			void toString(string &response, vector<string> headerOrder, map< string, vector<string> > fieldOrder);
			bool getStatus();
			string getErrorMessage();
			string map_to_string(map<string,string> key_values);
			string map_to_string();
			string error_message;
			void setErrorMessage(string msg);
			void addHeaderValue(string header, multimap<string, string> key_values, bool replace);
			void addHeaderValue(string header, multimap<string, string> key_values);
//			void addHeaderValue(string header, map<string, string> key_values);
			void addHeaderValue(string header, string key, string value);
			void addLabel(string header, string key, string label);
			void addLabel(string header, map<string,string> newLabels);

		private:
			
			bool status;
			void setStatus(bool b_status);
			vector <string> headers;
			string getLabel(string header, string key);

			map <string, string> labelsMap;// stores labels for each key against each header.
			map <string, multimap<string,string> > header_values_map;
	};
};

using namespace UBACData;

#endif /* __UBAC_DATA_H__ */
