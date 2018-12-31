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
	this->reqObj = this->fullObj["request"];
	this->sAppID =  this->reqObj["appID"];

	cout << "before Msgid inreq = " << this->reqObj["msgID"] << endl;
	addMessageID(sRequest);
	cout << "After Msgid inreq = " << sMsgID << endl;
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
	cout << "Message ID = " << sMessageID << endl;
	return sMessageID;
}

void MSFRequest::addMessageID(string sRequest)
{
	sMsgID = generateMessageID(sRequest);
	this->reqObj["msgID"] = sMsgID;
}

JsonObject MSFRequest::getData()
{
	return this->reqObj["data"];
}

string MSFRequest::getAppID()
{
	return sAppID;
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
