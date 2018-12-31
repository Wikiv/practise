#include <string.h>
#include <iostream>

#include "JsonParser.h"

using namespace std;

int main()
{
        /*Check for invalid json */
        string s1 = "{";   //Invalid case
        JsonParser par1(s1);
        cout << "par1.isValidJson(): " << par1.isValidJson() << endl;

	string s2 = "{}";  //valid case
        JsonParser par2(s2);
        cout << "par2.isValidJson(): " << par2.isValidJson() << endl;

    	string s3 = "{1}";  //invalid case
	    JsonParser par3(s3);
        cout << "par3.isValidJson(): " << par3.isValidJson() << endl;

        string s5 = "{1}\n";  //invalid case
        JsonParser par95(s5);
        cout << "par5.isValidJson(): " << par95.isValidJson() << endl;

        string s4 = "408<DELETE|ACCOUNTID=MOBILE4|WATCHLISTID=527>##SESSION=nikm003,ROUTER=pats##";   //Crashing....need to fix

        JsonParser par4(s4);
        cout << "par4.isValidJson(): " << par4.isValidJson() << endl;

        string req = "{\"num\" : 43534, \"num2\" : 233.03, \"request\":{\"data\":{\"symbols\":[{\"symbol\":\"206817_MCX\"}]},\"streaming_type\":\"quote\",\"request_type\":\"subscribe\",\"response_format\":\"json\",\"session\":\"foo\"},\"echo\":{\"DESTINATION\":\"MOSL\"}}";

        JsonParser par5(req);

        cout << "par5.isValidJson(): " << par5.isValidJson() << endl;
        JsonObject obj = par5.getJsonObject();

        cout << "json: " << obj.toString() << endl;
        string s6 = "[\"test\"]";
        JsonParser par6(s6);
        cout << "par6.isValidJson() : " << par6.isValidJson() << endl; 
}
