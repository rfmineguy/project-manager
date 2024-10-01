#ifndef COMMANDS_H
#define COMMANDS_H
#include "cmdline.h"


#define ERR(msg, errcode) (result) {.code=errcode, .errmsg=msg}
#define OK() (result) {.code=0}
typedef struct {
    int code; // 0 is success code
    const char* errmsg;
} result;

result cmd_list    (struct gengetopt_args_info*);
result cmd_register(struct gengetopt_args_info*);

#endif
