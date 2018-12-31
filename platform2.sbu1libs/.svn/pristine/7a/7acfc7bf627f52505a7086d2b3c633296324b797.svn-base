#include <stdlib.h>
#include <iostream>
#include <pthread.h>

#include "ConnectionPool.h"

#define NUM_THREADS 1

using namespace std;
using namespace MYSQL_POOL;

int main()
{
    ConnectionPool * pool = new ConnectionPool("localhost", "root", "root");
    pool->setSchema("test");
    pool->initialize(2);

    sql::Connection *con = NULL;
    sql::ResultSet * res = NULL;
    sql::PreparedStatement * stmt = NULL;

    con = pool->getConnection();

    for (int i = 0; i < 3; i++)
    {

        try {

            printf("Got connection : %p : t_id : %d\n", con, pthread_self());

            stmt = con->prepareStatement("call ptest()");
//            res = stmt->executeQuery();
            stmt->execute();

//             stmt = con->createStatement();
//             stmt->execute("call ptest()");

            do {

                if ( res )
                    delete res;

                res = stmt->getResultSet();

                while( res->next() ) {

                    cout << "Name-" << res->getString("name");
                    cout << " :: Owner-"<< res->getString("owner") <<  endl;
                }

           } while (stmt->getMoreResults());

        } catch (sql::SQLException &e) {
            cout << "MySQL error code: " << e.getErrorCode() << endl;
            cout << "ERR: " << e.what() << endl;
            cout << "SQLState: " << e.getSQLState() << endl;
        }

        if (res) {
            delete res;
            res = NULL;
        }

        delete stmt;
    }

    printf("Going to close : %p : t_id : %d\n", con, pthread_self());
    pool->closeConnection(con);

}
