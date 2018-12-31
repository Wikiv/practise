#include "UBACData.h"

CommonCsvRequest::CommonCsvRequest(string data) : string(data)
{
	parse(data);
}

CommonCsvRequest::~CommonCsvRequest()
{
}

void CommonCsvRequest::parse(string data)
{
        string tmp_buffer;
	IFHelper helper;
	for(size_t i = 0; i < data.length(); i++) {
                if( data[i] == '|' ) {
			vector<string> splitList;
                        helper.split(tmp_buffer, "=", splitList);
                        otherParams.insert( make_pair( splitList[0] , splitList[1] ) );
                        
			tmp_buffer.clear();
                } else {
                	 tmp_buffer.append(&data[i], 1);
                }
        }
        if( tmp_buffer.find('=') != string::npos ) {
		vector<string> splitList;
                helper.split(tmp_buffer, "=", splitList);
                otherParams.insert( make_pair( splitList[0] , splitList[1] ) );
        }
}

string CommonCsvRequest::getParam(string sKey)
{
	map<string, string>::iterator iOtherParams = otherParams.find(sKey);
        if(iOtherParams != otherParams.end())
                return iOtherParams->second;
        else
                return "";
}

string CommonCsvRequest::toString()
{
	string s = "590 <";
	s = s + (*this) + ">";
	return s;
}
