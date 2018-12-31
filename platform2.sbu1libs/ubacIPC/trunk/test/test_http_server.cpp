#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include <mcheck.h>
#include "HTTPServer.h"

using namespace UBACIPC;

int printUsage1(string tag)
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("%s -- Max RSS - %ld\n", tag.c_str() ,usage.ru_maxrss);
}

class MyHTTPListner:
	public HTTPListner
{
	public:
        char array[1024 * 1024];
		MyHTTPListner() {};
		~MyHTTPListner() {};

        void onGetRequest(HTTPServerRequest * request, HTTPConnection * client)
        {
            onPostRequest(request, client);
        }

		void onPostRequest(HTTPServerRequest * request, HTTPConnection *client)
		{
			cout << "MyWebService onPostRequest " << endl;
            cout << "HTTPServerRequest " << request->url << " : " 
                                         << request->queryParams << endl;
            
//            stringstream ss;
//            for(int i = 0; i < 1024 * 10; i++)
//                ss << 1;

			HTTPResponse httpResponse(HTTPResponse::ok);
//			httpResponse.setContent(ss.str());
			httpResponse.setContent("Hello world");
//          string response = "Hello World";
//          string response = "Hello World I am not send";
//          client->writen(client->descriptor, response.c_str(), response.length());
//          write(client->descriptor, response.c_str(), response.length() );

			client->send(httpResponse);
            client->release();
		}
};


int main()
{
	EventFax * fax = new EventFax();

	MyHTTPListner * httpListner = new MyHTTPListner();

	HTTPServer * h = new HTTPServer(30002, fax, httpListner);

	fax->addTCPServer(h);

	fax->run();
}
// g++ -I include/ test/test_http_server.cpp  src/* -lpthread -l:libubacutils.so.1.2.2 -l:libubacsslinterface.so.1.2.2 -lssl
