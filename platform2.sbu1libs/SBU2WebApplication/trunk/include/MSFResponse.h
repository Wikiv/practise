#ifndef __SBU2_MSF_RES_H__
#define __SBU2_MSF_RES_H__

/*
 *MSFResponse.h
 *
 *  Created on: 27-Nov-2013
 *      Author: kundan
 */

#include <string.h>
#include <iostream>

#include "MSFRequest.h"

namespace SBU2
{
	using namespace std;

	/// Class MSFResponse used for constructing Json response. */
	class MSFResponse: public JsonObject
	{
		protected:
			/** Response Json object. */
			JsonObject respObj;
			/** Json data object. */
			JsonObject dataObj;
			/** Json echo object. */
			JsonObject echoObj;
		private:
			string infoID, infoMsg, svcGroup, svcName, appID, msgID, svcVersion;
			string setServerTime();
		public:
			/** Constructs Json response. Copies MsgID and echo part from the 'msfRequest' to the response. */
			MSFResponse(MSFRequest * msfRequest);
			/** Adds Json object 'obj' along with 'key' to the data part of the response. */
			void addToData(string key, JsonObject obj);
			/** Adds Json object 'obj' to the data part of the response. */
			void addToData(JsonObject obj);
			/** Sets info ID in the response. */
			void setInfoID(string sInfoID);
			/** Sets info message in the response. */
			void setInfoMsg(string sInfoMsg);
			/** Sets service group in the response. */
			void setSvcGroup(string sSvcgrp);
			/** Sets service name in the response. */
			void setSvcName(string sSvcName);
			/** Sets service version in the response. */
			void setSvcVersion(string sSvcVersion);
			/** Sets App ID in the response. */
			void setAppID(string sAppID);
			/** Clears data part of the response. */
			void clearData();
			/** Adds Json object 'obj' along with 'key' to the data part of the existing response. */
			void addToMe(string key, JsonObject obj);

			/** Returns Message ID. */
			string getMsgID();
			/** Returns Info ID. */
			string getInfoID();
			/** Returns Info message. */
			string getInfoMsg();
			/** Returns service group. */
			string getSvcGroup();
			/** Returns service name. */
			string getSvcName();
			/** Returns service version. */ 
			string getSvcVersion();
			/** Returns Application ID. */
			string getAppID();
			/** Converts Json response and returns the converted string. */
			string toString();
	};
};

#endif /* __SBU2_MSF_RES_H__ */
