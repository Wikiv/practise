#include "ConnectionPool.h"

using namespace MYSQL_POOL;

ConnectionPool::ConnectionPool(string uri, string user, string password)
{
    connection_properties["hostName"] = uri;
    connection_properties["userName"] = user;
    connection_properties["password"] = password;
    connection_properties["OPT_RECONNECT"] = true;

    init();
}

ConnectionPool::ConnectionPool(sql::ConnectOptionsMap m) 
    : connection_properties(m)
{
    init();
}

void ConnectionPool::init()
{
	poolSize = 0;
	isClosedCount = 0;
}

void ConnectionPool::setSchema(string schema)
{
    connection_properties["schema"] = schema;
}

void ConnectionPool::initialize(size_t noofConnection)
{
	this->poolSize = noofConnection;

	createConnection(poolSize); 
}

void ConnectionPool::createConnection(size_t noofConnection) 
{

    mutex.lock();

    try {
        isClosedCount = 0;
        sql::Driver *driver = get_driver_instance();

        for( size_t i = 0 ; i < noofConnection ; i++ ) {

            sql::Connection *con = driver->connect(connection_properties);
            // con->setClientOption("clientTrace", "1");
            // con->setClientOption("libmysql_debug", "d:t:O,client.trace");

            connectionQ.enqueue(con);
        }

    } catch (sql::SQLException & e)
    {
        mutex.unlock();
        release();
        throw e;
    }

    mutex.unlock();
}

sql::Connection * ConnectionPool :: getConnection()
{
    sql::Connection * conn = connectionQ.dequeue();

    if ( conn != NULL ) 
    { 
        if (conn->isClosed()) 
        { 
            closeConnection(conn);
            conn = NULL;

        } else if ( conn->getAutoCommit() == false ) 
        {
            conn->setAutoCommit(true);
        }
    }

    if ( conn == NULL )
    {
        mutex.lock();
        int closedCount = isClosedCount;
        mutex.unlock();

        if( connectionQ.isEmpty() && closedCount == poolSize ) 
        {
            createConnection(poolSize);
            conn = getConnection();

        } else 
        {
            sql::SQLException e("ConnectionPool Exhausted", "-1", -1);
            throw e;
        }
    }

    //printf("Giving connection %p\n", conn);

    return conn;
}

void ConnectionPool::closeConnection(sql::Connection * conn)
{
    //printf("Closing connection %p\n", conn);

    if (conn == NULL) return;

    if (conn->isClosed())
    {
        printf("Closing connection isClosed() -- %p\n", conn);
        delete conn;

        mutex.lock();
        isClosedCount++;
        mutex.unlock();

        return;
    }

    //printf("Enqueing connection %p\n", conn);

    connectionQ.enqueue(conn);
}

void ConnectionPool::release()
{
    mutex.lock();

    while(! connectionQ.isEmpty())
    {
        sql::Connection * con = connectionQ.dequeue();
        delete con;
        con = NULL;

        isClosedCount++;
    }

    mutex.unlock();

    cout << "Releasing Connection Pool" << endl;
}

void ConnectionPool::setConnTimeout(int value)
{
    this->timeout = value ;
}
