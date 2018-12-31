#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <queue>  


#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


#include <ubacipc/Mutex.h>

#include "ConnectionQueue.h"

using namespace std;

namespace MYSQL_POOL
{

	class ConnectionPool : public UBACIPC::Mutex
	{
		public:

			ConnectionPool(string uri, string user, string password);

            ConnectionPool(sql::ConnectOptionsMap m);

            void initialize(size_t nConns = 1);

            void setSchema(string schema);

			void setConnTimeout(int);

			sql::Connection* getConnection();

			void closeConnection(sql::Connection *);

            void release();

		private:
            //string uri, user, password, schema;
            sql::ConnectOptionsMap connection_properties;

            void init();

			int timeout;
			int poolSize;
			int isClosedCount;

            Mutex mutex;

			ConnectionQueue connectionQ;

			void createConnection(size_t noofConnection);
	};

};

#endif
