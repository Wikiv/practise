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

namespace SBU2
{

	using namespace std;

	class MSFRequest: public JsonParser
	{
		private:
			JsonObject reqObj, dataObj, fullObj;
			string sMsgID, sAppID;
			JsonObject getJsonObjectfromKey(string sKey);
			string generateMessageID(string sMessage);
		public:
			MSFRequest( string sRequest );
			JsonObject getRequest();
			string getMsgID();
			string getAppID();
            string getSession();
			JsonObject getEchoObj();
			JsonObject getData();
			void addMessageID(std::string);
			string toString();

	};
};

#endif  /* __SBU2_MSF_REQ_H__ */
