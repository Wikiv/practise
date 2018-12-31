
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(size_t capacity)
{
	this->capacity = capacity + 1;
	data = new char[this->capacity];

	front = 0;
	rear = 1;
}

void CircularBuffer::reset()
{
	front = 0;
	rear = 1;
}

size_t CircularBuffer::write(const char * ptr, size_t nBytes)
{
	if ( spaceAvail() < nBytes )
		return 0;

	mutex.lock();

	if ( (rear + nBytes) <= capacity ) {
		memcpy(data + rear, ptr, nBytes);
		rear = (rear + nBytes) % capacity;

	} else {
		size_t bytesToWrite = capacity - rear;
		memcpy(data + rear, ptr, bytesToWrite);

		memcpy(data, ptr + bytesToWrite, nBytes - bytesToWrite);

		rear = nBytes - bytesToWrite;

	}

	mutex.unlock();

	return nBytes;
}

size_t CircularBuffer::read(char * ptr)
{
	if ( dataAvail() == 0 )
		return 0;

	size_t nRead = 0;
	mutex.lock();

	if ( front < rear ) {
		nRead = rear - front - 1;
		memcpy(ptr, data + front + 1, nRead);

	} else {
		nRead = capacity - (front + 1);

		memcpy(ptr, data + front + 1, nRead);

		if ( rear > 0) {
			memcpy(ptr + nRead, data, rear);
			nRead += rear;
		}
	}

	mutex.unlock();

	return nRead;
}

size_t CircularBuffer::dataAvail()
{
	return capacity - 1 - spaceAvail();
}

size_t CircularBuffer::spaceAvail()
{
	mutex.lock();
	size_t n = (rear > front) ? (front + capacity - rear) : (front - rear);
	mutex.unlock();

	return n;
}

void CircularBuffer::readCommit(size_t nBytes)
{
	mutex.lock();
	front = ( front + nBytes ) % capacity;
	mutex.unlock();
}
#include <stdio.h>

void CircularBuffer::print()
{
	cout << endl << "Circular Buffer ###BEGIN###" << endl;
	cout << "front : " << front << endl;
	cout << "rear : " << rear << endl;

	cout << "^";

	for (size_t i = (front + 1) % capacity; i != rear;) {
		cout << data[i];
		i = ( i + 1 ) % capacity;
	}

	cout << "$" << endl;
	cout << "Circular Buffer ###END###" << endl;
	cout << "Data avaiable " << dataAvail() << endl;
	cout << "Space available " << spaceAvail() << endl;
	cout << "Raw Circular Buffer -- BEGIN" << endl;
	for(size_t i = 0; i < capacity; i++)
	{
		 char c;
		 c = (i == rear) ? 'r' : ((i == front) ? 'f' : 0);
		 printf("%d -- %c -- %c\n", i, data[i], c);
	}
	cout << "Raw Circular Buffer -- END" << endl << endl;


}


CircularBuffer::~CircularBuffer()
{
	 delete [] data;
}
