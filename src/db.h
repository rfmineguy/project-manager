#ifndef DB_H
#define DB_H
#include "ht_str_project.h"

const char* db_loc();
int   db_exists();

/* db_read
 * return
 *    NULL if PROJDB_LOC isnt a file
 *    NULL if PROJDB_LOC couldnt be read
 *  
 *  returned char* must be freed by caller
 */
char* db_read();

ht_str_project db_parse(char*);

#endif
