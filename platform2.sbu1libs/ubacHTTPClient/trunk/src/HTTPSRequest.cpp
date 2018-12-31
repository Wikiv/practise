#include "HTTPSRequest.h"

HTTPSRequest::HTTPSRequest()
{
	if(c_handle) {
		curl_easy_setopt(c_handle, CURLOPT_SSL_VERIFYPEER, 0L);
	}
}

HTTPSRequest::~HTTPSRequest()
{
}

void HTTPSRequest::disableVerifyCertificate()
{
	curl_easy_setopt(c_handle, CURLOPT_SSL_VERIFYHOST, 0L);
}

void HTTPSRequest::enableVerifyCertificate()
{
	curl_easy_setopt(c_handle, CURLOPT_SSL_VERIFYHOST, 1L);
}

void HTTPSRequest::enableVerifyPeer()
{
	curl_easy_setopt(c_handle, CURLOPT_SSL_VERIFYPEER, 1L);
}

void HTTPSRequest::disableVerifyPeer()
{
	curl_easy_setopt(c_handle, CURLOPT_SSL_VERIFYPEER, 0L);
}
