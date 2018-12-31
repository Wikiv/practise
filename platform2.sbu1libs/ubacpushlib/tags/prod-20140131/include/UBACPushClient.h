#ifndef __UBAC_PUSH_CLIENT_H__
#define __UBAC_PUSH_CLIENT_H__

#include <iostream>
#include <ubacipc/TCPClient.h>
#include <ubacdata/UBACData.h>
#include <ubacipc/Mutex.h>
#include <vector>
#include "IFSubscriptions.h"

#include "UBACRequestCache.h"

class UBACPushClient :
	public TCPClient
{
	public:
		UBACPushClient(int fd, IFSubscriptions *ifSubscriptions);
		~UBACPushClient();

		void receive_data(void *data, size_t len);
		void unbind();
		int getDescriptor();
		bool send(string sResponse, ExtMod *extMod);
		bool isMarkedForRemoval();
		void checkInactivity(time_t);

	private:
		void unsubscribeAll();
		void parse(char *data, size_t len);
		void parse(string sRequest);
		string sToken;
		time_t uLastActivityTime;
		bool bMarkedForRemoval;

		int fd;
		Mutex mMutex;

		IFSubscriptions *ifSubscriptions;
		UBACRequestCache ubacCache;
};

#endif /* __PUSH_CLIENT_H__ */
