#include "Cipher.h"

const uint16_t Cipher::Cipher_DES_CBC = 0;
const uint16_t Cipher::Cipher_DES_ECB = 1;
const uint16_t Cipher::Cipher_DES_CFB = 2;
const uint16_t Cipher::Cipher_DES_OFB = 3;
const uint16_t Cipher::Cipher_AES_CBC = 4;

Cipher::Cipher()
{
	key = NULL;
	keyLength = 0;
	iv = NULL;
	ivLength = 0;
	salt = NULL;
}

Cipher::~Cipher()
{
	if(key) 
		free(key);
	if(iv)
		free(iv);
	if(salt)
		free(salt);
}

void Cipher::setKey(unsigned char *c_key, uint16_t u16KeyLength)
{
	
	key = (unsigned char *)calloc(1, u16KeyLength);
	memcpy(key, c_key, u16KeyLength);
}

void Cipher::setIV(unsigned char *c_iv, uint16_t u16IVLength)
{
	iv = (unsigned char *)calloc(1, u16IVLength);
	memcpy(iv, c_iv, u16IVLength);
}

void Cipher::setKeyGenerationString(string sKey)
{
	sKeyGenerator = sKey;
}

void Cipher::setKeyForAES()
{
	key = (unsigned char *)calloc(1, EVP_MAX_KEY_LENGTH);
}

void Cipher::setIVForAES()
{	
	iv = (unsigned char *)calloc(1, EVP_MAX_KEY_LENGTH);
}

void Cipher::setSalt(unsigned char *c_salt)
{
	salt = (unsigned char *)calloc(1, 8);
	memcpy(salt, c_salt, 8);
}

void Cipher::encrypt(uint16_t u16_cipher_type, string sInput, unsigned char *output, size_t *outputLength, int padding)
{
	unsigned char *input = (unsigned char *)sInput.c_str();
	encrypt(u16_cipher_type, input, sInput.length(), output, outputLength, padding);
}

void Cipher::decrypt( uint16_t u16_cipher_type, string sInput, unsigned char *output, size_t *outputLength, int padding)
{
	unsigned char *input = (unsigned char *)sInput.c_str();
	decrypt(u16_cipher_type, input, sInput.length(), output, outputLength, padding);
}


void Cipher::decrypt(uint16_t u16_cipher_type, unsigned char *input, size_t input_length, unsigned char *output, size_t *outputLength, int padding)
{
        EVP_CIPHER_CTX ctx;
        EVP_CIPHER_CTX_init(&ctx);


 	if( u16_cipher_type == Cipher_AES_CBC ) {
                int op_len = 0;
                EVP_CipherInit_ex(&ctx, EVP_aes_256_cbc(), NULL, NULL, NULL, 0);
                int i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_md5(), salt, (unsigned char *)sKeyGenerator.c_str(), sKeyGenerator.length(), 1, key, NULL);
                EVP_CipherInit_ex(&ctx, NULL, NULL, key, salt, -1);
                i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_md5(), salt, (unsigned char *)sKeyGenerator.c_str(), sKeyGenerator.length(), 1, key, iv);
                EVP_CipherInit_ex(&ctx, NULL, NULL, key, iv, -1);
                EVP_CipherUpdate(&ctx, output, &op_len, input, input_length);
                *outputLength = op_len;
		int op_len2 = 0;
                EVP_CipherFinal_ex(&ctx, &output[op_len], &op_len2);
                *outputLength += op_len2;
        }

}

void Cipher::encrypt(uint16_t u16_cipher_type, unsigned char *input, size_t input_length, unsigned char *output, size_t *outputLength, int padding)
{
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);

	if( u16_cipher_type == Cipher_DES_CBC ) {
		size_t op_len = 0;
		EVP_EncryptInit_ex(&ctx, EVP_des_cbc(), NULL, key, iv);
		EVP_CIPHER_CTX_set_padding(&ctx, padding);
		EVP_EncryptUpdate(&ctx, output, (int *)&op_len, input, (int)input_length);
		*outputLength = op_len;
		EVP_EncryptFinal_ex(&ctx, output+op_len, (int *)&op_len);
		*outputLength += op_len;
	} else if( u16_cipher_type == Cipher_DES_ECB ) {
		size_t op_len = 0;
		EVP_EncryptInit_ex(&ctx, EVP_des_ecb(), NULL, key, iv);
		EVP_CIPHER_CTX_set_padding(&ctx, padding);
		EVP_EncryptUpdate(&ctx, output, (int *)&op_len, input, (int)input_length);
		*outputLength = op_len;
		EVP_EncryptFinal_ex(&ctx, output+op_len, (int *)&op_len);
		*outputLength += op_len;
	} else if( u16_cipher_type == Cipher_DES_CFB ) {
		size_t op_len = 0;
		EVP_EncryptInit_ex(&ctx, EVP_des_cfb(), NULL, key, iv);
		EVP_CIPHER_CTX_set_padding(&ctx, padding);
		EVP_EncryptUpdate(&ctx, output, (int *)&op_len, input, (int)input_length);
		*outputLength = op_len;
		EVP_EncryptFinal_ex(&ctx, output+op_len, (int *)&op_len);
		*outputLength += op_len;
	} else if( u16_cipher_type == Cipher_DES_OFB ) {
		size_t op_len = 0;
		EVP_EncryptInit_ex(&ctx, EVP_des_ofb(), NULL, key, iv);
		EVP_CIPHER_CTX_set_padding(&ctx, padding);
		EVP_EncryptUpdate(&ctx, output, (int *)&op_len, input, (int)input_length);
		*outputLength = op_len;
		EVP_EncryptFinal_ex(&ctx, output+op_len, (int *)&op_len);
		*outputLength += op_len;
	} else if( u16_cipher_type == Cipher_AES_CBC ) {
		int op_len = 0;
		EVP_CipherInit_ex(&ctx, EVP_aes_256_cbc(), NULL, NULL, NULL, 1);
		int i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_md5(), salt, (unsigned char *)sKeyGenerator.c_str(), sKeyGenerator.length(), 1, key, NULL);
		EVP_CipherInit_ex(&ctx, NULL, NULL, key, salt, -1);
		i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_md5(), salt, (unsigned char *)sKeyGenerator.c_str(), sKeyGenerator.length(), 1, key, iv);
		EVP_CipherInit_ex(&ctx, NULL, NULL, key, iv, -1);
		EVP_CipherUpdate(&ctx, output, &op_len, input, input_length);
		*outputLength = op_len;
		int op_len2 = 0;
		EVP_CipherFinal_ex(&ctx, &output[op_len], &op_len2);
		*outputLength += op_len2;
	}
}



