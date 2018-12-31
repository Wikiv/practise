#include "SBU2PushClient.h"

SBU2PushClient::SBU2PushClient(int fd, SessionTable *sessionTable,
							   MasterTable *masterTable,
							   IFSubscriptions *ifSubscriptions,
							   Mutex *mTableMutex) : TCPClient(fd)
{
	this->ifSubscriptions = ifSubscriptions;
	this->sessionTable = sessionTable;
	this->masterTable = masterTable;
	this->mTableMutex = mTableMutex;
	this->bMarkedForRemoval = false;
	this->uLastActivityTime = time(NULL);
}

void SBU2PushClient::receive_data(void *data, size_t len)
{
	char *c_data = (char *)data;
	parse(c_data, len);
}

bool SBU2PushClient::isMarkedForRemoval()
{
	return this->bMarkedForRemoval;
}

void SBU2PushClient::markForRemoval()
{
	unsubscribeAll();
}

bool SBU2PushClient::checkInactivity(time_t t_threshold_time)
{
	if( t_threshold_time > uLastActivityTime ) {
		unsubscribeAll();
		return true;
	}

	return false;
}

void SBU2PushClient::parse(char *data, size_t len)
{
	if (isMarkedForRemoval())
		return;

	/* Set current time as last activity time. */
	uLastActivityTime = time(NULL);

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
	printf("SBU2 request : %s : fd = %d - Addr %p\n",
		   sRequest.c_str() , this->descriptor, this);

	handleSession( sbu2Request );

	if( sbu2Request.getRequestType() ==
			SBU2StreamingRequest::SBU2StreamingRequest_Level1 ) {

		if ( sbu2Request.isSubscribe() ) {
			vector<string>symbolList = sbu2Request.getSymbolList();
			//cout << "fd : " << this->descriptor << " Number of symbols = " << symbolList.size() << endl;

			if( symbolList.size() > 0 ) {
				// Remove old subscription. Update new subscription.

				vector<string> symbolsToUnsubscribe = removeSubscriptions(
						sbu2Request.getRequestType(),
						this->masterTable->l1SymbolTable);

				if (symbolsToUnsubscribe.size() > 0)
					ifSubscriptions->onLevel1UnSubscribe(sbu2Request, symbolsToUnsubscribe);


				sbu2Cache.add( sbu2Request );
				ifSubscriptions->onLevel1Subscribe(sbu2Request);

				this->masterTable->l1SymbolTable->addSymbolList(symbolList, this);
			}

		} else if (sbu2Request.isUnSubscribe()) {
			// Remove subscription.

			vector<string> symbolsToUnsubscribe = removeSubscriptions(
					sbu2Request.getRequestType(),
					this->masterTable->l1SymbolTable);

			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onLevel1UnSubscribe(sbu2Request,symbolsToUnsubscribe );
		}

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_Level2 ) {

		if ( sbu2Request.isSubscribe() ) {

			vector<string>symbolList = sbu2Request.getSymbolList();

			if( symbolList.size() > 0 ) {
				// Remove old subscription. Update new subscription.

				vector<string> symbolsToUnsubscribe = removeSubscriptions(
						sbu2Request.getRequestType(),
						this->masterTable->l2Symboltable);

				if (symbolsToUnsubscribe.size() > 0)
					ifSubscriptions->onLevel2UnSubscribe(sbu2Request,symbolsToUnsubscribe);


				sbu2Cache.add( sbu2Request );
				ifSubscriptions->onLevel2Subscribe(sbu2Request);

				this->masterTable->l2Symboltable->addSymbolList(symbolList, this);
			}

		} else if ( sbu2Request.isUnSubscribe() ) {
			// Remove subscription.

			vector<string> symbolsToUnsubscribe = removeSubscriptions(
					sbu2Request.getRequestType(),
					this->masterTable->l2Symboltable);

			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onLevel2UnSubscribe(sbu2Request, symbolsToUnsubscribe);
		}

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_TradeSymbols ) {

		if ( sbu2Request.isSubscribe() ) {
			vector<string>symbolList = sbu2Request.getSymbolList();

			if( symbolList.size() > 0 ) {

				vector<string> symbolsToUnsubscribe = removeSubscriptions(
						sbu2Request.getRequestType(),
						this->masterTable->tradeSymbolTable);

				if (symbolsToUnsubscribe.size() > 0)
					ifSubscriptions->onTradeSymbolsUnSubscribe(sbu2Request, symbolsToUnsubscribe);

				sbu2Cache.add( sbu2Request );
				ifSubscriptions->onTradeSymbolsSubscribe( sbu2Request );

				this->masterTable->tradeSymbolTable->addSymbolList(symbolList, this);
			}

		} else if ( sbu2Request.isUnSubscribe() ) {
			// Remove subscription.
			//
			vector<string> symbolsToUnsubscribe = removeSubscriptions(
					sbu2Request.getRequestType(),
					this->masterTable->tradeSymbolTable);

			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onTradeSymbolsUnSubscribe( sbu2Request ,
					symbolsToUnsubscribe);
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
			   SBU2StreamingRequest::SBU2StreamingRequest_Balances ) {

		if (sbu2Request.isSubscribe() ) {
			sbu2Cache.add( sbu2Request );
			ifSubscriptions->onBalancesSubscribe(sbu2Request);

		} else if ( sbu2Request.isUnSubscribe() ) {
			sbu2Cache.del(sbu2Request);
			ifSubscriptions->onBalancesUnSubscribe(sbu2Request);

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

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_LiveTrades ) {

		if ( sbu2Request.isSubscribe() ) {
			this->masterTable->liveTradeConns->addConn(this);

			sbu2Cache.add( sbu2Request );
			ifSubscriptions->onLiveTradesSubscribe(sbu2Request);


		} else if (sbu2Request.isUnSubscribe() ) {
			this->masterTable->liveTradeConns->removeConn(this);

			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onLiveTradesUnSubscribe(sbu2Request);
		}

	} else if( sbu2Request.getRequestType() ==
			   SBU2StreamingRequest::SBU2StreamingRequest_AccountUpdate ) {

		if ( sbu2Request.isSubscribe() ) {
			sbu2Cache.add( sbu2Request );
			ifSubscriptions->onAccountUpdateSubscribe(sbu2Request);

		} else if (sbu2Request.isUnSubscribe() ) {
			sbu2Cache.del( sbu2Request );
			ifSubscriptions->onAccountUpdateUnSubscribe(sbu2Request);
		}
    }

}

void SBU2PushClient::handleSession(SBU2StreamingRequest & sbu2Request)
{
	string currSession = sbu2Request.getSessionID();

	// Checking any session key is sending
	if ( currSession.length() == 0 )
		return ;

	// Checking current session and previous session sent by the same connection.
	if ( (this->sSessionID.length() > 0) &&
			(strcmp(this->sSessionID.c_str(), currSession.c_str()) != 0) ) {

		cout << "ERROR - Client is sending different session for same connection "
			 << this << " FD : " << this->descriptor << endl;
		return;
	}

	if (this->sSessionID.length() == 0) {
		this->sSessionID = currSession;
		// Adding Current request session to session table
		sessionTable->addSession( this->sSessionID, this );
	}


	// Checking if any other connections has same session ID.
	void * conn = sessionTable->getSession( this->sSessionID );

	if( conn != NULL ) {
		SBU2PushClient *client = static_cast<SBU2PushClient *>(conn);

		if ( this != client ) {
			client->removeFromTables();
		}
	}

}

vector<string> SBU2PushClient::removeSubscriptions(uint8_t streamType,
		SymbolTable * symbolTable)
{
	SBU2StreamingRequest sbu2Request;
	vector<string> recentlyRemovedSymbols;

	if (this->sbu2Cache.get(streamType, sbu2Request)) {
		cout << "Removing old Subscriptions " << endl;
		recentlyRemovedSymbols = symbolTable->removeSymbolList(
									 sbu2Request.getSymbolList(), this);
	}

	return recentlyRemovedSymbols;
}

int SBU2PushClient::getDescriptor()
{
	return this->descriptor;
}


bool SBU2PushClient::send(JsonObject *jsonResponse)
{
	string response = jsonResponse->toString() + "\n";

	//cout <<  " Sending data " << response << " to FD " << this->descriptor << endl;

	int nWritten = this->asyncSendData(response.c_str(), response.length());

	return (nWritten > 0);
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

		return send(&finalObj);
	}

	return true;
}

void SBU2PushClient::unsubscribeAll()
{
	mTableMutex->lock();
	removeFromTables();
	mTableMutex->unlock();
}

void SBU2PushClient::removeFromTables()
{

	cout << "Remove from table - fd " << this->descriptor  << endl;
	map<uint8_t, SBU2StreamingRequest>::iterator iCache = this->sbu2Cache.begin();

	while ( iCache != sbu2Cache.end() ) {

		if (iCache->first == SBU2StreamingRequest::SBU2StreamingRequest_Level1) {

			vector<string> removedSymbols =
				this->masterTable->l1SymbolTable->removeSymbolList(
					iCache->second.getSymbolList(), this);

			ifSubscriptions->onLevel1UnSubscribe(iCache->second, removedSymbols) ;

		} else if (iCache->first ==
				   SBU2StreamingRequest::SBU2StreamingRequest_Level2) {

			vector<string> removedSymbols =
				this->masterTable->l2Symboltable->removeSymbolList(
					iCache->second.getSymbolList(), this);
			ifSubscriptions->onLevel2UnSubscribe(iCache->second, removedSymbols) ;

		} else if (iCache->first ==
				   SBU2StreamingRequest::SBU2StreamingRequest_TradeSymbols) {

			vector<string> removedSymbols =
				this->masterTable->tradeSymbolTable->removeSymbolList(
					iCache->second.getSymbolList(), this);
			ifSubscriptions->onTradeSymbolsUnSubscribe(iCache->second, removedSymbols) ;

		} else if (iCache->first ==
				   SBU2StreamingRequest::SBU2StreamingRequest_LiveTrades ) {

			this->masterTable->liveTradeConns->removeConn(this);
			ifSubscriptions->onLiveTradesUnSubscribe(iCache->second);
		}

		iCache++;
	}

	this->sbu2Cache.clear();

	if (this->sSessionID.length() > 0)
		this->sessionTable->removeSession( this->sSessionID );

	this->bMarkedForRemoval = true;

}

void SBU2PushClient::unbind()
{

	printf("Unbind : fd = %d - Addr %p\n", this->descriptor, this);
	unsubscribeAll();
}
