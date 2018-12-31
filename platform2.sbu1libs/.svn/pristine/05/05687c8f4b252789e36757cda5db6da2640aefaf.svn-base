/*
 * MultiCastClient.h
 *
 *  Created on: 20-Aug-2013
 *      Author: vijayakanth
 */

#ifndef MULTICASTCLIENT_H_
#define MULTICASTCLIENT_H_

// c++ handlers..

#include <iostream>

using namespace std;


// socket handlers..
#include <stdio.h>   //printf
#include <string.h> //memset
#include <stdlib.h> //exit(0);
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ctype.h>
#include <fcntl.h>

// MOSL Feed structures..

#define UDP_BUFLEN 4*1024

// ubac dependencies..

#include "Thread.h"

/// Class MultiCastClient for creating MultiCast Client application
class MultiCastClient
{
	public:
		/** Create MultiCastClient application and connect to `sGroupIP' @ `iPort'. */
		MultiCastClient(string sGroupIP, int iPort);
		~MultiCastClient();
		/** Receives data from the socket and invokes the callback 'receive_data'. */
		void start();
		/** Implement this method, to handle the data read from the socket. */
		virtual void receive_data(void *buf, size_t received_bytes) {}

	private:
		int iUDPSocket;
		struct sockaddr_in client_addr;
		unsigned int addr_len;

		bool connect(string sGroupIP, int iPort);
};

#endif /* MULTICASTCLIENT_H_ */
