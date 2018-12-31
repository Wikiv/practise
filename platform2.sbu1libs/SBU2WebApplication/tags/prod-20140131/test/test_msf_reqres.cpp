#include <iostream>
#include <string>

#include "MSFResponse.h"
#include "MSFRequest.h"

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
	response.addToData("datakey", i);
	response.setAppID("12345appid");
	cout << " sResponse  = " << response.toString() << endl;
	return 0;

}
