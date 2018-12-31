#ifndef __UBAC_GZIP_H__
#define __UBAC_GZIP_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <zlib.h>

using namespace std;


namespace UBACGZIP {
	/// Class GZip. - Experimental.
	class GZip {
		public:
			/// Create GZip with data in `ptr' of length `len', set 'nDecompressionType' to '1' for GZip, '2' for ZLib decompression.
			GZip(void *ptr, size_t len, int nDecompressionType);
			/// Create GZip with data in a file `fileName', set 'nDecompressionType' to '1' for GZip, '2' for ZLib decompression.
			GZip(string fileName, int nDecompressionType);
			/// Create GZip without any input.
			GZip();
			~GZip();

			/// Decompress data in `data'. Decompressed data will be in `data'.
			bool inflateGet(string & data);
			/// Decompress data in `ptr'.
			bool inflateGet(void *ptr, size_t *length);
			/// Decompress data in ptr with length bytes and copy the data in output.
			bool inflateGet(unsigned char *ptr, size_t len, string & output);
			/// Compress data in `ptr'.
			bool deflateGet(unsigned char *data,size_t len,
                			unsigned char **destPtr, size_t *dLen, int level=Z_DEFAULT_COMPRESSION);
		private:
			void *p_data;
			size_t length;
			int nWindowsSize;
			enum DecompressionType
			{
				GZIP = 1, ZLIB
			};
			const static size_t CHUNK;
			const static size_t GZIP_WINDOWS_SIZE;
			const static size_t ZLIB_WINDOWS_SIZE;
			void zerr(int ret);
			void SetWindowsSize(int nDecompressionType);
	};
};

using namespace UBACGZIP;

#endif /* __UBAC_GZIP_H__ */
