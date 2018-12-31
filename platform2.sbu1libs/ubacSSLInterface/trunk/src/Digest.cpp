#include "Digest.h"

Digest::Digest()
{
}

Digest::~Digest()
{
}

void Digest::digest(void *ptr, size_t len, uint8_t digestType, string & digestData)
{
	switch(digestType) {
		case DigestType_SHA1: digestSHA(ptr, len, digestData); break;
//		case DigestType_SHA224: digestSHA224(ptr, len, digestData); break;
		case DigestType_SHA256: digestSHA256(ptr, len, digestData); break;
//		case DigestType_SHA384: digestSHA384(ptr, len, digestData); break;
		case DigestType_SHA512: digestSHA512(ptr, len, digestData); break;
		case DigestType_MD5: digestMD5(ptr, len, digestData); break;
	}
}

void Digest::digest(string data, uint8_t digestType, string & digestData)
{
	digest( (void *)data.c_str(), data.length(), digestType, digestData);
}

void Digest::hex(void *ptr, size_t len, string & hexDigest)
{
	unsigned char *c_ptr = (unsigned char *)ptr;
	for(size_t i = 0; i < len; i++) {
		char tmp[8] = {'\0'};
		unsigned char ch = *(c_ptr + i);
		sprintf(tmp, "%02x", (unsigned char)ch);
		hexDigest.append(tmp, strlen(tmp));
	}
}

void Digest::sha1sum(const void *input, size_t input_length, string & sOutput)
{
	unsigned char tmp_digest[SHA_DIGEST_LENGTH] = {'\0'};
	SHA1((const unsigned char *)input, input_length, tmp_digest);
	hex(tmp_digest, SHA_DIGEST_LENGTH, sOutput);
}
