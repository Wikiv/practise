#ifndef __CONNECTION_LIST_H__
#define __CONNECTION_LIST_H__

#include <vector>
#include <algorithm>

using namespace std;

/// Class ConnectionList maintains the connections

class ConnectionList :
	public vector<void *>
{
	public:
		ConnectionList();
		~ConnectionList();

		/** Adds the 'conn' to the vector. */
		void addConn(void * conn);
		/** Removes the 'conn' from the vector. */
		void removeConn(void * conn);
};

#endif /* __CONNECTION_LIST_H__ */
