/*
 * MSFResponse.cpp
 *
 *  Created on: 27-Nov-2013
 *      Author: Kundan Krishna
 */

#include "MSFResponse.h"

using namespace SBU2;

MSFResponse::MSFResponse(MSFRequest * msfRequest)
{
	this->iObjectType = JsonObject::JsonObject_MAP;
	this->dataObj.iObjectType = JsonObject::JsonObject_MAP;
	this->infoID = "0";
	this->msgID = msfRequest->getMsgID();
	this->respObj["msgID"] = (JsonObject) msgID;

	try {
		addToMe("echo", msfRequest->getEchoObj());

	} catch (Exceptions e) {
	}
}

void MSFResponse::addToData(string key, JsonObject obj)
{
	this->dataObj[key] = obj;
}

void MSFResponse::addToData(JsonObject obj)
{
    this->dataObj = obj;
}

string MSFResponse::getMsgID()
{
	return msgID;
}

string MSFResponse::getInfoID()
{
	return infoID;
}

string MSFResponse::getInfoMsg()
{
	return infoMsg;
}

string MSFResponse::getSvcGroup()
{
	return svcGroup;
}

string MSFResponse::getSvcName()
{
	return svcName;
}

string MSFResponse::getAppID()
{
	return appID;
}

void MSFResponse::setInfoID(string infoID)
{
	this->infoID = infoID;
}

void MSFResponse::setInfoMsg(string infoMsg)
{
	this->infoMsg = infoMsg;
}

void MSFResponse::setSvcGroup(string svcGroup)
{
	this->svcGroup = svcGroup;
}

void MSFResponse::setSvcName(string svcName)
{
	this->svcName = svcName;
}

void MSFResponse::setSvcVersion(string svcVersion)
{
	this->svcVersion = svcVersion;
}

void MSFResponse::setAppID(string appID)
{
	this->appID = appID;
}

string MSFResponse::setServerTime()
{
	stringstream sServerTime;
	sServerTime << (time(NULL)*1000);   // in Milliseconds
	return sServerTime.str();
}

void MSFResponse::addToMe(string key, JsonObject obj)
{
	((map<string, JsonObject> *)this)->insert( make_pair(key, obj) );
}

string MSFResponse::toString()
{
	respObj["serverTime"] = (JsonObject) (setServerTime());
	respObj["infoID"] = (JsonObject) infoID;
	respObj["svcName"] = (JsonObject) svcName;
	respObj["svcGroup"] = (JsonObject) svcGroup;

	if ( infoMsg.length() > 0 )
		respObj["infoMsg"] = (JsonObject)infoMsg;

	if(appID.length() > 0)
		respObj["appID"] = (JsonObject) appID;

	respObj["data"] = dataObj;

	addToMe("response", this->respObj);

	return JsonObject::toString();
}

