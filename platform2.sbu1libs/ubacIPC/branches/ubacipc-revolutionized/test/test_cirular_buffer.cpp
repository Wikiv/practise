
#include "CircularBuffer.h"
#include <stdio.h>
#include <stdlib.h>


void readOptions()
{
	CircularBuffer * c;

	while(true)
	{
		cout << "0 - BufferCapacity\n1 - Write\n2 - Read\n3 - ReadCommit" << endl;
		int choice = 0;

		cin >> choice;
		
		if ( choice == 0 )
		{
			cout << "Enter the capacity: ";
			int capacity;
			cin >> capacity;
			cout << endl;

			c = new CircularBuffer(capacity);
			
		} else if ( choice == 1 )
		{

				cout << "Enter the contents to buffer: ";
				string s;
				cin >> s;
				cout << endl;

				int nWritten = c->write(s.c_str(), s.length());
				printf("Written %d out of %d bytes\n", nWritten, s.length());

		} else if ( choice == 2 )
		{
			cout << "Reading from buffer";

			char * readbuffer = new char[100];
			int read = c->read(readbuffer);
			printf("Read data=%d from Buffer ^%s$\n", read, readbuffer);

			free(readbuffer);

		} else if ( choice == 3) 
		{
			cout << "Read commit : ";
			int readCommit;
			cin >> readCommit;

			c->readCommit(readCommit);

		} else {
			cout << "Wrong choice exiting " << choice << endl;
			break;
		}


		c->print();
	}
}


int main()
{

	readOptions();

	return 0;;	


	CircularBuffer c(5);
	c.print();

	char * readPtr = new char[10];

	string s = "hello";

	const char * ptr = s.c_str();


	cout << "Writing data " << s << endl;
	int nwritten = c.write(ptr, 5);
	c.print();


	memset(readPtr, '\0', 10);
	size_t read = c.read(readPtr);
	printf("Got data from buffer - ^%s$\n", readPtr);
	c.print();

	cout << "Read commiting " << read << endl;
	c.readCommit(read);
	c.print();


	s = "he";
	cout << "Writing data " << s << endl;
	c.write(s.c_str(), 2);
	c.print();

	memset(readPtr, '\0', 10);
	read = c.read(readPtr);
	cout << "Read commiting " << read << endl;
	c.readCommit(read);
	c.print();

	CircularBuffer * cir;

	if ( cir == NULL )
		cout << "CIR is null " << endl;
}
