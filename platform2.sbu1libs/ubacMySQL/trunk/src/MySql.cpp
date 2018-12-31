#include "MySql.h"

UBACSql::UBACSql(string sServerIP, string sUsername, string sPassword, string sDatabase)
{
    isConnection = false;
	bool flag = true;
	mysql_init(&mysqlID);
	mysql_options(&mysqlID, MYSQL_OPT_RECONNECT, (char *)&flag);
	if( mysql_real_connect(&mysqlID, sServerIP.c_str(), sUsername.c_str(), sPassword.c_str(), sDatabase.c_str(), 0, NULL, CLIENT_COMPRESS | CLIENT_MULTI_RESULTS | CLIENT_MULTI_STATEMENTS) )
        isConnection = true;
}

UBACSql::~UBACSql()
{
	mysql_close(&mysqlID);
}

bool UBACSql::isValidConnection()
{
    return isConnection;
}

bool UBACSql::query(string sQuery, MYSQL_RES * &res, uint64_t & id, string & sError)
{
	mutex.lock();
	int retVal = mysql_query(&mysqlID, sQuery.c_str());
	id  = mysql_insert_id(&mysqlID);
	res = mysql_store_result(&mysqlID);
	if( retVal != 0 )
		sError.append( mysql_error(&mysqlID) );
	mutex.unlock();
	return (retVal == 0);
}

bool UBACSql::query(string sQuery, uint64_t & id, uint64_t & affectedRows , string & sError)
{
	mutex.lock();
	int retVal = mysql_query(&mysqlID, sQuery.c_str());
	id  = mysql_insert_id(&mysqlID);
	affectedRows = mysql_affected_rows(&mysqlID);
	if( retVal != 0 )
		sError.append( mysql_error(&mysqlID) );
	mutex.unlock();
	return (retVal == 0);
}

bool UBACSql::setAutoCommit( bool bMode )
{
	int retVal = mysql_autocommit(&mysqlID, bMode);
	return (retVal == 0);
}

bool UBACSql::commit()
{
	int retVal = mysql_commit(&mysqlID);
	return (retVal == 0);
}
