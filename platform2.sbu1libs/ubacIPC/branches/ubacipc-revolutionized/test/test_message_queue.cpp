/*

g++ test_message_queue.cpp -l:libubacipc.so.1.3.7 -l:libubacutils.so.1.2.4 && ./a.out

*/

#include <iostream>
#include <unistd.h>
#include <ubacipc/MessageQueue.h>
#include <ubacutils/Exceptions.h>

using namespace UBACIPC;

struct mystruct {

	char name[20];
	int i;
	double d;

};


int main( int argc, char *argv[] ) {

	try{

		struct mystruct mys;
		bzero( &mys, sizeof( struct mystruct ) );
		memmove( mys.name, "kundan", 6 );
		mys.i = 10;
		mys.d = 222;

		key_t key = 100;
		cout << "key " << key << endl;

		bool bNew = true;
		MessageQueue< struct mystruct > msgQ( key, bNew );

        //msgQ.setMessageQueueSize(999999999999);

		cout << "in " << mys.name << ", " << mys.i << ", " << mys.d << endl;
		msgQ.enqueue( mys );

        sleep(5);

		MessageQueue< struct mystruct > msgQ2( key );
		struct mystruct mys2;
		mys2 = msgQ2.dequeue();

		cout << "out : " << mys2.name << ", " << mys2.i << ", " << mys2.d << endl;
	
    } catch ( Exceptions & e ) {

		cout << "Exception : " << e.what() << endl;

	}

}
