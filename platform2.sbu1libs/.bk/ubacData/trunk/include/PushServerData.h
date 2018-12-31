#ifndef __PUSH_SERVER_DATA_H__
#define __PUSH_SERVER_DATA_H__

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
//#define typeof(x)	__typeof(x)
#else
#include <stdint.h>
#endif

#include <string.h>
#include <stdlib.h>

//#include <ubacyajl/UBACJson.h>
#include <jsonparser/JsonParser.h>
#include <ubacutils/IFHelper.h>
#include "ExtMod.h"

using namespace std;

#define DEFINE_FIELD(name, field, type)							\
	class name :									\
		public std::string							\
	{										\
		public:									\
			name() : m_field( field ) {}					\
			name(std::string tmp##name) : m_field( field ) {		\
				this->append( tmp##name );				\
			}								\
			/** `m_field' stores the value of the field. */ 		\
			type m_field;							\
	};

/*std::map<typeof(field.m_field), std::string>::iterator i = this->fieldMap.find(field.m_field);          \*/

#define FIELD_SET(type)													\
	void setField(const type field)											\
	{														\
		std::map<std::string, std::string>::iterator i = this->fieldMap.find(field.m_field);          \
		if(i != this->fieldMap.end()) {						                                \
			fieldMap.erase(i);						                                \
			std::map<std::string, std::string>::iterator iter;	                                \
			this->clear();						                                	\
			for( iter=fieldMap.begin(); iter!=fieldMap.end(); iter++ ) {	                                \
				stringstream reform;					                                \
				if( this->length() > 0 )				                                \
					this->append(&this->entry_delimiter, 1);	                                \
				reform << iter->first << "=" << iter->second;		                                \
				this->append(reform.str());				                                \
			}								                                \
		}									                                \
		stringstream out;							                                \
		if( this->length() > 0 )						                                \
			this->append(&this->entry_delimiter, 1);			                                \
		out << field.m_field << "=" << field;					                                \
		(*this).append(out.str());						                                \
		fieldMap.insert( make_pair(field.m_field, field) );			                                \
	}

/*std::map<typeof(field.m_field), std::string>::iterator i = this->fieldMap.find(field.m_field);		*/

#define FIELD_GET(type)													\
	void getField(type & field)											\
	{														\
		std::map<std::string, std::string>::iterator i = this->fieldMap.find(field.m_field);		\
		if(i != this->fieldMap.end()) {										\
			field.append(i->second);									\
		}													\
	}


namespace PushServerData {

	const static int Protocol_SUBSCRIPTION_REQUEST = 410;
	const static int Protocol_UNSUBSCRIPTION_REQUEST = 414;

	const static string PushServerDataType_Symbol = "symbol";
	const static string PushServerDataType_AskPrice = "ask_price";
	const static string PushServerDataType_BidPrice = "bid_price";
	const static string PushServerDataType_LastPrice = "last_price";
	const static string PushServerDataType_OpenPrice = "open_price";
	const static string PushServerDataType_DayHigh = "day_high";
	const static string PushServerDataType_DayLow = "day_low";
	const static string PushServerDataType_AskSize = "ask_size";
	const static string PushServerDataType_BidSize = "bid_size";
	const static string PushServerDataType_Close = "prev_close";
	const static string PushServerDataType_TotalVolume = "total_volume";
	const static string PushServerDataType_LastVolume = "last_volume";
	const static string PushServerDataType_OpenInterest = "open_interest";
	const static string PushServerDataType_StrikePrice = "strike_price";
	const static string PushServerDataType_Exchange = "exchange";
	const static string PushServerDataType_YearHigh = "year_high";
	const static string PushServerDataType_LastTradedTime = "date";
	const static string PushServerDataType_YearLow = "year_low";
	const static string PushServerDataType_Name = "name";
	const static string PushServerDataType_ExpiryDate = "expiry_date";
	const static string PushServerDataType_Underlying = "underlying";
	const static string PushServerDataType_OptionIndicator = "option_indicator";
	const static string PushServerDataType_ItemGUID = "item_guid";
	const static string PushServerDataType_Text = "text";
	const static string PushServerDataType_Source = "source";
	const static string PushServerDataType_URL = "url";
	const static string PushServerDataType_Title = "title";
	const static string PushServerDataType_OrderQuantity = "order_quantity";
	const static string PushServerDataType_OrderAction = "order_action";
	const static string PushServerDataType_OrderType = "order_type";
	const static string PushServerDataType_OrderStatus = "order_status";
	const static string PushServerDataType_LimitPrice = "limit_price";
	const static string PushServerDataType_ActionPrice = "action_price";
	const static string PushServerDataType_TimeInForce = "time_force";
	const static string PushServerDataType_BackendType = "backend_type";
	const static string PushServerDataType_BackendSource = "backend_source";
	const static string PushServerDataType_ACL = "acl";
	const static string PushServerDataType_MessageType = "MT";
	const static string PushServerDataType_Precision = "precision";
	const static string PushServerDataType_Pip = "pip";
	const static string PushServerDataType_StopDistance = "stop_distance";
	const static string PushServerDataType_LimitDistance = "limit_distance";
	/// Class (type) Symbol.
	DEFINE_FIELD(Symbol, PushServerDataType_Symbol, string)
	/// Class (type) AskPrice.
	DEFINE_FIELD(AskPrice, PushServerDataType_AskPrice, string)
	/// Class (type) BidPrice.
	DEFINE_FIELD(BidPrice, PushServerDataType_BidPrice, string)
	/// Class (type) LastPrice.
	DEFINE_FIELD(LastPrice, PushServerDataType_LastPrice,string)
	/// Class (type) OpenPrice.
	DEFINE_FIELD(OpenPrice, PushServerDataType_OpenPrice, string)
	/// Class (type) DayHigh.
	DEFINE_FIELD(DayHigh, PushServerDataType_DayHigh, string)
	/// Class (type) DayLow.
	DEFINE_FIELD(DayLow, PushServerDataType_DayLow, string)
	/// Class (type) AskSize.
	DEFINE_FIELD(AskSize, PushServerDataType_AskSize, string)
	/// Class (type) BidSize.
	DEFINE_FIELD(BidSize, PushServerDataType_BidSize, string)
	/// Class (type) Close.
	DEFINE_FIELD(Close, PushServerDataType_Close, string)
	/// Class (type) LastTradedTime.
	DEFINE_FIELD(LastTradedTime, PushServerDataType_LastTradedTime, string)
	/// Class (type) TotalVolume.
	DEFINE_FIELD(TotalVolume, PushServerDataType_TotalVolume, string)
	/// Class (type) LastVolume.
	DEFINE_FIELD(LastVolume, PushServerDataType_LastVolume, string)
	/// Class (type) OpenInterest.
	DEFINE_FIELD(OpenInterest, PushServerDataType_OpenInterest, string)
	/// Class (type) StrikePrice.
	DEFINE_FIELD(StrikePrice, PushServerDataType_StrikePrice, string)
	/// Class (type) Exchange.
	DEFINE_FIELD(Exchange, PushServerDataType_Exchange, string)
	/// Class (type) YearHigh.
	DEFINE_FIELD(YearHigh, PushServerDataType_YearHigh, string)
	/// Class (type) YearLow.
	DEFINE_FIELD(YearLow, PushServerDataType_YearLow, string)
	/// Class (type) Name.
	DEFINE_FIELD(Name, PushServerDataType_Name, string)
	/// Class (type) ExpiryDate.
	DEFINE_FIELD(ExpiryDate, PushServerDataType_ExpiryDate, string)
	/// Class (type) Underlying.
	DEFINE_FIELD(Underlying, PushServerDataType_Underlying, string)
	/// Class (type) OptionIndicator.
	DEFINE_FIELD(OptionIndicator, PushServerDataType_OptionIndicator, string)
	/// Class (type) ItemGUID.
	DEFINE_FIELD(ItemGUID, PushServerDataType_ItemGUID,string)
	/// Class (type) Text.
	DEFINE_FIELD(Text, PushServerDataType_Text, string)
	/// Class (type) Source.
	DEFINE_FIELD(Source, PushServerDataType_Source, string)
	/// Class (type) URL.
	DEFINE_FIELD(URL, PushServerDataType_URL, string)
	/// Class (type) Title.
	DEFINE_FIELD(Title, PushServerDataType_Title,string)
	/// Class (type) BackendType.
	DEFINE_FIELD(BackendType, PushServerDataType_BackendType, string)
	/// Class (type) BackendSource.
	DEFINE_FIELD(BackendSource, PushServerDataType_BackendSource, string)
	/// Class (type) ACL.
	DEFINE_FIELD(ACL, PushServerDataType_ACL, string)
	/// Class (type) MessageType.
	DEFINE_FIELD(MessageType, PushServerDataType_MessageType, string)
	/// Class (type) Precision
	DEFINE_FIELD(Precision, PushServerDataType_Precision, string)
	/// Class (type) Pip
	DEFINE_FIELD(Pip, PushServerDataType_Pip, string)
	/// Class (type) StopDistance
	DEFINE_FIELD(StopDistance, PushServerDataType_StopDistance, string)
	/// Class (type) LimitDistance
	DEFINE_FIELD(LimitDistance, PushServerDataType_LimitDistance, string)

	/// Message type for registration of the source.
	const static uint16_t MessageType_REGISTATION = 0;
	/// Message type for the Level1 quote request.
	const static uint16_t MessageType_LEVEL1 = 1;
	/// Message type for the Level2 quote request.
	const static uint16_t MessageType_LEVEL2 = 2;
	/// Message type for the time and sales request.
	const static uint16_t MessageType_TIME_AND_SALES = 3;
	/// Message type for account activity.
	const static uint16_t MessageType_ACCOUNT_ACTIVITY = 4;
	/// Message type for news request/
	const static uint16_t MessageType_NEWS = 5;

	/// Class PushServerRequest.
	class PushServerRequest {
		public:
			// hanlde the json type request..
			PushServerRequest(JsonObject jRequest );
			/// Create PushServerRequest by passing the request string `sResponse'.
			PushServerRequest(string sRequest);
			/** Returns the list of symbols to be subscribed. */
			vector<string> getSymbolList();
			/// Get request type.
			uint16_t getRequestType();
			/// Get request type in string.
			string getRequesttype();
			/** Get Response format. UBAC, JSON. */
			string getResponseFormat();

			ExtMod *extMod;
			uint16_t code;
		private:
			void parse(string sRequest);
			void handleJsonRequest(JsonObject jRequest);

			void handleState(string sName, string sValue);
			vector<string>symbolList;
			uint16_t u16RequestType;
			string sResponseFormat, sRequestType;
	};

	/// Class Message. Generic message for the response.
	class Message :
		public string
	{
		public:
			/// Create message object by passing the actual message 'data'. Used to parse a PushServer message.
			Message(string data);
			/// Create message object with message type. Used to frame a PushServer message.
			Message(uint16_t m_messageType);
			virtual ~Message() {};

			/// fieldMap to store name/value pairs.
			map<string, string>fieldMap;

			FIELD_SET(MessageType)
			FIELD_GET(MessageType)
			
			const static char entry_delimiter;

			/// Message object to string.
			void toString(string & sResponse);

		private:
			void parse(string data);
	};

	class Registration :
		public Message
	{
		public:
			Registration() : Message(MessageType_REGISTATION) {}
			virtual ~Registration() {};
			
			/** Set the data provider backend type. */
			FIELD_SET(BackendType)
			/** Set the data backend source. */
			FIELD_SET(BackendSource)
			/** Set the ACL. For example: 'broker_session'. */
			FIELD_SET(ACL)
			
			/** Get the data backend type. */
			FIELD_GET(BackendType)
			/** Get the backend source information. */
			FIELD_GET(BackendSource)
			/** Get the ACL information. */
			FIELD_GET(ACL)
	};

	class Level1 : 
		public Message
	{
		public:
			Level1() : Message(MessageType_LEVEL1) {}
			Level1( string mLevel1Data ) : Message( mLevel1Data ) {}
			virtual ~Level1() {};

			/** Set last traded time. 
			  * The time should be in the format %Y/%m/%d %H:%M:%S. */
			FIELD_SET(LastTradedTime)
			/** Set the Symbol for the Level 1 data. */
			FIELD_SET(Symbol)
			/** Set the best ask price. */
			FIELD_SET(AskPrice)
			/** Set the best bid price. */
			FIELD_SET(BidPrice)
			/** Set the last traded price. */
			FIELD_SET(LastPrice)
			/** Set the day's open price. */
			FIELD_SET(OpenPrice)
			/** Set the day's high price. */
			FIELD_SET(DayHigh)
			/** Set the day's low price. */
			FIELD_SET(DayLow)
			/** Set the total ask quantity for the best ask price. */
			FIELD_SET(AskSize)
			/** Set the total bid quantity for the best bid price. */
			FIELD_SET(BidSize)
			/** Set closing price for the previous trading session. */
			FIELD_SET(Close)
			/** Set the total traded volume for the day. */
			FIELD_SET(TotalVolume)
			/** Set the last traded volume. */
			FIELD_SET(LastVolume)
			/** Set the open interest for the option. */
			FIELD_SET(OpenInterest)
			/** Set the strike price for the Symbol, if it is an Option. */
			FIELD_SET(StrikePrice)
			/** Set the market exchange, where the Level 1 data originated. */
			FIELD_SET(Exchange)
			/** Set the 52-week high price. */
			FIELD_SET(YearHigh)
			/** Set the 52-week low price. */
			FIELD_SET(YearLow)
			/** Set the name or description for the Symbol. Usually the 
			  * company name or the full description of the derivative. */
			FIELD_SET(Name)
			/** Set the expiry date if the Symbol is a derivative. */
			FIELD_SET(ExpiryDate)
			/** Set the underlying symbol, if 'Symbol' is a derivative. */
			FIELD_SET(Underlying)
			/** Set the option indicator. */
			FIELD_SET(OptionIndicator)
			/** Set Precision. */
			FIELD_SET(Precision)
			/** Set PIP. */
			FIELD_SET(Pip)
			/** Set StopDistance. */
			FIELD_SET(StopDistance)
			/** Set LimitDistance. */
			FIELD_SET(LimitDistance)

			/** Get Symbol from the Level 1 packet. */
			FIELD_GET(Symbol)
			/** Get the best ask price from the Level 1 packet. */
			FIELD_GET(AskPrice)
			/** Get the best bid price from the Level 1 packet. */
			FIELD_GET(BidPrice)
			/** Get the last traded price from the Level 1 packet. */
			FIELD_GET(LastPrice)
			/** Get the day's open price from the Level 1 packet. */
			FIELD_GET(OpenPrice)
			/** Get the day's high price from the Level 1 packet. */
			FIELD_GET(DayHigh)
			/** Get the day's low price from the Level 1 packet. */
			FIELD_GET(DayLow)
			/** Get the total ask quantity for the best ask price. */
			FIELD_GET(AskSize)
			/** Get the total bid quantity for the best bid price. */
			FIELD_GET(BidSize)
			/** Get the closing price for the previous trading session. */
			FIELD_GET(Close)
			/** Get the total traded volume for the day. */
			FIELD_GET(TotalVolume)
			/** Get the last trade volume. */
			FIELD_GET(LastVolume)
			/** Get open interest. */
			FIELD_GET(OpenInterest)
			/** Get strike price. */
			FIELD_GET(StrikePrice)
			/** Get exchange. */
			FIELD_GET(Exchange)
			/** Get 52-week high price. */
			FIELD_GET(YearHigh)
			/** Get 52-week low price. */
			FIELD_GET(YearLow)
			/** Get the company name or full description of the symbol. */
			FIELD_GET(Name)
			/** Get the expiry date for the derivative. */
			FIELD_GET(ExpiryDate)
			/** Get the underlying symbol. */
			FIELD_GET(Underlying)
			FIELD_GET(OptionIndicator)
			/** Get the last traded time. */
			FIELD_GET(LastTradedTime)
	};
	
	class Level2 : 
		public Message
	{
		public:
			Level2() : Message(MessageType_LEVEL2) {}
			virtual ~Level2() {};

			/** Set last traded time.
			  * The time should be in the format %Y/%m/%d %H:%M:%S. */
			FIELD_SET(LastTradedTime)
			/** Set the Symbol for the Level 1 data. */
			FIELD_SET(Symbol)
			/** Set the best ask price. */
			FIELD_SET(AskPrice)
			/** Set the best bid price. */
			FIELD_SET(BidPrice)
			/** Set the total ask quantity for the best ask price. */
			FIELD_SET(AskSize)
			/** Set the total bid quantity for the best bid price. */
			FIELD_SET(BidSize)
			/** Set the open interest for the option. */
			FIELD_SET(OpenInterest)
			/** Set the strike price for the Symbol, if it is an Option. */
			FIELD_SET(StrikePrice)
			/** Set the market exchange, where the Level 1 data originated. */
			FIELD_SET(Exchange)
			/** Set the name or description for the Symbol. Usually the
			  * company name or the full description of the derivative. */
			FIELD_SET(Name)
			/** Set the expiry date if the Symbol is a derivative. */
			FIELD_SET(ExpiryDate)
			/** Set the underlying symbol, if 'Symbol' is a derivative. */
			FIELD_SET(Underlying)
			/** Set the option indicator. */
			FIELD_SET(OptionIndicator)

			/** Get Symbol from the Level 1 packet. */
			FIELD_GET(Symbol)
			/** Get the best ask price from the Level 1 packet. */
			FIELD_GET(AskPrice)
			/** Get the best bid price from the Level 1 packet. */
			FIELD_GET(BidPrice)
			/** Get the total ask quantity for the best ask price. */
			FIELD_GET(AskSize)
			/** Get the total bid quantity for the best bid price. */
			FIELD_GET(BidSize)
			/** Get open interest. */
			FIELD_GET(OpenInterest)
			/** Get strike price. */
			FIELD_GET(StrikePrice)
			/** Get exchange. */
			FIELD_GET(Exchange)
			/** Get the company name or full description of the symbol. */
			FIELD_GET(Name)
			/** Get the expiry date for the derivative. */
			FIELD_GET(ExpiryDate)
			/** Get the underlying symbol. */
			FIELD_GET(Underlying)
			FIELD_GET(OptionIndicator)
			/** Get the last traded time. */
			FIELD_GET(LastTradedTime)
	};
	
	class TimeAndSales : 
		public Message
	{
		public:
			TimeAndSales() : Message(MessageType_TIME_AND_SALES) {}
			virtual ~TimeAndSales() {};

			/** Set the Symbol for the Level 1 data. */
			FIELD_SET(Symbol)
			/** Set the last traded price. */
			FIELD_SET(LastPrice)
			/** Set the last traded volume. */
			FIELD_SET(LastVolume)
			/** Set the open interest for the option. */
			FIELD_SET(OpenInterest)
			/** Set the strike price for the Symbol, if it is an Option. */
			FIELD_SET(StrikePrice)
			/** Set the market exchange, where the Level 1 data originated. */
			FIELD_SET(Exchange)
			/** Set the name or description for the Symbol. Usually the
			  * company name or the full description of the derivative. */
			FIELD_SET(Name)
			/** Set the expiry date if the Symbol is a derivative. */
			FIELD_SET(ExpiryDate)
			/** Set the underlying symbol, if 'Symbol' is a derivative. */
			FIELD_SET(Underlying)
			/** Set the option indicator. */
			FIELD_SET(OptionIndicator)
			/** Set last traded time.
			  * The time should be in the format %Y/%m/%d %H:%M:%S. */
			FIELD_SET(LastTradedTime)

			/** Get the last traded time. */
			FIELD_GET(LastTradedTime)
			/** Get Symbol from the  packet. */
			FIELD_GET(Symbol)
			/** Get the last traded price from the packet. */
			FIELD_GET(LastPrice)
			/** Get the last traded volume from the packet. */
			FIELD_GET(LastVolume)
			/** Get the open interest. */
			FIELD_GET(OpenInterest)
			/** Get Strike price. */
			FIELD_GET(StrikePrice)
			/** Get exchange information. */
			FIELD_GET(Exchange)
			/** Get the company name or the long description of the symbol. */
			FIELD_GET(Name)
			/** Get the expiry date for the derivative. */
			FIELD_GET(ExpiryDate)
			/** Get the underlying symbol. */
			FIELD_GET(Underlying)
			FIELD_GET(OptionIndicator)
	};
	
	class News :
		public Message
	{
		public:
			News() : Message(MessageType_NEWS) {}
			virtual ~News() {};
			
			/** Set the symbol information for the NEWS item. */
			FIELD_SET(Symbol)
			/** Get the GUID ID for the NEWS item. */
			FIELD_SET(ItemGUID)
			/** Set the news text. */
			FIELD_SET(Text)
			/** Set the source, from where this NEWS item was retrieved. */
			FIELD_SET(Source)
			/** Set the URL where the detailed NEWS is available. */
			FIELD_SET(URL)
			/** Set the headlines for the NEWS item. */
			FIELD_SET(Title)
			
			FIELD_GET(Symbol)
			FIELD_GET(ItemGUID)
			FIELD_GET(Text)
			FIELD_GET(Source)
			FIELD_GET(URL)
			FIELD_GET(Title)
	};

};

using namespace PushServerData;

#endif /* __PUSH_SERVER_DATA_H__ */
