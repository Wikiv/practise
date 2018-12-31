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
	/// Class JsonInt to handle integer data type.
	class JsonInt
	{
		public:
			JsonInt() {}
			~JsonInt() {}
			JsonInt(int64_t iValue)
			{
				this->iValue = iValue;
			}
			/** Returns the integer value. */
			int64_t getValue()
			{
				return iValue;
			}
			/** Converts the integer value to string and 
			* returns the converted string. */
		    	string toString() 
			{
				char buffer[1024] = {'\0'};
				sprintf(buffer, "%ld", this->iValue);
				return string(buffer);
			}
			/** Clears the integer value and defaults to zero. */
			void clear()
			{
				this->iValue = 0;
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
			/** Converts double to string and truncates the trailing zeroes if any. */
			string toString()
			{
				char buffer[1024] = {'\0'};
				size_t len = sprintf(buffer, "%f", this->dValue);

				size_t j = len;

				// decrementing the index until a non-zero character finds.
				while(j > 0 && buffer[j - 1] == '0'){
					j--;
				}

				// looking for dot char
				if (len != j && buffer[j - 1] == '.') 
					j--;
				
				return string(buffer, 0, j);
			}
			void clear()
			{
				dValue = 0.0;
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
			/** checks 'bValue'. If it is true, string 'true' is returned,
                        * else string 'false' is returned. */
			string toString()
			{
				return this->bValue ? "true" : "false";
			}

	};

	/** Class JsonObject, which abstracts json data. All integer, null, and boolean
	* values are taken as string. 
	*/
	class JsonObject :
		public vector<JsonObject>,
		public map<string, JsonObject>,
		public string,
		public JsonInt,
		public JsonDouble,
		public JsonBool
	{
		public:
			/** Possible values could be
			* JsonObject_ARRAY,
                        * JsonObject_MAP,
                        * JsonObject_VALUE,
			* JsonObject_BOOL,
			* JsonObject_INT,
			* JsonObject_DOUBLE,
			* JsonObject_NULL,
			* JsonObject_UNKNOWN. */
			int iObjectType;

			const static int JsonObject_UNKNOWN;
			const static int JsonObject_ARRAY;
			const static int JsonObject_MAP;
			const static int JsonObject_VALUE;
			const static int JsonObject_BOOL;
			const static int JsonObject_INT;
			const static int JsonObject_DOUBLE;
			const static int JsonObject_NULL;

			/** Constructs Json Object of type String. */
			JsonObject(string);
			/** Constructs Json Object of type double. */
			JsonObject(double val);
			/** Constructs Json Object of type char. */
			JsonObject(const char * val);
			/** Constructs vector of Json Objects. */
			JsonObject(vector<JsonObject>);
			/** Constructs map  of Json Objects with value as Json Object. */
			JsonObject(map<string, JsonObject>);
			/** Constructs JsonObject of type class JsonInt. */
			JsonObject(JsonInt);
			/** Constructs JsonObject of type class JsonDouble. */
			JsonObject(JsonDouble);
			/** Constructs JsonObject of type class JsonBool. */
			JsonObject(JsonBool);
			/** Constructs generic Json Object. */
			JsonObject() { this->iObjectType = JsonObject_UNKNOWN; }
			~JsonObject() {}


			/** Access objects from a map. Overloads the map [] operator.
			* <a href="http://www.cplusplus.com/reference/map/map/operator[]/">Please refer here for more details</a> */
			JsonObject & operator[](string sKey);
			/** Access objects from an array. Overloads the map [] operator.
			* <a href="http://www.cplusplus.com/reference/map/map/operator[]/">Please refer here for more details</a> */
			JsonObject & operator[](uint16_t iIndex);

           		bool operator==(const JsonObject & l) ;
			/** Returns true if the Json object associated with the 'key' is found. */
			bool hasKey(string key);
			/** Returns the Json object associated with the 'key'. 
                        * Throws exception if the 'key' is not found. */
			JsonObject getJsonObject(string sKey) throw(Exceptions);
			/** Converts Json Object to string and returns the converted string. */
			string toString();
			
			void clearAll();

            		size_t size();
		private:
			void replaceSpecialChars(string &data ) ;
	};

    class JsonObjectList:
        public vector<JsonObject>
    {
	/// Class JsonObjectList constructs vector of Json objects.
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
	    /** Returns true if there are any objects inserted in the list. If there is 
	    * no object inserted in the list there is issue in the format and it is 
            * invalid and false is returned. */
            bool isAnyValueInserted()
            {
                return dAnyValueInserted;
            }

    };

	class JsonParser
	{
		/// Class JsonParser parses the string and checks for the json string validity.
		public:
			/** Checks for any escape characters which falls within the 
                        * ascii range 32 to 126 in 'sData' if 'bEscapeChars' is set to true.
                        * Calls Parse to check the validity of json string. 
			* Parse function calls the yajl callbacks. Check for the status and sets the 'bIsJson'
                        * flag accordingly. */
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
			
			/** Returns the 'bIsJson' flag. */
			bool isValidJson();

	};
};

using namespace UBACJSON;

#endif /* __UBAC_JSON_H__ */
