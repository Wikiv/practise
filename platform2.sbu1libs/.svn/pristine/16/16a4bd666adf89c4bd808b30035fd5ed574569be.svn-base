#ifndef __UBAC_LZO_H__
#define __UBAC_LZO_H__

#include <iostream>
#include <string>
#include <lzo/lzo1z.h>
#include <string.h>

#include <stdlib.h>

using namespace std;

namespace UBACLZO {
	/// Class LZO decompression.
	class LZO {
		public:
			LZO();
			virtual ~LZO() {};

			/** Decompresses an LZO compressed data. Useful, when the expected output after decompression 
			  * is a string. */
			bool decompress(void *ptr_src, size_t len_src, string & dest, size_t multiplier = 5);
			/** Decompresses an LZO compressed data. Useful, when the expected output after decompression 
			  * is a binary data. */
			bool decompress(void *ptr_src, size_t len_src, unsigned char **ptr_dest, size_t * len_dest, size_t multiplier = 5);
			/** compresses data. Useful, when the expected output after decompression 
			  * is a string. */
			bool compress(string src, unsigned char **ptr_dest, size_t * len_dest);
			/** compresses data. Useful, when the expected output after decompression 
			  * is a binary data. */
			bool compress(void *ptr_src, size_t len_src, unsigned char **ptr_dest, size_t * len_dest);
	};
};

using namespace UBACLZO;

#endif /* __UBAC_LZO_H__ */
