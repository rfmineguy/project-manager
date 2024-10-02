#include "commands.h"
#include "db.h"
#include <stdlib.h>
#define cmd_assert(expr, msg, code, extra)\
    if (!(expr)) { extra; return ERR(msg, code); }

result cmd_list(struct gengetopt_args_info* info){
    cmd_assert(db_loc() != NULL, "Must assign PROJDB_LOC for your session", 1, {});
    cmd_assert(info->name_given, "List requires name parameter", 2, {});
    
    printf("List projects with name: %s\n", info->name_arg);

    return OK();
}

result cmd_register(struct gengetopt_args_info* info){
    cmd_assert(db_loc() != NULL, "Must assign PROJDB_LOC for your session", 1, {});
    cmd_assert(info->name_given, "Register requires name parameter", 2, {});
    cmd_assert(info->path_given, "Register requires path parameter", 3, {});

    printf("Register project {name=%s, path=%s}\n", info->name_arg, info->path_arg);

    char* content = db_read();
    cmd_assert(content != NULL, "Failed to read database", 4, free(content));
    ht_str_project ht = db_parse(content);

    ht_str_project_free(&ht);
    return OK();
}
