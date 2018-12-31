#ifndef __UBAC_SLOG_H__
#define __UBAC_SLOG_H__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#pragma warning( disable : 4290 )
#else
#include <unistd.h>
#endif

#include <errno.h>

using namespace std;

#include <ubacipc/TCPClient.h>
#include <ubacyaml/YamlConfig.h>
#include <ubacutils/IFHelper.h>
#include <ubacipc/Mutex.h>
#include <ubacutils/Exceptions.h>
#ifndef _WIN32
#include <ubacsslinterface/Cipher.h>
#endif
#include <ubacutils/Base64.h>

#define ONE_KB			1024

namespace UBACLOGGER {
	/** This is the class to handle logging to files. The constructor takes the Properties object
	  * which configuration elements for creating the log files. Basic parameters used are:
	  * - log_mode : which takes valid values are `1' for DEVELOPMENT and `2' for PRODUCTION. For now, DO NOT use PRODUCTION mode, since it is not fully tested.
	  * - log_level : Currently it takes a default value of `1'.
	  * - namespace : This is usually the application name used when using central logger.
	  * - filename : This will be the filename into which the messages are logged. 
	  * - pwd : This will be the default path where the file has to be created. This has to be set by the application, rather than picking from config file. 
	  * - url : This has to be used in case central logger is used for logging. This is in format ip:port, and is required only when using PRODUCTION mode.
	  **/
	
	struct s_logger_config {
	
		/// Central logger IP
		string central_logger_ip;
		/// Central logger Port
		string central_logger_port;
		/// Application name 
		string name_space;
		
		/// Log Mode
		string mode;
		/// Log level
		string level;
		/// Log file appender
		string appender;
		/// Name of log file
		string file_name;
		/// Directory to create log file
		string dir;
		/// Current directory to store log file if 'dir' is not specified
		string pwd;


        /// File rotation resolution D for day, H for HOUR
        char cFileRotaPeriod;
        /// File rotation period Value should 0 - 24;
        uint8_t uFileRotaResolution;


	};

	/// Class SLog handles logging to files.
	class SLog :
		public Mutex
	{
		public:
			/// Create SLog with default properties `m_property'.
			SLog(struct s_logger_config config);

			/// Create SLog with Yaml configuration.
			SLog(YamlConfig yamlConfig, string pwd, string sLogAppender, bool isOrderLogging);
			~SLog();

			/// Log at INFO level. 
			void info(const char *fmt, ...);
			/// Log at INFO level with message 'sMessage'.
			void info(const string sMessage);
			/// Log at WARNING level. 
			void warn(const char *fmt, ...);
			/// Log at WARNING level with message 'sMessage'.
			void warn(const string sMessage);
			/// Log at DEBUG level. 
			void debug(const char *fmt, ...);
			/// Log at DEBUG level with message 'sMessage'.
			void debug(const string sMessage);
			/// Log at ERROR level. 
			void error(const char *fmt, ...);
			/// Log at ERROR level with message 'sMessage'.
			void error(const string sMessage);
			/// Log at FATAL level. 
			void fatal(const char *fmt, ...);
			/// Log at FATAL level with message 'sMessage'.
			void fatal(const string sMessage);
			/// Log at AUDIT level. 
			void audit(const char *fmt, ...);
			/// Log at AUDIT level with message 'sMessage'.
			void audit(const string sMessage);
			/// returns the final log message.
			string getLogMessage();
#ifndef WIN32
			/// Log at Secure level. 
			void secure(const char *fmt, ...);
#endif
			/// Shifts the log file based on data and writes 'sBuffer' to file.
			void sync_buffer();	
			/// Contants for the different log levels. 
			const static uint8_t Level_INFO, Level_WARN, Level_DEBUG, Level_ERROR, Level_FATAL, Level_AUDIT, Level_SECURE;
			/// Constants for the log mode. In LIVE, it will write to central logger.
			const static uint8_t Mode_DEVELOPMENT, Mode_LIVE, Mode_LIVE_WITH_LOCAL;

            const static char DAY_ROTATION;
            const static char HOUR_ROTATION;


		protected:
			/// Write log `message' to file.
			void writeToFile(string message);
			/// This shifts the log file based on date. 
			bool shift();

		private:
			void make_message(const char *fmt, va_list ap, string & message);
			void init();
            void validate();
			void init_slog_client();
			void init_log_file(string path);
			void log(uint8_t level, string message);
			void sendControlMessage();
			void compose_message(string & message);
			void appendLogTime(stringstream & logMessage);
			void appendLogLevelIndicators(uint8_t level, stringstream & logMessage);
			void dispatchToServer(string message);
			void setLogMode(string sLogMode);
			void setLogLevel(int iLevel);
			string makeControlMessage();

			uint8_t logLevel;
			uint8_t logMode;
			int fileFd;
			string logNamespace, logFileName, centralLogFileName;
			string sLogDir;
			string sCentralLoggerIP;
			string s_logAppender;
			int iCentralLoggerPort;
			string sBufferRequired, sBuffer;
			size_t iBufferSize;
			stringstream finalLogMessage;

			TCPClient *tcp_client;
			bool isOrderLogging, isCreateLogFolder;
			YamlConfig *yamlConfig;
			const static string Level_INFO_STR, Level_WARN_STR, Level_DEBUG_STR, Level_ERROR_STR, Level_FATAL_STR, Level_AUDIT_STR, Level_SECURE_STR;

            char cFileRotaPeriod;
            uint8_t uFileRotaResolution;


	};
};

using namespace UBACLOGGER;

#endif /* __UBAC_SLOG_H__ */
