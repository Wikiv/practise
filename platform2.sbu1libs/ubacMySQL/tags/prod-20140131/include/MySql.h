#ifndef __UBACSQL_H__
#define __UBACSQL_H__

#include <iostream>
#include <string>
#include <stdint.h>

#include <mysql/mysql.h>

#include <ubacipc/Mutex.h>

using namespace std;
namespace UBACSQL {
	/// Class UBACSql for simple SQL interfaces.
	class UBACSql {
		public:
			/// Create a mysql.
			UBACSql(string sServerIP, string sUsername, string sPassword, string sDatabase);
			~UBACSql();

			/// Execute query. Useful for queries which affect the rows. 
			bool query(string sQuery, uint64_t & id, uint64_t & affectedRows, string & sError);
			/// Execute query. Useful for select queries. 
			bool query(string sQuery, MYSQL_RES * &res , uint64_t & id, string & sError);
			/// Set Autocommit mode OFF/
			bool setAutoCommit(bool bMode);
			bool commit();
            bool isValidConnection();

		private:
			MYSQL mysqlID;
			Mutex mutex;  
            bool isConnection;
	};
};

using namespace UBACSQL;

#endif /* __UBACSQL_H__ */
