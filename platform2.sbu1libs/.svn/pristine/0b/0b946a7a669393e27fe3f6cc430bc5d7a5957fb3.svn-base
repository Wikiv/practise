#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include "HTTPServer.h"

using namespace UBACIPC;

class MyWebService: 
	public WebService
{
	public:
	MyWebService(string s) : WebService(s){}

	void onPostRequest(HTTPServerRequest request, HTTPConnection *client) 
	{
		cout << "MyWebService onPostRequest " << endl;

		HTTPResponse httpResponse(HTTPResponse::ok);
		httpResponse.setContent("I am the Response");
		
		client->send(httpResponse);
	}
};

int main()
{
	MyWebService w("/init");

	HTTPServer h("30002", &w);

	h.run();
}
