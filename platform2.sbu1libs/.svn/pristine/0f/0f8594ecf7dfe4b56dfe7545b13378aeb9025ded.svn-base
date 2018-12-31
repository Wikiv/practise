#include "UBACData.h"

OptionsChain::OptionsChain()
{
	strikePrice.append("strike-price=");
	putSymbol.append("put-option-symbol=");
	callSymbol.append("call-option-symbol=");
	putLastPrice.append("put-last=");
	callLastPrice.append("call-last=");
	standardOption.append("standard-option=");
	putOpenInterest.append("put-open-interest=");
	callOpenInterest.append("call-open-interest=");
	putVolume.append("put-volume=");
	callVolume.append("call-volume=");
	putOptionDescription.append("Put Option Description=");
	callOptionDescription.append("Call Option Description=");
}

OptionsChain::~OptionsChain()
{
}

void OptionsChain::setExpiryDate( string mExpiryDate )
{
	expiryDate.append( mExpiryDate );
}

void OptionsChain::setLeap( string mLeap )
{
	leap.append( mLeap );
}

void OptionsChain::setMonthId( string mMonthId )
{
	monthId.append( mMonthId );
}

void OptionsChain::setNoOfDaysToExpire( string mNoOfDaysToExpire )
{
	noOfDaysToExpire.append( mNoOfDaysToExpire );
}

string OptionsChain::getNoOfDaysToExpire()
{
	return noOfDaysToExpire;
}

void OptionsChain::setStandardOption( string mStandardOption )
{
	standardOption.append( mStandardOption );
}

void OptionsChain::setStrikePrice( string mStrikePrice )
{
	strikePrice.append( mStrikePrice );
}

void OptionsChain::setPutSymbol( string mPutSymbol )
{
	putSymbol.append( mPutSymbol );
}

void OptionsChain::setCallSymbol( string mCallSymbol )
{
	callSymbol.append( mCallSymbol );
}

void OptionsChain::setPutLastPrice( string mPutLastPrice )
{
	putLastPrice.append( mPutLastPrice );
}

void OptionsChain::setCallLastPrice( string mCallLastPrice )
{
	callLastPrice.append( mCallLastPrice );
}

void OptionsChain::setPutOpenInterest( string mPutOpenInterest )
{
	putOpenInterest.append( mPutOpenInterest );
}

void OptionsChain::setPutVolume( string mPutVolume )
{
	putVolume.append( mPutVolume );
}

void OptionsChain::setCallOpenInterest( string mCallOpenInterest )
{
	callOpenInterest.append( mCallOpenInterest );
}

void OptionsChain::setCallVolume( string mCallVolume )
{
	callVolume.append( mCallVolume );
}

void OptionsChain::setPutOptionDescription( string mPutOptionDescription )
{
	putOptionDescription.append( mPutOptionDescription );
}

void OptionsChain::setCallOptionDescription( string mCallOptionDescription )
{
	callOptionDescription.append( mCallOptionDescription );
}

void OptionsChain::toString(string & response)
{
	response.append(strikePrice);
	response.append(",");
	response.append(standardOption);
	response.append(",");
	response.append(putSymbol);
	response.append(",");
	response.append(putLastPrice);
	response.append(",");
	response.append(putOpenInterest);
	response.append(",");
	response.append(putVolume);
	response.append(",");
	response.append(callSymbol);
	response.append(",");
	response.append(callLastPrice);
	response.append(",");
	response.append(callOpenInterest);
	response.append(",");
	response.append(callVolume);
	response.append(",");
	response.append(putOptionDescription);
	response.append(",");
	response.append(callOptionDescription);
	response.append("~");
};
