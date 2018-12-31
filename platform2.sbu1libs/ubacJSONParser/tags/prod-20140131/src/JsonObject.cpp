#include "JsonParser.h"

const int JsonObject::JsonObject_UNKNOWN = -1;
const int JsonObject::JsonObject_ARRAY = 1;
const int JsonObject::JsonObject_MAP = 2;
const int JsonObject::JsonObject_VALUE = 3;
const int JsonObject::JsonObject_BOOL = 4;
const int JsonObject::JsonObject_INT = 5;
const int JsonObject::JsonObject_DOUBLE = 6;
const int JsonObject::JsonObject_NULL = 7;

JsonObject::JsonObject(string sMessage) : string(sMessage)
{
	this->iObjectType = JsonObject_VALUE;
}

JsonObject::JsonObject(map<string, JsonObject> mapObject) :
	map<string, JsonObject>(mapObject)
{
	this->iObjectType = JsonObject_MAP;
}

JsonObject::JsonObject(vector<JsonObject> vObject) : vector<JsonObject>
	(vObject)
{
	this->iObjectType = JsonObject_ARRAY;
}

JsonObject::JsonObject(JsonInt jInt) : JsonInt(jInt.getValue())
{
	this->iObjectType = JsonObject_INT;
}

JsonObject::JsonObject(JsonDouble jDouble) : JsonDouble(jDouble.getValue())
{
	this->iObjectType = JsonObject_DOUBLE;
}

JsonObject::JsonObject(JsonBool jBool) : JsonBool(jBool.getValue())
{
	this->iObjectType = JsonObject_BOOL;
}

JsonObject & JsonObject::operator[](string sKey)
{
	iObjectType = JsonObject_MAP;
	map<string, JsonObject>::iterator iMap;
	iMap = ((map<string, JsonObject> *)this)->find( sKey );
	JsonObject sResponse;

	if( iMap == ((map<string, JsonObject> *)this)->end() ) {
		((map<string, JsonObject> *)this)->insert( make_pair(sKey, sResponse) );
	}

	iMap = ((map<string, JsonObject> *)this)->find( sKey );
	return iMap->second;
}

bool JsonObject::hasKey(string sKey)
{
	map<string, JsonObject>::iterator iMap;
	iMap = ((map<string, JsonObject> *)this)->find( sKey );

	return iMap != ((map<string, JsonObject> *)this)->end();
}

JsonObject JsonObject::getJsonObject(string sKey) throw(Exceptions)
{
	map<string, JsonObject>::iterator iMap;
	iMap = ((map<string, JsonObject> *)this)->find( sKey );

	if(iMap != ((map<string, JsonObject> *)this)->end())
	{
		return iMap->second;
	} else {
		Exceptions e;
		e.setMessage("Key " + sKey + " not found");
		throw e;
	}
}

JsonObject & JsonObject::operator[](uint16_t iIndex)
{
	iObjectType = JsonObject_ARRAY;
	return ((vector<JsonObject> *) this)->at(iIndex);
}


string JsonObject::toString()
{
	string sMessage;

	if( iObjectType == JsonObject_VALUE ) {
		sMessage += "\"" + (string)(*this) + "\"";

	} else if( iObjectType == JsonObject_MAP ) {
		map<string, JsonObject> mapObject = (map<string, JsonObject>)(*this);
		map<string, JsonObject>::iterator iMap;
		sMessage += "{";
		int i = 0;

		for(iMap = mapObject.begin(); iMap != mapObject.end(); iMap++) {

			if( i == 0 ) {
				sMessage += "\"" + iMap->first + "\":"  + iMap->second.toString();

			} else {
				sMessage += ",\"" + iMap->first + "\":" + iMap->second.toString();
			}

			i++;
			//return iMap->second.toString();
		}

		sMessage += "}";

	} else if( iObjectType == JsonObject_ARRAY ) {
		vector<JsonObject> vObject = (vector<JsonObject>)(*this);
		vector<JsonObject>::iterator iVector = vObject.begin();
		sMessage += "[";

		while( iVector != vObject.end() ) {
			sMessage += (*iVector).toString() + ",";
			iVector++;
		}

		if( (sMessage.length() > 1) && (sMessage[sMessage.length() - 1] == ',') )
			sMessage = sMessage.substr(0, sMessage.length() - 1);

		sMessage += "]";

	} else if( iObjectType == JsonObject_INT ) {
		char buffer[1024] = {'\0'};
		sprintf(buffer, "%ld", ((JsonInt *)this)->getValue());
		sMessage += (( JsonInt *) this)->toString();

	} else if( iObjectType == JsonObject_DOUBLE ) {
		sMessage += ( (JsonDouble *) this)->toString();

	} else if( iObjectType == JsonObject_BOOL ) {
		sMessage += ((JsonBool *) this)->toString();

	} else if( iObjectType == JsonObject_NULL ) {
		sMessage += "null";

	} else {
		cout << "unknown iObjectType " << endl;
	}

	return sMessage;
}
