#include <ubachttpclient/HTTPRequest.h>

int main(int argc, char *argv[])
{
	HTTPRequest request;
	string req("http://www.google.com");	
	bool status = request.get(req, 10) ;

	if ( status ) {
		string response("");
	        request.getBody(response ) ;
		cout << response << endl;
	}	
	return 0;
}
