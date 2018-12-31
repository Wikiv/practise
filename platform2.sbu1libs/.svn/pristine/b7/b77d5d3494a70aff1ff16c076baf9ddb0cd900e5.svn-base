#include <ubacyaml/YamlConfig.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	YamlConfig *conf = new YamlConfig("./yaml_files/yamlmap.yaml");

	cout << (*conf)["prod"]["webservice_url"] << (*conf)["uat"]["webservice_url"] << endl;

	map<string,YamlValue>::iterator iter = ((map<string,YamlValue> * )conf )->begin();

	while( iter != ((map<string,YamlValue> * ) conf )->end())
	{
		cout << "key: " << iter->first << endl;
		map<string,YamlValue> valueMap = (map<string,YamlValue> ) iter->second;

		map<string,YamlValue>::iterator iter_value = valueMap.begin();
		while(iter_value != valueMap.end())
		{
			cout << "subkey: " << iter_value->first << ", value:  " << iter_value->second << endl;
			iter_value++;
		}

		iter++;
	}
	return 0;
}
