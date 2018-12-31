#ifndef __IF_SUBSCRIPTIONS_H__
#define __IF_SUBSCRIPTIONS_H__

#include "SBU2StreamingRequest.h"
#include "SBU2PushClient.h"
class SBU2PushClient;

class IFSubscriptions 
{
	public:
		IFSubscriptions() {}
		virtual ~IFSubscriptions() {}

        /* Added to handle quote through streaming to send the last updated packet */
        virtual void onLevel1Subscribe(SBU2StreamingRequest request, void *client) {}

        /* Added to handle market depth through streaming to send the last updated packet */
		virtual void onLevel2Subscribe(SBU2StreamingRequest request, void *client) {}

		virtual void onPositionsSubscribe(SBU2StreamingRequest request, void *client) {}
		virtual void onOrdersSubscribe(SBU2StreamingRequest request, void *client) {}
		virtual void onBalancesSubscribe(SBU2StreamingRequest request, void *client) {}
		virtual void onAlertsSubscribe(SBU2StreamingRequest request, void *client) {}
		virtual void onTradeSymbolsSubscribe(SBU2StreamingRequest request, void *client) {}
		virtual void onLiveTradesSubscribe(SBU2StreamingRequest request, void *client) {}
        virtual void onAccountUpdateSubscribe(SBU2StreamingRequest request, void *client) {}
		
		virtual void onLevel1UnSubscribe(SBU2StreamingRequest request,
										 vector<string> symbolsToUnsubscribe) {}
		virtual void onLevel2UnSubscribe(SBU2StreamingRequest request,
										 vector<string> symbolsToUnsubscribe) {}
		virtual void onPositionsUnSubscribe(SBU2StreamingRequest request) {}
		virtual void onOrdersUnSubscribe(SBU2StreamingRequest request) {}
		virtual void onBalancesUnSubscribe(SBU2StreamingRequest request) {}
		virtual void onAlertsUnSubscribe(SBU2StreamingRequest request) {}
		virtual void onTradeSymbolsUnSubscribe(SBU2StreamingRequest request,
											   vector<string> symbolsToUnsubscribe) {}
		virtual void onLiveTradesUnSubscribe(SBU2StreamingRequest request) {}
		virtual void onAccountUpdateUnSubscribe(SBU2StreamingRequest request) {}
		
		virtual void onPushClientClose(SBU2PushClient *) {}
		virtual bool onPushClientSessionChange(string prev, string current, SBU2StreamingRequest & request, SBU2PushClient *) {return true;}

		/* 
		 *  The application side should return session is valid or not. 
		 *  If not connection will be removed from all tables and marked for removal
		 */
		virtual bool onPushClientInitialSession(string current, SBU2StreamingRequest & request, SBU2PushClient *) {return true;}

		/* 
		 *  Application side should return whether it supports empty session.
		 *  If not, connection will be removed from all tables and marked for removal
		 */
		virtual bool onPushClientEmptySession(SBU2PushClient *) {return true;}
};

#endif /* __IF_SUBSCRIPTIONS_H__ */
