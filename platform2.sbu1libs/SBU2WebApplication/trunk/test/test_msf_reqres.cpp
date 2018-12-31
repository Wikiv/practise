#include <iostream>
#include <string>

#include <sbu2webapp/MSFResponse.h>
#include <sbu2webapp/MSFRequest.h>

using namespace std;
using namespace SBU2;

int main()
{
	string sReq =
		"{\"request\":{\"requestType\":\"U\",\"msgID\":\"d39d5f47-11a3-4327-97ec-949ff9f53ec3\",\"data\":{\"instrumentType\":\"FO\"},\"appID\":\"appid\",\"formFactor\":\"M\"},\"echo\":{\"hi\":\"tellme\"}}";
	cout << "sReq = " << sReq << endl;

	MSFRequest request( sReq );
	cout << "APPID = " << request.getAppID()  << " size is " <<
		 request.getAppID().length() << endl;
	cout << "MSG ID = " << request.getMsgID() << endl;

	JsonObject obj1, echoobj;
	obj1 = request.getRequest();
	echoobj = request.getEchoObj();
	cout << "Json data instrument type = " <<  request.getData()["instrumentType"]
		 << endl;
	cout << "Json Req type = " << obj1["requestType"] << endl;
	cout << "echo param = " << echoobj["hello"] << " size is " <<
		 echoobj["hello"].length() << endl;

	MSFResponse response( &request );
	JsonInt i(10);
    JsonDouble d1(70.09);
    JsonDouble d2(2.09);
    vector<JsonObject> v;
    v.push_back(d1);
    v.push_back(d2);

	response.addToData("addeddoublearray", v);
	response.addToData("addedint", i);
	response.setAppID("12345appid");
	cout << " sResponse  = " << response.toString() << endl;
	return 0;

}

/* to compile
 g++ test_msf_reqres.cpp -lsbu2webapp++
*/
