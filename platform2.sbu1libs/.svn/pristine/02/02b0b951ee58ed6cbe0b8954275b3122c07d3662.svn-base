#include "JsonParser.h"


static int reformat_null(void * ctx)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_null();
}

static int reformat_boolean(void * ctx, int boolean)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_boolean(boolean);
}

static int reformat_integer(void * ctx, long long integer)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_integer(integer);
}

static int reformat_double(void * ctx, double d)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_double(d);
}

static int reformat_string(void * ctx, const unsigned char * stringVal,
						   size_t stringLen)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_string(stringVal, stringLen);
}

static int reformat_map_key(void * ctx, const unsigned char * stringVal,
							size_t stringLen)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_map_key(stringVal, stringLen);
}

static int reformat_start_map(void * ctx)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_start_map();
}

static int reformat_end_map(void * ctx)
{

	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_end_map();
}

static int reformat_start_array(void * ctx)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_start_array();
}

static int reformat_end_array(void * ctx)
{
	JsonParser *json = static_cast<JsonParser *>(ctx);
	return json->reformat_end_array();
}

static yajl_callbacks callbacks = {
	reformat_null,
	reformat_boolean,
	reformat_integer,
	reformat_double,
	NULL,
	reformat_string,
	reformat_start_map,
	reformat_map_key,
	reformat_end_map,
	reformat_start_array,
	reformat_end_array
};

JsonParser::JsonParser(string sData, bool bEscapeChars)
{
	bIsJson = false;

	if( bEscapeChars ) {
		string sTmp = sData;
		sData = "";

		for(size_t i = 0; i < sTmp.length(); i++ ) {
			char c = sTmp[i];

			if( (c > 31) && (c < 127) )
				sData.append(&c, 1);
		}
	}

	parse(sData);
}

void JsonParser::parse(string sData)
{
	size_t rd = sData.length();
	const unsigned char *c_data = (const unsigned char *)sData.c_str();

	g = yajl_gen_alloc(NULL);
	hand = yajl_alloc(&callbacks, NULL, this);

	stat = yajl_parse(hand, c_data, rd);
    // Checking above `stat` is not required, since this is not stream based.

    stat = yajl_complete_parse(hand);

	if ( stat != yajl_status_ok ) {

		unsigned char * str = yajl_get_error(hand, 1, c_data, rd);
        cout << "Yajl error Invalid Json " << str << endl;
		yajl_free_error(hand, str);

		bIsJson = false;

	} else {

        bIsJson = true;

        // DELETE
        // If there was no object inserted into the list.
        // Then there is some issue in json string.
		// bIsJson = this->objectList.isAnyValueInserted();
	}

	yajl_gen_free(g);
	yajl_free(hand);
}

int JsonParser::reformat_null()
{
	yajl_gen_null(g);

	JsonObject _j;
	_j.iObjectType = JsonObject::JsonObject_NULL;

	setNodeValue( _j);

	return 1;
}

int JsonParser::reformat_boolean(int boolean)
{
	yajl_gen_bool(g, boolean);

	if (boolean == 0) {
		JsonObject _j(JsonBool(false));
		setNodeValue( _j);

	} else {
		JsonObject _j(JsonBool(true));
		setNodeValue( _j);
	}

	return 1;
}

int JsonParser::reformat_integer(long long i)
{
	yajl_gen_integer(g, i);

    JsonObject _j = JsonObject(JsonInt(i));

	setNodeValue( _j );

	return 1;
}

int JsonParser::reformat_double(double d)
{
	yajl_gen_double(g, d);

    JsonObject _j = JsonObject(JsonDouble(d));

	setNodeValue(_j);

	return 1;
}

int JsonParser::reformat_string(const unsigned char * stringVal,
								size_t stringLen)
{
	yajl_gen_string(g, stringVal, stringLen);
	string str((const char *)stringVal, stringLen);

    JsonObject _j(str);
    
	setNodeValue( _j);

	return 1;
}

int JsonParser::reformat_map_key(const unsigned char * stringVal,
								 size_t stringLen)
{
	yajl_gen_string(g, stringVal, stringLen);
	string str((const char *)stringVal, stringLen);

	JsonObject object, valueObject;
	object.iObjectType = JsonObject::JsonObject_MAP;
	((map<string, JsonObject>&)object).insert( make_pair(str, valueObject) );
	objectList.push_back( object );
	return 1;
}

int JsonParser::reformat_start_map()
{
	JsonObject object;
	object.iObjectType = JsonObject::JsonObject_MAP;

	objectList.push_back( object );

	yajl_gen_map_open(g);
	return 1;
}


int JsonParser::reformat_end_map()
{
	yajl_gen_map_close(g);

	if( objectList.size() > 1 ) {
		JsonObject object(getLastObject());
		setMapValue( object );
	}

	return 1;
}

int JsonParser::reformat_start_array()
{
	JsonObject object;
	object.iObjectType = JsonObject::JsonObject_ARRAY;
	objectList.push_back( object );

	yajl_gen_array_open(g);
	return 1;
}

int JsonParser::reformat_end_array()
{
	yajl_gen_array_close(g);

	if( objectList.size() > 1 ) {
		JsonObject object(getLastObject());
		setMapValue( object );
	}

	return 1;
}

JsonObject JsonParser::getLastObject()
{
	vector<JsonObject>::iterator iObject = objectList.end();
	iObject--;
	JsonObject object( *iObject );
	objectList.pop_back();

	return object;
}

void JsonParser::setNodeValue(JsonObject & jsonObject)
{
    if (objectList.size() < 2)
        return;

    setMapValue(jsonObject);
}

void JsonParser::setMapValue(JsonObject jsonObject)
{

	if( objectList[objectList.size()-1].iObjectType ==
			JsonObject::JsonObject_ARRAY ) {

		((vector<JsonObject>&)objectList[objectList.size()-1]).push_back(jsonObject);

	} else {
		string sKey( ( (map<string, JsonObject> &)objectList[objectList.size()
					   -1]).begin()->first );

		( (map<string, JsonObject> &)objectList[objectList.size()-2]).insert(
			make_pair(sKey, jsonObject) );
		objectList.pop_back();
	}
}

JsonObject JsonParser::getJsonObject()
{
	JsonObject tmpObject;

	if( objectList.size() > 0 )
		tmpObject = objectList[0];

	return tmpObject;
}

bool JsonParser::isValidJson()
{
	return bIsJson;
}

