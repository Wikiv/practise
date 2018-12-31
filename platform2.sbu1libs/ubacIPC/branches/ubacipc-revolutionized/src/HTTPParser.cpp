#include "HTTPClient.h"

HTTPParser::HTTPParser()
{
	crlf_count = 0;
	endOfHeader = 0;
	request = new HTTPServerRequest();
}

HTTPParser::~HTTPParser()
{
	delete request;
}

void HTTPParser::handle_packet(void *ptr, size_t len)
{
	char *s = (char *)ptr;

	for(size_t i = 0; i < len; i++) {
		char c = *(s + i);

		if (endOfHeader >= 4) {
			// storing message-body
			sBuffer.append(&c, 1);

		} else if(c == '\r') {
			// CR
			endOfHeader++;

		} else if( c == '\n' ) {
			// LF
			endOfHeader++;
			crlf_count++;

			if (sBuffer.length() > 0) {

				// got message-header parse it.
				parse(sBuffer);
				sBuffer.clear();
			}

		} else {
			// storing message-header
			sBuffer.append(&c, 1);

			if( endOfHeader < 4 )
				endOfHeader = 0;
		}
	}

	if( endOfHeader >= 4 ) {
		size_t contentLen = (size_t) atoi(
								request->headers["Content-Length"].c_str() );

		// TODO Should check for contentLen > sBuffer.length() and throw error
		if ( contentLen <= sBuffer.length() ) {
			request->sContent = sBuffer;
			onRequest(request);

			sBuffer.clear();

			crlf_count = 0;
			endOfHeader = 0;

		}
	}
}

void HTTPParser::parseMethod(string line)
{
	int state = 0;
	string sMethod, sPath, sHTTP;

	for(size_t i = 0; i < line.length(); i++) {
		if( line[i] == ' ' ) {
			state++;

		} else {
			switch(state) {
			case 0:
				sMethod.append(&line[i], 1);
				break;

			case 1:
				sPath.append(&line[i], 1);
				break;

			default:
				sHTTP.append(&line[i], 1);
				break;
			}
		}
	}

	request->sMethod = sMethod;
	request->sHttpVersion = sHTTP;
    parsePath( sPath );
}

void HTTPParser::parseOthers(string line)
{
	int state = 0;
	string sHeaderKey, sHeaderValue;

	for(size_t i = 0; i < line.length(); i++) {
		if( (line[i] == ':') && (state == 0) ) {
			state++;

		} else {
			if( state == 0 ) {
				sHeaderKey.append(&line[i], 1);

			} else {
				if( !((sHeaderValue.length() == 0) && (line[i] == ' ')) )
					sHeaderValue.append(&line[i], 1);
			}
		}
	}

	request->headers[sHeaderKey] = sHeaderValue;

	if( line == "Expect: 100-continue" ) {
		onHeaderExpectContinue(sHeaderKey, sHeaderValue, request->sHttpVersion);
	}
}

void HTTPParser::parse(string line)
{
	if( crlf_count == 1 ) {
		parseMethod(line);

	} else {
		parseOthers(line);
	}
}

void HTTPParser::parsePath(string & path)
{
    string url, queryParams;
    size_t state = 0;

    for(size_t i = 0; i < path.length(); i++)
    {
        if ( path[i] == '?')
            state++;

        else {
            switch(state)
            {
            case 0:
                url.append( &path[i], 1);
                break;
            case 1:
                queryParams.append( &path[i], 1);
                break;
            }

        }
    }

    request->url = url;
    request->queryParams = queryParams;
}
