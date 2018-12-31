#include <iostream>
#include <string>

#include <ubacyaml/YamlConfig.h>

using namespace std;

int main(int argc, char *argv[])
{
	string sFilename1(argv[1]);
	string sFilename2(argv[2]);
	cout << sFilename1 << ", " << sFilename2 << endl;
	YamlConfig config1( sFilename1 );
	YamlConfig config2(sFilename2);
	config1 += config2;
	cout << "filename = " << config1["debug"]["file_name"] << endl;
	cout << "level = " << config1["logging"]["level"] << endl;
	cout << "port = " << config1["clog_server"]["port"] << endl;
}
