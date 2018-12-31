//g++ selectStatmentConnector.cpp -l:libmysqlcppconn.so

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
   Include directly the different
   headers from cppconn/ and mysql_driver.h + mysql_util.h
   (and mysql_connection.h). This will reduce your build time!
 */
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main()
{

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
		time_t b4Start = time(0);
		cout << b4Start << ":::" << endl ;


		 //pstmt = con->prepareStatement("select * from test where created_at between '2015-06-26 22:50:02' and '2015-06-26 22:53:02' limit 10");
		 //pstmt = con->prepareStatement("SELECT * FROM test WHERE id = '54098' AND (SELECT * FROM (SELECT(SLEEP(5)))GiwL) OR 1='1'");
		 pstmt = con->prepareStatement("SELECT * FROM test WHERE infoid = ?");

		 pstmt->setString(1,"'202' AND (SELECT * FROM (SELECT(SLEEP(5)))GiwL) OR 1='1'");
		 //pstmt->setString(1,"202");
		 res = pstmt->executeQuery();
		 while(res->next()){
			 cout << "id :: " << res->getInt("id") << endl;
			 cout << "Name ::" << res->getString("name") << endl;
		 }
		 time_t afterFinish = time(0);
		 cout << afterFinish << ":::" << endl;

		 cout << "Time Taken :: " << afterFinish - b4Start << endl; 
		 delete res;
		 delete pstmt;
		 delete con;

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
