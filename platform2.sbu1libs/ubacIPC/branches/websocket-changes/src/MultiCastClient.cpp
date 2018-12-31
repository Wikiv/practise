/*
 * MultiCastClient.cpp
 *
 *  Created on: 20-Aug-2013
 *      Author: vijayakanth
 */

#include "MultiCastClient.h"

MultiCastClient::MultiCastClient(string sGroupIP, int iPort)
{
	if( !this->connect(sGroupIP, iPort) )
		throw "unable to connect to group ip";
}

MultiCastClient::~MultiCastClient()
{
}

bool MultiCastClient::connect(string groupIP, int port)
{
	struct ip_mreq mreq;
	addr_len = sizeof(struct sockaddr_in);
	iUDPSocket = socket(AF_INET, SOCK_DGRAM,0);

	if (iUDPSocket == -1) {
		return false;

	} else {
		// create multicast subscription..
		mreq.imr_multiaddr.s_addr = inet_addr(groupIP.c_str());
		mreq.imr_interface.s_addr = INADDR_ANY;
		memset((char *) &client_addr, 0, sizeof(client_addr));

		client_addr.sin_family = AF_INET;
		client_addr.sin_addr.s_addr = INADDR_ANY;
		client_addr.sin_port = htons(port);

		//cout <<" port: " << port << endl;
		int retcode = bind(iUDPSocket,(struct sockaddr *)&client_addr,
						   sizeof(struct sockaddr));

		if (retcode < 0) {
			// throw some error..
			iUDPSocket = -1;
			return false;

		} else {
			// subsribing to multicast group
			retcode = setsockopt(iUDPSocket, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&mreq,
								 sizeof(mreq));

			if (retcode < 0) {
				// throw some error..
				iUDPSocket = -1;
				return false;

			} else {
				// subscribed successfully...
				return true;
			}
		}
	}
}

void MultiCastClient::start()
{
	while(1) {
		char buffer[UDP_BUFLEN] = {'\0'};
		int received_bytes = recvfrom(iUDPSocket, buffer, sizeof(buffer), 0,
									  (struct sockaddr *) &client_addr, (unsigned int *) &addr_len);
		receive_data(buffer, received_bytes);
	}
}
