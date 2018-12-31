#ifndef __SBU2_AUDIT_TRANS_H_
#define __SBU2_AUDIT_TRANS_H_

#include <string>
#include <map>

#include "AuditObject.h"

namespace SBU2
{
    class AuditTrans
    {
        private:
            string sTable;

        public:
            AuditTrans();

            void setTable(string sTable);

            string getTable();

            string getAuditQuery(AuditObject & auditObject);

    };
};

#endif /* __SBU2_AUDIT_TRANS_H_ */
