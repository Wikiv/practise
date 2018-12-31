#ifndef _JSTRING_DEF
#define _JSTRING_DEF
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

namespace UBACFramer {
class Json:
	public map<string,string>,
	public vector<string>
{	
	public:
		const static int  TYPE_OBJ;//0;
		const static int  TYPE_ARRAY;//1;
		const static int  VALUE_NUMBER;//0;
		const static int  VALUE_STRING;//1;
		const static int  VALUE_JSON;//2;
		const static int  VALUE_BOOLEAN;//3;

		Json(){ 
			type =  TYPE_OBJ;
		};
		
		Json(int type);
		~Json();

		void addValue(string value, int type);
		void addValue(Json value);

		void addNameValue(string key, Json value);
		void addNameValue(string key, string value);
		void addNameValue(string key, string value, int type);
		void toString(string &json_object);
	private:		
		int type;
		// type of the value
		// "number"
		// "string"
		// "boolean"
		// "json"
		// defaults to string


		void format_to_array(string &m);
		void format_to_object(string &a);
		
};
};

using namespace UBACFramer;

#endif
