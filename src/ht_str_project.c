#include "ht_str_project.h"
#include <string.h>
#include <stdlib.h>

HT_CMP_KEY_DEF(str, project, const char*, project) {
	return strcmp(key1, key2) == 0;
}
HT_CMP_VALUE_DEF(str, project, const char*, project) {
	return strcmp(val1.name, val2.name) == 0 &&
        strcmp(val1.path, val2.path) == 0;
}
HT_HASH_DEF(str, project, const char*, project) {
	unsigned long hash = 5381;
	int c;
	while ((c = *key++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % BUCKET_COUNT;
}
HT_GET_PTR_IMPL(str, project, const char*, project)
HT_GET_IMPL(str, project, const char*, project, (project){})
HT_PUT_IMPL(str, project, const char*, project)
HT_REMOVE_KEY_IMPL(str, project, const char*, project)
HT_CONTAINS_KEY_IMPL(str, project, const char*, project)
HT_CONTAINS_VALUE_IMPL(str, project, const char*, project)
HT_FREE_IMPL(str, project, const char*, project)
