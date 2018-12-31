#ifndef __SBU2_MSF_REQ_H__
#define __SBU2_MSF_REQ_H__


/*
 * MSFRequest.h
 *
 *  Created on: 27-Nov-2013
 *      Author: kundan
 */

#include <iostream>
#include <string.h>

#include <jsonparser/JsonParser.h>
#include <ubacsslinterface/Digest.h>
#include <ubacutils/IFHelper.h>
#include <ubacipc/HTTPClient.h>

namespace SBU2
{

	using namespace std;

	/// Class MSFRequest used for constructing JSON request.
	class MSFRequest: public JsonParser
	{
		protected:
			JsonObject reqObj, dataObj, fullObj;
			string sMsgID, sAppID;
			JsonObject getJsonObjectfromKey(string sKey);
			string generateMessageID(string sMessage);
			HTTPServerRequest * httpServerReq;
		public:
			/** Constructs Json Request. */
			MSFRequest( string sRequest );
			/** Returns Json Request. */
			JsonObject getRequest();
			/** Returns message ID. */
			string getMsgID();
			/** Returns app ID. */
			string getAppID();
			/** Returns session ID. */
			string getSession();
			/** Returns echo part of the request. */
			JsonObject getEchoObj();
			/** Returns data part of the request. */
			JsonObject getData();
			/** Sets message ID for the request. */
			void setMsgID(std::string sMsg);
			/** Converts Json Request to string and returns the converted string. */

			/** Get HTTPServerRequest reference */
			HTTPServerRequest * getHTTPServerReq();

			/** Set HTTPServerRequest reference */
			void setHTTPServerReq(HTTPServerRequest * req);

			string toString();

	};
};

#endif  /* __SBU2_MSF_REQ_H__ */
