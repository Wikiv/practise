#include <iostream>
#include <stdio.h>

#include <ubacmysql/MySql.h>

using namespace std;

int main()
{
	UBACSql *mysqlConnection = new UBACSql( "localhost", "root", "root",
											"test" );

    for (int i = 0; i < 2000; i++ ) {

	MYSQL_RES *mResult;
	uint64_t nID;
	string sError;
	string sQuery = "SELECT name, age FROM student LIMIT 1";

	mysqlConnection->query(sQuery, mResult, nID, sError);

	if (mResult) 
	{
		MYSQL_ROW mysqlRow;
		while (mysqlRow = mysql_fetch_row(mResult)) {
			cout << mysqlRow[0] << endl;			
			cout << mysqlRow[1] << endl;			
		}
		
		
	}

	if(sError.length()>0) {
		cout << "Error in executing Query1 = " << sError << endl;

	} else {
		cout << "Query executed successfully\n";
	}
    }

	delete mysqlConnection;
}
