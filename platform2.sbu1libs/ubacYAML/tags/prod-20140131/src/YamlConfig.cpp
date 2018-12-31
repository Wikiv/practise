#include "YamlConfig.h"

YamlConfig::YamlConfig(string sFilename)
{
	this->sFilename = sFilename;
	parse();
}

YamlConfig::~YamlConfig()
{
}

void YamlConfig::parse()
{
	FILE *fp = fopen(sFilename.c_str(), "rb");
	yaml_parser_t parser;;

	yaml_parser_initialize(&parser);

	yaml_parser_set_input_file(&parser, fp);

	yaml_event_t event;

	vector<YamlValue>list;

	bool isMaping = false;
	int iMappingLevel = 0;
	string sName, sValue, sBuffer;

	while( yaml_parser_parse(&parser, &event) && (event.type != YAML_STREAM_END_EVENT) ) {
		if( event.type == YAML_NO_EVENT ) {
		} else if( event.type == YAML_STREAM_START_EVENT ) {
		} else if( event.type == YAML_DOCUMENT_START_EVENT ) {
		} else if( event.type == YAML_DOCUMENT_END_EVENT ) {
		} else if( event.type == YAML_ALIAS_EVENT ) {
		} else if( event.type == YAML_SCALAR_EVENT ) {
			if( sName.length() == 0 ) {
				sName.append( (char *)event.data.scalar.value );
			} else if( sValue.length() == 0 ) {
				sValue.append( (char *)event.data.scalar.value );
				if( isMaping ) {
					if( (list.size() > 0) && (iMappingLevel > 1) ) {
						YamlValue tmpMap(*(list.end() - 1));
						list.erase( list.end() - 1 );

						tmpMap.yamlValueType = YamlValue::YamlValue_YAML_VALUE;

						string sKey( static_cast< map<string, YamlValue> *>(&tmpMap)->begin()->first );
						map<string, YamlValue>::iterator iKey = static_cast< map<string, YamlValue> *>(&tmpMap)->find( sKey );
						YamlValue tmpValue1( iKey->second );
						static_cast< map<string, YamlValue> *>(&tmpMap)->erase( iKey );

						YamlValue tmpValue2;
						tmpValue2.append( sValue );
						tmpValue2.yamlValueType = YamlValue::YamlValue_STRING;
						static_cast< map<string, YamlValue> *>(&tmpValue1)->insert( make_pair(sName, tmpValue2) );

						static_cast< map<string, YamlValue> *>(&tmpMap)->insert( make_pair(sKey, tmpValue1) );
						list.push_back( tmpMap );
					} else {
						YamlValue tmpMap;
						tmpMap.yamlValueType = YamlValue::YamlValue_YAML_VALUE;

						YamlValue tmpValue1;
						tmpValue1.append( sValue );
						tmpValue1.yamlValueType = YamlValue::YamlValue_STRING;

						static_cast< map<string, YamlValue> *>(this)->insert( make_pair(sName, tmpValue1) );
					}
				} else {
					YamlValue tmpValue1;
					tmpValue1.append( sValue );
					tmpValue1.yamlValueType = YamlValue::YamlValue_STRING;
					(static_cast< map<string, YamlValue> *>(this))->insert( make_pair(sName, tmpValue1) );
				}
				sName.clear(); sValue.clear();
			}
		} else if( event.type == YAML_SEQUENCE_START_EVENT ) {
		} else if( event.type == YAML_SEQUENCE_END_EVENT ) {
		} else if( event.type == YAML_MAPPING_START_EVENT ) {
			iMappingLevel++;
			isMaping = true;
			if( sName.length() > 0 ) {
				YamlValue tmpValue;
				tmpValue.yamlValueType = YamlValue::YamlValue_YAML_VALUE;
				YamlValue v1;
				static_cast< map<string, YamlValue> *>(&tmpValue)->insert( make_pair(sName, v1) );
				list.push_back( tmpValue );
				sName.clear();
			}
		} else if( event.type == YAML_MAPPING_END_EVENT) {
			isMaping = false;
			if( list.size() > 0 ) {
				YamlValue tmpMap(*(list.end() - 1));
				list.erase( list.end() - 1 );
				if( (list.size() > 0) && (iMappingLevel > 1) ) {
					YamlValue tmpMap1(*(list.end() - 1));
					list.erase( list.end() - 1 );
					string sKey( (static_cast< map<string, YamlValue> >(tmpMap1)).begin()->first );

					map<string, YamlValue>::iterator i = static_cast< map<string, YamlValue> *>(&tmpMap1)->find( sKey );

					YamlValue tmpValue2(i->second);
					string sPrevKey( static_cast< map<string, YamlValue> *>(&tmpMap)->begin()->first);
					YamlValue sPrevValue( static_cast< map<string, YamlValue> *>(&tmpMap)->begin()->second );
					(static_cast< map<string, YamlValue> *>(&tmpValue2))->insert( make_pair(sPrevKey, sPrevValue) );

					(static_cast< map<string, YamlValue> *>(&tmpMap1))->erase( i );

					(static_cast< map<string, YamlValue> *>(&tmpMap1))->insert( make_pair(sKey, tmpValue2) );

					list.push_back( tmpMap1 );
				} else {
					tmpMap.yamlValueType = YamlValue::YamlValue_YAML_VALUE;
					string sKey( (static_cast< map<string, YamlValue> >(tmpMap)).begin()->first );
					YamlValue tmpMap1((static_cast< map<string, YamlValue> >(tmpMap)).begin()->second);
					(static_cast< map<string, YamlValue> *>(this))->insert( make_pair(sKey, tmpMap1) );
				}
			}
			iMappingLevel--;
		}
		yaml_event_delete(&event);
	}

	yaml_parser_delete(&parser);

	fclose(fp);
}

void YamlConfig::print(YamlValue value)
{
	map<string, YamlValue>yamlValue = static_cast< map<string, YamlValue> >(value);
	map<string, YamlValue>::iterator i;
	for(i = yamlValue.begin(); i != yamlValue.end(); i++) {
		if( i->second.yamlValueType == YamlValue::YamlValue_STRING ) {
			string sValue = static_cast<string>(i->second);
			cout << i->first << " = " << sValue << endl;
		} else {
			cout << "Printing: " << i->first << endl;
			print(i->second);
		}
	}
}
