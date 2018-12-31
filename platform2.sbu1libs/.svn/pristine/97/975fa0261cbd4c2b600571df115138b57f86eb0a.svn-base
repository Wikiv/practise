#include "UBACData.h"

ServiceCapability::ServiceCapability(string exchange, string key)
{
	capability.append("230 <");
	capability.append("exchange=");
	capability.append(exchange);
	capability.append("|");
	capability.append("key=");
	capability.append(key);
	capability.append(">");
}

ServiceCapability::~ServiceCapability()
{
}

string ServiceCapability::toString()
{
	return capability;
}
