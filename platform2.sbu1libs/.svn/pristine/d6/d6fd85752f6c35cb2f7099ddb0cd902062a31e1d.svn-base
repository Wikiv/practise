#include "AuditTrans.h"

using namespace SBU2;
using namespace std;

AuditTrans::AuditTrans()
{
    setTable("AUDIT_TRANSACTIONS");
}

void AuditTrans::setTable(string sTable)
{
    this->sTable = sTable;
}

string AuditTrans::getTable()
{
    return this->sTable;
}

string AuditTrans::getAuditQuery(AuditObject & auditObject)
{
    map<string, string> keyValue;

    MSFRequest * msfReq = auditObject.msfRequest;
    MSFResponse * msfResp = auditObject.msfResponse;

    keyValue["MSG_ID"] = msfReq->getMsgID();
    keyValue["SVC_GROUP"] =  msfResp->getSvcGroup();
    keyValue["SVC_NAME"] =  msfResp->getSvcName();
    keyValue["SVC_VERSION"] =  auditObject.getSvcVersion();
    keyValue["INFOID"] =  msfResp->getInfoID();
    keyValue["INFO_MSG"] =  msfResp->getInfoMsg();
    keyValue["APP_ID"] =  msfResp->getAppID();
    keyValue["USERNAME"] =  auditObject.getUser();
    keyValue["USER_TYPE"] =  auditObject.getUserType();
    keyValue["API_TIME"] =  auditObject.getApiTime();
    keyValue["REQ_TIME"] =  auditObject.getReqTime();
    keyValue["RES_TIME"] =  auditObject.getRespTime();
    keyValue["SRC_IP"] =  auditObject.getSrcIP();

    map<string, string> extraFieldMap = auditObject.getExtraFieldMap();

    keyValue.insert( extraFieldMap.begin(), extraFieldMap.end());

    string sColumns, sValues;

    map<string, string>::iterator it = keyValue.begin();

    while ( it != keyValue.end() )
    {
        sColumns += it->first + ","; 

        if (it->second.length() > 0 ) 
            sValues += "'" + it->second + "',";
        else
            sValues += string("NULL") + "," ; 


        it++;
    }

    sColumns = sColumns.substr(0, sColumns.length() - 1);

    sValues = sValues.substr(0, sValues.length() - 1);

    string sQuery = "INSERT INTO " + this->sTable 
                    + "(" + sColumns + ") VALUES (" 
                    + sValues + ")";


    return sQuery;
}
