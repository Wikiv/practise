#include "UBACPushClient.h"

UBACPushClient::UBACPushClient(int fd,
							   IFSubscriptions *ifSubscriptions) : TCPClient(fd)
{
	this->ifSubscriptions = ifSubscriptions;
	bMarkedForRemoval = false;
	uLastActivityTime = time(NULL);
	this->fd = fd;
}

UBACPushClient::~UBACPushClient()
{
	cout << "deleting " << fd << endl;
	close(fd);
}

void UBACPushClient::receive_data(void *data, size_t len)
{
	/* Set current time as last activity time. */
	uLastActivityTime = time(NULL);
	/* Reset flag, so that eventfax does not remove
	   this in case it is already marked for removal. */
	bMarkedForRemoval = false;

	char *c_data = (char *)data;
	parse(c_data, len);
}

bool UBACPushClient::isMarkedForRemoval()
{
	return bMarkedForRemoval;
}

void UBACPushClient::checkInactivity(time_t t_threshold_time)
{
	if( t_threshold_time > uLastActivityTime ) {
		unsubscribeAll();
		bMarkedForRemoval = true;
	}
}

void UBACPushClient::parse(char *data, size_t len)
{
	for(size_t i = 0; i < len; i++) {
		char c = *(data + i);

		if( c == '\n' ) {
			parse(sToken);
			sToken.clear();

		} else {
			sToken.append(&c, 1);
		}
	}
}

void UBACPushClient::parse(string sRequest)
{
	int code;
	string sData, sExtMod, sReply;
	UBACData::crack(sToken, code, sData, sExtMod);

	PushServerRequest pushRequest( sData );
	string requestType = pushRequest.getRequesttype();
	vector<string>symbolList = pushRequest.getSymbolList();

	ExtMod *extMod = new ExtMod(sExtMod);

	if( code == Protocol_SUBSCRIPTION_REQUEST ) {
		if( requestType.compare("quote") == 0 ) {
			if( symbolList.size() > 0 ) {
				// Remove old subscription. Update new subscription.
				ubacCache.set(requestType, symbolList, extMod);

			} else {
				// Remove subscription.
				ubacCache.reset(requestType);
			}

		} else if( requestType.compare("quote2") == 0 ) {
			if( symbolList.size() > 0 ) {
				// Remove old subscription. Update new subscription.
				ubacCache.set(requestType, symbolList, extMod);

			} else {
				// Remove subscription.
				ubacCache.reset(requestType);
			}
		}
	}
}

int UBACPushClient::getDescriptor()
{
	return this->fd;
}

bool UBACPushClient::send(string sResponse, ExtMod *pExtMod)
{
	mMutex.lock();
	ExtMod newExtMod( *pExtMod );
	/*
	if(extMod != NULL)
	{
		newExtMod = newExtMod + *extMod;
	}
	*/
	newExtMod.toString( sResponse );
	sResponse.append("\n");
	mMutex.unlock();

	int nWritten = this->sendData( sResponse );
	bool flag = (nWritten > 0);
	return flag;
}

void UBACPushClient::unsubscribeAll()
{
	ubacCache.reset();
}

void UBACPushClient::unbind()
{
	close(fd);
	fd = -1;
	bMarkedForRemoval = true;
	unsubscribeAll();
}
