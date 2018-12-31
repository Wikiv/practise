#include <iostream>
#include<stdio.h>

#include<ubacmysql/MySql.h>

using namespace std;

int main()
{
	UBACSql *mysqlConnection = new UBACSql( "localhost", "root", "root", "kundan" );
        MYSQL_RES *mResult;
        uint64_t nID;
	mysqlConnection->setAutoCommit( false );
	string sQuery1 = "INSERT INTO kundan.test VALUES(100);", sError;
	string sQuery2 = "INSERT INTO kundan.test VALUES(200);";
	string sQuery3 = "INSERT INTO kundan.test VALUES(300);";
	mysqlConnection->query(sQuery1, mResult, nID, sError);
        if(sError.length()>0) {
		cout << "Error in executing Query1 = " << sError << endl;
        } else {
		cout << "Query executed successfully\n";
	}
	mysqlConnection->query(sQuery2, mResult, nID, sError);
	mysqlConnection->query(sQuery3, mResult, nID, sError);
	if(sError.length()>0) {
                cout << "Error in executing Query 2 or 3= " << sError << endl;
        } else {
                cout << "Query 2 and 3 executed successfully\n";
        }
	cout << "mysqlConnection->commit() " << mysqlConnection->commit() << endl;
        delete mysqlConnection;
}
