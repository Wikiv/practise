#include <ConnectionPool.h>
#include <iostream>
#include <stdlib.h>
#include <ubacipc/Thread.h>
using namespace MYSQL_POOL;
class pool : public Thread
{
	public:
		pool(){}
		void run()
		{
			sql::Connection *con;
			try{
				con = ((ConnectionPool *)(th_data))->getConnection(16);
				sql::ResultSet *res;
				sql::PreparedStatement *pstmt;
				con->setSchema("testDB");
				pstmt = con->prepareStatement("INSERT INTO test(name,accno,appid,infoid,orderid) VALUES (?,?,?,?,?)");
			//	while(1){
					pstmt->setString(1, "SRI");
					pstmt->setString(2, "1989009");
					pstmt->setString(3, "sadadj2423msfms");
					pstmt->setString(4, "202");
					pstmt->setString(5, "72034678");
					pstmt->executeUpdate();
			//		sleep(60);
			//		break;
			//	}   
				delete pstmt;
			} catch(connectionException &e){
				cout << "Error Msg :::" << e.getErrorMsg() << endl;
				cout << "Error Code :::" << e.getErrorCode() << endl ;
			}catch (sql::SQLException &e) {
				cout << "# ERR: SQLException in " << __FILE__;
				cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
				cout << "# ERR: " << e.what();
				cout << " (MySQL error code: " << e.getErrorCode();
				cout << ", SQLState: " << e.getSQLState() << " )" << endl;
			}
			((ConnectionPool *)(th_data))->closeConnection(con); 

		}
};

int main()
{
	pool *p ;
	vector < pool*> connList;
	ConnectionPool *connpool = new ConnectionPool(10);	
	for(int i = 0 ; i < 20 ; i++){
		p = new pool();
		connList.push_back(p);
		p->start(connpool);
	}

	vector<pool *>::iterator iter_tasks = connList.begin();
	while(iter_tasks != connList.end()){
		//cout << (* iter_tasks)->getThreadID() << endl;
		pthread_join((* iter_tasks)->getThreadID(), NULL);
		iter_tasks++;
	}  

}

