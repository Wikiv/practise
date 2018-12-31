#include "UBACData.h"

BrokerResearchResponse::BrokerResearchResponse(){
	cout << "creating object" << endl;

}

BrokerResearchResponse::~BrokerResearchResponse(){

}

string BrokerResearchResponse::map_to_string(){
	string response;
	map <string,multimap<string,string> >::iterator iter_header = header_values_map.begin();
	multimap <string,string>::iterator iter_kv;
	int i = header_values_map.size();
	int j;
	while ( iter_header!= header_values_map.end() ){
		iter_kv = iter_header->second.begin();
		j = iter_header->second.size();
		if (j!=0){
			response.append( iter_header->first );
			response.append(";");
			while(iter_kv!=iter_header->second.end()){
				cout << iter_kv->first << ":" << iter_kv->second << "," << endl;
				response.append(iter_kv->first);
				response.append("=");
				response.append(iter_kv->second);
				if (j>1)
					response.append(",");
				iter_kv++;
				j--;
			}
			if (i>1)
				response.append("|");
		}
		iter_header++;
		i--;
	}

	IFHelper helper;
	helper.rstrip(response, '|',1);
	return response;
}
void BrokerResearchResponse::addHeaderValue(string header, string key, string value){
	map<string, multimap<string,string> >::iterator header_iter = header_values_map.find(header);

	if (header_iter == header_values_map.end()){
		multimap<string,string> new_kv_map;
		new_kv_map.insert(make_pair(key,value));
		header_values_map.insert(make_pair(header,new_kv_map));
	} else {
		multimap<string,string>::iterator value_iter = header_iter->second.find(key);
		if (value_iter == header_iter->second.end()){
			header_iter->second.insert(make_pair(key,value));			
		} else {
			header_iter->second.erase(key);
			header_iter->second.insert(make_pair(key,value));
		}
	}

}
void BrokerResearchResponse::addHeaderValue(string header, multimap<string, string> key_values, bool replace){

	if (replace){
		map<string, multimap<string,string> >::iterator header_iter = header_values_map.find(header);
		if (header_iter!=header_values_map.end()){
			header_values_map.erase(header);
		}
		header_values_map.insert(make_pair(header , key_values));
	} else {
	

	}

}


void BrokerResearchResponse::addHeaderValue(string header, multimap<string, string> key_values){
	addHeaderValue(header, key_values, true);
}

void BrokerResearchResponse::toString(string &response, vector<string> headerOrder){
	
}

void BrokerResearchResponse::toString(string &response, vector<string> headerOrder, map< string, vector<string> > fieldOrder){
	
	stringstream response_stream;
	IFHelper helper;
	response_stream << UBACData::Protocol_BROKER_RESEARCH_REQUEST+2 << " <";

	response.clear();
	response.append(response_stream.str());
	response_stream.clear();
	vector<string>::iterator iter_header = headerOrder.begin();
	int i= 0 , j = 0 ;
	while(iter_header!=headerOrder.end()){ 
		map <string,multimap<string,string> >::iterator iter_values = header_values_map.find(*iter_header);
		if (iter_values != header_values_map.end() && iter_values->second.size() > 0){
//			cout << "header: " << *iter_header << endl;		
			response.append(*iter_header);response.append(";");
			map <string, vector<string> >::iterator iter_fo = fieldOrder.find(*iter_header);
			if(iter_fo!=fieldOrder.end()){
				vector<string>::iterator iter_f = iter_fo->second.begin();	
				j = iter_fo->second.size() - 1;	
				while(iter_f!=iter_fo->second.end()){
					multimap<string,string>::iterator iter_v = iter_values->second.find(*iter_f);
					if (iter_v!=iter_values->second.end() && (!iter_v->second.empty()) ){
						cout << iter_v->first << ":" << iter_v->second;
						string label = getLabel(*iter_header, iter_v->first);
						cout << ", label: " << label << endl;
						// format the value to 2 decimal precision if double..
						string value;
						value = iter_v->second;
						helper.gsubSpecialCharacters(value);
						response.append(label);
						response.append("=");
						response.append(value);	
						//response_stream << label << "=" << value;
					       	//if (j>0){
						response.append(",");	
						//}
					}
					iter_f++;
					j--;
				}
				helper.rstrip(response,',',1);
			}
			if (i<headerOrder.size() - 1)
				response.append("|");
			//				response_stream  << "|";
		}
		iter_header++;
		i++;
	}
	helper.rstrip(response,'|',1);
//	response_stream << ">";
	response.append(">");
	cout<< response << endl;
}

void BrokerResearchResponse::addLabel(string header, string key, string label){

	string index = header + (string) "_" + key;
	cout << "adding index; " << index << endl;
	cout << "adding index; " << index << endl;
	map<string,string>::iterator i_label = labelsMap.find(index);
	if (i_label!=labelsMap.end())
		labelsMap.erase(i_label);
	labelsMap.insert(make_pair(index,label));

}

void BrokerResearchResponse::addLabel(string header, map<string, string> key_label){
	map<string,string>::iterator i_label = key_label.begin();
	while(i_label!=key_label.end()){
		addLabel(header, i_label->first, i_label->second);
		i_label++;
	}
}

string BrokerResearchResponse::getLabel(string header, string key){

	// label stored in header_key format
	// Returns the label for the field or the field name itself if not set.
	
	string index = header + (string ) "_" + key;
	cout << "searching for index: " << index << endl;
	map<string,string>::iterator i_label = labelsMap.find(index);
	if (i_label!=labelsMap.end()){
		return i_label->second;
	} else {
		return key;	
	}
}

void BrokerResearchResponse::toString(string &response){
	stringstream response_stream;
	response_stream << UBACData::Protocol_BROKER_RESEARCH_REQUEST+2
	       << " <" << map_to_string() << ">";	
	response.clear();
	response.append(response_stream.str());
}

