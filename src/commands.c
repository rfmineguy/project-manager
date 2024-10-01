#include "commands.h"
#define cmd_assert(expr, msg, code)\
    if (!(expr)) return ERR(msg, code)

result cmd_list(struct gengetopt_args_info* info){
    cmd_assert(info->name_given, "List requires name parameter", 1);
    
    printf("List projects with name: %s\n", info->name_arg);

    return OK();
}

result cmd_register(struct gengetopt_args_info* info){
    cmd_assert(info->name_given, "Register requires name parameter", 1);
    cmd_assert(info->path_given, "Register requires path parameter", 2);

    printf("Register project {name=%s, path=%s}\n", info->name_arg, info->path_arg);

    return OK();
}
