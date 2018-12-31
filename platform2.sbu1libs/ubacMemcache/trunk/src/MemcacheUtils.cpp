#include "MemcacheUtils.h"

using namespace UBACMEMCACHE;

MemcacheUtils::MemcacheUtils(string ip, int port, string namesp): TCPClient(ip, port)
{
    this->ip = ip;
    this->port = port;
    this->namesp = namesp;
}

vector <Slab> MemcacheUtils::getSlabs()
{
    vector<Slab> output;

    this->sendData("stats items\r\n");

    string data;
    this->readUntilDelimiter(data, "END\r\n");

    vector<string> lines;

    ifHelper.split(data, "\r\n", lines);

    vector<string>::iterator iter = lines.begin();

    vector<string> _tmp;
    while( iter != lines.end())
    {
        ifHelper.split( *iter, ":number ", _tmp);

        if (_tmp.size() > 1)
        {
            Slab slab;
            slab.entries = _tmp[1];

            string _first = _tmp[0];
            _tmp.clear();

            ifHelper.split( _first, ":", _tmp);

            slab.id = _tmp[1];

            output.push_back(slab);
        }

        _tmp.clear();

        iter++;
    }

    return output;
}

vector<string> MemcacheUtils::getKeys() 
{
    vector<Slab> slabs = getSlabs();
    cout << "No of Memache Slabs : " << slabs.size() << endl;

    vector<string> output;

    vector<Slab>::iterator  iter = slabs.begin();

    while ( iter != slabs.end()) 
    {
        string command = "stats cachedump ";
        command.append(iter->id + " ");
        command.append(iter->entries + " ");

        this->sendData(command + "\r\n");

        string data;
        this->readUntilDelimiter(data, "END\r\n");

        vector<string> lines;

        ifHelper.split(data, "\r\n", lines);

        vector<string>::iterator iter2 = lines.begin();

        vector<string> _tmp;
        while ( iter2 != lines.end() )
        {

            ifHelper.split(* iter2, " ", _tmp);

            if (_tmp.size() > 1)
            {
                string key = _tmp[1];
                // Stripping of namespace
                _tmp.clear();

                if (this->namesp.length() > 0) {

                    ifHelper.split(key, this->namesp + ":", _tmp);

                    if ( _tmp.size() > 1 )
                    {
                        output.push_back(_tmp[1]);
                    }
                } else {
                    output.push_back( key );
                }

            }

            _tmp.clear();

            iter2++;
        }

        iter++;
    }

    return output;
}

vector<KeyValue *> MemcacheUtils::getKeyValues()
{
     MemCache memCache(this->ip, this->port, this->namesp);

     vector<KeyValue *> keyValues;

     vector<string> keys = getKeys();

     vector<string>::iterator it = keys.begin();

     while ( it != keys.end() )
     {
         KeyValue * kv = new KeyValue();

         kv->key = *it;
         kv->value = NULL;
         kv->valueLen = 0;

         memCache.getCache(kv->key, kv->value, kv->valueLen);

         keyValues.push_back(kv);

         it++;
     }

     return keyValues;
}
