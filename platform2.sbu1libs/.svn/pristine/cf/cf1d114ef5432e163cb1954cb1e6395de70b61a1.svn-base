#include "SLog.h"
#include <ubacyaml/YamlConfig.h>

int main(int argc, char * argv[])
{
/*    struct s_logger_config config;

    config.mode = "2";
    config.level = "4";
    config.appender = "MSF100";
    config.file_name = "slog-testing";
    config.name_space = "oms"; 
    config.central_logger_ip = "localhost";
    config.central_logger_port = "5679";
    SLog sLog(config);
    sLog.info("Hello\n");*/

    SLog *sLogID;
    YamlConfig *yamlConfig = new YamlConfig(argv[1]);

    if((*yamlConfig)["logging"]["mode"] == "2") {
        YamlConfig newConfig(*yamlConfig);
        YamlValue value;
        value.append((*yamlConfig)["logging"]["filename"] + "." + "MSF2000");

        YamlValue valueMap = newConfig["logging"];

        map<string, YamlValue>::iterator itr = ((map<string, YamlValue> &)valueMap).find("filename");
        if(itr != ((map<string, YamlValue> &)valueMap).end())
            ((map<string, YamlValue> &) valueMap).erase("filename");
        ((map<string, YamlValue> &) valueMap).insert( make_pair("filename",value) );
        ((map<string, YamlValue> &)newConfig)["logging"] = valueMap;

        cout << "file = " << newConfig["logging"]["filename"] << endl;
        sLogID = new SLog(newConfig, "/tmp", "anything", false);
    } else {
        sLogID = new SLog(*yamlConfig, "/tmp", "MSF2000", false);
    }

    sLogID->debug("Hello");
    return 0;
}


// g++ test_clogging.cpp -l:libubacyaml.so.1.2.1 -l:libubaclogger.so.1.2.8
