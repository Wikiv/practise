#include <iostream>
#include<stdio.h>

#include <ubacmssql/MsSql.h>

using namespace std;

int main()
{
	string sDbHost = "maybankmssql.cnmzwmhoqejx.ap-southeast-1.rds.amazonaws.com123";
//	string sDbHost1 = "maybankmssql.cnmzwmhoqejx.ap-southeast-1.rds.amazonaws.com";
	string sDbHost1 = "";
	string sDbUsername = "maybank";
	string sDbPassword = "maybankmsf";
	string sDbName = "maybank_audit";
	string sPort = "";
	UBACMSSql *mssqlConn = new UBACMSSql( sDbHost, sDbHost1, sPort, sDbUsername, sDbPassword, sDbName,30 );
	string sError, sQuery = "insert into maybank_audit.dbo.MAYBANK_AUDIT (REQUEST_TYPE,REQUEST_PROTOCOL,RESPONSE_PROTOCOL,CREATED_AT) values ('Testing','1234','5678',GETDATE());";
        int flag = mssqlConn->query( mssqlConn->conn_ptr, sQuery, sError );
        if( sError.length() > 0 ) {
        	cout << "Error while executing MSSQL query " << sError << endl;
        } else 
		cout << "Query executed successfully\n";
        delete mssqlConn;
}

