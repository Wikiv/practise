#ifndef __GENERIC_CACHE_H__
#define __GENERIC_CACHE_H__

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

namespace UBAC
{
	/// Class GenericCache for implementing generic hash table.
	template <class KeyType, class GenericCacheItem>
	class GenericCache :
		public map<KeyType, GenericCacheItem>
	{
		public:
			GenericCache() {}
			~GenericCache() {}

			/// Remove `key' from the cache.
			void remove(KeyType key)
			{
				typename map<KeyType, GenericCacheItem>::iterator iCacheMap;

				if( isCached(key, iCacheMap) )
					this->erase( iCacheMap );
			}

			/** Set 'item' for 'key' in the cache. */
			void set(KeyType key, GenericCacheItem item)
			{
				typename map<KeyType, GenericCacheItem>::iterator iCacheMap;

				if( isCached(key, iCacheMap) ) {
					this->erase( iCacheMap );
				}

				this->insert(make_pair(key, item));
			}

			/** Get item from the cache for 'key'. */
			GenericCacheItem get(KeyType key)
			{
				typename map<KeyType, GenericCacheItem>::iterator iCacheMap;

				if( isCached(key, iCacheMap) ) {
					return iCacheMap->second;
				}

				GenericCacheItem *item = NULL;
				return *item;
			}

			/** Checks if 'key' is already cached. Returns true or false and sets the iterator 'iCacheMap'; */
			bool isCached(KeyType key,
						  typename map<KeyType, GenericCacheItem>::iterator & iCacheMap)
			{
				typename map<KeyType, GenericCacheItem>::iterator iTmpCacheMap = this->find(
							key );

				if( iTmpCacheMap != this->end() ) {
					iCacheMap = iTmpCacheMap;
					return true;

				} else {
					return false;
				}
			}

			/** Checks if 'key' is already cached. Returns true or false. */
			bool isCached(KeyType key)
			{
				typename map<KeyType, GenericCacheItem>::iterator iCacheMap;
				return isCached(key, iCacheMap);
			}

		private:
	};
};

using namespace UBAC;

#endif /* __GENERIC_CACHE_H__ */
