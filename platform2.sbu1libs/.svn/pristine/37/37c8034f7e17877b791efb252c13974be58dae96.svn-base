#include <iostream>

#include "PushServer.h"
class BrokerSubscriptions:
	public IFSubscriptions
{
	public:
		BrokerSubscriptions() {}
		~BrokerSubscriptions() {}

		void onLevel1Subscribe(SBU2StreamingRequest request)
		{
			cout << "onLevel1Subscribe..... " << endl;
			vector<string>  symbols = request.getSymbolList();

			vector<string>::iterator iter_symbol = symbols.begin();

			while(iter_symbol != symbols.end()) {
				cout << "symbol:  " << *iter_symbol << endl;
				iter_symbol++;
			}
		}
		void onLevel1UnSubscribe(SBU2StreamingRequest request,
								 vector<string> symbolsToUnsubscribe)
		{
			cout << "onLevel2Unsubscribe.. " << endl;
			vector<string>::iterator iter_symbol = symbolsToUnsubscribe.begin();

			while(iter_symbol != symbolsToUnsubscribe.end()) {
				cout << "symbol: " << *iter_symbol << endl;
				iter_symbol++;
			}
		}


};

int main()
{

	BrokerSubscriptions ifSubscriptions;

	EventFax fax;

	PushServer * server = new PushServer(12001, 3600, PushServer::DataType_SBU2,
										 &fax, &ifSubscriptions);

	fax.addTCPServer(server);

	fax.run();
}
