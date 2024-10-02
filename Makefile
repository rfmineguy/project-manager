OUT_DIR := out
GETOPT_DIR := getopt
SRC_DIR := src
SOURCES := $(SRC_DIR)/*.c

CFLAGS := -ggdb

BIN := projman

.PHONY: always build
.PHONY: getopt
always:
	mkdir -p $(OUT_DIR)
build: always getopt $(OUT_DIR)/$(BIN)
getopt:
	gengetopt -i config.ggo --src-output-dir $(SRC_DIR) --header-output-dir $(SRC_DIR)  
#=============================

$(OUT_DIR)/$(BIN): $(SOURCES)
	gcc $^ -o $@ $(CFLAGS) -I$(INCLUDE_DIR)/projman
