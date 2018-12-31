#ifndef __SESSION_TABLE_H__
#define __SESSION_TABLE_H__

#include <iostream>
#include <string>
#include <map>

using namespace std;

class SessionTable :
	public map<string, void *>
{
	public:
		SessionTable();
		~SessionTable();

		void addSession(string sSession, void *conn);
		void *getSession(string sSession);
		void removeSession(string sSession);
	private:
		void printSessionTable(string);
};

#endif /* __SESSION_TABLE_H__ */
