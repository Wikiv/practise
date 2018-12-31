#ifndef __UBAC_JSON_H__
#define __UBAC_JSON_H__

#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

#include <yajl/yajl_parse.h>
#include <yajl/yajl_gen.h>

#include <ubacutils/Exceptions.h>

typedef unsigned short int uint16_t;

using namespace std;

namespace UBACJSON
{
	class JsonInt
	{
		public:
			JsonInt() {}
			~JsonInt() {}
			JsonInt(int64_t iValue)
			{
				this->iValue = iValue;
			}
			int64_t getValue()
			{
				return iValue;
			}
            string toString() 
            {
    	    	char buffer[1024] = {'\0'};
	    	    sprintf(buffer, "%ld", this->iValue);

                string s(buffer);

                return s;
            }
		private:
			int64_t iValue;
	};

	class JsonDouble
	{
		public:
			JsonDouble() {}
			~JsonDouble() {}
			JsonDouble(double dValue)
			{
				this->dValue = dValue;
			}
			double getValue()
			{
				return this->dValue;
			}

			string toString()
			{
				char buffer[1024] = {'\0'};
				size_t len = sprintf(buffer, "%f", this->dValue);

				size_t j = len;

				// decrementing the index until a non-zero character finds.
				while(j > 0 && buffer[j - 1] == '0')
				{
					j--;
				}

				// looking for dot char
				if (len != j && buffer[j - 1] == '.') 
					j--;
				
				string s(buffer, 0, j);

				return s;
			}
		private:
			double dValue;
	};

	class JsonBool
	{
		private:
			bool bValue;

		public:
			JsonBool() {}
			~JsonBool() {}
			explicit JsonBool(bool bValue)
			{
				this->bValue = bValue;
			}
			bool getValue()
			{
				return this->bValue;
			}
			string toString()
			{
				return this->bValue ? "true" : "false";
			}
	};

	/* Class JsonObject, which abstracts json data. All integer, null, and boolean
	 * values are taken as string. */
	class JsonObject :
		public vector<JsonObject>,
		public map<string, JsonObject>,
		public string,
		public JsonInt,
		public JsonDouble,
		public JsonBool
	{
		public:
			int iObjectType;

			const static int JsonObject_UNKNOWN;
			const static int JsonObject_ARRAY;
			const static int JsonObject_MAP;
			const static int JsonObject_VALUE;
			const static int JsonObject_BOOL;
			const static int JsonObject_INT;
			const static int JsonObject_DOUBLE;
			const static int JsonObject_NULL;

			JsonObject(string);
			JsonObject(vector<JsonObject>);
			JsonObject(map<string, JsonObject>);
			JsonObject(JsonInt);
			JsonObject(JsonDouble);
			JsonObject(JsonBool);
			JsonObject() { this->iObjectType = JsonObject_UNKNOWN; }
			~JsonObject() {}


			/* Access objects from a map. */
			JsonObject & operator[](string sKey);
			/* Access objects from an array. */
			JsonObject & operator[](uint16_t iIndex);

			bool hasKey(string key);
			JsonObject getJsonObject(string sKey) throw(Exceptions);
			string toString();
	};

    class JsonObjectList:
        public vector<JsonObject>
    {
        private:
            bool dAnyValueInserted;

        public:
            JsonObjectList()
            {
                dAnyValueInserted = false;
            }

            void push_back(const JsonObject & jsonObject)
            {
                vector<JsonObject>::push_back(jsonObject);

                dAnyValueInserted = true;
            }

            bool isAnyValueInserted()
            {
                return dAnyValueInserted;
            }

    };

	class JsonParser
	{
		public:
			JsonParser(string sData, bool bEscapeChars = false);
			JsonObject getJsonObject();

		private:
//			JsonObject magicObject;
			void parse(string sData);

			yajl_handle hand;
			yajl_gen g;
			yajl_status stat;

			bool bIsJson;

			void setNodeValue(JsonObject & node);
			void setMapValue(JsonObject sValue);

            JsonObjectList objectList;			

			JsonObject getLastObject();
		public:
			int reformat_null();
			int reformat_boolean(int boolean);
			int reformat_number(const char * s, unsigned int l);
			int reformat_string(const unsigned char * stringVal, unsigned int stringLen);
			int reformat_map_key(const unsigned char * stringVal, unsigned int stringLen);
			int reformat_start_map();
			int reformat_end_map();
			int reformat_start_array();
			int reformat_end_array();
			int reformat_integer(int64_t i);
			int reformat_double(double d);

			bool isValidJson();

	};
};

using namespace UBACJSON;

#endif /* __UBAC_JSON_H__ */
