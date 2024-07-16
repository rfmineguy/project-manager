OUT_DIR := out
GETOPT_DIR := getopt
SRC_DIR := src
INCLUDE_DIR := include
SOURCES := $(SRC_DIR)/*.c

BIN := projman

.PHONY: always build
.PHONY: getopt
always:
	mkdir -p $(OUT_DIR)
build: always getopt $(OUT_DIR)/$(BIN)
getopt:
	gengetopt -i config.ggo --src-output-dir $(SRC_DIR) --header-output-dir $(INCLUDE_DIR)/projman  
#=============================

$(OUT_DIR)/$(BIN): $(SOURCES)
	gcc $^ -o $@ -I$(INCLUDE_DIR)/projman
