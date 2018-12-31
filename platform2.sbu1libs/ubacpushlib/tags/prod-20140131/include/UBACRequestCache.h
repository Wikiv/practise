#ifndef __UBAC_REQUEST_CACHE_H__
#define __UBAC_REQUEST_CACHE_H__

#include <iostream>
#include <vector>

#include <ubacdata/UBACData.h>

class UBACRequestCache
{
	public:
		UBACRequestCache();
		~UBACRequestCache();

		void set(string sSubscriptionType, vector<string>symbolList, ExtMod *extMod);
		void reset(string sSubscriptionType );
		void reset( );
		bool isSubscribed(string sSubscriptionType, string sSymbol, ExtMod *extMod);

	private:
		map<string, ExtMod *>extModMap;
		map<string , vector<string> >subscriptionMap;
};

#endif /* __UBAC_REQUEST_CACHE_H__ */
