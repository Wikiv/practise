#include <string.h>
#include <iostream>

#include <jsonparser/JsonParser.h>

using namespace std;


int main()
{
	string data = "{\"k1\":\"v1\"}";
        cout << data << endl;

	/* Test for key exception */

        JsonParser json(data);
        JsonObject json_object = json.getJsonObject();

        try {
                cout << "key which is present is = " << (string)json_object.getJsonObject("k1") << endl;
                string s = (string) json_object.getJsonObject("k1");
				cout << s << endl;
                //JsonObject kk2 = json_object.getJsonObject("k3");
				
        } catch (Exceptions e) {
                cout << "Exception yippee\n = " << e.what() << endl;
        }

	/* Test for has key */
	cout << "json_object.hasKey(k3) : " << json_object.hasKey("k3") << endl;
	cout << "json_object.hasKey(k1) : " << json_object.hasKey("k1") << endl;
}
