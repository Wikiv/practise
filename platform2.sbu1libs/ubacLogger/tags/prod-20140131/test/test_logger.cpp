
#include <ubacyaml/YamlConfig.h>
#include <ubaclogger/SLog.h>

////
// g++ test_logger.cpp -lubaclogger++ -lubacyaml++
////

int main(int argc, char * argv[]) {

	YamlConfig yamlConfig("slog.yml");

    SLog slog(yamlConfig, "", "", false);
	
	slog.info("Info statement");

	slog.debug("Degug statement");

	slog.error("Error...");		

}
