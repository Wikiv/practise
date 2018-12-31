#ifndef _CIRCULAR_BUFFER_H_
#define _CIRCULAR_BUFFER_H_

#include <iostream>
#include <string.h>

#include "Mutex.h"

namespace UBACIPC
{

	using namespace std;

	//! Class CircularBuffer.This class is used as a utility buffer to write and read data from sockets.
	class CircularBuffer
	{
		private:
			char * data;
			size_t front;
			size_t rear;
			size_t capacity;
			Mutex mutex;

		public:
			//! Creates new CircularBuffer instance of size 'capacity'. 
			/*!
			Allocates a buffer of size capacity and initialize the front and rear member variables
			*/
			CircularBuffer(size_t capacity);
			
			//! Writes 'ptr' of length 'nBytes' to buffer. 
			/*!
			This function first checks if there is space available in buffer to write.
			If space is available it writes the  data from from \a ptr to buffer by checking the
			current position rear and front variable.
			Note:The function uses mutex protection to avoid race conditions.
			\param ptr The Char pointer which contains the data to be written to buffer.
			\param nBytes The number of bytes that is to be written to buffer.
			\return The number of bytes actually written
			*/
			size_t write(const char * ptr, size_t nBytes);

			//! Reads data from buffer and stores data in 'ptr'. Returns the number of bytes read. 
			/*!
			This Function first checks if there is any data in buffer to read.If there is data to read .
			It checks the current value of rear and front variable to know where to 
			read the data from buffer.
			Note:This function uses mutex to avoid race conditions
			\param ptr.The char pointer to which the data read from buffer must be written
			\return The number of bytes read from buffer.
			*/
			size_t read(char * ptr);

			//! Returns number of bytes occupied in the buffer. 
			size_t dataAvail();

			//! Returns the number of bytes available in the buffer. 
			size_t spaceAvail();
			
			//! Reassigns front pointer after reading data from the buffer. 
			void readCommit(size_t nBytes);

			//! Prints the contents of circular buffer. 
			void print();

			//! Resets the front and rear pointer. 
			void reset();

			~CircularBuffer();
	};

};
#endif /* _CIRCULAR_BUFFER_H_ */

