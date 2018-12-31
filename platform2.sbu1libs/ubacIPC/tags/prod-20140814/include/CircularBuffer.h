#ifndef _CIRCULAR_BUFFER_H_
#define _CIRCULAR_BUFFER_H_

#include <iostream>
#include <string.h>

#include "Mutex.h"

namespace UBACIPC
{

	using namespace std;

	class CircularBuffer
	{
		private:
			char * data;
			size_t front;
			size_t rear;
			size_t capacity;
			Mutex mutex;

		public:
			CircularBuffer(size_t capacity);

			size_t write(const char * ptr, size_t nBytes);

			size_t read(char * ptr);

			size_t dataAvail();

			size_t spaceAvail();

			void readCommit(size_t nBytes);

			void print();

			void reset();

			~CircularBuffer();
	};

};
#endif /* _CIRCULAR_BUFFER_H_ */

