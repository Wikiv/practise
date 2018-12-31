#ifndef _UBAC_MEMCACHE_UTILS_H_
#define _UBAC_MEMCACHE_UTILS_H_

#include <ubacipc/TCPClient.h>
#include <ubacutils/IFHelper.h>

#include <vector>

#include "MemCache.h"

using namespace std;

namespace UBACMEMCACHE {

    class Slab
    {
        public:
            string entries;
            string id;

    };

    class KeyValue
    {
        public:
            string key;
            char * value;
            size_t valueLen;

            ~KeyValue()
            {
                free(value);
            }
    };

    class MemcacheUtils:
        public TCPClient
    {
        private :
            string namesp;
            IFHelper ifHelper;
            string ip;
            int port;

        public:
            MemcacheUtils(string ip, int port, string namesp);

            vector<Slab> getSlabs();

            vector<string> getKeys();

            vector<KeyValue *> getKeyValues();

    };
};

#endif /* MEMCACHE_UTILS_H_ */
