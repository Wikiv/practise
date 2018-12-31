#ifndef __UBAC_IFHELPER_H__
#define __UBAC_IFHELPER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <time.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <string.h>
//#include "Properties.h"

#ifdef _WIN32
#include <windows.h>
#include <WinBase.h>
#include <stdint.h>
typedef unsigned long long int uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short int uint16_t;
typedef unsigned char uint8_t;


#define bswap_64(x)     (((uint64_t)(x) << 56) | \
                        (((uint64_t)(x) << 40) & 0xff000000000000ULL) | \
                        (((uint64_t)(x) << 24) & 0xff0000000000ULL) | \
                        (((uint64_t)(x) << 8)  & 0xff00000000ULL) | \
                        (((uint64_t)(x) >> 8)  & 0xff000000ULL) | \
                        (((uint64_t)(x) >> 24) & 0xff0000ULL) | \
                        (((uint64_t)(x) >> 40) & 0xff00ULL) | \
                        ((uint64_t)(x)  >> 56))

#define strcasecmp(s1, s2)	_strcmpi(s1, s2)
#define strncasecmp(s1, s2, n) _strnicmp(s1, s2, n)

#else
#include <stdint.h>
#include <sys/time.h>
#include <arpa/inet.h>
//#include <curl/curl.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef _BSD_SOURCE
#define _BSD_SOURCE
#endif

#include <byteswap.h>
#include <endian.h>
#endif



using namespace std;

#define CONVERT_DOUBLE_TO_STRING(value, strValue, precision) {	\
	stringstream s;						\
	s.setf(ios::fixed);					\
	s.precision(precision);					\
	s << value;						\
	strValue.append( s.str() );				\
}

#define CONVERT_TO_STRING(value, strValue) {	\
	stringstream s;				\
	s << value;				\
	strValue.append( s.str() );		\
}

namespace UBAC {
	/// Class IFHelper. Implemente helper functions for generic stuff.
	class IFHelper {
		public:
			IFHelper();
			~IFHelper();

			/** Parse the date 'dateString' in the format 'format' and
			  * convert to a time structure define by 'struct tm'. */
			void parseTime(string dateString, string format, struct tm *tmTime);
			/** Parse the date 'dateString' in the format 'format' and
			  * convert to epoch time of type 'time_t'. */
			void parseTime(string dateString, string format, time_t *t_time);
			/** Formats time_t value to a string as per 'format' specified. */
			void formatTime(time_t time, const char *format, string & formattedTime);
			/** Formats 'struct tm' value to a string as per 'format' specified. */
			void formatTime(struct tm *tmTime, const char *format, string & formattedTime);
			/** Gets the current system time and formats it into a string. */
			void currentTime(const char *format, string & formattedTime);
			/** Returns the current time as float, to the precision of microseconds. */
			double currentTime();
			/** Gets the complete date string, to the resolution of
			  * microseconds. This is used by SLog for logging time. */
			void logTime(string & formattedTime);
			/** Left-strip. Strips off the character 'c' from the left most side of
			  * the string 'data'. */
			void lstrip(string & data, char c, int noOfStrips = 0);
			/** Right-strip. Strips off the character 'c' from the right most side of
			  * the string 'data'. The parameter 'noOfStrips' tells the function, how
			  * many characters 'c' should be stripped. A value '0' suggests to strip off
			  * all. */
			void rstrip(string & data, char c, int noOfStrips = 0);
			/** Check if timezone is in daylight saving time. */
			bool isDST();
			/** Convert all the characters in 'data' to upper case. */
			void upcase(string & data);
			/** Convert all the characters in 'data' to lower case. */
			void lowercase(string & data);
			/** Returns the offset of localtime from UTC time.
			  * For example: The function will return 19800 for IST, and
			  * -18000 for EST (Easter Standard Time - New York). */
			int32_t getLocalTimeOffset();
			/** Join a vector to a string. */
			void join(vector<string> input, char c_join_delimiter, string & sResponse);
			/** Split the string 'data', with delimiter as 'pattern' and add the tokens to 'list'
			  * This is similar to 'strtok', with the different that, this
			  * does not considers, contiguous delimiter patterns as one, and hence
			  * can have empty string as tokens. */
			void split(string data, string pattern, vector<string> & list);
			/** Split the string 'data', with delimiter as 'pattern' and add the tokens to 'list'
			  * This is similar to 'strtok', with the different that, this
			  * does not considers, contiguous delimiter patterns as one, and hence
			  * can have empty string as tokens. */
			void newsplit(string data, string pattern, vector<string> & list);
			/** Get the UTC time a time_t data. */
			time_t getGMTime();
			/** Replace special characters. */
			void gsubSpecialCharacters( string & data );
			/** Formats double values to a string, and restricts the number of decimals
			  * to 'noOfDecimals'. */
			string formatDouble(double value, int noOfDecimals);
			/** Formats double values to a string, and restricts the number of decimals
			  * to 'noOfDecimals'. */
			void formatDouble(double value, string & formattedValue, int noOfDecimals);
			/** Please DONOT use this function. */
			void htmlToText(string & data);
			/** Converts all character in 'value' to capital letters. */
			void capitalize(string & value);
			/** Induce a sleep. Sleep for 'timeInSeconds' seconds. */
			void sleep(uint32_t timeInSeconds);
			/** Induce a sleep. Sleep for 'timeInMilliseconds' milliseconds. */
			void usleep(uint32_t timeInMilliseconds);
			/** Substitutes the character 'charFrom' in the string 'data',
			  * to the character 'charTo'. This substitutes all the characters, and
			  * not just the first one. */
			void substitute(string & data, char charFrom, char charTo);
			/** Substitutes the string 'strFrom' in the string 'data',
			  * to the string 'strTo'. This substitutes all the characters, and
			  * not just the first one. */
			void substitute(string & data, string strFrom, string strTo);
			/** Substitutes the character 'charFrom' in the string 'data',
			  * to the string 'strTo'. This substitutes all the characters, and
			  * not just the first one. */
			void substitute(string & data, char charFrom, string strTo);
			/** Substitutes the string 'strFrom' in the string 'data',
			  * to the string 'strTo'. This substitutes all the characters, and
			  * not just the first one. */
			void gsub(string & data, string strFrom, string strTo);
			/** Formats the float value provided in 'data', with commas.
			  * This is not the right definition. Should extend this function. */
			void formatFloatWithComma(string & data);

			/** Get Struct Time from Number of days */
			void getTimeFromNoOfDays(int noOfDays, int year, struct tm *histDate);

			/** Read 4 bytes from 'data' in big-endian format
			  * convert it into a 4-byte unsigned integer. It
			  * returns the integer value and increments the pointer
			  * 'data' by 4 bytes. */
			uint32_t readU32(void * & data);
			/** Read 4 bytes from 'data' in big-endian format
			  * convert it into a 4-byte signed integer. It
			  * returns the integer value and increments the pointer
			  * 'data' by 4 bytes. */
			int32_t readI32(void * & data);
			/** Read 2 bytes from 'data' in big-endian format
			  * convert it into a 2-byte unsigned integer. It
			  * returns the integer value and increments the pointer
			  * 'data' by 2 bytes. */
			uint16_t readU16(void * & data);
			/** Read 2 bytes from 'data' in big-endian format
			  * convert it into a 2-byte signed integer. It
			  * returns the integer value and increments the pointer
			  * 'data' by 2 bytes. */
			int16_t readI16(void * & data);
			/** Read 8 bytes from 'data' in big-endian format
			  * convert it into a double value. It
			  * returns the double value and increments the pointer
			  * 'data' by 8 bytes. */
			double readDouble(void * & data);
			/** Read 8 bytes from 'data' in big-endian format
                          * convert it into a 8-byte unsigned integer. It
                          * returns the integer value and increments the pointer
                          * 'data' by 8 bytes. */
			uint64_t readU64(void * & data);
			/** Read 1 byte from 'data' in big-endian format
                          * convert it into a 1-byte signed integer. It
                          * returns the integer value and increments the pointer
                          * 'data' by 1 byte. */
			int8_t readByte(void * & data);
			/** Read a file. */
			bool readFile(string sFileName, string & sFileContent);
			/** Get logappender from the command like arguments. */
			string getLogAppender(int argc, char *argv[]);

			/** get the charts refresh time in seconds for n:MIN, n:HOUR, n:WEEK, n:MON**/
			uint32_t getChartsRefreshTime(string sResolution);

			/** Set logfile name. */
			//void appendProperty(string sPropertyName, Properties  & property, string sLogAppender);
			/** get PWD, assuming that executable path contain "/bin". */
			string getPWD(const char *c_progname, const char *c_path = "/bin");
			/** Get week number for a day in the month. */
			int getWeekOfMonth(time_t t);
			/** Remove invalid escape sequences. */
			void removeInvalidEscapeChars(string & data);
			/** Replace encoded values with corresponding special characters. */
			void greplaceSpecialCharacters(string & data);

#ifndef WIN32
			/** A wrapper for waidpid when my process doesn't have to handle multiple SIGCHLD signals.
			  * It returns a vector of pid's (child process id's) exited. */
			vector<pid_t> waitpidNTimes();
#endif
#ifdef _WIN32
			/** WINDOWS only function. Converts SYSTEMTIME to 'struct tm'. */
			void convertSYSTEMTIMEToStructTM(SYSTEMTIME sysTime, struct tm *tmTime);
#endif
		private:
			int isLeap( int year);
			int getNoOfDays( int mYear );
	};
};

using namespace UBAC;
#endif /* __UBAC_IFHELPER_H__ */
