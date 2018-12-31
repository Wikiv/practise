#ifndef __PROXY_QUOTE_RECEIVER_H__
#define __PROXY_QUOTE_RECEIVER_H__

#include <iostream>

#include "QuotePacket.h"
#include <ubacipc/EventFax.h>
#include <ubacipc/TCPClient.h>
#include <ubacipc/Thread.h>
#include <ubacipc/StaticBuffer.h>
#include <ubacdata/QuotePacket.h>

class ProxyQuoteReceiver :
	public TCPClient,
	public Thread,
	public StaticBuffer
{
	public:
		ProxyQuoteReceiver(string sIP, int iPort);
		~ProxyQuoteReceiver();

		void receive_data(void *data, size_t len);
		void start_proxy();
		void run();
		void handleStaticBufferedData(void *data, size_t len);

		virtual void handle_proxy_quote(struct proxy_quote_packet_t *proxy_quote) {}

	private:
		EventFax fax;
};

#endif /* __PROXY_QUOTE_RECEIVER_H__ */
