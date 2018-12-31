/* 
 * g++ test_3des.cpp -l:libubacutils.so.1.2.4 -l:libubacsslinterface.so.1.2.4
 * ./a.out "The quick brown fox jumps over the lazy dog."
 */

#include <iostream>
#include <string>
#include <string.h>

#include <ubacutils/Base64.h>

#include <ubacsslinterface/Cipher.h>

int main(int argc, char *argv[])
{
	string appid = "ae7f8b2c65f8987bc410d150";
	unsigned char *key = (unsigned char *) appid.c_str();
	//unsigned char key[] = "ae7f8b2c65f8987bc410d150";
	printf("\n%s",key);
	unsigned char iv[8] = {0};

	unsigned char *data = (unsigned char *)argv[1];
	unsigned char output[1024] = {0};

	Cipher *cipher = new Cipher();
	cipher->setKey(key, sizeof(key));
	cipher->setIV(iv, 8);

	size_t outputLength = 0;
	cipher->encrypt(Cipher::Cipher_TRIPLE_DES_CBC, data, sizeof(data), output, &outputLength, 8);

    cout << "\nSize of outputLEngth = " << outputLength << endl;

    // Print in Hex
	for(size_t i = 0;output[i] != '\0'; i++)
		printf("%02X ", output[i]);
    printf("\n");

	string s((char *)output,outputLength);
	cout << endl <<"s="<<s <<endl;
	//string sOp;
	//Base64 b64;
	//b64.encode(s, sOp);
	//cout << "Base64 encoded: " << sOp << endl;
	unsigned char dec[1024] = {0};
	size_t outlength = 0;
	//Cipher *ipher = new Cipher();
	//cipher->setIV(iv, 8);
	//cipher->setKey(key, sizeof(key));


    cipher->decrypt( Cipher::Cipher_TRIPLE_DES_CBC, s, dec, &outlength, 8);
	//printf("\ns", dec);
	string outPut((char *) dec,outlength);
	cout << "\ndecypted=" << outPut << endl;
        outlength = 0;
	cipher->decrypt( Cipher::Cipher_TRIPLE_DES_CBC, s, dec, &outlength, 8);
	//printf("\ns", dec);
	string outPut2((char *)dec,outlength);
	cout << "\ndecypted2=" << outPut2 << endl;





}
