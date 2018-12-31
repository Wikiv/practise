#ifndef __GET_OPTION_H__
#define __GET_OPTION_H__

#include <string>
#include <iostream>
#include <sstream>
#ifdef _WIN32
#include "getopt_win32.h"
#else
#include <getopt.h>
#include <unistd.h>
#endif

/*#ifdef _WIN32
typedef std::basic_string<TCHAR> tstring;
#endif*/

using namespace std;

/// Class GetOption.
class GetOption {
	public:
		/// Create GetOption by passing `m_argc' (no of arguments) and `m_argv' (array for the command line arguments).
		GetOption(int m_argc, char * m_argv[]);
		~GetOption();

		/** Wrapper for getoption. Returns the parameter in 'value'. */
		void getOption(char option, string & value);
		/** Wrapper for getoption. Takes imput 'option' as a string. Returns the parameter in 'value'. */
		void getOption(const char *option, string & value);

	private:
		int noOfArguments;
		char **argList;
};

#endif /* __GET_OPTION_H__ */
