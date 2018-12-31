#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include <mcheck.h>
#include "HTTPServer.h"

using namespace UBACIPC;

class MyHTTPListner:
	public HTTPListner
{
	public:
		MyHTTPListner() {};

        void onGetRequest(HTTPServerRequest * request, HTTPConnection * client)
        {
            onPostRequest(request, client);
        }

		void onPostRequest(HTTPServerRequest * request, HTTPConnection *client)
		{
//			cout << "MyWebService onPostRequest " << endl;
            
            stringstream ss;
            for(int i = 0; i < 1024 * 10; i++)
                ss << 1;

			HTTPResponse httpResponse(HTTPResponse::ok);
			httpResponse.setContent(ss.str());

			client->send(httpResponse);
            client->release();
		}
};

int main()
{

	EventFax fax;

	MyHTTPListner * httpListner = new MyHTTPListner();

	HTTPServer h(30002, & fax, httpListner);

	fax.addTCPServer(& h);
	fax.run();
}
// g++ -I include/ test/test_http_server.cpp  src/* -lpthread -l:libubacutils.so.1.2.2 -l:libubacsslinterface.so.1.2.2 -lssl
