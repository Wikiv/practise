
#include "CircularBuffer.h"

int main()
{
	char * readPtr = new char[10];

	string s = "hello";

	const char * ptr = s.c_str();

	CircularBuffer c(5);
	int nwritten = c.write(ptr, 5);
	c.print();

	memset(readPtr, '\0', 10);
	size_t read = c.read(readPtr);
	c.print();

	c.readCommit(read);
	c.print();

	s = "he";
	c.write(s.c_str(), 2);
	c.print();

	s = "h";
	cout << "nWritten " << c.write(s.c_str(), 1) << endl ;
	c.print();

	memset(readPtr, '\0', 10);
	read = c.read(readPtr);
	c.readCommit(read);
	c.print();

	CircularBuffer * cir;

	if ( cir == NULL )
		cout << "CIR is null " << endl;
}
