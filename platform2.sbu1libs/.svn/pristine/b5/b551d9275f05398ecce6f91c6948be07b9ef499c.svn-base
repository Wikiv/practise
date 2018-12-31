#include "SBU2PushClient.h"

SBU2PushClient::SBU2PushClient(int fd, SessionTable *sessionTable,
							   MasterSymbolTable *masterSymbolTable,
							   IFSubscriptions *ifSubscriptions,
							   Mutex *mTableMutex) : TCPClient(fd)
{
	this->ifSubscriptions = ifSubscriptions;
	this->sessionTable = sessionTable;
	this->masterSymbolTable = masterSymbolTable;
	this->mTableMutex = mTableMutex;
	bMarkedForRemoval = false;
	uLastActivityTime = time(NULL);
	this->fd = fd;
}

void SBU2PushClient::receive_data(void *data, size_t len)
{
	/* Set current time as last activity time. */
	uLastActivityTime = time(NULL);
	/* Reset flag, so that eventfax does not remove
	   this in case it is already marked for removal. */
	bMarkedForRemoval = false;

	char *c_data = (char *)data;
	parse(c_data, len);
}

bool SBU2PushClient::isMarkedForRemoval()
{
	return bMarkedForRemoval;
}

void SBU2PushClient::checkInactivity(time_t t_threshold_time)
{
	if( t_threshold_time > uLastActivityTime ) {
		unsubscribeAll();
		bMarkedForRemoval = true;
	}
}

void SBU2PushClient::parse(char *data, size_t len)
{
	cout << data << endl;

	for(size_t i = 0; i < len; i++) {
		char c = *(data + i);

		if( c == '\n' ) {
			//Synchronized call to parse and process the request.
			mTableMutex->lock();
			parse(sToken);
			mTableMutex->unlock();

			sToken.clear();

		} else {
			sToken.append(&c, 1);
		}
	}
}

void SBU2PushClient::parse(string sRequest)
{
	SBU2StreamingRequest sbu2Request(sRequest);
	sessionTable->addSession( sbu2Request.getSessionID(), this );
	printf("Got SBU2 request: %d\n", sbu2Request.getRequestType());
	printf("SBU2 request isSubscribe(): %d\n", sbu2Request.isSubscribe());

	if( sbu2Request.getRequestType() ==
			SBU2StreamingRequest::SBU2StreamingRequest_Level1 ) {

		if ( sbu2Request.isSubscribe() ) {
			vector<string>symbolList = sbu2Request.getSymbolList();
			cout << "size = " << symbolList.size() << endl;

			if( symbolList.size() > 0 ) {
				// Remove old subscription. Update new subscription.

				removeSubscriptions(sbu2Request.getRequestType(),
									this->masterSymbolTable->l1SymbolTable);

				sbu2Cache.add( sbu2Request );
				ifSubscriptions->onLevel1Subscribe(sbu2Request);

				this->masterSymbolTable->l1SymbolTable->addSymbolList(symbolList, this);
			}

		} else if (sbu2Request.isUnSubscribe()) {
			// Remove subscription.

			removeSubscriptions(sbu2Request.getRequestType(),
								this->masterSymbolTable->l1SymbolTable);

			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onLevel1UnSubscribe(sbu2Request);
		}

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_Level2 ) {

		if ( sbu2Request.isSubscribe() ) {

			vector<string>symbolList = sbu2Request.getSymbolList();

			if( symbolList.size() > 0 ) {
				// Remove old subscription. Update new subscription.

				removeSubscriptions(sbu2Request.getRequestType(),
									this->masterSymbolTable->l2Symboltable);

				sbu2Cache.add( sbu2Request );
				ifSubscriptions->onLevel2Subscribe(sbu2Request);

				this->masterSymbolTable->l2Symboltable->addSymbolList(symbolList, this);
			}

		} else if ( sbu2Request.isUnSubscribe() ) {
			// Remove subscription.

			removeSubscriptions(sbu2Request.getRequestType(),
								this->masterSymbolTable->l2Symboltable);

			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onLevel2UnSubscribe(sbu2Request);
		}

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_TradeSymbols ) {

		if ( sbu2Request.isSubscribe() ) {
			vector<string>symbolList = sbu2Request.getSymbolList();

			if( symbolList.size() > 0 ) {

				removeSubscriptions(sbu2Request.getRequestType(),
									this->masterSymbolTable->tradeSymbolTable);

				sbu2Cache.add( sbu2Request );
				ifSubscriptions->onTradeSymbolsSubscribe( sbu2Request );

				this->masterSymbolTable->tradeSymbolTable->addSymbolList(symbolList, this);
			}

		} else if ( sbu2Request.isUnSubscribe() ) {
			// Remove subscription.
			//
			removeSubscriptions(sbu2Request.getRequestType(),
								this->masterSymbolTable->tradeSymbolTable);

			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onTradeSymbolsUnSubscribe( sbu2Request );
		}

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_Positions ) {

		if (sbu2Request.isSubscribe() ) {
			sbu2Cache.add( sbu2Request );
			ifSubscriptions->onPositionsSubscribe(sbu2Request);

		} else if ( sbu2Request.isUnSubscribe() ) {
			sbu2Cache.del(sbu2Request);
			ifSubscriptions->onPositionsUnSubscribe(sbu2Request);

		}

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_Orders ) {

		if ( sbu2Request.isSubscribe() ) {
			sbu2Cache.add( sbu2Request );
			ifSubscriptions->onOrdersSubscribe(sbu2Request);

		} else if ( sbu2Request.isUnSubscribe() ) {
			sbu2Cache.del(sbu2Request);
			ifSubscriptions->onOrdersUnSubscribe(sbu2Request);

		}

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_Alerts ) {

		if ( sbu2Request.isSubscribe() ) {
			sbu2Cache.add( sbu2Request );
			ifSubscriptions->onAlertsSubscribe(sbu2Request);

		} else if (sbu2Request.isUnSubscribe() ) {
			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onAlertsUnSubscribe(sbu2Request);
		}
	}
}

void SBU2PushClient::removeSubscriptions(uint8_t streamType,
		SymbolTable * symbolTable)
{
	SBU2StreamingRequest sbu2Request;

	if (this->sbu2Cache.get(streamType, sbu2Request)) {
		cout << "Removing old Subscriptions " << endl;
		symbolTable->removeSymbolList(sbu2Request.getSymbolList(), this);
	}
}

int SBU2PushClient::getDescriptor()
{
	return this->fd;
}

bool SBU2PushClient::sendLevel1(string sSymbol, JsonObject *jsonResponse)
{
	return send(SBU2StreamingRequest::SBU2StreamingRequest_Level1, jsonResponse );
}

bool SBU2PushClient::sendLevel2(string sSymbol, JsonObject *jsonResponse)
{
	return send(SBU2StreamingRequest::SBU2StreamingRequest_Level2, jsonResponse );
}

bool SBU2PushClient::sendTradeSymbols(string sSymbol, JsonObject *jsonResponse)
{
	return send(SBU2StreamingRequest::SBU2StreamingRequest_TradeSymbols,
				jsonResponse );
}

bool SBU2PushClient::send(uint8_t iStreamingRequestType,
						  JsonObject *jsonResponse)
{
	SBU2StreamingRequest sbu2Request;

	if( sbu2Cache.get( iStreamingRequestType, sbu2Request ) ) {

		//set echo block on jsonResponse
		JsonObject finalObj;
		JsonObject respJson;
		(*jsonResponse)["streaming_type"] =
			sbu2Request.reqObject["request"]["streaming_type"];
		finalObj["response"] = (*jsonResponse);

		if(sbu2Request.reqObject.hasKey("echo")) {
			finalObj["echo"] = sbu2Request.reqObject["echo"];
		}
        
		int nWritten = this->sendData( finalObj.toString() + "\n" );
		bool flag = (nWritten > 0);
		return flag;
	}

	return true;
}

void SBU2PushClient::unsubscribeAll()
{
	map<uint8_t, SBU2StreamingRequest>::iterator iCache = this->sbu2Cache.begin();

	while ( iCache != sbu2Cache.end() ) {

		if (iCache->first == SBU2StreamingRequest::SBU2StreamingRequest_Level1) {

			this->masterSymbolTable->l1SymbolTable->removeSymbolList(
				iCache->second.getSymbolList(), this);

		} else if (iCache->first ==
				   SBU2StreamingRequest::SBU2StreamingRequest_Level2) {

			this->masterSymbolTable->l2Symboltable->removeSymbolList(
				iCache->second.getSymbolList(), this);

		} else if (iCache->first ==
				   SBU2StreamingRequest::SBU2StreamingRequest_TradeSymbols) {

			this->masterSymbolTable->tradeSymbolTable->removeSymbolList(
				iCache->second.getSymbolList(), this);

		}
            
        this->sessionTable->removeSession(iCache->second.getSessionID());

		iCache++;
	}

	this->sbu2Cache.clear();
}

void SBU2PushClient::unbind()
{
	close(fd);
	fd = -1;
	unsubscribeAll();
	bMarkedForRemoval = true;
}
