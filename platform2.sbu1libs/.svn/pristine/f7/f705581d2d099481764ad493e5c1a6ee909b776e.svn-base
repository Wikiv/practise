#include "UBACData.h"

BrokerResearchRequest::BrokerResearchRequest(string request){

	cout << "request:" << request  << endl;
	parse(request + (string ) ("|"));
}

BrokerResearchRequest::~BrokerResearchRequest(){}

void BrokerResearchRequest::parse(string request){
	string name, value;
	int length = request.length();
	int i = 0;
	char ch;
	if (!request.empty()) {

		for (;i < length; i++){
			ch = request[i];
			if (ch == '|'){
				addKeyValue(name,value);
				name.clear(); 
				value.clear();
			} else if (ch == '='){
				name.append(value);
				value.clear();
			} else {
				value.append(&ch,1);
			}
		}	
	}
}

void BrokerResearchRequest::addKeyValue(string key, string value){
	
	if ((!(key.empty())) && (!(value.empty())))
		((map<string,string>*) this)->insert(make_pair(key,value));
} 

string BrokerResearchRequest::getParam(string key){
	map<string,string>::iterator iter_v = ((map<string,string>*) this)->find(key);
	if (iter_v!=((map<string,string>*) this)->end()){
		return iter_v->second;
	} else {
		return "";
	}
}

string BrokerResearchRequest::getSymbol(){
	return getParam("SYMBOL");
}
string BrokerResearchRequest::getType(){
	return getParam("TYPE");
}
