#ifndef __IF_SUBSCRIPTIONS_H__
#define __IF_SUBSCRIPTIONS_H__

#include "SBU2StreamingRequest.h"

class IFSubscriptions
{
	public:
		IFSubscriptions() {}
		~IFSubscriptions() {}

		virtual void onLevel1Subscribe(vector<string> symbolList) {}
		virtual void onLevel2Subscribe(vector<string> symbolList) {}
		virtual void onLevel3Subscribe(vector<string> symbolList) {}

		virtual void onLevel1Subscribe(SBU2StreamingRequest request) {}
		virtual void onLevel2Subscribe(SBU2StreamingRequest request) {}
		virtual void onPositionsSubscribe(SBU2StreamingRequest request) {}
		virtual void onOrdersSubscribe(SBU2StreamingRequest request) {}
		virtual void onBalancesSubscribe(SBU2StreamingRequest request) {}
		virtual void onAlertsSubscribe(SBU2StreamingRequest request) {}
		virtual void onTradeSymbolsSubscribe(SBU2StreamingRequest request) {}
		virtual void onLiveTradesSubscribe(SBU2StreamingRequest request) {}
        virtual void onAccountUpdateSubscribe(SBU2StreamingRequest request) {}

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
};

#endif /* __IF_SUBSCRIPTIONS_H__ */
