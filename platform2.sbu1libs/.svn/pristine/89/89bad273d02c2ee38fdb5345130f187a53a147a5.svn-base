#ifndef __UBAC_DIGEST_H__
#define __UBAC_DIGEST_H__

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include <string.h>
#include <stdint.h>


#include <openssl/sha.h>
#include <openssl/md5.h>

#define DIGEST_FUNC(name)       							\
	void digest##name(void *ptr, size_t len, string & digestData) 			\
	{										\
		unsigned char tmpDigest[ name##_DIGEST_LENGTH ] = {'\0'};               \
		name##_CTX c;								\
		name##_Init(&c);							\
		name##_Update(&c, ptr, len);						\
		name##_Final(tmpDigest, &c);						\
		hex( tmpDigest, name##_DIGEST_LENGTH, digestData );			\
	}

using namespace std;

namespace UBACSSL {
	/// Class Digest. Implementes hashing algorithms.
	class Digest {
		public:
			Digest();
			~Digest();

			/** Converts the data at 'ptr' with length 'len' to a SHA1, SHA256, SHA512
			  * or MD5 hashed hex data. Result is stored in 'digestData' */
			void digest(void *ptr, size_t len, uint8_t digestType, string & digestData);
			/** Converts the data at 'data' to a SHA1, SHA256, SHA512
			  * or MD5 hashed hex data. Result is stored in 'digestData'. */
			void digest(string data, uint8_t digestType, string & digestData);
			/** SHA1 sum. */
			void sha1sum(const void *input, size_t input_length, string & sOutput);

			/// Supported hashing types: DigestType_SHA1, DigestType_SHA224, DigestType_SHA256, DigestType_SHA384, DigestType_SHA512, DigestType_MD5.
			enum DigestType {
				DigestType_SHA1 = 1,
				DigestType_SHA224,
				DigestType_SHA256,
				DigestType_SHA384,
				DigestType_SHA512,
				DigestType_MD5,
			};

		private:
			DIGEST_FUNC(SHA)
//			DIGEST_FUNC(SHA224)
			DIGEST_FUNC(SHA256)
//			DIGEST_FUNC(SHA384)
			DIGEST_FUNC(SHA512)
			DIGEST_FUNC(MD5)
			void hex(void *ptr, size_t len, string & hexDigest);
	};
};

using namespace UBACSSL;

#endif /* __UBAC_DIGEST_H__ */
