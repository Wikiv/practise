#include <ubacdata/UBACData.h>

#include <iostream>
using namespace std;
int main()
{
        string sResponse = "OK|TU9CSUxFMi0wLjE1NDAwMA**|AccountID=MOBILE1,DisplayName=MOBILE1,Margin=0,Option=0,Stock=0,Futures=1,StreamingNews=0,StreamingData=1,Forex=0,MutualFunds=0,Tradable=Y&AccountID=MOBILE2,DisplayName=MOBILE2,Margin=0,Option=0,Stock=0,Futures=1,StreamingNews=0,StreamingData=1,Forex=0,MutualFunds=0,Tradable=Y&AccountID=MOBILE3,DisplayName=MOBILE3,Margin=0,Option=0,Stock=0,Futures=1,StreamingNews=0,StreamingData=1,Forex=0,MutualFunds=0,Tradable=Y&AccountID=MOBILE4,DisplayName=MOBILE4,Margin=0,Option=0,Stock=0,Futures=1,StreamingNews=0,StreamingData=1,Forex=0,MutualFunds=0,Tradable=Y";
        BrokerLoginResponse loginResponse(sResponse);
        cout << "Login status = " << loginResponse.getLoginStatus() << endl;
}

