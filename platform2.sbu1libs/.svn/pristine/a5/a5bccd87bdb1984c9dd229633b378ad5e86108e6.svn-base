#include "JsonParser.h"

const int JsonObject::JsonObject_UNKNOWN = -1;
const int JsonObject::JsonObject_ARRAY = 1;
const int JsonObject::JsonObject_MAP = 2;
const int JsonObject::JsonObject_VALUE = 3;
const int JsonObject::JsonObject_BOOL = 4;
const int JsonObject::JsonObject_INT = 5;
const int JsonObject::JsonObject_DOUBLE = 6;
const int JsonObject::JsonObject_NULL = 7;


JsonObject::JsonObject(char const *val ) : string(val)
{
    this->iObjectType = JsonObject_VALUE;	
}

JsonObject::JsonObject(double val ) : JsonDouble(val)
{
    this->iObjectType = JsonObject_DOUBLE;
}

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
    //	map<string, JsonObject>::iterator iMap;
    //	iMap = ((map<string, JsonObject> *)this)->find( sKey );

    //	if( iMap == ((map<string, JsonObject> *)this)->end() ) {
    JsonObject sResponse;
    pair<map<string, JsonObject>::iterator, bool> iPair = 
        ((map<string, JsonObject> *)this)->insert( make_pair(sKey, sResponse) );
    return iPair.first->second;
    //	} else {
    //		return iMap->second;
    //	}

    //	iMap = ((map<string, JsonObject> *)this)->find( sKey );
    //	return iMap->second;
}

bool JsonObject::hasKey(string sKey)
{
    map<string, JsonObject>::iterator iMap;
    iMap = ((map<string, JsonObject> *)this)->find( sKey );

    return iMap != ((map<string, JsonObject> *)this)->end();
}

JsonObject JsonObject::getJsonObject(string sKey) 
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
bool JsonObject::operator==(const JsonObject & l)
{
    if ( iObjectType == JsonObject::JsonObject_VALUE 
            && l.iObjectType == JsonObject::JsonObject_VALUE )
    {
        return ( ( (string *) & l)->compare( (string) (*this) ) ) == 0;

    } else if ( iObjectType == JsonObject::JsonObject_BOOL 
            && l.iObjectType == JsonObject::JsonObject_BOOL ) 
    {
        return ((JsonBool *) & l)->getValue() == ((JsonBool *) this)->getValue();
    } else if ( iObjectType == JsonObject::JsonObject_INT 
            && l.iObjectType == JsonObject::JsonObject_INT ) 
    {
        return ((JsonInt *) & l)->getValue() == ((JsonInt *) this)->getValue();

    } else if ( iObjectType == JsonObject::JsonObject_DOUBLE
            && l.iObjectType == JsonObject::JsonObject_DOUBLE )
    {
        return ((JsonDouble *) & l)->getValue() == ((JsonDouble *) this)->getValue();

    } else if ( iObjectType == JsonObject::JsonObject_NULL
            && l.iObjectType == JsonObject::JsonObject_NULL )
    {
        return true;
    }

    return false;
}

JsonObject & JsonObject::operator[](uint16_t iIndex)
{
    iObjectType = JsonObject_ARRAY;
    return ((vector<JsonObject> *) this)->at(iIndex);
}

void JsonObject::replaceSpecialChars(string &data )                             
{       
        string buffer = "";                                             
        
        for (size_t i = 0 ; i < data.length(); i++ ) {                  
                char ch = data[i];
                if ( ch == '\"' ) {
                        buffer.append("\\\"");                          
                } else if ( ch == '\\') {
                        buffer.append("\\\\");                          
                } else if ( ch == '\n' ) {
                        buffer.append("\\n");                           
                } else if ( ch == '\t' ) {
                        buffer.append("\\t");                           
                } else if ( ch == '\b' ) {
                        buffer.append("\\b");                           
                } else if ( ch == '\f' ) {
                        buffer.append("\\f");                           
                } else if ( ch == '\r' ) {
                        buffer.append("\\r");                           
                } else {
                        buffer.append(&ch , 1 );                        
                }                                                       
        }
        data = buffer;                                                  
}

string JsonObject::toString()
{
    string sMessage;

    if( iObjectType == JsonObject_VALUE ) {
	string sData(this->c_str());
	replaceSpecialChars(sData );
        sMessage += "\"" + sData + "\"";
    } else if( iObjectType == JsonObject_MAP ) {
        map<string, JsonObject> mapObject = (map<string, JsonObject>)(*this);
        map<string, JsonObject>::iterator iMap;
        sMessage += "{";
        int i = 0;

        for(iMap = mapObject.begin(); iMap != mapObject.end(); iMap++) {
	    if (iMap->second.iObjectType != JsonObject_UNKNOWN) {
                if( i == 0 ) {
                    sMessage += "\"" + iMap->first + "\":"  + iMap->second.toString();
                } else {
                    sMessage += ",\"" + iMap->first + "\":" + iMap->second.toString();
                }
     	        i++;
	    }
        }

        sMessage += "}";

    } else if( iObjectType == JsonObject_ARRAY ) {
        vector<JsonObject> vObject = (vector<JsonObject>)(*this);
        vector<JsonObject>::iterator iVector = vObject.begin();
        sMessage += "[";

        while( iVector != vObject.end() ) {
	    if ( (*iVector).iObjectType != JsonObject_UNKNOWN ) {
		    sMessage += (*iVector).toString() + ",";
	    }
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
void JsonObject::clearAll()
{
    this->vector<JsonObject>::clear();
    this->map<string,JsonObject>::clear();
    this->string::clear();
    this->JsonInt::clear();
    this->JsonDouble::clear();
}

size_t JsonObject::size()
{

    if ( iObjectType == JsonObject::JsonObject_VALUE )
    {
        return ((string *) this)->size();

    } else if ( iObjectType == JsonObject::JsonObject_BOOL ) 
    {
        return sizeof( (JsonBool) (* this) );
    }
    else if ( iObjectType == JsonObject::JsonObject_INT ) 
    {
        return sizeof( (JsonInt) (* this));

    } else if ( iObjectType == JsonObject::JsonObject_DOUBLE )
    {
        return sizeof( (JsonDouble) (* this));

    } else if ( iObjectType == JsonObject::JsonObject_MAP )
    {
        return ( (map<string,JsonObject> *) this)->size() ;

    } else if ( iObjectType == JsonObject::JsonObject_ARRAY )
    {
        return ( (vector<JsonObject> *) this)->size() ;
    } 

    return 0;
}
