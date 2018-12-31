/*
 * MSFRequest.cpp
 *
 *  Created on: 27-Nov-2013
 *      Author: kundan
 */

#include "MSFRequest.h"

using namespace SBU2;

MSFRequest::MSFRequest(string sRequest):JsonParser( sRequest)
{
	this->fullObj = this->getJsonObject();

    if (fullObj.hasKey("request"))
    {
	    this->reqObj = this->fullObj["request"];

        if (this->reqObj.hasKey("appID"))
	        this->sAppID = this->reqObj["appID"];
    }


    this->httpServerReq = NULL;
}

string MSFRequest::generateMessageID(string sMessage)
{
	IFHelper helper;
	Digest digest;
	string sMessageID;
	stringstream sTime;
	sTime.setf(ios::fixed, ios::floatfield);
	sTime << helper.currentTime();
	digest.digest(sMessage + sTime.str(), Digest::DigestType_MD5, sMessageID);
	return sMessageID;
}

void MSFRequest::setMsgID(string sMsg)
{
	sMsgID = generateMessageID(sMsg);
	this->reqObj["msgID"] = sMsgID;
}

JsonObject MSFRequest::getData()
{
	return this->reqObj.getJsonObject("data");
}

string MSFRequest::getAppID()
{
	return sAppID;
}

void MSFRequest::setHTTPServerReq(HTTPServerRequest * req)
{
    httpServerReq = req;   
}

HTTPServerRequest  * MSFRequest::getHTTPServerReq()
{
    return this->httpServerReq;
}

JsonObject MSFRequest::getEchoObj()
{
	return this->fullObj.getJsonObject("echo");
}

string MSFRequest::getMsgID()
{
	return sMsgID;
}

JsonObject MSFRequest::getRequest()
{
	return reqObj;
}

string MSFRequest::getSession()
{
    return this->reqObj.getJsonObject("session");
}

string MSFRequest::toString()
{
	return this->fullObj.toString();
}
