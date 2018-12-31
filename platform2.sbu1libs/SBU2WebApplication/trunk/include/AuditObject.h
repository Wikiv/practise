#ifndef __SBU2_AUDIT_OBJECT_H_
#define __SBU2_AUDIT_OBJECT_H_

#include <string>
#include <map>

#include "MSFRequest.h"
#include "MSFResponse.h"

namespace SBU2
{
    /*
     *   Holds basic @MSFRequest and @MSFResponse values.
     */
    class AuditTrans;

    class AuditObject
    {
        friend class AuditTrans;
        private:
            string sUser, sUserType, sApiTime, sReqTime, sRespTime,
                   sSrcIP, sSvcVersion;

            MSFRequest * msfRequest;
            MSFResponse * msfResponse;

        protected:
            map<string, string> extraFieldsMap;

        public:
            AuditObject(MSFRequest msfReq, MSFResponse msfResp);

            virtual ~AuditObject() {}

            void setUser(string sUser);

            void setUserType(string sUserType);

            void setApiTime(string sApiTime);

            void setReqTime(string sReqTime);

            void setRespTime(string sRespTime);

            void setSrcIP(string sSrcIP);

            void setSvcVersion(string sSvcVersion);
            void setMsfRequest(MSFRequest * msfRequest);
            void setMsfResponse(MSFResponse * msfResponse);

            string getUser();

            string getUserType();

            string getApiTime();

            string getReqTime();

            string getRespTime();

            string getSrcIP();

            string getSvcVersion();

            MSFRequest getMSFRequest();

            MSFResponse getMSFResponse();

            void addColumnNameValue(string key, string value);

            map<string, string> getExtraFieldMap();
    };
};


#endif /* __SBU2_AUDIT_OBJECT__ */
