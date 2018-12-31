#ifndef __UBAC_MSSql
#define __UBAC_MSSql

#include <iostream>
#include <unistd.h>
#include <sys/param.h>
#include <stdio.h>
#include <sybfront.h>
#include <sybdb.h>
#include <syberror.h>
#include <string.h>

#include <ubacipc/Mutex.h>
#include <ubacipc/ScopedLock.h>

void setDatabaseErrorHandlers();
int err_handler(DBPROCESS *conn_ptr, int severity, int dberr, int oserr, char* dberrstr, char* oserrstr);
int msg_handler(DBPROCESS *conn_ptr, DBINT msgno, int msgstate, int severity, char * msgtext, char * server,char * procedure, int line);

using namespace std;

/// Class UBACMSSql for simple MSSQL interfaces.
class UBACMSSql
{
        private:
		void init(string host, string port, string user, string pwd, string db);
		void init(string host1, string host2, string port, string user, string pwd, string db);
                void init_db_connectors();
                void set_login_struct(string user, string password);
                void connect_to_db(string host, string port);
                void choose_db(string db);
                string geterror();
	
                LOGINREC *login_rec;
		Mutex mutex;

                string s_error_message;
                bool conn_status,db_conn_status;
                int error_code;
		int seconds;
	public:
		/// Creates MSSQL connection.
                UBACMSSql(string host, string port, string user, string pwd, string db);
		UBACMSSql (string host1, string host2, string port, string user, string password, string db, int seconds=10);
                ~UBACMSSql();
		/// Connection with the SQL Server.
                DBPROCESS *conn_ptr;
		/// Execute query.
		bool query( DBPROCESS *conn_ptr, string sQuery, string & sError );
};

#endif /*__UBAC_MSSql*/


