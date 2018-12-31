#ifndef __UBAC_YAML_PARSER_H__
#define __UBAC_YAML_PARSER_H__

#include <yaml.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#ifdef _WIN32
typedef __int16 int16_t;
#endif

using namespace std;

namespace UBACYAML {

	/** Class YamlValue. Could be defined in a much generic manner.
	  * However, this is being used here on experimental basis. 
	  * YamlValue represents a yaml value in a general manner.
	  * Either it is a string key or it is a map of fields.
	  */
	class YamlValue :
		public string,
		public map<string, YamlValue>
	{
		public:
			enum {
				/** Indicates that YamlValue is a string value. */
				YamlValue_STRING = 1,
				/** Indicates that YamlValue is holding a map of entries to be looked into. */
				YamlValue_YAML_VALUE = 2
			}YamlValue_t;

			/** Clears the content of YamlValue object. */
			void clear();
			
			/** Used for fetching a yaml value using [] operator. Similar to a get method. */
			YamlValue operator[](const string sKey);

			YamlValue operator+=(const YamlValue yamlValue);

			/** Defines the Yaml Type. Required for identifying, if it is a string value or a map of values. */
			int16_t yamlValueType;
	};

	/** Class YamlConfig for handling yaml config files for reading alone. */
	class YamlConfig :
		public YamlValue
	{
		public: 
			/** Pass the file name to the constructor. */
			YamlConfig(string sFilename);
			~YamlConfig();

		private:
			void parse();

			string sFilename;

			void print( YamlValue);
	};
};

using namespace UBACYAML;

#endif /* __UBAC_YAML_PARSER_H__ */
