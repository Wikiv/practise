#include<iostream>


#include <ubacmysql/MySql.h>

using namespace std;


int main()
{
    UBACSql testsql("localhost", "root", "root", "curr_init");
    cout << "testsql.isValidConnection: " << testsql.isValidConnection() << endl;

    return 0;
}


