#include "AuditLog.h"

AuditLog::AuditLog( YamlConfig *yamlConfig, SLog *sLogID, bool isMYSql )
{
	this->isMYSql = isMYSql;
	this->sLogID = sLogID;
        sDbHost = (*yamlConfig)["audit_db"]["host"];
        sDbUsername = (*yamlConfig)["audit_db"]["username"];
        sDbPassword = (*yamlConfig)["audit_db"]["password"];
        sDbName = (*yamlConfig)["audit_db"]["db_name"];
        sDbTable = (*yamlConfig)["audit_db"]["table_name"];
}

AuditLog::~AuditLog()
{
}

void AuditLog::addExtModSQLMap( ExtMod *extMod, map<string, string> & sqlMap )
{
        string sMessageID, sSession, sAppID, sClientType, sVersion;

        extMod->getValue("MESSAGE_ID", sMessageID, true);
        extMod->getValue("SESSION",sSession, true);
        extMod->getValue("APP_ID", sAppID, true);
        extMod->getValue("CLIENT_TYPE", sClientType, true);
        extMod->getValue("VERSION", sVersion, true);

	if(sMessageID.length() > 0) {
        	sqlMap.insert(std::make_pair("MESSAGE_ID", sMessageID));
	}
	if(sAppID.length() > 0) {
	        sqlMap.insert(std::make_pair("APP_ID", sAppID));
	}
	if(sClientType.length() > 0) {
	        sqlMap.insert(std::make_pair("CLIENT_TYPE", sClientType));
	}
	if(sSession.length() > 0) {
	        sqlMap.insert(std::make_pair("SESSION_ID", sSession));
	}
	if(sVersion.length() > 0) {
	        sqlMap.insert(std::make_pair("APP_VERSION", sVersion));
	}
}

void AuditLog::frameSQLQuery( string sQuerykey, string sQueryValue, string & sQuery )
{
        stringstream streamQuery;
	if ( isMYSql ) {
        	streamQuery << "insert into " << sDbTable <<  " (" << sQuerykey << " CREATED_AT) values (" << sQueryValue << " CURRENT_TIMESTAMP);";
	} else {
		streamQuery << "insert into " << sDbName << ".dbo." << sDbTable <<  " (" << sQuerykey << " CREATED_AT) values (" << sQueryValue << " GETDATE());";
	}
        sQuery.append(streamQuery.str());
        cout << "Query = " << sQuery << endl;
}

void AuditLog::logAuditDetails( string sReqType, string sReqProtocol, string sResProtocol, map<string, string> mRequestMap, ExtMod *extMod )
{
        cout << "Size of map in logaudit " << mRequestMap.size()<< endl;
        addExtModSQLMap( extMod, mRequestMap);
        mRequestMap.insert(std::make_pair("REQUEST_TYPE", sReqType));
        mRequestMap.insert(std::make_pair("REQUEST_PROTOCOL", sReqProtocol));
        mRequestMap.insert(std::make_pair("RESPONSE_PROTOCOL", sResProtocol));

        stringstream sQueryKey, sQueryValue;
        string sQuery;

        map<string, string>::iterator iter_map = mRequestMap.begin();
        while( iter_map != mRequestMap.end() ) {
                sQueryKey << (*iter_map).first << ",";
                sQueryValue << "'" << (*iter_map).second << "' ,";
                iter_map++;
        }
        frameSQLQuery( sQueryKey.str(), sQueryValue.str(), sQuery );

        if( execute_query(sQuery) ) {
               	cout << "Query successfully executed\n";
        } else {
		this->m_auditfile.lock();
               	sLogID->debug("Failed Query: %s\n", sQuery.c_str());
		this->m_auditfile.unlock();
        }
}

bool AuditLog::execute_query( string sQuery )
{
	bool flag = false;
        string sError;
#ifdef ALL
#define SQL
#define MSSQL
#endif
#ifdef SQL
	if( isMYSql ) {
		cout << "creating MYSQL connection in execute query\n";
		UBACSql *mysqlConnection = new UBACSql( sDbHost, sDbUsername, sDbPassword, sDbName );
        	MYSQL_RES *mResult;
        	uint64_t nID;
        	flag = mysqlConnection->query(sQuery, mResult, nID, sError);
        	if(sError.length()>0) {
                	cout << "Error in executing Query" << sError << endl;
        	}
		delete mysqlConnection;
	}
#endif
#ifdef MSSQL 
	if( !isMYSql ) {
		cout << "creating MSSQL connection in execute query\n";
		UBACMSSql *mssqlConn = new UBACMSSql( sDbHost, "", sDbUsername, sDbPassword, sDbName );
		flag = mssqlConn->query( mssqlConn->conn_ptr, sQuery, sError );
		if( sError.length() > 0 ) {
			cout << "Error while executing MSSQL query " << sError << endl;
		}
		delete mssqlConn;
        }
#endif
        return flag;
}

