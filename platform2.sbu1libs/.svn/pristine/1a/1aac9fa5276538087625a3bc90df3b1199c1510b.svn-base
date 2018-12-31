#ifndef __UBAC_HTTP_REQUEST_H__
#define __UBAC_HTTP_REQUEST_H__

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <stdlib.h>

#ifndef WIN32
#include <curl/curl.h>
#include <curl/easy.h>
#else
#include "curl/curl.h"
#include "curl/easy.h"
#endif

#include <ubacutils/IFHelper.h>
#include <ubacutils/Exceptions.h>
#include <ubaclogger/SLog.h>
#include <ubacipc/Mutex.h>


#define MY_REALLOC(ptr, s)              ((ptr) ? realloc(ptr, s) : calloc(1, s))

#define NO_SIGNAL			1

/** Default timeout for all HTTP requests. */
#define DEFAULT_TIMEOUT_IN_SECONDS	10

/*HTTP Version */
#define HTTPVERSION_1_0 0

#define HTTPVERSION_1_1 1

using namespace std;

/// Data structure to handle variable length binary data.
struct ubac_bytes_t {
	/// Pointer containing data.
	void *ptr;
	/// Length of the data.
	size_t length;
};

namespace UBACHTTP {
	/// Class HTTPRequest for handling webservices.
	class HTTPRequest
	{
		public:
			/// Create HTTPRequest.
			HTTPRequest();
			~HTTPRequest();

			/** Handle incoming headers. */
			void handleIncomingHeader( string sHeader );
			/** Resets the header. */
			void resetHeader();

			/** Get the headers. */
			void getHeader(string & m_header);
			/** Get the response received, after making the HTTP request. Copies the response into 'm_body'. */
			void getBody(string & m_body);
			/** Get the response received, after making the HTTP request. Copies the response into 'ptr' and sets the length.
			  * This is used in cases, when the expected response is binary instead of string. */
			void getBody(void **ptr, size_t *len);
			/** Get the error for the last HTTP request. */
			void getError(string & m_error);

			/** Sets the cookie file name as given in 'm_cookieFileName'; */
			void setCookieFile(string m_cookieFileName);

			/** Make an non-blocking HTTP GET request. Request URL will be 'httpURL' and the timeout parameter is mentioned in 'timeout.
			  * Default timeout is mentioned as DEFAULT_TIMEOUT_IN_SECONDS. */
			bool get_multi(string httpURL, time_t timeout = DEFAULT_TIMEOUT_IN_SECONDS);
			/** Use this non-blocking call if there is not change in the request. */
			bool get_multi( time_t timeout = DEFAULT_TIMEOUT_IN_SECONDS );
			/** Make an HTTP GET request. Request URL will be 'httpURL' and the timeout parameter is mentioned in 'timeout.
			  * Default timeout is mentioned as DEFAULT_TIMEOUT_IN_SECONDS. */
			bool get(string httpURL, time_t timeout = DEFAULT_TIMEOUT_IN_SECONDS);
			/** Make an HTTP POST request. Request URL will be 'httpURL', POST data in 'fields' and the timeout parameter is mentioned in 'timeout.
			  * Default timeout is mentioned as DEFAULT_TIMEOUT_IN_SECONDS. */
			bool post(string httpURL, string fields, time_t timeout = DEFAULT_TIMEOUT_IN_SECONDS);
			/** Make an HTTP DELETE call. */
			bool http_delete(string httpURL, time_t timeout = DEFAULT_TIMEOUT_IN_SECONDS);
			/** Make an HTTP PUT call. */
			bool put(string httpURL, string sData, time_t timeout = DEFAULT_TIMEOUT_IN_SECONDS);
			/** Get PUT Data */
			void getPutData(string & sData);

     	            	/** Set re-try count. */
	            	void setRetryCount(uint8_t uRetryCount);
			/** Please do not use this function. */
			size_t copyToBody(void *ptr, size_t size);
			/** Please do not use this function. */
			size_t copyToHeader(void *ptr, size_t size);

			/** Sets the header. Input is a list of headers. Each header is of the form Name: Value. 
			  * For example: 'Content-Type: xml/html'. */
			void setHeader(vector<string>headerList);
			/** Set header. 'm_header' is of the form 'Name: Value'. 
			  * For example: 'Content-Type: xml/html'. */
			void setHeader(string m_header);
			/** Set verbose mode. Prints all library backtraces to standard output. 
			  * If input 'mLogID' is non-null, the backtraces are written in to the log file
			  * pointed by 'mLogID'. */
			void setVerbose(SLog *mLogID = NULL);
			/** Set debug mode. Prints all library backtraces and the transmitted information. 
			  * If input 'mLogID' is non-null, the backtraces are written in to the log file
			  * pointed by 'mLogID'. */
			void setDebugMode(SLog *mLogID = NULL);
			/** Set the username and password for basic http authentication. */
			void basicAuthentication(string username, string password);
			/** Get the cookie information in 'sCookie'. The format will be:
			  * 'Name1: Value1; Name2: Value2;'. */
			void getCookieList(string & sCookie);
			/** Get the cookie information as stored by object. The format will be:
			  * 'Name1: Value1; Name2: Value2;'. */
			string getCookieList();
			/** Set a custom cookie. The format will be: 
			  * 'Name1: Value1; Name2: Value2;'. */
			void setCookie(string sCookie);
			/** Get the time taken for the last HTTP request. Time is in the precision of microseconds. */
			double lastRequestTime();
			
			/** Set HTTPS flag. */
			void use_ssl(bool flag = true);
			/** DONOT use this method. */
			void printDebugData(string sData);
			/** Get header. */
			string getHeaderFromMap(string sKey);
			/** Set the HTTP Version in the request */
			void setHTTPVersion(int httpVersion);
			/** Flags for verbose and debug mode. */
			bool bDebugMode;
			/** Encode the URL */
			static void url_encode(string & sURL);
			/** Decode the URL */
			static int url_decode(string &sURL);

		protected:
			/** CURL handle */
			CURL *c_handle;
			/** CURL multi handle */
			CURLM *multi_handle;

		private:
			SLog *sLogID;
			struct ubac_bytes_t header, body;
			string cookieFileName;
			string sCookieInfo;
			char errorBuffer[CURL_ERROR_SIZE];

			string sPutData;

			struct curl_slist *headerList;

			double dLastRequestTime;

			Mutex *mMutex;

			void reset();
			void resetErrorBuffer();

			map<string, string>headerMap;
			uint8_t uRetryCount;
	};
};

using namespace UBACHTTP;

#endif /* __UBAC_HTTP_REQUEST_H__ */
