/*
 * BrokerStrategyFetchRequest.cpp
 *
 *  Created on: Dec 20, 2011
 */
#include "UBACData.h"

BrokerStrategyFetchRequest::BrokerStrategyFetchRequest(string data){
	sOrigRequest = data;
	parse(data);

}

BrokerStrategyFetchRequest::~BrokerStrategyFetchRequest(){

}


bool BrokerStrategyFetchRequest::isSingleLeg()
{
	return (this->size() == 1);
}

vector<OrderLeg> BrokerStrategyFetchRequest::getLegs(){
	return (*((vector<OrderLeg> *)this));

}

void BrokerStrategyFetchRequest::addOrderLeg(OrderLeg leg)
{
	this->push_back( leg );
}


void BrokerStrategyFetchRequest::parse(string data)
{
	size_t i;
	string buffer = "", name = "";
	bool firstParam = true;
	for(i = 0;i < data.length(); i++) {
		if(data[i] == '&') {
			OrderLeg leg( buffer );
			addOrderLeg( leg );
			buffer.clear();
		} else {
			buffer.append(&data[i], 1);
		}
	}
	if(buffer.length() > 0) {
		OrderLeg leg( buffer );
		addOrderLeg( leg );
	}
}
