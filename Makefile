OUT_DIR := out
SRC_DIR := src
SOURCES := $(SRC_DIR)/main.c

BIN := projman

.PHONY: always build
always:
	mkdir -p $(OUT_DIR)
build: always $(OUT_DIR)/$(BIN)
#=============================

$(OUT_DIR)/$(BIN): $(SOURCES)
	gcc $^ -o $@
