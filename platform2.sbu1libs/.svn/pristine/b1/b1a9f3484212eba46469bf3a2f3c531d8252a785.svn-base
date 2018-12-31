#include <iostream>
#include <string>
#include <string.h>

#include <ubacutils/Base64.h>

#include <ubacsslinterface/Cipher.h>

int main(int argc, char *argv[])
{
	//unsigned char key[18] = {57, 51, 49, 50, 107, 49, 105, 112, 104, 48, 110, 49, 107, 49, 49, 49, 52, 48};
	unsigned char key[8] = {57, 51, 49, 50, 107, 49, 105, 112};//, 104, 48, 110, 49, 107, 49, 49, 49, 52, 48};

	unsigned char iv[8] = {8, 103, 67, 79, 185, 214, 167, 9};
	unsigned char *data = (unsigned char *)argv[1];
	unsigned char output[1024] = {'\0'};
	Cipher *cipher;
	cipher = new Cipher();
	cipher->setKey(key, sizeof(key));
//	cipher->setIV(iv, 8);
	size_t outputLength = 0;
	cipher->encrypt(Cipher::Cipher_DES_ECB, data, strlen((char *)data), output, &outputLength, 8);

	for(size_t i = 0;output[i] != '\0'; i++)
		printf("%d\n", output[i]);

	string s((char *)output);
	string sOp;
	Base64 b64;
	b64.encode(s, sOp);
	cout << sOp << endl;
}
