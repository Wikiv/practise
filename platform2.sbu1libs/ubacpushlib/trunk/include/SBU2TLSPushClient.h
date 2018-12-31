#ifndef __SBU2_TLS_PUSH_CLIENT_H__
#define __SBU2_TLS_PUSH_CLIENT_H__

#include <iostream>
#include <ubacipc/TCPClient.h>
#include <ubacipc/TLSClient.h>
#include <ubacipc/Mutex.h>
#include <vector>

#include "SessionTable.h"
#include "SymbolTable.h"
#include "MasterTable.h"
#include "SBU2RequestCache.h"
#include "SBU2StreamingRequest.h"
#include "IFSubscriptions.h"
#include "SBU2PushClient.h"


class SBU2TLSPushClient :
	public TLSClient,
	public SBU2PushClient
{
	public:
		SBU2TLSPushClient(int fd, SessionTable *sessionTable,
						  MasterTable *masterSymbolTable,
						  IFSubscriptions *ifSubscriptions,
						  Mutex *mTableMutex, SSL_CTX * ssl_ctx, bool SessionValidate)
			: TCPClient(fd),
			  TLSClient(fd, ssl_ctx),
			  SBU2PushClient(fd, sessionTable, masterSymbolTable,
							 ifSubscriptions, mTableMutex, SessionValidate) {}

		~SBU2TLSPushClient() {}

		void receive_data(void *ptr, size_t len)
		{
			SBU2PushClient::receive_data( ptr, len);
		};

		int sendData(string data)
		{
			return TLSClient::sendData(data);
		};
		/*
		bool asyncSendData(const char *data, int length)
		{
			return TLSClient::asyncSendData(data, length);
		};
		*/
};

#endif /* __SBU2_TLS_PUSH_CLIENT_H__ */
