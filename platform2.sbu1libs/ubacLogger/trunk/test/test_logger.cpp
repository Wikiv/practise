#include <sys/wait.h>
#include <sys/types.h>
#include <sys/prctl.h>

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <sstream> 
#include <ubacyaml/YamlConfig.h>

#include "SLog.h"

using namespace std;

////
// g++ -I include/ test_logger.cpp -lubaclogger++ -lubacyaml++
////
//
//

size_t KB = 1024;

int main(int argc, char * argv[]) 
{
    /*struct s_logger_config config;

    config.mode = "2";
    config.level = "4";
    config.appender = "one";
    config.file_name = "slog-testing.MSF0001";
    config.name_space = "oms"; 
    config.central_logger_ip = "localhost";
    config.central_logger_port = "5679";

    SLog sLog(config);

    sLog.info("Hello");
*/
    string _s(argv[1]);

    size_t msg_size = KB * KB;
    if (argc > 2)
        msg_size = KB * atoi(argv[2]);

    YamlConfig appConfig(_s);

    cout << appConfig["logging"]["filename"] << endl;

    string pwd;
    string appender;

    SLog sLog(appConfig, pwd, appender, false);

    int counter = 0;
    while(1)
    {

        string msg;

        for(size_t i = 0; i < msg_size; i++)
        {
            msg.append(1, 'a');
        }

        sLog.info(msg.c_str());

        counter++;
        sLog.info("------- END ------ %d", counter);
        //cout << counter << endl;

        usleep(1000 * 1000);

    }


}
