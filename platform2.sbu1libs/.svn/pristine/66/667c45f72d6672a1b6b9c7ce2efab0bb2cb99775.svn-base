#include "StaticBuffer.h"
namespace UBACIPC {
StaticBuffer::StaticBuffer(size_t len)
{
	data = NULL;
	buffer_pos = 0;
	buffer_size = len;
	this->allocate(len);
}

void StaticBuffer::allocate(size_t len ) 
{	
	data = calloc(1, len);
	bzero(data, len ) ;
}

void StaticBuffer::align_data(void *packet, size_t len ) 
{

	if ( ( len + buffer_pos ) < buffer_size )  {
		memcpy(((uint8_t*)data)+buffer_pos, packet, len );
		buffer_pos += len;
	} else {
		size_t packet_pos = 0;
		len += buffer_pos;
		while( len >= buffer_size ){
			memcpy(((uint8_t *)data)+buffer_pos , ((uint8_t*)packet)+packet_pos , buffer_size- buffer_pos) ;
			this->handleStaticBufferedData(data, this->buffer_size);
			len -= buffer_size;
			packet_pos += (buffer_size - buffer_pos ) ;
			buffer_pos = 0;
		}
		
		buffer_pos = len;
		
		if (buffer_pos > 0 ){
			bzero(this->data, buffer_size ) ;
			memcpy(this->data,(char *)packet + packet_pos , buffer_pos);
		} else {
			buffer_pos = 0; 
			bzero(this->data, buffer_size);
		}
	}
}
}
#ifdef TEST
int main(int argc, char *argv[])
{
	StaticBuffer buf(12);
	char b[30];
	while(1){
		size_t s  =  random()%26;
		strncpy(b, "abcdefghijklmnopqrstuvwxyz" , s ) ;
		buf.align_data(b,s);
		usleep(100000);
	}
	return 0;	
}
#endif
