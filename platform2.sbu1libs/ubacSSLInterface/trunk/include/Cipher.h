#ifndef __UBAC_CIPHER_H__
#define __UBAC_CIPHER_H__

#include <iostream>
#include <string>

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <openssl/des.h>
#include <openssl/evp.h>


using namespace std;

namespace UBACSSL {
	/// Class Cipher
	class Cipher {
		public:
			/// DES Cipher Block Chaining mode.
			const static uint16_t Cipher_DES_CBC;
			/// DES Electronic Code Book mode.
			const static uint16_t Cipher_DES_ECB;
			/// DES Cipher Feedback mode.
			const static uint16_t Cipher_DES_CFB;
			/// DES Output Feedback mode.
			const static uint16_t Cipher_DES_OFB;
			/// AES Cipher Block chaining mode.
			const static uint16_t Cipher_AES_CBC;
            /// 3-DES Cipher Block Chaining mode.
            const static uint16_t Cipher_TRIPLE_DES_CBC;

			/// Create Cipher object. 
			Cipher();
			~Cipher();

			/** Set Key to use for encryption. */
			void setKey(unsigned char *key, uint16_t u16KeyLength);
			/** Set IV to use for encryption. */
			void setIV(unsigned char *iv, uint16_t u16IVLength);
			
			/** Set Key for AES encryption. */
			void setKeyForAES();
			/** Set IV for AES encryption. */
			void setIVForAES();
			
			/** Set Salt for key and IV generation for AES encryption. */
			void setSalt(unsigned char *c_salt);

			/** Input for Key and IV genration for AES encryption/decryption.*/
			void setKeyGenerationString(string sKey);

			/** Encrypt sInput. */
			void encrypt(uint16_t u16_cipher_type, string sInput, unsigned char *output, size_t *outputLength, int padding = 0);
			/** Encrypt input. */
			void encrypt(uint16_t u16_cipher_type, unsigned char *input, size_t input_length, unsigned char *output, size_t *outputLength, int padding = 0);
			/**decrypt sInput. 
			 * aes is supported for now.
                         */
			void decrypt( uint16_t u16_cipher_type, string sInput, unsigned char *output, size_t *outputLength, int padding = 0);

			/** Encrypt input.
			 * aes is supported for now.
                         */
			void decrypt( uint16_t u16_cipher_type, unsigned char *input, size_t input_length, unsigned char *output, size_t *outputLength, int padding = 0);

		private:
			unsigned char *key, *iv, *salt;
			string sKeyGenerator;
			size_t keyLength, ivLength;
	};
};

using namespace UBACSSL;

#endif /* __UBAC_CIPHER_H__ */
