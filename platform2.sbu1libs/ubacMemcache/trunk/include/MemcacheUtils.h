#ifndef _UBAC_MEMCACHE_UTILS_H_
#define _UBAC_MEMCACHE_UTILS_H_

#include <ubacipc/TCPClient.h>
#include <ubacutils/IFHelper.h>

#include <vector>

#include "MemCache.h"

using namespace std;

namespace UBACMEMCACHE {
    /// Class Slab stores data that Memcache allocates.
    class Slab
    {
        public:
	    /// count of items
            string entries;
	    /// Slab ID
            string id;

    };
    /// Class KeyValue 
    class KeyValue
    {
        public:
	    /// Item key
            string key;
	    /// Item Value
            char * value;
	    /// Value Length
            size_t valueLen;

            ~KeyValue()
            {
                free(value);
            }
    };
 
    /// Class MemcacheUtils to retrieve contents from a specific namespace.
    class MemcacheUtils:
        public UBACIPC::TCPClient
    {
        private :
            string namesp;
            IFHelper ifHelper;
            string ip;
            int port;

        public:
	    /// Create MemcacheUtils object with memcache server as `ip' opened at `port', with namespace as `namesp'.
            MemcacheUtils(string ip, int port, string namesp);
	    /** Retrieves the list of Slabs which includes the count of items stored within each Slab along with the Slab ID.
            * <a href="http://www.alphadevx.com/a/90-Accessing-Memcached-from-the-command-line">Please refer here for more details</a> */
            vector<Slab> getSlabs();
	    /// Retrieves the keys contained within each Slab.
            vector<string> getKeys();
            /** Retrieves the actual value of the item stored within each Slab using 'key' retrived using 'getKeys'.
	    * Delete the KeyValue object after the usage. This is very important. */
            vector<KeyValue *> getKeyValues();

    };
};

#endif /* MEMCACHE_UTILS_H_ */
