#include "UBACData.h"

BrokerInitializationResponse::BrokerInitializationResponse()
{
	status = 0;
	mandatory = 0;
}

BrokerInitializationResponse::BrokerInitializationResponse(string data)
{
	parse(data);
}

BrokerInitializationResponse::~BrokerInitializationResponse()
{
}


void BrokerInitializationResponse::parse(string data)
{

}

void BrokerInitializationResponse::setAppID( string appID )
{
	this->appID = appID;
}

void BrokerInitializationResponse::setUpdateStatus( int status )
{
	this->status = status;
}

void BrokerInitializationResponse::setDataForUpdation( int mandatory, string release_header, string release_notes, string version, string url )
{
	IFHelper helper;

	this->mandatory = mandatory;
	this->version = version;

	helper.gsubSpecialCharacters( release_header );
	this->release_header = release_header;

	helper.gsubSpecialCharacters( release_notes );
	this->release_notes = release_notes;

	helper.gsubSpecialCharacters( url );
	this->url = url;

}
void BrokerInitializationResponse::setUnencodedDataForUpdation(int mandatory,
                string release_header, string release_notes, string version, string url)
{
        this->mandatory = mandatory;
        this->version = version;
        this->release_header = release_header;
        this->release_notes = release_notes;
        this->url = url;
}

void BrokerInitializationResponse::toString(string & response)
{
	stringstream tempresponse;

	tempresponse << "802 <app_id=" << appID << "|update_flag=" << status;
	if ((status == 1) || (status == 2)) 
	{
		tempresponse << "|mandatory=" << mandatory << "|release_notes=" << release_header << "," << release_notes << "|url=" << url << "|latest_version=" << version;
	} 
	tempresponse << ">";
	response = tempresponse.str();
}
