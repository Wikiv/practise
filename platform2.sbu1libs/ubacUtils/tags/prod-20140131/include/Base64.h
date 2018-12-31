#ifndef __BASE64_H__
#define __BASE64_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

/// Class Base64 for encoding and decoding.
class Base64 {
	public:
		/** Converts string 'sSource' to a Base64 endoded data in 'sDestination'. */
		void encode(string sSource, string & sDestination);
		/** Converts binary 'sSource' to a Base64 endoded data in 'sDestination'. */
		void encode(const char *sSource, string & sDestination, size_t length);
		/** Converts a Base64 endoded 'sSource' to raw 'sDestination'. */
		size_t decode(string sSource, string & sDestination);
		/** Converts a Base64 endoded 'sSource' to raw 'output. This is useful when the decoded output
		  * is expected to be in binary. */
		size_t decode(string sSource, void *output, size_t *output_length);

	private:
		char encode(unsigned char u);
		unsigned char decode(char c);
		int is_base64(char c);
};

#endif /* __BASE64_H__ */
