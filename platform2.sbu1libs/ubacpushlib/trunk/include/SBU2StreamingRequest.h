#ifndef __SBU2_STREAMING_REQUEST_H__
#define __SBU2_STREAMING_REQUEST_H__

#include <iostream>
#include <string>
#include <jsonparser/JsonParser.h>
#include <stdint.h>

/** Class SBU2StreamingRequest parses the JSON streaming request.
* Sets the request type to be either subscription or unsubscription.
* Sets the streaming request type. 
* Adds the symbols to the symbol list if the request type is subscription. 
* Sets the Session ID and account ID if available.
*/

class SBU2StreamingRequest
{
	public:
		SBU2StreamingRequest() {};
		/** Parses the streaming request. */
		SBU2StreamingRequest(string sRequest);
		~SBU2StreamingRequest();

		/** Returns the request type. It can be either subscription or unsubscription. */
		uint8_t getRequestType();
		/** Returns the symbol list. */
		vector<string> getSymbolList();
		/** Returns the account ID. */
		string getAccountID();
		/** Returns the session ID. */
		string getSessionID();

		/** Returns true if the request type is subscription. */
		bool isSubscribe();
		/** Returns true if the request type is unsubscription. */
		bool isUnSubscribe();

		/** Returns true if the request is valid */
		bool isValid(){
			return valid;
		}	

		
		/** Returns the App ID. */
        string getAppID(){
                return sAppID;
        }
        



        /** Streaming request types. */
		const static uint8_t SBU2StreamingRequest_Unknown;
		const static uint8_t SBU2StreamingRequest_Level1;
		const static uint8_t SBU2StreamingRequest_Level2;
		const static uint8_t SBU2StreamingRequest_TradeSymbols;
		const static uint8_t SBU2StreamingRequest_Positions;
		const static uint8_t SBU2StreamingRequest_Balances;
		const static uint8_t SBU2StreamingRequest_Orders;
		const static uint8_t SBU2StreamingRequest_Alerts;
		const static uint8_t SBU2StreamingRequest_LiveTrades;
        const static uint8_t SBU2StreamingRequest_AccountUpdate;

        const static uint8_t SBU2StreamingRequest_MAX_SYMS;
		
		/** Json request object. */
		JsonObject reqObject;
	private:
		uint8_t iStreamingRequestType;
		string sAccountID;
		string sSessionID,sAppID;

		bool subscription;
		bool unSubscription;
		bool valid;
		vector<string>symbolList;

		void parse(string sRequest);
		bool setRequestType();
		void setAccountID();
		void setStreamingType();
        void setAppID();

};

#endif /* __SBU2_STREAMING_REQUEST_H__ */
