/**
 * @file
 * @ingroup cli
 */


#include "cli/shell/cli_shell.h"

// TODO #include "mcu/cputimers/mcu_cputimers.h"


int cli_uptime(int argc, const char** argv)
{
	if (argc == 0)
	{
		// TODO snprintf(CLI_CMD_OUTPUT, CLI_CMD_OUTPUT_LENGTH, "uptime: %llums", mcu::SystemClock::now());
	}
	else
	{
		if (strcmp(argv[0], "-v") == 0)
		{
			uint64_t sec = 1;// TODO mcu::SystemClock::now() / 1000;
			uint64_t msec = 42;// TODO mcu::SystemClock::now() - 1000 * sec;
			uint64_t min = sec / 60;
			sec -= 60 * min;

			// TODO float uptime = mcu::SystemClock::now() / 1000.f;
			snprintf(CLI_CMD_OUTPUT, CLI_CMD_OUTPUT_LENGTH, "uptime: %llum %llus %llums", min, sec, msec);
		}
		else
		{
			snprintf(CLI_CMD_OUTPUT, CLI_CMD_OUTPUT_LENGTH, "uptime: invalid option - \"%s\"", argv[0]);
		}
	}

	cli::nextline();
	cli::print(CLI_CMD_OUTPUT);
	return 0;
}


