#ifndef __UBAC_MEMCACHE_H__
#define __UBAC_MEMCACHE_H__

#include <stdio.h>
#include <string>
#include <libmemcached/memcached.h>
#include <ubacipc/Mutex.h>

using namespace std;

namespace UBACMEMCACHE {
	/// Class MemCache
	class MemCache :
		public Mutex
	{
		public:
			/// Create MemCache object with memcache server as `cacheIP' opened at `cachePort', with namespace as `mBucketName'.
			MemCache(string cacheIP, int cachePort, string mBucketName);
			MemCache(string cacheIP, int cachePort);
			~MemCache();
			
			/** Set data in cache. Exclusively specify the namespace in 'mBucketName'. 
			  * Set 'expiryTime' for the cached data. This method is used to store binary data 
			  * or raw structures. */
			bool setCache(string mBucketName, string key, void *data, size_t len, time_t expiryTime = 0);
			/** Set data in cache. Exclusively specify the namespace in 'mBucketName'. 
			  * Set 'expiryTime' for the cached data. */
			bool setCache(string mBucketName, string key, string value, time_t expiryTime = 0);
			/** Set data in cache. Bucket name is the same as the one provided while creating the object.
			  * Set 'expiryTime' for the cached data. Used to set binary data or raw structures. */
			bool setCache(string key, void *data, size_t len, time_t expiryTime = 0);
			/** Set data in cache. Bucket name is the same as the one provided while creating the object.
			  * Set 'expiryTime' for the cached data. */
			bool setCache(string key, string value, time_t expiryTime = 0);

			/** Get data from cache by specifying the bucket 'mBucketName' and expecting binary data. */
			bool getCache(string mBucketName, string key, char * & data, size_t & len);

			/** Get data from cache by specifying the bucket 'mBucketName'. */
			bool getCache(string mBucketName, string key, string & value);

			/** Get data from cache and read binary data. */
			bool getCache(string key, char * & data, size_t & len);

			/** Get data from cache. */
			bool getCache(string key, string & value);

			/** Delete data from memcache server for 'key' in the bucket 'mBucketName'. */
			bool deleteCache(string mBucketName, string key);
			/** Delete data from memcache server for 'key'. */
			bool deleteCache(string key);
		
		private:
			memcached_st *ptr;
			string bucketName;
			string sCacheIP;
			int iCachePort;

			string makeKey(string sBucketName, string sKey);
			void reconnect(memcached_return rc);
	};
};

using namespace UBACMEMCACHE;

#endif /* __UBAC_MEMCACHE_H__ */
