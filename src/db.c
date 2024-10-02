#include "db.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
 * ENV: PROJDB_LOC
 */
int db_exists() {
    const char* projloc = getenv("PROJDB_LOC");
    return projloc != NULL;
}

const char* db_loc() {
    return getenv("PROJDB_LOC");
}

FILE* db_create_if_not_exist() {
    const char* projloc = getenv("PROJDB_LOC");
    char filename[strlen(projloc) + 100];
    filename[0] = 0;
    strcat(filename, projloc);
    strcat(filename, "/projman.db");
    printf("dbfile = %s\n", filename);
    FILE* f = fopen(filename, "wa");
    fprintf(f, "[Empty_DB]");
    fclose(f);
    f = fopen(filename, "r");
    return f;
}

char* db_read() {
    FILE* f = db_create_if_not_exist();
    fseek(f, 0, SEEK_END);
    long s = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* buf = malloc(sizeof(char) * s);
    fread(buf, sizeof(char), s, f);
    fclose(f);
    return buf;
}

ht_str_project db_parse(char* str) {
    ht_str_project ht = {0};
    char *line, *linerest = str;
    while ((line = strtok_r(linerest, "\n", &linerest))) {
        char *entry, *entryrest = line;
        while ((entry = strtok_r(entryrest, ", ", &entryrest))) {
            printf("Entry:  %s\n", entry);
        }
    }
    
    return ht;
}
