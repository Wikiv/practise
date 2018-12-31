/*Compile:
   g++ insertStatementConnector.cpp -l:libmysqlcppconn.so
  Run:
  	./a.out 3000 
*/
/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
   Include directly the different
   headers from cppconn/ and mysql_driver.h + mysql_util.h
   (and mysql_connection.h). This will reduce your build time!
 */
#include "mysql_connection.h"
#include "mysqlConnectionPool.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main(int argc, char *argv[])
{
	size_t nRows = atoi(argv[1]);

	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
		/* Connect to the MySQL test database */
		con->setSchema("testDB");
		/* '?' is the supported placeholder syntax */
		pstmt = con->prepareStatement("INSERT INTO test(name,accno,appid,infoid,orderid) VALUES (?,?,?,?,?)");

		time_t b4Start = time(0);
		cout << b4Start << ":::" << endl ;

		for(int i =0 ; i < nRows ; i++){
			pstmt->setString(1, "SRI");
			pstmt->setString(2, "1989009");
			pstmt->setString(3, "sadadj2423msfms");
			pstmt->setString(4, "202");
			pstmt->setString(5, "72034678");
			pstmt->executeUpdate();
		}

		time_t afterFinish = time(0);
		cout << afterFinish << ":::" << endl;

		cout << "Time Taken :: " << afterFinish - b4Start << endl; 
		delete con;
		cout << "Connection State ::: " << checkCloseConnection(con) << endl;
		closeConnection(*con);
		//delete res;
		delete pstmt;

	} catch (sql::SQLException &e) {

		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	cout << endl;

	return EXIT_SUCCESS;
}
