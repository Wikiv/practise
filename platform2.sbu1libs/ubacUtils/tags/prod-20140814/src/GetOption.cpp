#include "GetOption.h"

GetOption::GetOption(int m_argc, char * m_argv[])
{
	noOfArguments = m_argc;
	argList = m_argv;
}

GetOption::~GetOption()
{
}

void GetOption::getOption(char option, string & value)
{
	int opt;
	stringstream pattern;
	pattern << option << ":";
	while( (opt = getopt(noOfArguments, argList, pattern.str().c_str())) != -1 ) {
		if( opt == option ) {
			value.append(optarg);
		}
	}
}

void GetOption::getOption(const char *option, string & value)
{
	opterr = 0;
	optind = 1;
	int c;
	int option_index = 0;
	struct option longopts[2];
	longopts[0].name = option;
	longopts[0].has_arg = 1;
	longopts[0].flag = NULL;
	longopts[0].val = 0;
	longopts[1].name = NULL;
	longopts[1].has_arg = 0;
	longopts[1].flag = NULL;
	longopts[1].val = 0;
	while(1) {
		c = getopt_long_only(noOfArguments, argList, "", longopts, &option_index);
		if( c == 0 ) {
			cout << longopts[option_index].name << ", value = " << optarg << endl;
			value.append( optarg );
			return;
		} else if( c == -1 ) {
			break;
		}
	}
}
