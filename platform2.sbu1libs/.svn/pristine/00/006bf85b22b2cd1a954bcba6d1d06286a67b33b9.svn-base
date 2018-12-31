#include <iostream>
#include<stdio.h>

#include<ubacmssql/MsSql.h>

using namespace std;

int main()
{
	string sDbHost = "maybankmssql.cnmzwmhoqejx.ap-southeast-1.rds.amazonaws.com";
	string sDbUsername = "maybank";
	string sDbPassword = "maybankmsf";
	string sDbName = "maybank_audit";
	UBACMSSql *mssqlConn = new UBACMSSql( sDbHost, "", sDbUsername, sDbPassword, sDbName );
	string sError, sQuery = "insert into maybank_audit.dbo.MAYBANK_AUDIT (REQUEST_TYPE,REQUEST_PROTOCOL,RESPONSE_PROTOCOL) values ('Testing','1234','5678');";
        int flag = mssqlConn->query( mssqlConn->conn_ptr, sQuery, sError );
        if( sError.length() > 0 ) {
        	cout << "Error while executing MSSQL query " << sError << endl;
        } else 
		cout << "Query executed successfully\n";
        delete mssqlConn;
}

