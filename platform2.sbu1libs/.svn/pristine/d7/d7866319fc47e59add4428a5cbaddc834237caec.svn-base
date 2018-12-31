#ifndef __QUOTE_PACKET_UTILS_H__
#define __QUOTE_PACKET_UTILS_H__

#include "QuotePacket.h"
#include <ubacdata/UBACData.h>
#include <iostream>

#include <ubacutils/IFHelper.h>
#include <jsonparser/JsonParser.h>

class QuotePacketUtils
{
	public:
		static void convert_proxy_to_push(struct proxy_quote_packet_t *proxy_quote,
										  struct quote_packet_t *push_quote);

		static string getMarketDepth(struct market_depth_t, ExtMod *extMod);
		static JsonObject getMarketDepth(struct market_depth_t *);
		static string getMarketDepthWithYield(struct proxy_quote_packet_t
											  *proxy_quote);
		static string getLevel1Quote(struct proxy_quote_packet_t *proxy_quote,
									 ExtMod *extMod);
		static JsonObject getLevel2Quote(struct proxy_quote_packet_t *proxy_quote);
		static JsonObject getLevel1Quote(struct proxy_quote_packet_t *proxy_quote);

		static const uint8_t ResponseType_UBAC;
		static const uint8_t ResponseType_JSON;
};

#endif /* __QUOTE_PACKET_UTILS_H__ */
