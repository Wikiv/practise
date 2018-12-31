#ifndef __UBAC_AUDIT_LOG_H__
#define __UBAC_AUDIT_LOG_H__

#include "UBACData.h"
#include <ubaclogger/SLog.h>
#include <ubacyaml/YamlConfig.h>
#ifdef ALL
#define MSSQL
#define SQL
#endif
#ifdef MSSQL
#include <ubacmssql/UBACMSSql.h>
#endif
#ifdef SQL
#include <ubacsql/UBACSql.h>
#endif

using namespace std;

class AuditLog
{
	public:
		AuditLog( YamlConfig *yamlConfig, UBACLOGGER::SLog *sLogID, bool isMYSql );
		~AuditLog();
                void logAuditDetails( string sReqType, string sReqProtocol, string sResProtocol, map<string, string> mRequestMap, ExtMod *extMod );
	private:
		string sDbHost, sDbUsername, sDbPassword, sDbName, sDbTable;
		bool isMYSql;
		UBACLOGGER::SLog *sLogID;
                bool execute_query( string sQuery );
		void addExtModSQLMap( ExtMod *extMod, map<string, string> & sqlMap );
                void frameSQLQuery( string sQuerykey, string sQueryValue, string & sQuery );
		Mutex m_auditfile;
};

#endif /*__UBAC_AUDIT_LOG_H__*/
