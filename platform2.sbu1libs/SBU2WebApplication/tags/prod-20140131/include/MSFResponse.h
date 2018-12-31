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

	class MSFResponse: public JsonObject
	{
		protected:
			JsonObject respObj;
			JsonObject dataObj;
			JsonObject echoObj;
		private:
			string infoID, infoMsg, svcGroup, svcName, appID, msgID, svcVersion;
			string setServerTime();
		public:
			MSFResponse(MSFRequest * msfRequest);
			void addToData(string key, JsonObject obj);
			void setInfoID(string sInfoID);
			void setInfoMsg(string sInfoMsg);
			void setSvcGroup(string sSvcgrp);
			void setSvcName(string sSvcName);
			void setSvcVersion(string sSvcVersion);
			void setAppID(string sAppID);
			void clearData();
			void addToMe(string key, JsonObject obj);

			string getMsgID();
			string getInfoID();
			string getInfoMsg();
			string getSvcGroup();
			string getSvcName();
			string getSvcVersion();
			string getAppID();
			string toString();
	};
};

#endif /* __SBU2_MSF_RES_H__ */
