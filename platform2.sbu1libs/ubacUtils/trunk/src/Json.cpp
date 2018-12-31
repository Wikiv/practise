#include "Json.h"

using namespace UBACFramer;

const int Json::TYPE_OBJ = 0;
const int Json::TYPE_ARRAY = 1;

const int Json::VALUE_NUMBER = 0;
const int Json::VALUE_STRING = 1;
const int Json::VALUE_JSON = 2;
const int Json::VALUE_BOOLEAN = 3;

Json::Json(int t){
	type = t;
}


Json::~Json(){
}

void Json::toString(string &json_message)
{
	if (TYPE_OBJ == type)
	{
		format_to_object(json_message);	
	} 
	else if (TYPE_ARRAY== type ) 
	{
		format_to_array(json_message);
	}
}
void Json::format_to_object(string &msg){
	msg.clear();
	msg.append("{");
	stringstream s;	
	s.clear();
	map<string,string>::iterator iter_map = ((map<string,string>*)this)->begin();
	bool begin = true;
	while(iter_map!=((map<string,string>*)this)->end()){
		if (!begin){
			s << ",";
		}
		s << iter_map->first << " : " << iter_map->second;
		begin = false;
		iter_map++;
	}
	msg.append(s.str());
	msg.append("}");
}

void Json::addValue(string value, int type){

	string v;
	switch( type ){
		case VALUE_NUMBER:
		case VALUE_JSON:
		case VALUE_BOOLEAN:
			v.append(value);
			break;
		case VALUE_STRING:
			v.append("\"");
			v.append(value);
			v.append("\"");
			break;
		default:
			break;
	}
	((vector<string>*) this)->push_back(v);
}


void Json::addValue(Json a){
	string b;
	a.toString(b);
	addValue(b, VALUE_JSON);
}

void Json::addNameValue(string key, Json a ){
	string b;
	a.toString(b);
	addNameValue(key,b, VALUE_JSON);
}
void Json::addNameValue(string key, string value){
	addNameValue(key, value, VALUE_STRING);
}
void Json::addNameValue(string key, string value , int type){
	string v;
	string k;
	k.append("\"");
	k.append(key);
	k.append("\"");

	switch( type ){
		case VALUE_NUMBER:
		case VALUE_JSON:
		case VALUE_BOOLEAN:
			v.append(value);
			break;
		case VALUE_STRING:
			v.append("\"");
			v.append(value);
			v.append("\"");
			break;
		default:
			break;
	}

	cout << "key: " << k << ", value: " << v << endl;
	((map<string,string> *) this )->insert(make_pair(k, v));

}

void Json::format_to_array(string &msg){
	msg.append("[");
	vector<string>::iterator iter_v = ((vector<string>*)this)->begin();
	bool begin = true;
	while(iter_v!=((vector<string>*)this)->end()){
		if (!begin){
			msg.append(",");
		}
		msg.append(*iter_v);
		begin = false;
		iter_v++;
	}
	msg.append("]");
}
