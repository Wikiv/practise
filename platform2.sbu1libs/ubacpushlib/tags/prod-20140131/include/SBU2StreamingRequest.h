#ifndef __SBU2_STREAMING_REQUEST_H__
#define __SBU2_STREAMING_REQUEST_H__

#include <iostream>
#include <string>
#include <jsonparser/JsonParser.h>
#include <stdint.h>

class SBU2StreamingRequest
{
	public:
		SBU2StreamingRequest() {};
		SBU2StreamingRequest(string sRequest);
		~SBU2StreamingRequest();

		uint8_t getRequestType();
		vector<string> getSymbolList();
		string getAccountID();
		string getSessionID();

		bool isSubscribe();
		bool isUnSubscribe();

		const static uint8_t SBU2StreamingRequest_Unknown;
		const static uint8_t SBU2StreamingRequest_Level1;
		const static uint8_t SBU2StreamingRequest_Level2;
		const static uint8_t SBU2StreamingRequest_TradeSymbols;
		const static uint8_t SBU2StreamingRequest_Positions;
		const static uint8_t SBU2StreamingRequest_Orders;
		const static uint8_t SBU2StreamingRequest_Alerts;

		JsonObject reqObject;
	private:
		uint8_t iStreamingRequestType;
		string sAccountID;
		string sSessionID;

		bool subscription;
		bool unSubscription;

		vector<string>symbolList;

		void parse(string sRequest);
		bool setRequestType();
		void setAccountID();
		void setStreamingType();

};

#endif /* __SBU2_STREAMING_REQUEST_H__ */
