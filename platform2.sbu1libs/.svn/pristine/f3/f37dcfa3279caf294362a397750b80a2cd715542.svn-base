
#include <ubacyaml/YamlConfig.h>
#include "SLog.h"

////
// g++ -I include/ test_logger.cpp -lubaclogger++ -lubacyaml++
////

int main(int argc, char * argv[]) {

	YamlConfig yamlConfig("test/slog.yml");

    SLog slog(yamlConfig, "", "", false);
	
	slog.info("Info statement");

	slog.debug("Degug statement");

	slog.error("Error...");		

}
