#include "ProxyQuoteReceiver.h"

ProxyQuoteReceiver::ProxyQuoteReceiver(string sIP, int iPort) : TCPClient(sIP,
			iPort), StaticBuffer(sizeof(struct proxy_quote_packet_t))
{
}

ProxyQuoteReceiver::~ProxyQuoteReceiver()
{
}

void ProxyQuoteReceiver::receive_data(void *data, size_t len)
{
	align_data(data, len);
}

void ProxyQuoteReceiver::run()
{
	while(1) {
		if( !isConnected() ) {
			if( reconnect() )
				fax.addTCPClient( this );
		}

		sleep(1);
	}
}

void ProxyQuoteReceiver::start_proxy()
{
	fax.addTCPClient(this);
	fax.run();
}

void ProxyQuoteReceiver::handleStaticBufferedData(void *data, size_t len)
{
	struct proxy_quote_packet_t *proxy_quote = (struct proxy_quote_packet_t *)data;
	handle_proxy_quote(proxy_quote);
}
