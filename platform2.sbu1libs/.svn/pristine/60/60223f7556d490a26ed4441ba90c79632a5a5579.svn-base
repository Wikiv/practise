#include "HTTPRequest.h"

static unsigned long id_callback()
{
	return ((unsigned long) pthread_self());
}

static void locking_callback(int mode, int type, const char *file, int line)
{
	static Mutex curl_mutex[CRYPTO_NUM_LOCKS];
//	if( mode & CRYPTO_WRITE ) {
//	} else if( mode & CRYPTO_READ ) {
//	} else 
	if( mode & CRYPTO_LOCK ) {
		curl_mutex[type].lock();
	} else {
		curl_mutex[type].unlock();
	}
}

static int debug_request(CURL *handle, curl_infotype type, char *data, size_t size, void *userp)
{
	string stringData;
	bool isIncomingHeader = false;
	switch(type) {
		case CURLINFO_HEADER_OUT: stringData.append("Header out: "); break;
		case CURLINFO_DATA_OUT: stringData.append("Data out: "); break;
		case CURLINFO_HEADER_IN: stringData.append("Header in: "); isIncomingHeader = true; break;
		case CURLINFO_DATA_IN: stringData.append("Data in: "); break;
		case CURLINFO_TEXT: stringData.append("Text: "); break;
		case CURLINFO_SSL_DATA_OUT: stringData.append("SSL Out: "); break;
		case CURLINFO_SSL_DATA_IN: stringData.append("SSL In: "); break;
		case CURLINFO_END: stringData.append("Info end: "); break;
	}
	stringData.append( data, size );
	HTTPRequest *httpRequest = static_cast<HTTPRequest *>(userp);
	if( httpRequest->bDebugMode ) {
		cout << stringData << endl;
		httpRequest->printDebugData(stringData);
	}
	if( isIncomingHeader )
		httpRequest->handleIncomingHeader( string(data, size) );
	return 0;
}

static size_t write_header_callback(void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;
	HTTPRequest *httpRequest = static_cast<HTTPRequest *>(data);
	return httpRequest->copyToHeader(ptr, realsize);
}

static size_t read_callback(void *ptr, size_t size, size_t nmemb, void *stream)
{
	HTTPRequest *http = static_cast<HTTPRequest *>(stream);
	string sData;
	http->getPutData(sData);
	memcpy(ptr, sData.c_str(), sData.length());
	return sData.length();
}

static size_t write_body_callback(void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;
	HTTPRequest *httpRequest = static_cast<HTTPRequest *>(data);
	return httpRequest->copyToBody(ptr, realsize);
}

HTTPRequest::HTTPRequest()
{
	mMutex = new Mutex();

	uRetryCount = 1;
	sLogID = NULL;
	headerList = NULL;
	header.ptr = body.ptr = NULL;
	header.length = body.length = 0;

	c_handle = curl_easy_init();
	multi_handle = curl_multi_init();
	//curl_multi_add_handle( multi_handle, c_handle );

	if( !c_handle ) {
		Exceptions curlException;
		curlException.setMessage("Unable to create a CURL easy handle.");
		throw curlException;
	}
	curl_easy_setopt(c_handle, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(c_handle, CURLOPT_ERRORBUFFER, errorBuffer);
	curl_easy_setopt(c_handle, CURLOPT_NOSIGNAL , NO_SIGNAL);
	curl_easy_setopt(c_handle, CURLOPT_USERAGENT, "libcurl/1.0");
	curl_easy_setopt(c_handle, CURLOPT_HEADERFUNCTION, write_header_callback);
	curl_easy_setopt(c_handle, CURLOPT_WRITEHEADER, this);
	curl_easy_setopt(c_handle, CURLOPT_WRITEFUNCTION, write_body_callback);
	curl_easy_setopt(c_handle, CURLOPT_WRITEDATA, this);
	curl_easy_setopt(c_handle, CURLOPT_DNS_CACHE_TIMEOUT, 0);
	//curl_easy_setopt(c_handle, CURLOPT_VERBOSE, 1);
	curl_easy_setopt(c_handle, CURLOPT_DEBUGFUNCTION, debug_request);
	curl_easy_setopt(c_handle, CURLOPT_DEBUGDATA, this);

	CRYPTO_set_locking_callback(locking_callback);
	CRYPTO_set_id_callback(id_callback);
}

HTTPRequest::~HTTPRequest()
{
	reset();
    resetHeader();
	curl_easy_cleanup( c_handle );
	curl_multi_cleanup( multi_handle );
	delete mMutex;
}

void HTTPRequest::handleIncomingHeader( string sHeader )
{
	IFHelper helper;
	vector<string>lines;
	helper.split(sHeader, "\n", lines);
	for(size_t i = 0; i < lines.size(); i++) {
		vector<string>nvpairs;
		helper.split(lines[i], ":", nvpairs);
		if( nvpairs.size() == 2 ) {
			headerMap[nvpairs[0]] = nvpairs[1];
		}
	}
}

void HTTPRequest::setRetryCount(uint8_t uRetryCount)
{
	this->uRetryCount = uRetryCount;
}

void HTTPRequest::printDebugData(string sData)
{
	if(sLogID) 
		sLogID->debug("%s\n", sData.c_str());
}

size_t HTTPRequest::copyToBody(void *ptr, size_t size)
{
	body.ptr = (char *)MY_REALLOC(body.ptr, body.length + size + 1);
	if( body.ptr ) {
		memcpy( ((char *)body.ptr + body.length), ptr, size );
		body.length += size;
		char c = '\0';
		memcpy( ((char *)body.ptr + body.length), &c, 1);
		return size;
	}
	return 0;
}

void HTTPRequest::use_ssl(bool flag)
{
	if( c_handle && flag )
		curl_easy_setopt(c_handle, CURLOPT_SSL_VERIFYPEER, 0L);
}

void HTTPRequest::resetErrorBuffer()
{
	memset(errorBuffer, '\0', sizeof(errorBuffer));
}

void HTTPRequest::basicAuthentication(string username, string password)
{
	string userpwd(username);
	userpwd.append( ":" );
	userpwd.append( password );
	if( c_handle )
		curl_easy_setopt(c_handle, CURLOPT_USERPWD, userpwd.c_str());
}

void HTTPRequest::setVerbose(SLog *mLogID)
{
	sLogID = mLogID;
	bDebugMode = true;
}

void HTTPRequest::setDebugMode(SLog *mLogID)
{
	sLogID = mLogID;
	bDebugMode = true;
}

void HTTPRequest::resetHeader()
{
	if( headerList ) 
		curl_slist_free_all( headerList );
	headerList = NULL;
}

void HTTPRequest::setHeader(vector<string>m_headerList)
{
	if( !c_handle ) return;
	vector<string>::iterator iHeader = m_headerList.begin();
	while( iHeader != m_headerList.end() ) {
		headerList = curl_slist_append(headerList, (*iHeader).c_str());
		iHeader++;
	}
	curl_easy_setopt(c_handle, CURLOPT_HTTPHEADER, headerList);
}

void HTTPRequest::setHeader(string m_header)
{
	if( c_handle ) {
		headerList = curl_slist_append(headerList, m_header.c_str());
		curl_easy_setopt(c_handle, CURLOPT_HTTPHEADER, headerList);
	}
}

size_t HTTPRequest::copyToHeader(void *ptr, size_t size)
{
	header.ptr = (char *)MY_REALLOC(header.ptr, header.length + size + 1);
	if( header.ptr ) {
		memcpy( ((char *)header.ptr + header.length), ptr, size );
		header.length += size;
		char c = '\0';
		memcpy( ((char *)header.ptr + header.length), &c, 1 );
		return size;
	}
	return 0;
}

void HTTPRequest::getHeader(string & m_header)
{
	if( (header.length > 0) && (header.ptr != NULL) ) 
		m_header.append( (char*)header.ptr, header.length );
}

void HTTPRequest::getBody(string & m_body)
{
	if( (body.length > 0) && (body.ptr != NULL) ) 
		m_body.append( (char*)body.ptr, body.length );
}

void HTTPRequest::getBody(void **ptr, size_t *len)
{
	if( ( body.length > 0 ) && ( body.ptr != NULL) ) {
		*ptr = ( void * ) body.ptr;
		*len = body.length;
	}
}

void HTTPRequest::getError(string & m_error)
{
	if( strlen(errorBuffer) > 0 )
		m_error.append(errorBuffer);
}

void HTTPRequest::setCookieFile(string m_cookieFileName)
{
	cookieFileName.clear();
	cookieFileName.append( m_cookieFileName );
	if( !c_handle )
		return;

	curl_easy_setopt(c_handle, CURLOPT_COOKIEJAR, cookieFileName.c_str());
	curl_easy_setopt(c_handle, CURLOPT_COOKIEFILE, cookieFileName.c_str());
}

void HTTPRequest::setCookie(string sCookie)
{
	if( !c_handle )
		return;
	sCookieInfo = sCookie;
	curl_easy_setopt(c_handle, CURLOPT_COOKIE, sCookie.c_str());
}

void HTTPRequest::reset()
{
	if( header.ptr ) {
		free( header.ptr );
		header.ptr = NULL;
		header.length = 0;
	}
	if( body.ptr ) {
		free( body.ptr );
		body.ptr = NULL;
		body.length = 0;
	}
}

double HTTPRequest::lastRequestTime()
{
	return dLastRequestTime;
}

bool HTTPRequest::get_multi(string httpURL, time_t timeout)
{
	if( !c_handle ) 
		return false;

	if( !multi_handle )
		return false;
	
	mMutex->lock();

	curl_easy_setopt(c_handle, CURLOPT_HTTPGET, 1L);
	curl_multi_remove_handle( multi_handle, c_handle );
	curl_easy_setopt(c_handle, CURLOPT_URL, httpURL.c_str());
	curl_multi_add_handle( multi_handle, c_handle);

	mMutex->unlock();
	return get_multi(timeout);
}

bool HTTPRequest::get_multi(time_t timeout)
{

	mMutex->lock();

	reset();
	resetErrorBuffer();

	int32_t no_of_handles = 0;

	IFHelper helper;

	double startTime = helper.currentTime();
	
	int result = curl_multi_perform( multi_handle, &no_of_handles );

	struct timeval timeval_timeout = {0, 1000};

	fd_set fdread;
	fd_set fdwrite;
	fd_set fdexcep;
	int maxfd = -1;

	FD_ZERO(&fdread);
	FD_ZERO(&fdwrite);
	FD_ZERO(&fdexcep);

	curl_multi_fdset(multi_handle, &fdread, &fdwrite, &fdexcep, &maxfd);

	int rc = select(maxfd+1, &fdread, &fdwrite, &fdexcep, &timeval_timeout);

	if( rc > 0 )
		result = curl_multi_perform( multi_handle, &no_of_handles );
	dLastRequestTime = helper.currentTime() - startTime;

	mMutex->unlock();

	return (result == 0);
}

bool HTTPRequest::get(string httpURL, time_t timeout)
{
	if( !c_handle ) 
		return false;

	bool flag = false;
	IFHelper helper;

	mMutex->lock();

	for(uint8_t i = 0; i < uRetryCount; i++) {	
		reset();
		resetErrorBuffer();
		double startTime = helper.currentTime();
		curl_easy_setopt(c_handle, CURLOPT_HTTPGET, 1L);
		curl_easy_setopt(c_handle, CURLOPT_URL, httpURL.c_str());
		curl_easy_setopt(c_handle, CURLOPT_TIMEOUT, timeout);
		CURLcode result = curl_easy_perform(c_handle);
		dLastRequestTime = helper.currentTime() - startTime;
		flag = (result == 0);
		if( flag ) break;
	}
	mMutex->unlock();
	return flag;
}

bool HTTPRequest::post(string httpURL, string fields, time_t timeout)
{
	if( !c_handle )
		return false;

	bool flag = false;
	IFHelper helper;
	mMutex->lock();
	for(uint8_t i = 0; i < uRetryCount; i++) {
		reset();
		resetErrorBuffer();
		double startTime = helper.currentTime();

		CURLcode retCode, result;
		curl_easy_setopt(c_handle, CURLOPT_POST, 1L);
		curl_easy_setopt(c_handle, CURLOPT_URL, httpURL.c_str());
		retCode = curl_easy_setopt(c_handle, CURLOPT_POSTFIELDS, fields.c_str());
		if( retCode == CURLE_OK ) {
			curl_easy_setopt(c_handle, CURLOPT_TIMEOUT, timeout);
			result = curl_easy_perform(c_handle);
			if( result != CURLE_OK )
				result = retCode;
		}

		dLastRequestTime = helper.currentTime() - startTime;
		flag = (result == CURLE_OK);
		if( flag ) break;
	}
	mMutex->unlock();

	return flag;
}

void HTTPRequest::getPutData(string & sData)
{
	cout << "httpput data" << endl;
	sData.append( sPutData );
	sPutData = "";
}

bool HTTPRequest::put(string httpURL, string sData, time_t timeout)
{
	if( !c_handle )
		return false;

	sPutData = sData;

	mMutex->lock();

	reset();
	resetErrorBuffer();
	IFHelper helper;
	double startTime = helper.currentTime();

/*	resetHeader();
	vector<string>headerList;
	headerList.push_back("Content-Type: application/x-www-form-urlencoded");
*/
	curl_easy_setopt(c_handle, CURLOPT_READFUNCTION, read_callback);
	curl_easy_setopt(c_handle, CURLOPT_UPLOAD, 1L);
	curl_easy_setopt(c_handle, CURLOPT_PUT, 1L);
	curl_easy_setopt(c_handle, CURLOPT_URL, httpURL.c_str());
	curl_easy_setopt(c_handle, CURLOPT_READDATA, this);
	curl_easy_setopt(c_handle, CURLOPT_INFILESIZE_LARGE, sData.length());
	
	curl_easy_setopt(c_handle, CURLOPT_TIMEOUT, timeout);

//	setHeader( headerList );
	CURLcode result = curl_easy_perform(c_handle);

	dLastRequestTime = helper.currentTime() - startTime;

	mMutex->unlock();

	return (result == 0);
}

bool HTTPRequest::http_delete(string httpURL, time_t timeout)
{
	if( !c_handle )
		return false;

	mMutex->lock();

	reset();
	resetErrorBuffer();
	IFHelper helper;
	double startTime = helper.currentTime();

	curl_easy_setopt(c_handle, CURLOPT_CUSTOMREQUEST, "DELETE");
	curl_easy_setopt(c_handle, CURLOPT_URL, httpURL.c_str());
	curl_easy_setopt(c_handle, CURLOPT_TIMEOUT, timeout);
	CURLcode result = curl_easy_perform(c_handle);

	dLastRequestTime = helper.currentTime() - startTime;

	mMutex->unlock();

	return (result == 0);
}

string HTTPRequest::getCookieList()
{
	return sCookieInfo;
}

void HTTPRequest::getCookieList(string & sCookie)
{
	if( !c_handle )
		return;

	IFHelper helper;
	struct curl_slist *cookie_list, *tmp_cookie_list;
	curl_easy_getinfo(c_handle, CURLINFO_COOKIELIST, &cookie_list);

	tmp_cookie_list = cookie_list;
	while(tmp_cookie_list) {
		string tmpData(tmp_cookie_list->data), name, value;
		vector<string>list;
		helper.split(tmpData, "\t", list);
		name.append(list[list.size()-2]);
		value.append(list[list.size()-1]);
		sCookie.append(name); sCookie.append("="); sCookie.append(value); sCookie.append("; ");
		cout << tmp_cookie_list->data << endl;
		tmp_cookie_list = tmp_cookie_list->next;
	}
	helper.rstrip(sCookie, ' ');
	curl_slist_free_all(cookie_list);
}

string HTTPRequest::getHeaderFromMap(string sKey)
{
	string sValue = "";
	map<string, string>::iterator iMap = headerMap.find( sKey );
	if( iMap != headerMap.end() )
		sValue = iMap->second;
	return sValue;
}

void HTTPRequest::setHTTPVersion(int httpVersion)
{
        if(httpVersion == HTTPVERSION_1_0)
        {
                curl_easy_setopt(c_handle, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
        }
        else if(httpVersion == HTTPVERSION_1_1)
        {
                curl_easy_setopt(c_handle, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
        }
	else
	{
                curl_easy_setopt(c_handle, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_NONE);
	}
}
void HTTPRequest::url_encode(string & sURL)
{
        CURL *c = curl_easy_init();
        if( c ) {
                char *encoded_url = curl_easy_escape(c, sURL.c_str(), sURL.length());
                if( encoded_url ) {
                        sURL.clear();
                        sURL.append( encoded_url );
                        free(encoded_url);
                        encoded_url = NULL;
                }
                curl_easy_cleanup(c);
        }
}

int HTTPRequest::url_decode(string &sURL)
{
        CURL *c = curl_easy_init();
        int outputLength = 0;

        if( c ) {
                char * decoded_url = curl_easy_unescape(c, sURL.c_str(), sURL.length(), &outputLength);
                if ( decoded_url ) {
                        sURL.clear();
                        sURL.append( decoded_url );
                        free( decoded_url );
                        decoded_url = NULL;
                }
                curl_easy_cleanup(c);
        }
        return outputLength;
}
