#include "Gibberish.h"

Gibberish::Gibberish(string sKey) 
{
	sKeyGenerator = sKey;
}

void Gibberish::aes_decrypt(string sInput, string & sOutput)
{
  	unsigned char output[10024] = {'\0'};
    	unsigned char decout[10024] = {'\0'};
      	size_t outputLength = 0;
  	unsigned char salt[8] ;
      	size_t op_len = 0;

      	Base64 b64;
     	unsigned char baseOutput[10024] = {'\0'};
    	size_t baseOutputLength = 0;
       	b64.decode( sInput, baseOutput, &baseOutputLength);
     	for(size_t i = 8, l = 0;i < 16; i++, l++) {
       		printf("%d\n", baseOutput[i]);
         	salt[l] = baseOutput[i];
      	}
   	for(size_t i = 16, j = 0; i < baseOutputLength ; i++,j++) {
        	output[j] = baseOutput[i];
           	outputLength=outputLength+1;
    	}

     	string stemp( (char * )output, outputLength);
      	Cipher cipher;
    	cipher.setKeyForAES();
      	cipher.setIVForAES();
       	cipher.setSalt( salt );
   	cipher.setKeyGenerationString( sKeyGenerator );
      	cipher.decrypt( Cipher::Cipher_AES_CBC,stemp, decout, &op_len);

      	sOutput.append((char *)decout, op_len);
}

void Gibberish::aes_encrypt(string sInput, string & sOutput)
{
  	unsigned char decout[10024] = {'\0'};
      	unsigned char salt[8] ;
      	size_t op_len = 0;
	string kOutput;
       	Base64 b64;

   	for(size_t i = 0; i < 8; i++ ){
      		salt[i] = rand() % 1000 + 1;
	     	printf("%d\n", salt[i]);
     	}

      	Cipher cipher;
    	cipher.setKeyForAES();
    	cipher.setIVForAES();
    	cipher.setSalt( salt );
    	cipher.setKeyGenerationString( sKeyGenerator );
   	cipher.encrypt( Cipher::Cipher_AES_CBC,sInput, decout, &op_len);

     	kOutput = "Salted__";
	kOutput.append((char *) salt, 8 );
      	kOutput.append((char *)decout, op_len);
      	b64.encode( kOutput, sOutput);
}

