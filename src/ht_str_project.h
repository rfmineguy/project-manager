#ifndef HT_STR_PROJECT_H
#define HT_STR_PROJECT_H
#include "chash_tplt.h"

typedef struct project {
    char name[100];
    char path[100];
} project;

#define BUCKET_COUNT 10
HT_DEF(str, project, const char*, project);
HT_PUT_PROTO(str, project, const char*, project);
HT_CONTAINS_KEY_PROTO(str, project, const char*, project);
HT_CONTAINS_VALUE_PROTO(str, project, const char*, project);
HT_REMOVE_KEY_PROTO(str, project, const char*, project);
HT_GET_PROTO(str, project, const char*, project);
HT_GET_PTR_PROTO(str, project, const char*, project);
HT_HASH_PROTO(str, project, const char*, project);
HT_FREE_PROTO(str, project, const char*, project);
HT_CMP_KEY_PROTO(str, project, const char*, project);
HT_CMP_VALUE_PROTO(str, project, const char*, project);

#endif
