#include <iostream>

#include "SBU2StreamingRequest.h"

int main()
{
	SBU2StreamingRequest
	request("{\"request\":{\"data\":{\"symbols\":[{\"symbol\":\"AUD/IDR\"}]},\"streaming_type\":\"quote\",\"request_type\":\"unsubscribe\",\"response_format\":\"json\",\"session\":\"foo\"},\"echo\":{\"DESTINATION\":\"MOSL\"}}");

	cout << " request.isSubscribe() : "  << request.isSubscribe() << endl;
	cout << " request.isUnSubscribe() : "  << request.isUnSubscribe() << endl;

	cout << "request.getSessionID() : " << request.getSessionID() << endl;
}

// g++ -I include/ test/test_sbu2_streaming_request.cpp src/SBU2StreamingRequest.cpp -ljsonparser++
