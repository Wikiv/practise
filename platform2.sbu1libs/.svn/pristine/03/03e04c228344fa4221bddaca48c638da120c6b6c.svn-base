
#include "AuditTrans.h"

using namespace SBU2;
using namespace std;

int main()
{
    string sReq =
        "{\"request\":{\"requestType\":\"U\",\"msgID\":\"d39d5f47-11a3-4327-97ec-949ff9f53ec3\",\"data\":{\"instrumentType\":\"FO\"},\"appID\":\"appid\",\"formFactor\":\"M\"},\"echo\":{\"hi\":\"tellme\"}}";

    MSFRequest msfRequest(sReq);
    MSFResponse msfResponse(&msfRequest);

    AuditObject auditObject(msfRequest, msfResponse);
    auditObject.addColumnNameValue("ORDERID", "12123123");
    auditObject.addColumnNameValue("ACCOUNTID", "12123123");
    auditObject.setUser("USER");
    auditObject.setReqTime(""); // time that is in database date format
    auditObject.setRespTime(""); // time that is in database date format
    


    AuditTrans auditTrans;

    string sQuery = auditTrans.getAuditQuery(auditObject);

    cout << sQuery << endl;
}

// g++ -I include/ src/* test/test_audit_trans.cpp -l:libubacjsonparser.so.1.2.2 -l:libubacsslinterface.so.1.2.2 -l:libubachttpclient.so.1.2.1 -l:libubacipc.so.1.2.5 -l:libubacutils.so.1.2.2 -l:libubaclogger.so.1.2.2 -l:libubacyaml.so.1.2.1
