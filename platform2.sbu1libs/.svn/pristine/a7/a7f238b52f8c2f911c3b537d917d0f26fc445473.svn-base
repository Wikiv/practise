#include "UBACData.h"

ValidateOtpRequest::ValidateOtpRequest(string request)
{
	parse( request );
}

ValidateOtpRequest::~ValidateOtpRequest()
{
}

string ValidateOtpRequest::getOtp()
{
    return otp;
}

void ValidateOtpRequest::parse(string request)
{
        otp = request;    
}

string ValidateOtpRequest::toString()
{
        string s = "586 <";
        s = s + (*this) + ">";
        return s;
}
