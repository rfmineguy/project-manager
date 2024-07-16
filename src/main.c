#include <stdio.h>
#include "cmdline.h"

struct register_info {
	const char *projname, *projpath;
};

int command_run_list() {}
int command_run_register(struct register_info info) {}

int main(int argc, char** argv) {
	struct gengetopt_args_info info = {0};
	if (cmdline_parser(argc, argv, &info) != 0) {
		fprintf(stderr, "Failed to parse arguments\n");
		return 1;
	}
	if (info.list_given) {
		command_run_list();
	}
	if (info.register_given) {
		struct register_info rinfo = (struct register_info){0};
		rinfo.projname = info.name_arg;
		rinfo.projpath = info.path_arg;
		command_run_register(rinfo);
	}
}
