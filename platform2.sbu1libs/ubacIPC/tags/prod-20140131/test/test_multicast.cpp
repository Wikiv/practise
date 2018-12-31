#include <ubacipc/MultiCastClient.h>
#include <iostream>

using namespace std;


class MOSLBroadCastClient:
	public MultiCastClient
{
	public:
	static const string BROADCAST_GROUP_IP;
	static const int BROADCAST_GROUP_PORT;

	void udpsubscribe()
	{
		this->subscribe(BROADCAST_GROUP_IP , BROADCAST_GROUP_PORT );
	}

	void receive_data(void *data, size_t len)
	{
		printf("sizeof(packet) :  %d \n", len ) ;
		// will receive the packets here when startReceiveingis called.
	}
};
const string MOSLBroadCastClient::BROADCAST_GROUP_IP = "239.2.2.20";
const int MOSLBroadCastClient::BROADCAST_GROUP_PORT = 6020;



int main(int argc, char *argv[])
{
	MOSLBroadCastClient client;
	client.udpsubscribe();
	if (client.isConnected()){
		client.startReceiving(client.PARENT_THREAD);
	}

	while(1);
	
	return 0;
}
