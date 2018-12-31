#include "IFHelper.h"

IFHelper::IFHelper()
{
}

IFHelper::~IFHelper()
{
}

int IFHelper::isLeap( int year)
{
	if( year%100 == 0 ) {
		return ( year%400 == 0 );
	}
	return (year%4 == 0);
}

bool IFHelper::isDST()
{
	int isDst = -1;
#ifdef WIN32
	_tzset();
    _get_daylight( &isDst );
#else
	struct tm * tmTime = new tm;
	tmTime->tm_isdst = 1;
	mktime(tmTime);
	isDst = tmTime->tm_isdst;
	delete tmTime;
#endif
	return (isDst != 0);
}

uint32_t IFHelper::getChartsRefreshTime(string sResolution){
	/*
	 * Supported durations n:MIN, n:HOUR, n:DAY, n:WEEK, n:MON
       	 * Returns the refresh time in seconds.
	 */

	vector<string>resList;
	split(sResolution, ":", resList);
	string sInterval = resList[1];

	uint32_t multiplier = 60;// MIN as default...
	uint32_t n = atoi(resList[0].c_str());

	if (sInterval.compare("MIN") == 0){
		multiplier *=1;		
	} else if (sInterval.compare("HOUR") == 0){
		multiplier *= 60;
	} else if (sInterval.compare("DAY") == 0) {
		multiplier *= 60;
		multiplier *= 24;
	} else if (sInterval.compare("WEEK") == 0){
		multiplier *= 60;
		multiplier *= 24;
		multiplier *= 7;
	} else if (sInterval.compare("MON") == 0) {
		multiplier *= 60;
		multiplier *= 24;
		multiplier *= 30;
	} 

	multiplier *= n;
	time_t t = time(NULL);
	uint32_t refresh_time = multiplier - t%multiplier;
	return refresh_time;	
}

void IFHelper::join(vector<string> input, char c_join_delimiter, string & sResponse)
{
	vector<string>::iterator iInput = input.begin();
	while(iInput != input.end()) {
		sResponse.append( *iInput );
		sResponse.append(&c_join_delimiter, 1);
		iInput++;
	}
	rstrip(sResponse, c_join_delimiter);
}

void IFHelper::gsubSpecialCharacters( string & data )
{
	string tmpStr("");
	for(size_t i = 0; i < data.length(); i++) {
		if ( data[i] == '<' ) {
			tmpStr.append(":lt");
		} else if ( data[i] == '>' ) {
			tmpStr.append(":gt");
		} else if ( data[i] == '\'' ) {
			tmpStr.append(":sqt");
		//} else if ( data[i] == ':' ) {
		//	tmpStr.append(":col");
		} else if ( data[i] == ';' ) {
			tmpStr.append(":scol");
		} else if ( data[i] == '&' ) {
			tmpStr.append(":amp");
		} else if ( data[i] == ',' ) {
			tmpStr.append(":comma");
		} else if ( data[i] == '(' ) {
			tmpStr.append(":lp");
		} else if ( data[i] == ')' ) {
			tmpStr.append(":rp");
		} else if ( data[i] == '{' ) {
			tmpStr.append(":lb");
		} else if ( data[i] == '}' ) {
			tmpStr.append(":rb");
		} else if ( data[i] == '[' ) {
			tmpStr.append(":lsq");
		} else if ( data[i] == ']' ) {
			tmpStr.append(":rsq");
		} else if ( data[i] == '#' ) {
			tmpStr.append(":hash");
		} else if ( data[i] == '|' ) {
			tmpStr.append(":pipe");
		} else if ( data[i] == '=' ) {
			tmpStr.append(":eq");
		} else if ( data[i] == '~' ) {
			tmpStr.append(":til");
		} else if ( data[i] == '\n' ) {
			tmpStr.append(":nl");
		} else if ( data[i] == '/') {
			tmpStr.append(":slash"); 
		} else {
			tmpStr.append(&data[i], 1);
		}
	}
	data.clear();
	data.append( tmpStr );
}


int IFHelper::getNoOfDays( int mYear )
{
	int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int noOfDays = 0;
	int year = 1900;
	time_t t = time(NULL);
	struct tm start;
#ifdef WIN32
#ifdef _USE_32BIT_TIME_T
	_localtime32_s(&start, &t);
#else
	localtime_s(&start, &t);
#endif
#else
	localtime_r(&t, &start);
#endif

	while( year < (start.tm_year + 1900)) {
		int i;
		int bIsLeap = isLeap(year);
		for(i = 0; i < 12;i++) {
			if( (i == 1) && bIsLeap ) {
				noOfDays += daysPerMonth[i] + 1;
			} else {
				noOfDays += daysPerMonth[i];
			}
		}
		year++;
		if ( year == mYear ) {
			break;
		}
	}
	return noOfDays;

}

void IFHelper::getTimeFromNoOfDays(int noOfDays, int year, struct tm *histDate)
{
	int noOfDaysSinceYear = ( noOfDays - getNoOfDays( year ) );
	time_t inSeconds = (noOfDaysSinceYear * 24 * 3600);
#ifdef WIN32
#ifdef _USE_32BIT_TIME_T
	_localtime32_s(histDate, &inSeconds);
#else
	localtime_s(histDate, &inSeconds);
#endif
#else
	localtime_r(&inSeconds, histDate);
#endif
}

bool IFHelper::readFile(string sFileName, string & sFileContent)
{
	bool flag = false;
#ifdef WIN32
	int fd = _open(sFileName.c_str(), O_RDONLY);
#else
	int fd = open(sFileName.c_str(), O_RDONLY);
#endif
	if( fd > 0 ) {
		struct stat stat_buf;
		memset(&stat_buf, '\0', sizeof(struct stat));
		fstat(fd, &stat_buf);
		char *buffer = (char *)calloc(1, stat_buf.st_size);
		if( buffer ) {
			flag = true;
#ifdef WIN32
			_read(fd, buffer, stat_buf.st_size);
#else
			read(fd, buffer, stat_buf.st_size);
#endif
			sFileContent.append( buffer, stat_buf.st_size );
			free(buffer);
			buffer = NULL;
		}
	}
#ifdef WIN32
	_close(fd);
#else
	close(fd);
#endif
	return flag;
}

void IFHelper::gsub(string & data, string strFrom, string strTo)
{
	string tmpData;
	vector<string>splitList;
	split(data, strFrom, splitList);
	for(size_t i = 0; i < splitList.size(); i++) {
		tmpData.append( splitList[i] );
		if (  (i+1) < splitList.size() ) 
			tmpData.append( strTo );
	}
	data.clear();
	data.append( tmpData );
}

void IFHelper::substitute(string & data, string strFrom, string strTo)
{
	string tmpData;
	vector<string>splitList;
	split(data, strFrom, splitList);
	for(size_t i = 0; i < splitList.size(); i++) {
		tmpData.append( splitList[i] );
		if ( ( (i+1) <= splitList.size() ) && ( tmpData.length() < data.length() ) )
			tmpData.append( strTo );
	}
	data.clear();
	data.append( tmpData );
}

void IFHelper::substitute(string & data, char charFrom, string strTo)
{
	string tmpData;
	for(size_t i = 0; i < data.length(); i++) {
		if( data[i] == charFrom ) {
			tmpData.append( strTo );
		} else {
			tmpData.append(&data[i], 1);
		}
	}
	data.clear();
	data.append( tmpData );
}

double IFHelper::currentTime()
{
	struct timeval time_now;
	memset(&time_now, '\0', sizeof(struct timeval));
#ifdef _WIN32
	SYSTEMTIME s;
	GetSystemTime(&s);
	struct tm tmTime;
	memset(&tmTime, '\0', sizeof(struct tm));
	tmTime.tm_hour = s.wHour;
	tmTime.tm_min = s.wMinute;
	tmTime.tm_sec = s.wSecond;
	tmTime.tm_year = s.wYear;
	tmTime.tm_mon = s.wMonth;
	tmTime.tm_mday = s.wDay;
	time_t epoch_time = mktime(&tmTime);
	double dTimeNow = (double)epoch_time + s.wMilliseconds/1000.0;
#else
	gettimeofday(&time_now, NULL);
	double dTimeNow = (double)time_now.tv_sec + ((double)time_now.tv_usec/1000000.0);
#endif
	return dTimeNow;
}

void IFHelper::substitute(string & data, char charFrom, char charTo)
{
	string tmpData;
	for(size_t i = 0; i < data.length(); i++) {
		if( data[i] == charFrom ) {
			tmpData.append(&charTo, 1);
		} else {
			tmpData.append(&data[i], 1);
		}
	}
	data.clear();
	data.append( tmpData );
}

void IFHelper::parseTime(string dateString, string format, struct tm *tmTime)
{
#ifdef _WIN32
#else
	strptime(dateString.c_str(), format.c_str(), tmTime);
#endif
}

void IFHelper::sleep(uint32_t timeInSeconds)
{
	struct timeval timeToSleep = {timeInSeconds, 0};
	select(1, NULL, NULL, NULL, &timeToSleep);
}

void IFHelper::usleep(uint32_t timeInMilliseconds)
{
	uint32_t time_second = timeInMilliseconds/1000;
	uint32_t time_micro_second = (timeInMilliseconds*1000)%1000000;
	struct timeval timeToSleep = {time_second, time_micro_second};
	select(1, NULL, NULL, NULL, &timeToSleep);
}

void IFHelper::capitalize(string & value)
{
	string tmp;
	for(size_t i = 0 ; i < value.length(); i++) {
		if( isupper(value[i]) > 0 ) {
			if(tmp.length() > 0)
				tmp.append(" ");
		}
		tmp.append(&value[i], 1);
	}
	value.clear();
	value.append( tmp );
}

void IFHelper::htmlToText( string & htmlData )
{
	string tmpBuf, splCharacter;
	bool isSplChracter=false, isTag=false, isHref=false;
	for(size_t i = 0;i < htmlData.length(); i++) {
		if ( isSplChracter )
			splCharacter.append(&htmlData[i], 1);
		if ( htmlData[i] == '&'  ) {
			splCharacter.append(&htmlData[i], 1);
			isSplChracter = true;
		} else if(htmlData[i] == '<') {
			isHref=true;
		} else if(htmlData[i] == '>') {
			isHref=false;
			tmpBuf.append(" ");
		} else if ( htmlData[i] == ';' ) {
			if ( strcasecmp( splCharacter.c_str() , "&lt;" ) == 0 ) {
				isTag = true;
				splCharacter.clear();
			} else if ( strcasecmp( splCharacter.c_str() , "&gt;" ) == 0 ) {
				tmpBuf.append(" ");
				isTag = false;
				splCharacter.clear();
			}
			isSplChracter = false;
		} else {
			if ( ( !isHref ) && ( !isSplChracter ) && ( !isTag ) )
				tmpBuf.append(&htmlData[i], 1);
		}
	}
	htmlData.clear();
	htmlData.append( tmpBuf );
}

void IFHelper::parseTime(string dateString, string format, time_t *t_time)
{
	struct tm tmTime;
	memset(&tmTime, '\0', sizeof(struct tm));
	parseTime(dateString, format, &tmTime);
	tmTime.tm_isdst = -1;
	*t_time = mktime(&tmTime);
}

void IFHelper::lowercase(string & data)
{
	string tmp;
	for(size_t i = 0; i < data.length(); i++) {
		char c = tolower(data[i]);
		tmp.append(&c, 1);
	}
	data.clear();
	data.append(tmp);
}

void IFHelper::upcase(string & data)
{
	string tmp;
	for(size_t i = 0; i < data.length(); i++) {
		char c = toupper(data[i]);
		tmp.append(&c, 1);
	}
	data.clear();
	data.append(tmp);
}

void IFHelper::split(string data, string pattern, vector<string> & list)
{
	string tmp, tmpPattern;
	bool isMatched = false;
	for(size_t i = 0, j = 0; i < data.length(); i++) {
		if( data[i] == pattern[j] ) {
			isMatched = true;
			tmpPattern.append(&data[i], 1);
			j++;
		} else {
			isMatched = false;
			if( tmpPattern != pattern )
				tmp.append( tmpPattern );
			tmpPattern.clear();
			j = 0;
			tmp.append(&data[i], 1);
		}
		if( isMatched ) {
			if( j == pattern.length() ) {
				list.push_back(tmp);
				tmp.clear();
				j = 0;
				tmpPattern.clear();
			}
		}
	}
	if( isMatched || (tmp.length() > 0) ) {
		list.push_back( tmp );
	}
}

void IFHelper::formatTime(struct tm *tmTime, const char *format, string & formattedTime)
{
	char timeBuf[1024] = {'\0'};
	strftime(timeBuf, sizeof(timeBuf), format, tmTime);
	formattedTime.append(timeBuf);
}

void IFHelper::formatTime(time_t time, const char *format, string & formattedTime)
{
	struct tm tmTime;
	memset(&tmTime, '\0', sizeof(struct tm));
#ifdef _WIN32
#ifdef _USE_32BIT_TIME_T
	_localtime32_s(&tmTime, &time);
#else
	localtime_s(&tmTime, &time);
#endif
#else
	localtime_r(&time, &tmTime);
#endif
	formatTime( &tmTime, format, formattedTime );
}

void IFHelper::currentTime(const char *format, string & formattedTime)
{
	time_t t = time(NULL);
	formatTime(t, format, formattedTime);
}

void IFHelper::logTime(string & formattedTime)
{
	struct timeval tv;
	memset(&tv, '\0', sizeof(struct timeval));
#ifdef _WIN32
	SYSTEMTIME sysTime;
	GetSystemTime( &sysTime );
	char time_buf[128] = {'\0'};
	struct tm tmTime;
	memset(&tmTime, '\0', sizeof(struct tm));
	convertSYSTEMTIMEToStructTM(sysTime, &tmTime);
	strftime(time_buf, sizeof(time_buf), "%Y/%m/%d %H:%M:%S", &tmTime);
	formattedTime.append(time_buf);
	memset(time_buf, '\0', sizeof(time_buf));
	sprintf_s(time_buf, "%.03f", sysTime.wMilliseconds);
	formattedTime.append(time_buf);
#else
	gettimeofday(&tv, NULL);
	formatTime( tv.tv_sec, "%Y-%m-%d %H:%M:%S", formattedTime );
	char c_micro_secs[16] = {'\0'};
	sprintf(c_micro_secs, ".%06lu", tv.tv_usec);
	formattedTime.append( c_micro_secs );
#endif
}

void IFHelper::lstrip(string & data, char c, int noOfStrips)
{
	int i = 0;
	string::iterator iString = data.begin();
	while( 1 ) {
		if( data.length() == 0 )
			break;
		if ( *iString == c ) {
			data.erase( iString );
			if( (noOfStrips > 0) && ( ++i == noOfStrips ) )
				break;
			iString = data.begin();
		} else {
			break;
		}
	}
}

void IFHelper::rstrip(string & data, char c, int noOfStrips)
{
	int i = 0;
	string::iterator iString = data.end();
	while( 1 ) {
		if( data.length() == 0 )
			break;
		iString--;
		if( *iString == c ) {
			data.erase( iString );
			if( (noOfStrips > 0) && (++i == noOfStrips) )
				break;
			iString = data.end();
		} else {
			break;
		}
	}
}

#ifdef _WIN32
void IFHelper::convertSYSTEMTIMEToStructTM(SYSTEMTIME sysTime, struct tm *tmTime)
{
	tmTime->tm_hour = sysTime.wHour;
	tmTime->tm_mday = sysTime.wDay;
	tmTime->tm_min = sysTime.wMinute;
	tmTime->tm_year = sysTime.wYear - 1900;
	tmTime->tm_mon = sysTime.wMonth - 1;
	tmTime->tm_sec = sysTime.wSecond;
}
#endif

int32_t IFHelper::getLocalTimeOffset()
{
#ifdef _WIN32
	SYSTEMTIME sysLocalTime, sysGMTime;
	GetSystemTime(&sysGMTime);
	GetLocalTime(&sysLocalTime);
	struct tm tmLocalTime, tmGMTime;
	memset(&tmLocalTime, '\0', sizeof(struct tm));
	memset(&tmGMTime, '\0', sizeof(struct tm));
	convertSYSTEMTIMEToStructTM(sysLocalTime, &tmLocalTime);
	convertSYSTEMTIMEToStructTM(sysGMTime, &tmGMTime);
	int32_t time_offset = (int32_t)(mktime(&tmLocalTime) - mktime(&tmGMTime));
	return time_offset;
#else
	struct tm tmTime;
	memset(&tmTime, '\0', sizeof(struct tm));
	time_t t = time(NULL);
	localtime_r(&t, &tmTime);
	return (-1*tmTime.tm_gmtoff);
#endif
}

time_t IFHelper::getGMTime()
{
	time_t t = time(NULL);
	struct tm tmpTime;
	memset(&tmpTime, '\0', sizeof(struct tm));
#ifdef _WIN32
	//TODO: Find an alternative here.
	gmtime_s(&tmpTime, &t);
	return 0;
#else
	localtime_r(&t, &tmpTime);
	return (t - tmpTime.tm_gmtoff);
#endif
}

string IFHelper::formatDouble(double d_value)
{
    char buffer[1024] = {'\0'};
    size_t len = sprintf(buffer, "%f", d_value);
    size_t j = len;
    while(j > 0 && buffer[j - 1] == '0') { j--; }   
    if (len != j && buffer[j - 1] == '.') { j--; }
    string s(buffer, 0, j); 
    return s;
}

string IFHelper::formatDouble(double d_value, int noOfDecimals)
{
	stringstream sField;
	sField.setf(ios::fixed, ios::floatfield);
	sField.precision( noOfDecimals );
	sField << d_value;
	string res(sField.str());
	if (atof(sField.str().c_str())==0){
		gsub(res,"-","");
	}
	return res;
}

void IFHelper::formatDouble(double d_value, string & formattedValue, int noOfDecimals)
{
	char tmpFormattedOutput[128] = {'\0'};
	stringstream formatStream;
	formatStream << "%." << noOfDecimals << "f";
#ifdef _WIN32
	sprintf_s(tmpFormattedOutput, formatStream.str().c_str(), d_value);
#else
	sprintf(tmpFormattedOutput, formatStream.str().c_str(), d_value);
#endif
	formattedValue.clear();
	formattedValue.append( tmpFormattedOutput );
	
	if (atof(formattedValue.c_str())==0){
	       gsub(formattedValue,"-","");
	}
}

void IFHelper::formatFloatWithComma(string & data)
{
    if(data.length() == 0) 
        return;

	string tmpBuf, sSign;

    char signBit = data.at(0);
    if (signBit == '-' || signBit == '+')
    {
        lstrip(data, signBit);
        sSign.append(& signBit, 1);
    }

	const char *dotPos = strstr(data.c_str(), ".");
	bool hasDot = (dotPos != NULL);
	if( hasDot )
		tmpBuf.append(dotPos);
	int intLength = data.length() - (( hasDot ) ? strlen(dotPos) : 0) - 1;
	int commaPos = 0;
	for(int i = intLength; i != -1 ; i--) {
		tmpBuf.insert(tmpBuf.begin(), data[i]);
		commaPos++;
		if( commaPos == 3 ) {
			tmpBuf.insert(0, ",");
			commaPos = 0;
		}
	}

	data.clear();
	lstrip(tmpBuf, ',');
    data.append(sSign);
	data.append(tmpBuf);
}

uint32_t IFHelper::readU32(void * & data)
{
	uint32_t *ptr = (uint32_t *)data;
	uint32_t value = (uint32_t)ntohl( *ptr );
	ptr++;
	data = ptr;
	return value;
}

int32_t IFHelper::readI32(void * & data)
{
	uint32_t *ptr = (uint32_t *)data;
	uint32_t value = (uint32_t)ntohl( *ptr );
	ptr++;
	data = ptr;
	return (int32_t)value;
}

uint16_t IFHelper::readU16(void * & data)
{
	uint16_t *ptr = (uint16_t *)data;
	uint16_t value = (uint16_t)ntohs( *ptr );
	ptr++;
	data = ptr;
	return value;
}

int16_t IFHelper::readI16(void * & data)
{
	uint16_t *ptr = (uint16_t *)data;
	uint16_t value = (uint16_t)ntohs( *ptr );
	ptr++;
	data = ptr;
	return (int16_t)value;
}

int8_t IFHelper::readByte(void * & data)
{
        uint8_t *ptr = (uint8_t *)data;
        uint8_t value = (uint8_t)( *ptr );
        ptr++;
        data = ptr;
        return (int8_t)value;
}


double IFHelper::readDouble(void * & data)
{
	uint64_t *ptr = (uint64_t *)data;
#if ( (__GNUC__ == 4) && (__GNUC_MINOR__ == 3) && (__GNUC_PATCHLEVEL__ > 2) )
	uint64_t value = be64toh( *ptr );
#elif __BYTE_ORDER == __LITTLE_ENDIAN
	uint64_t value = bswap_64( *ptr );
#else
	uint64_t value = *ptr;
#endif
	ptr++;
	data = ptr;
	double *dptr = (double *)&value;
	return *dptr;
}

uint64_t IFHelper::readU64(void * & data)
{
	uint64_t *ptr = (uint64_t *)data;
#if ( (__GNUC__ == 4) && (__GNUC_MINOR__ == 3) && (__GNUC_PATCHLEVEL__ > 2) )
        uint64_t value = be64toh( *ptr );
#elif __BYTE_ORDER == __LITTLE_ENDIAN
        uint64_t value = bswap_64( *ptr );
#else
        uint64_t value = *ptr;
#endif
        ptr++;
        data = ptr;
	return value;
}

string IFHelper::getLogAppender(int argc, char *argv[])
{
	stringstream sAppender;
	if( argc > 1) {
		sAppender << argv[1];
	} else {
#ifdef WIN32
		sAppender << GetCurrentProcessId();
#else
		sAppender << getpid();
#endif
	}
	return sAppender.str();
}

/*void IFHelper::appendProperty(string sPropertyName, Properties  & property, string sLogAppender)
{
	string sLogFilename;
	property.getProperty(sPropertyName, sLogFilename);
	sLogFilename.append( "."  + sLogAppender );
	property.setProperty(sPropertyName, sLogFilename);
}*/

string IFHelper::getPWD(const char *c_progname, const char *c_path)
{
	stringstream sPWD;
	string sData(c_progname);
	vector<string>sList;
	split(sData, string(c_path), sList);
	sPWD << sList[0] << "/";

	return sPWD.str();
}

int IFHelper::getWeekOfMonth(time_t t)
{
	struct tm tm1, tm2;
	memset(&tm1, '\0', sizeof(struct tm));
	memset(&tm2, '\0', sizeof(struct tm));

#ifdef WIN32
#ifdef _USE_32BIT_TIME_T
	_localtime32_s(&tm1, &t);
#else
	localtime_s(&tm1, &t);
#endif
#else
	localtime_r(&t, &tm1);
#endif
	
	time_t t_start = t - (tm1.tm_mday * 24 * 3600);
#ifdef WIN32
#ifdef _USE_32BIT_TIME_T
	_localtime32_s(&tm1, &t);
#else
	localtime_s(&tm2, &t_start);
#endif
#else
	localtime_r(&t_start, &tm2);
#endif

	tm2.tm_mday = 1;

	string sStartWeek, sCurrWeek;
	formatTime(&tm1, "%U", sCurrWeek);
	formatTime(&tm2, "%U", sStartWeek);

	cout << "Curr = " << sCurrWeek << ", Start = " << sStartWeek << endl;

	return (atoi(sCurrWeek.c_str()) - atoi(sStartWeek.c_str()));
}

#ifndef WIN32
vector<pid_t> IFHelper::waitpidNTimes()
{
	vector<pid_t> pidList;
	pid_t pid;
	do {
		int status;
		pid = waitpid(WAIT_ANY, &status, WNOHANG | WUNTRACED);
		if( pid > 0 ) {
			pidList.push_back(pid);
		}
	} while( pid > 0 );
	return pidList;
}
#endif

void IFHelper::removeInvalidEscapeChars(string & data)
{
	string sTemp = "";
	size_t j = 0, i = 1;
	for( ; i < data.length(); i++, j++ ) {
		if( (data[j] == '\\') && (isalnum( data[i] ) > 0) ) {
//			sTemp.append(&data[i], 1);
		} else {
			sTemp.append(&data[j], 1);
		}
	}
	sTemp.append(&data[j], 1);
	data = sTemp;
}

void IFHelper::greplaceSpecialCharacters( string & data )
{
	string tmpStr("");
        for(size_t i = 0; i < data.length(); i++) {
                if ((data[i] == ':') && (data[i+1] == 'l') && (data[i+2] == 't'))
                {
                        i+=2;
                        tmpStr.append("<");
                }
                else if ((data[i] == ':') && (data[i+1] == 'g') && (data[i+2] == 't'))
                {
                        i+=2;
                        tmpStr.append(">");
                }
                else if ((data[i] == ':') && (data[i+1] == 's') && (data[i+2] == 'q') && (data[i+3] == 't'))
                {
                        i += 3;
                        tmpStr.append("\'");
                }
                else if ((data[i] == ':') && (data[i+1] == 's') && (data[i+2] == 'c') && (data[i+3] == 'o') && (data[i+4] == 'l'))
                {
                        i += 4;
                        tmpStr.append(";");
                }
                else if ((data[i] == ':') && (data[i+1] == 'a') && (data[i+2] == 'm') && (data[i+3] == 'p'))
                {
                        i += 3;
                        tmpStr.append("&");
                }
                else if ((data[i] == ':') && (data[i+1] == 'c') && (data[i+2] == 'o') && (data[i+3] == 'm') && (data[i+4] == 'm') && (data[i+5] == 'a'))
                {
                        i += 5;
                        tmpStr.append(",");
                }
 		else if ((data[i] == ':') && (data[i+1] == 'l') && (data[i+2] == 'p'))
                {
                        i += 2;
                        tmpStr.append("(");
                }
                else if ((data[i] == ':') && (data[i+1] == 'r') && (data[i+2] == 'p'))
                {
                        i += 2;
                        tmpStr.append(")");
                }
                else if ((data[i] == ':') && (data[i+1] == 'l') && (data[i+2] == 'b'))
                {
                        i += 2;
                        tmpStr.append("{");
                }
                else if ((data[i] == ':') && (data[i+1] == 'r') && (data[i+2] == 'b'))
                {
                        i += 2;
                        tmpStr.append("}");
                }
                else if ((data[i] == ':') && (data[i+1] == 'l') && (data[i+2] == 's') && (data[i+3] == 'q'))
                {
                        i += 3;
                        tmpStr.append("[");
                }
                else if ((data[i] == ':') && (data[i+1] == 'r') && (data[i+2] == 's') && (data[i+3] == 'q'))
                {
                        i += 3;
                        tmpStr.append("]");
                }
		else if ((data[i] == ':') && (data[i+1] == 'h') && (data[i+2] == 'a') && (data[i+3] == 's') && (data[i+4] == 'h'))
                {
                        i += 4;
                        tmpStr.append("#");
                }
                else if ((data[i] == ':') && (data[i+1] == 'p') && (data[i+2] == 'i') && (data[i+3] == 'p') && (data[i+4] == 'e'))
                {
                        i += 4;
                        tmpStr.append("|");
                }
                else if ((data[i] == ':') && (data[i+1] == 'e') && (data[i+2] == 'q'))
                {
                        i += 2;
                        tmpStr.append("=");
                }
                else if ((data[i] == ':') && (data[i+1] == 't') && (data[i+2] == 'i') && (data[i+3] == 'l'))
                {
                        i += 3;
                        tmpStr.append("~");
                }
                else if ((data[i] == ':') && (data[i+1] == 'n') && (data[i+2] == 'l'))
                {
                        i += 2;
                        tmpStr.append("\n");
                }
                else
                {
                        tmpStr.append(&data[i], 1);
                }
        }
        data.clear();
        data.append( tmpStr );
}


