#include "MsSql.h"

int err_handler( DBPROCESS *conn_ptr, int severity, int dberr, int oserr, char* dberrstr, char* oserrstr )
{
    cout << "ERROR HANDLER MSSQL SYBASE: Severity: " << severity << " dberr: " << dberr << " oserr: " << oserr << " dberrstr: " << dberrstr << endl;
    return INT_CANCEL;
}

int msg_handler( DBPROCESS *conn_ptr, DBINT msgno, int msgstate, int severity, char * msgtext, char * srvname,char * procname, int line )
{
    if( msgno != 5701 ) { //Ignoring for 5701 since this callback is called twice for database change for each successful connection also and msgtext comes as
        // database changes as 'master' and databse changed as '$dbname'
        printf ("MESSAGE HANDLER MSSQL SYBASE: Msg %ld, Level %d, State %d\n", msgno, severity, msgstate); 
        if (strlen(srvname) > 0) 
            printf ("Server '%s', ", srvname); 
        if (strlen(procname) > 0) 
            printf ("Procedure '%s', ", procname); 
        if (line > 0) 
            printf ("Line %d", line); 

        printf("\n\t%s\n", msgtext); 
        dberrhandle( err_handler );
    }

    return INT_CANCEL; 
}

void setDatabaseErrorHandlers()
{
    dberrhandle (err_handler);
    dbmsghandle (msg_handler);
}

void setDatabaseConnTimeOut(int seconds )
{
    dbsetlogintime(seconds);
}

UBACMSSql::UBACMSSql (string host, string port, string user, string password, string db)
{
    init( host, port, user, password, db );
}

UBACMSSql::UBACMSSql (string host1, string host2, string port, string user, string password, string db, int seconds)
{
    this->seconds = seconds;
    init( host1, host2, port, user, password, db );
}
void UBACMSSql::init( string host, string port, string user, string password, string db )
{
    login_rec = NULL;
    conn_ptr = NULL;


    conn_status = false;
    db_conn_status = false;
    init_db_connectors();
    setDatabaseErrorHandlers();
    if( conn_status ) {
        set_login_struct(user, password);
        if ( conn_status ) {
            cout << "connecting to db..." << db << endl;
            connect_to_db( host, port );
            if ( conn_status ) {
                choose_db( db );
            } else {
                cout << "geterror: " << geterror() << endl;
            }
        } else {
            cout << "geterror: " << geterror() << endl;
        }
    } else {
        cout << "geterror: " << geterror() << endl;
    }
}

void UBACMSSql::init( string host1, string host2, string port, string user, string password, string db )
{
    login_rec = NULL;
    conn_ptr = NULL;

    conn_status = false;
    db_conn_status = false;
    init_db_connectors();
    setDatabaseErrorHandlers();
    setDatabaseConnTimeOut(this->seconds);
    if( conn_status ) {
        set_login_struct(user, password);
        if ( conn_status ) {
            connect_to_db( host1, port );
            if ( conn_status ) {
                choose_db( db );
            } else {
                connect_to_db( host2, port );
                cout << "geterror: " << geterror() << endl;
                if ( conn_status ) {

                    choose_db( db );
                }
                else {
                    cout << "Secondary Server geterror: " << geterror() << endl;
                }
            }
        } else {
            cout << "geterror: " << geterror() << endl;
        }
    } else {
        cout << "geterror: " << geterror() << endl;
    }
}

UBACMSSql::~UBACMSSql()
{
    if( conn_status ) {
        dbclose( conn_ptr );
        dbloginfree( login_rec );
    }
}

string UBACMSSql::geterror()
{
    return s_error_message;
}

void UBACMSSql::choose_db( string current_db )
{
    if( (dbuse(conn_ptr, current_db.c_str())) == FAIL ) 
    {
        s_error_message = "Could not switch the database";
	db_conn_status = false;
        error_code = 4;
    } else {
	db_conn_status = true;
    }
}

void UBACMSSql::connect_to_db( string host, string port)
{
    conn_ptr = dbopen(login_rec, host.c_str());

    if (conn_ptr == NULL){
        conn_status = false;
        s_error_message = "Could not connect to database";
        error_code = 3;
    } else {
        conn_status = true;
    }
}

void UBACMSSql::init_db_connectors()
{
    if (dbinit() == FAIL){
        conn_status = false;
        cout << "could not initialize lib.." << endl;
        s_error_message.append("Could not initialize db library. ");
        error_code = 1;
    } else {
        conn_status = true;
    }
}

void UBACMSSql::set_login_struct(string user , string password )
{
    if ( (login_rec = dblogin()) == FAIL){
        conn_status = false;
        s_error_message.append("Failed to initialize the login struct");
        error_code = 2;
    }

    DBSETLUSER(login_rec, user.c_str());
    DBSETLPWD(login_rec, password.c_str());
    DBSETLAPP(login_rec, "msfmobile");

    char hostname[MAXHOSTNAMELEN];
    int max_len = MAXHOSTNAMELEN;

    if (gethostname(hostname, max_len) == 0){
        DBSETLHOST(login_rec, hostname);
    }
}

bool UBACMSSql::query( DBPROCESS *conn_ptr, string sQuery, string & sError )
{
    ScopedLock scopedLock( &mutex );
    if( conn_status && db_conn_status ) {
        if ( dbcmd(conn_ptr, sQuery.c_str()) == SUCCEED ) {
            if (dbsqlexec( conn_ptr) == FAIL) {
                sError.append("Could not execute the sql statement\n");
                return false;
            }
        } else {
            sError.append(s_error_message);
            return false;
        }
    } else {
        sError.append(s_error_message);
        return false;
    }
    return true;
}

