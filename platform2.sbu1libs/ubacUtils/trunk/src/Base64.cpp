#include "Base64.h"

void Base64::encode(string sSource, string & sDestination) {
	const char *src = sSource.c_str();
	size_t size = sSource.length();
	encode(src, sDestination, size);
}

void Base64::encode(const char *src, string & sDestination, size_t size) {
	size_t i;
	char *out, *p;

	if(!src) 
		return;
	
	if(!size)
		size= strlen((char *)src);
	
	out=  (char *)calloc(sizeof(char), size*4/3+4);
	p= out;
	
	for(i=0; i<size; i+=3) {
		unsigned char b1=0, b2=0, b3=0, b4=0, b5=0, b6=0, b7=0;
		b1 = src[i];
		
		if(i+1<size)
			b2 = src[i+1];
		
		if(i+2<size)
			b3 = src[i+2];
		
		b4= b1>>2;
		b5= ((b1&0x3)<<4)|(b2>>4);
		b6= ((b2&0xf)<<2)|(b3>>6);
		b7= b3&0x3f;
		*p++= encode(b4);
		*p++= encode(b5);
		
		if(i+1<size) {
			*p++= encode(b6);
		} else {
			*p++= '=';
		}
		if(i+2<size) {
			*p++= encode(b7);
		} else {
			*p++= '=';
		}
	}
	sDestination.append(out);
	free(out);
	out = NULL;
}

size_t Base64::decode(string sSource, void *dest, size_t *output_length)
{
		//unsigned char *dest, const char *src) {
	const char *src = sSource.c_str();
	size_t size = sSource.length();
//	dest = (char *)calloc(1, size+1);
	*output_length = 0;
	
	if(src && *src) {
		unsigned char *p= (unsigned char *)dest;
		int k, l = size+1;
		unsigned char *buf= (unsigned char *)calloc(sizeof(unsigned char), l);  
		
		for(k=0, l=0; src[k]; k++) {
			if(is_base64(src[k])) {
				buf[l++]= src[k];
			}
		}
		for(k=0; k<l; k+=4) {
			char c1='A', c2='A', c3='A', c4='A';
			unsigned char b1=0, b2=0, b3=0, b4=0;
			c1= buf[k];
			if(k+1<l) {
				c2= buf[k+1];
			}
			
			if(k+2<l) {
				c3= buf[k+2];
			}
			if(k+3<l) {
				c4= buf[k+3];
			}
			b1= decode(c1);
			b2= decode(c2);
			b3= decode(c3);
			b4= decode(c4);
			
			*p++=((b1<<2)|(b2>>4) );
			(*output_length) += 1;
			if(c3 != '=') {
				*p++=(((b2&0xf)<<4)|(b3>>2) );
				(*output_length) += 1;
			}
			if(c4 != '=') {
				*p++=(((b3&0x3)<<6)|b4 );
				(*output_length) += 1;
			}
		}
		cout << (char *)dest << endl;
		free(buf);
		buf = NULL;
	}
	return 0;
}

size_t Base64::decode(string sSource, string & sDestination)
{
		//unsigned char *dest, const char *src) {
	const char *src = sSource.c_str();
	size_t size = sSource.length();
	char *dest = (char *)calloc(1, size+1);
	
	if(src && *src) {
		unsigned char *p= (unsigned char *)dest;
		int k, l = size+1;
		unsigned char *buf= (unsigned char *)calloc(sizeof(unsigned char), l);  
		
		for(k=0, l=0; src[k]; k++) {
			if(is_base64(src[k])) {
				buf[l++]= src[k];
			}
		}
		for(k=0; k<l; k+=4) {
			char c1='A', c2='A', c3='A', c4='A';
			unsigned char b1=0, b2=0, b3=0, b4=0;
			c1= buf[k];
			if(k+1<l) {
				c2= buf[k+1];
			}
			
			if(k+2<l) {
				c3= buf[k+2];
			}
			if(k+3<l) {
				c4= buf[k+3];
			}
			b1= decode(c1);
			b2= decode(c2);
			b3= decode(c3);
			b4= decode(c4);
			
			*p++=((b1<<2)|(b2>>4) );
			if(c3 != '=') {
				*p++=(((b2&0xf)<<4)|(b3>>2) );
			}
			if(c4 != '=') {
				*p++=(((b3&0x3)<<6)|b4 );
			}
		}
		free(buf);
		buf = NULL;
		sDestination.append( dest );
		return sDestination.length();
	}
	return 0;
}

char Base64::encode(unsigned char u) 
{
	if(u < 26)  return 'A'+u;
	if(u < 52)  return 'a'+(u-26);
	if(u < 62)  return '0'+(u-52);
	if(u == 62) return '+';
	
	return '/';
}

unsigned char Base64::decode(char c) 
{
	if(c >= 'A' && c <= 'Z') return(c - 'A');
	if(c >= 'a' && c <= 'z') return(c - 'a' + 26);
	if(c >= '0' && c <= '9') return(c - '0' + 52);
	if(c == '+') return 62;
	
	return 63;
}

int Base64::is_base64(char c) 
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
		(c >= '0' && c <= '9') || (c == '+')        ||
		(c == '/')             || (c == '=')) {
		
		return 1;
	}
	return 0;
}
