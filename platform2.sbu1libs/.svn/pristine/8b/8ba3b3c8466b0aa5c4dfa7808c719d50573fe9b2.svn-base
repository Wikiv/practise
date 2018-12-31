#include <iostream>
#include <sstream>
#include<stdio.h>

#include <ubacmysql/MySql.h>

using namespace std;

int main()
{
	UBACSql *mysqlConnection = new UBACSql( "localhost", "root", "root", "test" );
    MYSQL_RES *mResult;
    uint64_t nID;


    for (int i = 0; i < 1000; i++) {

        stringstream ss;

        ss << "INSERT INTO student(name, age) VALUES('" ;
        ss << i ;
        ss << "', 100)" ;

    	string sQuery = ss.str();

        string sError;

    	mysqlConnection->query(sQuery, mResult, nID, sError);

        if(sError.length()>0) {
            cout << "Error in executing Query1 = " << sError << endl;
        } else {
            cout << "Query executed successfully\n";
        }
    }

    delete mysqlConnection;
}
