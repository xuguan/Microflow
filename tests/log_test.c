#include "../src/mf_logger.h"

//extern const char* mf_default_log_path;

int main()
{
	//mf_logger_open(mf_default_log_path);
	mf_logger_open(mf_default_log_path);
	mf_write_log("Test string..");
	mf_write_log("another test string");
	mf_logger_close();
	return 0;
}