
#include <iostream>


#include "ConnectionPool.h"

using namespace std;
using namespace MYSQL_POOL;
using namespace sql;

int main(int argc, char * argv[])
{
    Connection * conn = NULL;

    try 
    {

        ConnectionPool * pool = new ConnectionPool("tcp://localhost", "root", "root");
        pool->setSchema("test");
        pool->initialize();

        conn = pool->getConnection();

//        conn->setAutoCommit(false);

        pool->closeConnection(conn);

    } catch (sql::SQLException & e)
    {
        cout << e.what() << endl;
        cout << e.getErrorCode() << endl;
    }

    while(1)
    {
        if ( conn != NULL && conn->isClosed() )
        {
            cout << "Connection is closed " << endl;
            delete conn;

            conn = NULL;
        }

        sleep(1);
    }
}

// g++ -I include/ test/test_connection_pool.cpp src/* -lmysqlcppconn -l:libubacipc.so.1.3.1
