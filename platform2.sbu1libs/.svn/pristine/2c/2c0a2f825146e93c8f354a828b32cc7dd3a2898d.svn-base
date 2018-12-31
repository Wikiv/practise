#include <stdlib.h>
#include <iostream>
#include <pthread.h>

#include "ConnectionPool.h"


#define NUM_THREADS 100

using namespace std;
using namespace MYSQL_POOL;


void *test(void * tData)
{

    while(1) 
    {

        ConnectionPool * pool = (ConnectionPool * ) tData; 

        sql::Connection *con = NULL;
        sql::ResultSet *res = NULL;
        sql::PreparedStatement *pstmt = NULL;

        try {

            con =  pool->getConnection();

            printf("Got connection : %p : t_id : %d\n", con, pthread_self());

            sleep(5);

            pstmt = con->prepareStatement("call ptest()");
            pstmt->execute();

            do {

                res = pstmt->getResultSet();

                while(res->next()){
                    cout << "Name ::" << res->getString("name") << 
                         " - Owner :: "<< res->getString("owner") <<  endl;
                }

            } while( pstmt->getMoreResults() );

        } catch (sql::SQLException &e) {
            cout << "MySQL error code: " << e.getErrorCode() << endl;
            cout << "ERR: " << e.what() << endl;
            //cout << "SQLState: " << e.getSQLState() << endl;
        }


        delete res;
        delete pstmt;

        printf("Going to close : %p : t_id : %d\n", con, pthread_self());
        pool->closeConnection(con);

//        sleep(1);
    }
}


int main()
{
    ConnectionPool * pool = new ConnectionPool("localhost", "root", "root");
    pool->setSchema("test");
    pool->initialize(10);

    pthread_t threads[NUM_THREADS];
    for(int t = 0; t < NUM_THREADS; t++)
    {
        pthread_create(&threads[t], NULL, test, pool);
//        sleep(2);
    }
    /*
       while(1)
       {
       test(pool);
       int x;
       scanf("Enter no to continue : %d", &x);
       }
       */
    while(1);
}
