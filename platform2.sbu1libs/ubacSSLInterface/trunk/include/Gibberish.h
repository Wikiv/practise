#ifndef __GIBBERISH__
#define __GIBBERISH__

#include <iostream>
#include <stdio.h>
#include <string>

#include <openssl/aes.h>
#include <openssl/evp.h>

#include <ubacutils/Base64.h>
#include "Cipher.h"


using namespace std;

/// Class Gibberish handles AES encryption and decryption.
class Gibberish
{
        public:
		/// Create Gibberish object.
                Gibberish(string sKey);
		/// AES Decryption.
		void aes_decrypt(string sInput, string & sOutput);
		/// AES Encryption.
		void aes_encrypt(string sInput, string & sOutput);

	private:
		string sKeyGenerator;
};

#endif
