#include "SLog.h"

const uint8_t SLog::Level_INFO = 0x1;
const uint8_t SLog::Level_WARN = (SLog::Level_INFO << 1);
const uint8_t SLog::Level_DEBUG = (SLog::Level_WARN << 1);
const uint8_t SLog::Level_ERROR = (SLog::Level_DEBUG << 1);
const uint8_t SLog::Level_FATAL = (SLog::Level_ERROR << 1);
const uint8_t SLog::Level_AUDIT = (SLog::Level_FATAL << 1);
const uint8_t SLog::Level_SECURE = (SLog::Level_AUDIT << 1);
const string SLog::Level_INFO_STR = "INFO";
const string SLog::Level_WARN_STR = "WARN";
const string SLog::Level_DEBUG_STR = "DEBUG";
const string SLog::Level_ERROR_STR = "ERROR";
const string SLog::Level_FATAL_STR = "FATAL";
const string SLog::Level_AUDIT_STR = "AUDIT";
const string SLog::Level_SECURE_STR = "SECURE";
const uint8_t SLog::Mode_DEVELOPMENT = 1;
const uint8_t SLog::Mode_LIVE = 2;
const uint8_t SLog::Mode_LIVE_WITH_LOCAL = 3;

SLog::SLog(struct s_logger_config config){

	this->isOrderLogging = false;
	this->yamlConfig = NULL;
	this->isCreateLogFolder = false;
	setLogMode(config.mode);
	setLogLevel( atoi(config.level.c_str()));
	logNamespace = config.name_space;
	if (atoi(config.mode.c_str())==Mode_DEVELOPMENT){
		logFileName.append(config.file_name);
		logFileName.append(".");
		logFileName.append(config.appender);
	} else {
		logFileName.append(config.file_name);
		centralLogFileName.append(config.file_name);
		sCentralLoggerIP = config.central_logger_ip;
		iCentralLoggerPort = atoi(config.central_logger_port.c_str());
	}
	sLogDir = config.dir;
	if (sLogDir.empty()){
		sLogDir = config.pwd;
	}

	init();
}

SLog::SLog(YamlConfig yamlConfig, string pwd, string sLogAppender, bool isOrderLogging)
{
	IFHelper helper;
	this->isOrderLogging = isOrderLogging;
	this->yamlConfig = new YamlConfig(yamlConfig);

/* create folder for logging */
	this->isCreateLogFolder = false;
	if ( yamlConfig["logging"]["require_log_folder"] == "true" )
		this->isCreateLogFolder = true;

	if( !this->isOrderLogging ) {
		setLogMode( (*(this->yamlConfig))["logging"]["mode"] );
		setLogLevel( atoi((*(this->yamlConfig))["logging"]["level"].c_str()) );
		logNamespace = yamlConfig["logging"]["namespace"];
		if( logMode == Mode_DEVELOPMENT ) {
			logFileName = yamlConfig["logging"]["filename"];
			if( sLogAppender.length() > 0 )
				logFileName.append("." + sLogAppender);
		} else {
			logFileName = yamlConfig["logging"]["filename"];
                        if( sLogAppender.length() > 0 )
                                logFileName.append("." + sLogAppender);
			centralLogFileName = yamlConfig["logging"]["filename"];
		}
		sLogDir = yamlConfig["logging"]["dir"];
		sBufferRequired = yamlConfig["logging"]["buffer_required"];
		helper.upcase( sBufferRequired );
		iBufferSize = atoi(yamlConfig["logging"]["buffer_size"].c_str());      // In bytes
	} else {
		setLogMode( (*(this->yamlConfig))["order_logging"]["mode"] );
		setLogLevel( atoi((*(this->yamlConfig))["order_logging"]["level"].c_str()) );
		logNamespace = yamlConfig["order_logging"]["namespace"];
		this->s_logAppender = sLogAppender;
		if( logMode == Mode_DEVELOPMENT ) {
			logFileName = yamlConfig["order_logging"]["filename"];
			if( sLogAppender.length() > 0 )
				logFileName.append("." + sLogAppender);
		} else {
			logFileName = yamlConfig["order_logging"]["filename"];
                        if( sLogAppender.length() > 0 )
                                logFileName.append("." + sLogAppender);
			centralLogFileName = yamlConfig["order_logging"]["filename"];
		}
		sLogDir = yamlConfig["order_logging"]["dir"];
	}
	if( sLogDir == "" )
		sLogDir = pwd;
	sCentralLoggerIP = yamlConfig["central_logger"]["ip"];
	iCentralLoggerPort = atoi(yamlConfig["central_logger"]["port"].c_str());
	init();
}

void SLog::setLogLevel(int level)
{

	if( !(level == Level_INFO) && !(level == Level_WARN) 
            && !(level == Level_DEBUG) && !(level == Level_ERROR) 
            && !(level == Level_FATAL) && !(level == Level_AUDIT) )	
		logLevel = Level_DEBUG;
    else
        logLevel = level;
}

void SLog::setLogMode(string sLogMode)
{
	logMode = atoi(sLogMode.c_str());
	if( (logMode != Mode_DEVELOPMENT) && (logMode != Mode_LIVE) &&  (logMode != Mode_LIVE_WITH_LOCAL)) {
		logMode = Mode_DEVELOPMENT;
	}
}

SLog::~SLog()
{
	if( (logMode == Mode_LIVE) || ( logMode == Mode_LIVE_WITH_LOCAL) ) 
		delete tcp_client;
}

void SLog::init()
{
	if( logMode == Mode_DEVELOPMENT ) {
		init_log_file(sLogDir);
	} else if (logMode == Mode_LIVE) {
		init_slog_client();
	} else {
		string url;
		init_slog_client();
		init_log_file(sLogDir);
	}
}

void SLog::init_slog_client()
{
	cout << "ip = " << sCentralLoggerIP << ", port = " << iCentralLoggerPort << endl;
	tcp_client = new TCPClient(sCentralLoggerIP, iCentralLoggerPort);
	cout << "Sending control message" << endl;
	sendControlMessage();
}

string SLog::makeControlMessage()
{
	stringstream controlMessageStream;
	controlMessageStream << 200 << logNamespace << ":" << centralLogFileName << ":" << "production";
	return controlMessageStream.str();
}

void SLog::sendControlMessage()
{
	dispatchToServer( makeControlMessage() );
}

void SLog::init_log_file(string path)
{
	if( path[path.length()-1] != '/' )
		path.append("/");
	if( sLogDir.length() > 0 ) {
		path.clear();
		path.append(sLogDir);
	}

#ifdef _WIN32
	if( path[path.length()-1] != '\\' )
		path.append("\\");
	if ( isCreateLogFolder ) {
		path.append("Log\\");
		int old_umask = 0;
		_umask_s(0000, &old_umask);
		_mkdir(path.c_str());
		cout << "old_umask = " << old_umask << endl;
	}
#else
	if( path[path.length()-1] != '/' )
		path.append("/");
	if ( isCreateLogFolder ) {
		path.append("Log/");
		int old_umask = umask(0000);
		mkdir(path.c_str(), 0777);
		cout << "old_umask = " << old_umask << endl;
	}
#endif
	string fileName(path);
	fileName.append( logFileName );
	logFileName.clear();
	logFileName.append( fileName );
	cout << "fileName = " << fileName << endl;

#ifdef _WIN32
	fileFd = _open(fileName.c_str(), O_CREAT | O_APPEND | O_RDWR , 0666);
#else
	fileFd = open(fileName.c_str(), O_CREAT | O_APPEND | O_RDWR | O_LARGEFILE , 0666);
#endif
	if( fileFd < 0 )
#ifdef _WIN32
		cout << "errno in opening file is " << errno << endl;
#else
		cout << strerror(errno) << endl;
#endif
}

void SLog::info(const char *fmt, ...)
{
	string message;
	va_list ap;
	va_start(ap, fmt);
	make_message( fmt, ap, message );
	va_end(ap);
	log(Level_INFO, message);
}

void SLog::info(const string sMessage)
{
	log(Level_INFO, sMessage);
}

void SLog::warn(const char *fmt, ...)
{
	string message;
	va_list ap;
	va_start(ap, fmt);
	make_message( fmt, ap, message );
	va_end(ap);
	log(Level_WARN, message);
}

void SLog::warn(const string sMessage)
{
	log(Level_WARN, sMessage);
}

void SLog::debug(const char *fmt, ...)
{
	string message;
	va_list ap;
	va_start(ap, fmt);
	make_message( fmt, ap, message );
	va_end(ap);

    debug( message );
//	log(Level_DEBUG, message);
}

void SLog::debug(const string sMessage)
{
    if ( logLevel == Level_DEBUG )
    	log(Level_DEBUG, sMessage);
}

void SLog::error(const char *fmt, ...)
{
	string message;
	va_list ap;
	va_start(ap, fmt);
	make_message( fmt, ap, message );
	va_end(ap);
	log(Level_ERROR, message);
}

void SLog::error(const string sMessage)
{
	log(Level_ERROR, sMessage);
}

void SLog::fatal(const char *fmt, ...)
{
	string message;
	va_list ap;
	va_start(ap, fmt);
	make_message( fmt, ap, message );
	va_end(ap);
	log(Level_FATAL, message);
}

void SLog::fatal(const string sMessage)
{
	log(Level_FATAL, sMessage);
}

void SLog::audit(const char *fmt, ...)
{
	string message;
	va_list ap;
	va_start(ap, fmt);
	make_message( fmt, ap, message );
	va_end(ap);
	log(Level_AUDIT, message);
}

void SLog::audit(const string sMessage)
{
	log(Level_AUDIT, sMessage);
}

#ifndef WIN32
void SLog::secure(const char *fmt, ...)
{
	string message;
	va_list ap;
	va_start(ap, fmt);
	make_message( fmt, ap, message );
	va_end(ap);
	unsigned char key[8] = {57, 51, 49, 50, 107, 49, 105, 112};
	unsigned char *data = (unsigned char *)message.c_str();
	unsigned char *output = (unsigned char *)calloc(1, (message.length() * 5 ));
	Cipher *cipher = new Cipher();
	cipher->setKey(key, sizeof(key));
	size_t outputLength = 0;
	cipher->encrypt(Cipher::Cipher_DES_ECB, data, strlen((char *)data), output, &outputLength, 8);
	Base64 b64;
	message.clear();
	b64.encode( (const char *)output, message, outputLength );
	log(Level_SECURE, message);
}
#endif

void SLog::make_message(const char *fmt, va_list ap, string & message)
{
	char *ptr = NULL;
	int length = 0;
	int size = 5*ONE_KB*ONE_KB;
    while(1) {
        va_list bp; 
        va_copy(bp, ap);
        ptr = (char *)calloc(1, size);
		length = vsnprintf(ptr, size, fmt, bp);
		if( (length > -1) && (length < size) ) {
			break;
		} else {
			free(ptr);
			ptr = NULL;
			length = 0;
			size = size * 2;
		}
	}

        stringstream pidstream;
        pidstream << "[" << getpid() << "] " ;

        message.append(pidstream.str());

	message.append( (char *)ptr, length );
	free(ptr);
	ptr = NULL;
}

void SLog::compose_message(string & message)
{
	stringstream logMessage;
	char tmpBuf[16] = {'\0'};
#ifdef _WIN32
	sprintf_s(tmpBuf, sizeof(tmpBuf), "%09d", message.length());
#else
	sprintf(tmpBuf, "%09ld", message.length());
#endif
	logMessage << tmpBuf << message;
	message.clear();
	message.append( logMessage.str() );
}

void SLog::appendLogTime(stringstream & logMessage)
{
	IFHelper helper;
	string timeBuf;
	helper.logTime(timeBuf);
	logMessage << timeBuf << " ";
}

void SLog::appendLogLevelIndicators(uint8_t level, stringstream & logMessage)
{
	if( level == Level_INFO ) {
		((logMode == Mode_LIVE) || (logMode == Mode_LIVE_WITH_LOCAL)) ? logMessage << 202 : logMessage << Level_INFO_STR << ": ";
	} else if( level == Level_WARN ) {
		((logMode == Mode_LIVE) || (logMode == Mode_LIVE_WITH_LOCAL)) ? logMessage << 204 : logMessage << Level_WARN_STR << ": ";
	} else if( level == Level_DEBUG ) {
		((logMode == Mode_LIVE) || (logMode == Mode_LIVE_WITH_LOCAL)) ? logMessage << 206 : logMessage << Level_DEBUG_STR << ": ";
	} else if( level == Level_ERROR ) {
		((logMode == Mode_LIVE) || (logMode == Mode_LIVE_WITH_LOCAL)) ? logMessage << 208 : logMessage << Level_ERROR_STR << ": ";
	} else if( level == Level_FATAL ) {
		((logMode == Mode_LIVE) || (logMode == Mode_LIVE_WITH_LOCAL)) ? logMessage << 210 : logMessage << Level_FATAL_STR << ": ";
	} else if( level == Level_AUDIT ) {
		((logMode == Mode_LIVE) || (logMode == Mode_LIVE_WITH_LOCAL)) ? logMessage << 202 : logMessage << Level_AUDIT_STR << ": ";
	} else if( level == Level_SECURE ) {
		((logMode == Mode_LIVE) || (logMode == Mode_LIVE_WITH_LOCAL)) ? logMessage << 202 : logMessage << Level_SECURE_STR << ": ";
	}
}

void SLog::dispatchToServer(string message)
{
	lock();
	compose_message( message );
	cout << message << endl;
	if(tcp_client->sendData( message ) < 0 ) {
		tcp_client->reconnect();
		if( tcp_client->isConnected() ) {
			string sControlMessage( makeControlMessage() );
			compose_message( sControlMessage );
			tcp_client->sendData( sControlMessage );
			tcp_client->sendData( message );
		}
	}
	unlock();
}

bool SLog::shift()
{
#ifdef _WIN32
#ifdef _USE_32BIT_TIME_T
	struct _stat32 stat_buf;
	memset(&stat_buf, '\0', sizeof(struct _stat));
	_fstat(fileFd, &stat_buf);
#else
	struct __stat64 stat_buf;
	memset(&stat_buf, '\0', sizeof(struct __stat64));
	_fstat64(fileFd, &stat_buf);
#endif
#else
	struct stat64 stat_buf;
	memset(&stat_buf, '\0', sizeof(struct stat64));
	fstat64(fileFd, &stat_buf);
#endif
	time_t t = time(NULL);
	struct tm current_tm_time, file_tm_time;
	memset(&current_tm_time, '\0', sizeof(struct tm));
	memset(&file_tm_time, '\0', sizeof(struct tm));
#ifdef _WIN32
#ifdef _USE_32BIT_TIME_T
	_localtime32_s(&current_tm_time, &t);
	_localtime32_s(&file_tm_time, &stat_buf.st_mtime);
#else
	localtime_s(&current_tm_time, &t);
	localtime_s(&file_tm_time, &stat_buf.st_mtime);
#endif
#else
	localtime_r(&t, &current_tm_time);
	localtime_r(&stat_buf.st_mtime, &file_tm_time);
#endif
	if( current_tm_time.tm_mday != file_tm_time.tm_mday ) {
		IFHelper helper;
		string date;
		helper.formatTime(&file_tm_time, "%Y-%m-%d", date);
		stringstream newLogFileName;
		newLogFileName << logFileName << "." << date;
#ifdef _WIN32
		_close(fileFd);
#else
		close(fileFd);
#endif
		rename(logFileName.c_str(), newLogFileName.str().c_str());
		
#ifdef _WIN32
		fileFd = _open(logFileName.c_str(), O_CREAT | O_APPEND | O_RDWR , 0666);
#else
		fileFd = open(logFileName.c_str(), O_CREAT | O_APPEND | O_RDWR | O_LARGEFILE, 0666);
#endif
		return true;
	}
	return false;
}

void SLog::writeToFile(string message)
{
	lock();
	shift();
	int nWritten = 0;
#ifdef _WIN32
	nWritten = _write(fileFd, message.c_str(), message.length());
#else
	nWritten = write(fileFd, message.c_str(), message.length());
#endif
	if( nWritten < 0 )
		cout << "Unable to write." << endl;
	unlock();
}

void SLog::log(uint8_t level, string message)
{
	stringstream logMessage;

        if( message[message.length() - 1] != '\n' )
                message.append("\n");

	
	if( (logMode != Mode_LIVE) && (logMode != Mode_LIVE_WITH_LOCAL)) 
		appendLogTime( logMessage );

	appendLogLevelIndicators( level, logMessage );

	logMessage << message;

	if ( logMode == Mode_LIVE ) {
		dispatchToServer( logMessage.str() );
	} else if( logMode == Mode_LIVE_WITH_LOCAL ) {
		dispatchToServer( logMessage.str() );
		stringstream locallogMessage;
		appendLogTime( locallogMessage );
		locallogMessage << message;
		writeToFile( locallogMessage.str() );
	} else {
		time_t t = time(NULL);
		struct tm *t1 = localtime(&t);
		if( (sBufferRequired == "YES") && ( (t1->tm_hour >= 9) && (t1->tm_hour <= 17) ) ) {
			lock();
			sBuffer.append( logMessage.str() );
			unlock();
			if( sBuffer.size() >= iBufferSize ) {
				writeToFile( sBuffer );
				lock();
				sBuffer.clear();
				unlock();
			}
		} else {
			writeToFile( logMessage.str() );
		}
	}
}

void SLog::sync_buffer()
{
	if( sBuffer.size() > 0 ) {
		writeToFile( sBuffer );
		lock();
                sBuffer.clear();
		unlock();
        }
}
