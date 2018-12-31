#include "MemCache.h"

/********************************************************************
 * A wrapper for memcache's client side operations.                 *
 * Handles namespace `bucketName`, since it will allow easy    *
 * access in ruby clients and primarily classify data types.        *
 * The same implementation has been used in other programs also.    *
 ********************************************************************/


/********************************************************************
 * Defined below is the constructor for `MemCache`.                 *
 ********************************************************************/

MemCache::MemCache(string cacheIP, int cachePort, string mBucketName)
{
	ptr = memcached_create(NULL);
	bucketName.append( mBucketName );
	sCacheIP = cacheIP;
	iCachePort = cachePort;
	memcached_server_add(ptr, (char *)cacheIP.c_str(), cachePort);
}

/********************************************************************
 * The destructor. Clear private variables used for namespace and   *
 * the memcache pointer.                                            *
 ********************************************************************/

MemCache::~MemCache()
{
	bucketName.clear();
	memcached_free(ptr);
}

/********************************************************************
 * A wrapper class member function (private), for writing data into *
 * the cache. This prefixes the namespace, before the data is       *
 * written to the memcache server.                                  *
 ********************************************************************/

bool MemCache::setCache(string key, string value, time_t expiryTime)
{
	return setCache( bucketName, key, value, expiryTime );
}

void MemCache::reconnect(memcached_return rc)
{
	if ( (rc != MEMCACHED_SUCCESS) && (rc != MEMCACHED_NOTFOUND) ) {
//		memcached_servers_reset(ptr);
		memcached_free(ptr);
		ptr = memcached_create(NULL);
		memcached_server_add(ptr, (char *)sCacheIP.c_str(), iCachePort);
	}
}

bool MemCache::setCache(string mBucketName, string key, string value, time_t expiryTime)
{
	string newKey = makeKey(mBucketName, key);
	lock();
	memcached_return rc = memcached_set(ptr, newKey.c_str(), newKey.length(), value.c_str(), value.length(), expiryTime, (uint32_t)0);
	reconnect(rc);
	unlock();
	return (rc == MEMCACHED_SUCCESS);
}

bool MemCache::setCache(string mBucketName, string key, void *data, size_t len, time_t expiryTime)
{
	string newKey = makeKey(mBucketName, key);
	lock();
	memcached_return rc = memcached_set(ptr, newKey.c_str(), newKey.length(), (const char *)data, len, expiryTime, (uint32_t)0);
	reconnect(rc);
	unlock();
	return (rc == MEMCACHED_SUCCESS);
}

bool MemCache::setCache(string key, void *data, size_t len, time_t expiryTime)
{
	return setCache( bucketName, key, data, len, expiryTime );
}

bool MemCache::getCache(string mBucketName, string key, char * & data, size_t & len)
{
	uint32_t flags = 0;
	memcached_return error;
	string newKey = makeKey(mBucketName, key);
	lock();
	data = memcached_get(ptr, newKey.c_str(), newKey.length(), &len, &flags, &error);
	reconnect(error);
	unlock();
	bool retFlag = ( error == MEMCACHED_SUCCESS );
	return retFlag;
}

bool MemCache::getCache(string key, char * & data, size_t & len)
{
	return getCache(bucketName, key, data, len);
}

bool MemCache::getCache(string mBucketName, string key, string & value)
{
	uint32_t flags = 0;
	memcached_return error;
	size_t lengthOfValue;
	string newKey = makeKey(mBucketName, key);
	lock();
	char *data = memcached_get(ptr, newKey.c_str(), newKey.length(), &lengthOfValue, &flags, &error);
	reconnect(error);
	unlock();
	bool retFlag = ( error == MEMCACHED_SUCCESS );
	if( retFlag ) {
		value.append( data, lengthOfValue);
		free( data );
		data = NULL;
	}
	return retFlag;
}

bool MemCache::getCache(string key, string & value)
{
	return getCache(bucketName, key, value);
}

bool MemCache::deleteCache(string mBucketName, string key)
{
	string new_key = makeKey(mBucketName, key);
	lock();
	memcached_return error = memcached_delete (ptr, new_key.c_str(), new_key.length(), 0);
	unlock();
	return ( error == MEMCACHED_SUCCESS );
}

bool MemCache::deleteCache(string key)
{
	return deleteCache(bucketName, key);
}

string MemCache::makeKey(string sBucketName, string sKey)
{
	string sNewKey = sBucketName + ":" + sKey;
	return sNewKey;
}
