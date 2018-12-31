
#include "AuditObject.h"

using namespace std;
using namespace SBU2;

AuditObject::AuditObject(MSFRequest msfReq, MSFResponse msfResp)
{
    msfRequest = & msfReq;
    msfResponse = & msfResp;
}

void AuditObject::setUser(string sUser)
{
    this->sUser = sUser;
}

void AuditObject::setUserType(string sUserType)
{
    this->sUserType = sUserType;
}

void AuditObject::setApiTime(string sApiTime)
{
    this->sApiTime = sApiTime;
}

void AuditObject::setReqTime(string sReqTime)
{
    this->sReqTime = sReqTime;
}

void AuditObject::setSrcIP(string sSrcIP)
{
    this->sSrcIP = sSrcIP;
}

void AuditObject::setSvcVersion(string sSvcVersion)
{
    this->sSvcVersion = sSvcVersion;
}

void AuditObject::setRespTime(string sRespTime)
{
    this->sRespTime = sRespTime;
}

void AuditObject::setMsfRequest(MSFRequest * msfRequest)
{
  this->msfRequest = msfRequest;
}

void AuditObject::setMsfResponse(MSFResponse * msfResponse)
{
  this->msfResponse = msfResponse;	
}

string AuditObject::getUser()
{
    return sUser;
}

string AuditObject::getUserType()
{
    return sUserType;
}

string AuditObject::getApiTime()
{
    return sApiTime;
}

string AuditObject::getReqTime()
{
    return sReqTime;
}

string AuditObject::getRespTime()
{
    return sRespTime;
}

string AuditObject::getSrcIP()
{
    return sSrcIP;
}

string AuditObject::getSvcVersion()
{
    return sSvcVersion;
}

MSFRequest AuditObject::getMSFRequest()
{
    return * msfRequest;
}

MSFResponse AuditObject::getMSFResponse()
{
    return * msfResponse;
}

void AuditObject::addColumnNameValue(string key, string value)
{
    this->extraFieldsMap[key] = value;
}

map<string, string> AuditObject::getExtraFieldMap()
{
    return this->extraFieldsMap;
}
