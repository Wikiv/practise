#ifndef __SESSION_TABLE_H__
#define __SESSION_TABLE_H__

#include <iostream>
#include <string>
#include <map>

using namespace std;

/// Class SessionTable maintains the map of sessions along with the connection information. 
class SessionTable :
	public map<string, void *>
{
	public:
		SessionTable();
		~SessionTable();

		/** Adds 'sSession' and 'conn' to the map. */
		void addSession(string sSession, void *conn);
		/** Retrives the connection information of 'sSession'. */
		void *getSession(string sSession);
		/** Removes 'sSession' from the map. */
		void removeSession(string sSession);
	private:
		void printSessionTable(string);
};

#endif /* __SESSION_TABLE_H__ */
