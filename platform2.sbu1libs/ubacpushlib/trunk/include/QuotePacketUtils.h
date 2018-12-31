#ifndef __QUOTE_PACKET_UTILS_H__
#define __QUOTE_PACKET_UTILS_H__

#include "QuotePacket.h"
#include <iostream>

#include <ubacutils/IFHelper.h>
#include <jsonparser/JsonParser.h>

/// Class QuotePacketUtils
class QuotePacketUtils
{
	public:
		
		static void convert_proxy_to_push(struct proxy_quote_packet_t *proxy_quote,
										  struct quote_packet_t *push_quote);

		/** Converts market depth structure to Market depth Json Object and returns the Json Object. */
		static JsonObject getMarketDepth(struct market_depth_t *);
		static string getMarketDepthWithYield(struct proxy_quote_packet_t							
				  *proxy_quote);
		/** Returns Market depth.*/
		static JsonObject getLevel2Quote(struct proxy_quote_packet_t *proxy_quote);
		/** Returns quote. */
		static JsonObject getLevel1Quote(struct proxy_quote_packet_t *proxy_quote);

		/** UBAC response type. */
		static const uint8_t ResponseType_UBAC;
		/** Json response type. */
		static const uint8_t ResponseType_JSON;
};

#endif /* __QUOTE_PACKET_UTILS_H__ */
