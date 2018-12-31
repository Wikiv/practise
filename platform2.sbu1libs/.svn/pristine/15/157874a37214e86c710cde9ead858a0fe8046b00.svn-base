#include <jsonparser/JsonParser.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	JsonObject obj;
	/***********INIT STRINGS******
	 *  takes char * and string both
	 */

	obj["strings"]["hello"] = "testMessage";
	obj["strings"]["hello2"] = string("HelloWorld2");

	/* Init numbers - int, int16,int8_t, int32_t, int64_t
	 * uint8_t,uint16_t,uint32_t,uint64_t
	 * double,float
	 * time_t, size_t 
	 */
	
	obj["numbers"]["signed"]["8"] = 12;
	obj["numbers"]["signed"]["16"] = int16_t(13);
	obj["numbers"]["signed"]["32"] = int32_t(14);
	obj["numbers"]["signed"]["64"] = int64_t(-14);

	obj["numbers"]["unsigned"]["8"] = uint8_t(3);
	obj["numbers"]["unsigned"]["16"] = uint16_t(5);
	obj["numbers"]["unsigned"]["32"] = uint32_t(6);
	obj["numbers"]["unsigned"]["64"] = uint64_t(7);

	obj["numbers"]["decimal"]["double"] = double(489.3894);
	obj["numbers"]["decimal"]["float"] = float(489.3894);

	obj["numbers"]["long"]["size_t"] = size_t(489.3894);
	obj["numbers"]["long"]["time_t"] = time_t(489.3894);
	obj["numbers"]["long"]["long"] = long(489.3894);

	/* Boolean
	 */

	obj["boolean_true"] = JsonBool(true);
	obj["boolean_false"] = JsonBool(false);
	
	/* JsonObject
	 */

	JsonObject obj2 = JsonParser("[{\"company\":\"marketsimplified\"}]").getJsonObject();

	obj["jsonObj"] = obj2;

	cout << obj.toString() << endl;
	return 0;
}
