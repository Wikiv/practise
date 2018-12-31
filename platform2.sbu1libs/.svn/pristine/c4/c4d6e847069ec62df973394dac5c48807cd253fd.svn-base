#ifndef __MESSAGE_QUEUE_H__
#define __MESSAGE_QUEUE_H__

#include <queue>
#include <ubacipc/Mutex.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

namespace MYSQL_POOL {

	class ConnectionQueue :
		public Mutex
	{
		public:
			ConnectionQueue() {}
			~ConnectionQueue() {}

			/** Insert a connection into the queue. */
			void enqueue(sql::Connection *conn)
			{
				lock();
				connectionQ.push(conn);
				unlock();
			}

			/** Delete the first connection from the queue. */
			sql::Connection* dequeue()
			{
				lock();
				sql::Connection *item = connectionQ.front();
				if( ! connectionQ.empty() )
					connectionQ.pop();
				else 
					item = NULL;
				unlock();

				return item;
			}

			/** Check if the queue is empty. */
			bool isEmpty()
			{
				lock();
				bool _b = connectionQ.empty();
				unlock();

				return _b;
			}

			/** Get the size of the queue. */
			size_t size()
			{
				return connectionQ.size();
			}

		private:
			queue<sql::Connection *> connectionQ;
	};
};
#endif /* ConnectionQueue */
