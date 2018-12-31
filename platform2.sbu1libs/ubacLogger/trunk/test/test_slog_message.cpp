#include <ubaclogger/SLog.h>
#include <fstream>


int main()
{
    struct s_logger_config config;
    config.mode = "1";
    config.level = "4";
    config.appender="test";
    config.file_name="slog-testing";
    config.dir="./";
    config.pwd="/home/kundan/workspace/Brokers/currenex/platform/cx_open_oms/trunk";

    SLog sLog(config);
    std::ifstream in("/home/kundan/Downloads/news.xml", std::ios::in | std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
    
        string sKundan = "hey Kundan";
        sLog.debug("Starting sLog testing = %s\n", sKundan.c_str());
        sLog.debug("Contents = %s\n", contents.c_str());
//        sLog.debug("Hello\n");
//        cout << "contents " << contents << endl;
    }

}

//g++ -g test_slog_message.cpp -l:libubaclogger.so.1.2.0
