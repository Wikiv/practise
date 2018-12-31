#include "UBACRequestCache.h"

UBACRequestCache::UBACRequestCache()
{
}

UBACRequestCache::~UBACRequestCache()
{
}

void UBACRequestCache::set(string sSubscriptionType, vector<string>symbolList,
						   ExtMod *extMod)
{
	reset( sSubscriptionType );

	subscriptionMap.insert( make_pair(sSubscriptionType, symbolList) );
	extModMap.insert( make_pair(sSubscriptionType, extMod) );
}

void UBACRequestCache::reset()
{
	subscriptionMap.clear();

	for( map<string, ExtMod *>::iterator iExtMod = extModMap.begin();
			iExtMod != extModMap.end() ; iExtMod++ ) {
		ExtMod *tmpExtMod = iExtMod->second;
		delete tmpExtMod;
	}

	extModMap.clear();
}

void UBACRequestCache::reset(string sSubscriptionType)
{
	map<string, vector<string> >::iterator iSubscription = subscriptionMap.find(
				sSubscriptionType );

	if( iSubscription != subscriptionMap.end() ) {
		subscriptionMap.erase( iSubscription );
	}

	map<string, ExtMod *>::iterator iExtMod = extModMap.find( sSubscriptionType );

	if( iExtMod != extModMap.end() ) {
		ExtMod *tmpExtMod = iExtMod->second;
		delete tmpExtMod;
		extModMap.erase( iExtMod );
	}
}

bool UBACRequestCache::isSubscribed(string sSubscriptionType, string sSymbol,
									ExtMod *extMod)
{
	map<string, vector<string> >::iterator iSubscription = subscriptionMap.find(
				sSubscriptionType );

	if( iSubscription == subscriptionMap.end() ) {
		return false;

	} else {
		vector<string>::iterator iSymbol = ::find( iSubscription->second.begin(),
										   iSubscription->second.end(), sSymbol );

		if( iSymbol == iSubscription->second.end() ) {
			return false;

		} else {
			map<string, ExtMod *>::iterator iExtMod = extModMap.find( sSubscriptionType );

			if( iExtMod != extModMap.end() )
				extMod = iExtMod->second;

			return true;
		}
	}
}
