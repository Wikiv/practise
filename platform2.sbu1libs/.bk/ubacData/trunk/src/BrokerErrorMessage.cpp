#include "UBACData.h"

BrokerErrorMessage::BrokerErrorMessage(uint32_t iError_Type)
{
	iErrorType=iError_Type;
}

BrokerErrorMessage::~BrokerErrorMessage()
{
}

void BrokerErrorMessage::setCustomMessage( string customMessage )
{
	if ( customMessage.length() > 0 ) {
		custom_error.append( customMessage );
	}
}

void BrokerErrorMessage::setErrorMessage( string message_to_be_added, string & errorMessage )
{
	if ( custom_error.length() > 0 ) {
		errorMessage.append( custom_error );
	} else {
		errorMessage.append( message_to_be_added );
	}
}

void BrokerErrorMessage::toString( string & errorMessage )
{
	string message_to_be_added;
	if ( iErrorType == API_ERROR ) {
		message_to_be_added.append("API services are temporarily down. Please try after sometime.");
		errorMessage.append( "614 <" );
	} else if ( iErrorType == LOGIN_ERROR ) {
		errorMessage.append( "624 <" );
	} else if ( iErrorType == UPDATE_LOGIN_ERROR ) {
		errorMessage.append( "626 <" ); 
	} else if ( iErrorType == INVALID_SESSION_ERROR ) {
		message_to_be_added.append("Invalid Session");
		errorMessage.append( "656 <" );
	} else if ( iErrorType == INVALID_SYMBOL_ERROR ) {
		message_to_be_added.append("Invalid Symbol");
		errorMessage.append( "612 <" );
	} else if ( iErrorType == WATCHLIST_ERROR ) {
		errorMessage.append( "684 <" );
	} else if ( iErrorType == OPTION_CHAIN_ERROR ) {
		errorMessage.append( "686 <" );
	} else if ( iErrorType == SPECIFIC_ERROR ) {
		errorMessage.append( "658 <" );
	} else if ( iErrorType == DRAGON_ERROR ) {
		errorMessage.append( "660 <" );
	} else if ( iErrorType == TRADE_PASSWORD_ERROR ) {
		errorMessage.append( "652 <" );
	} else if ( iErrorType == NO_NEWS_ERROR ) {
		errorMessage.append( "630 <" );
	} else if ( iErrorType == NO_DATA_AVAILABLE ) {
		errorMessage.append( "642 <" );
	} else if ( iErrorType == NO_IMAGE_ERROR ) {
		errorMessage.append( "690 <" );
	} else if ( iErrorType == LOGIN_QUESTION ) {
		errorMessage.append("694 <");
	} else if ( iErrorType == AUTH_ERROR ) {
		errorMessage.append("696 <");
	} else if ( iErrorType == INITIALIZATION_ERROR ) {
		errorMessage.append("630 <");
	} else if ( iErrorType == PROTOCOL_ERROR ) {
		errorMessage.append("640 <");
	}
		
	setErrorMessage( message_to_be_added, errorMessage);
	errorMessage.append( ">" );
}

