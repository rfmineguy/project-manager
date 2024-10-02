#include <stdio.h>
#include <assert.h>
#include "cmdline.h"
#include "commands.h"
#include "db.h"

int main(int argc, char** argv) {
	struct gengetopt_args_info info = {0};
	if (cmdline_parser(argc, argv, &info) != 0) {
		fprintf(stderr, "Failed to parse arguments\n");
		return 1;
	}
    result r;
    if (info.list_given && (r = cmd_list(&info)).code != 0) {
        fprintf(stderr, "Error: %s\n", r.errmsg);
        return r.code;
    }
    if (info.register_given && (r = cmd_register(&info)).code != 0) {
        fprintf(stderr, "Error: %s\n", r.errmsg);
        return r.code;
    }
    return r.code;
}
