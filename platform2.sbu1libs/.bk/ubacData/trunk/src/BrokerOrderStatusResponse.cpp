#include "UBACData.h"

BrokerOrderStatusResponse::BrokerOrderStatusResponse()
{
	this->sMessage = "No orders pending";
}

BrokerOrderStatusResponse::~BrokerOrderStatusResponse()
{
}

void BrokerOrderStatusResponse::setMessage(string sMessage)
{
	this->sMessage = sMessage;
}

void BrokerOrderStatusResponse::addOrderStatus(OrderStatusEntry orderStatusEntry)
{
	this->push_back(orderStatusEntry);
}

void BrokerOrderStatusResponse::toString(string & output)
{
	output.append("550 <");
	if(this->size() == 0) {
		output.append(this->sMessage);
	} else {
		vector<OrderStatusEntry>::iterator i;
		for(i = this->begin(); i != this->end(); i++) {
			output.append( (*i) );
			output.append("|");
		}
	}
	IFHelper helper;
	helper.rstrip( output, '|' );
	output.append(">");
}
