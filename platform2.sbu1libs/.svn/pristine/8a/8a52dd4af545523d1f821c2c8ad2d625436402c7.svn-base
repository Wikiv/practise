#ifndef BUFFER
#define BUFFER
#include <iostream>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
namespace UBACIPC {
class StaticBuffer
{
	public:
	       StaticBuffer(size_t buffer_size ) ;
	       StaticBuffer(){};
	       ~StaticBuffer()
	       {
		       free(data);
	       };

	       void init_buffer( size_t size) 
	       {
		       this->buffer_size = size;
		       this->buffer_pos = 0;
		       allocate(size);
	       }
	       void align_data(void *data , size_t len );

	       virtual void handleStaticBufferedData(void *data , size_t len ) 
	       {
		       printf("data: %s , len:  %ld\n" ,(char*) data,  len );
	       }

	private:
	       void *data;
	       size_t buffer_size;
	       size_t buffer_pos;

	       void allocate(size_t len);
};
};
using namespace UBACIPC;
#endif
