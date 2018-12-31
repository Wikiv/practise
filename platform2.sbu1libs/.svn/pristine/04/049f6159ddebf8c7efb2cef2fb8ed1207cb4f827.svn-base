#ifndef __UBAC_MINILZO_H__
#define __UBAC_MINILZO_H__

#include <iostream>
#include <string>
#include <lzo/lzo1x.h>

#include <stdlib.h>

using namespace std;

namespace UBACLZO {
	/// Class MiniLZO. For MiniLZO decompression.
	class MiniLZO {
		public:
			/// Creat MiniLZO.
			MiniLZO();
			virtual ~MiniLZO() {};

			/** Decompresses an MiniLZO compressed data. Useful, when the expected output after decompression 
			  * is a string. */
			bool decompress(void *ptr_src, size_t len_src, string & dest);
			/** Decompresses an MiniLZO compressed data. Useful, when the expected output after decompression 
			  * is a binary data. */
			bool decompress(void *ptr_src, size_t len_src, unsigned char **ptr_dest, size_t * len_dest);
	};
};

using namespace UBACLZO;

#endif /* __UBAC_MINILZO_H__ */
