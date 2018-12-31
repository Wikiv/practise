#include "YamlConfig.h"

void YamlValue::clear()
{
        static_cast< map<string, YamlValue> *>(this)->clear();
        static_cast< string *>(this)->clear();
}

/** Used for fetching a yaml value using [] operator. Similar to a get method. */
YamlValue YamlValue::operator[](const string sKey)
{
        map<string, YamlValue>::iterator i;
        map<string, YamlValue> *tmpValue = static_cast< map<string, YamlValue> *>(this);

        i = tmpValue->find( sKey );
        if( i != tmpValue->end() ) {
                return i->second;
        } else {
                YamlValue s;
                s.append("");
                return s;
        }
}

YamlValue YamlValue::operator+=(const YamlValue yamlValue)
{
       map<string, YamlValue> tmpValue = (map<string, YamlValue>)yamlValue;
       map<string, YamlValue> * thisValue = (static_cast< map<string, YamlValue> *>(this));
       map<string, YamlValue>::iterator i;
       for(i = tmpValue.begin(); i != tmpValue.end(); i++) {
               if( thisValue->find( i->first ) == thisValue->end() ) {
                       thisValue->insert( make_pair( i->first, i->second ) );
               } else {
                       YamlValue & child = (YamlValue &)((*thisValue)[i->first]);
                       YamlValue dest = yamlValue;
                       child += dest[i->first];
               }
       }
       YamlValue *v = static_cast<YamlValue *>(thisValue);
       return *v;
}

