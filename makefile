.DEFAULT_GOAL := all

# Make commands
.PHONY = all clean test install uninstall

# Compiler
CC ?= gcc

BUILD_DIR = ./build

# Directories
BIN_DIR ?= $(BUILD_DIR)/bin
OBJ_DIR ?= $(BUILD_DIR)/obj
TEST_DIR ?= $(BUILD_DIR)/test
INC_DIR ?= ./inc
SRC_DIR ?= ./src
TEST_SRC_DIR ?= ./test

# Target list
TARGET_NAME ?= libnidaqmx.so
TARGET = $(BIN_DIR)/$(TARGET_NAME)
TEST_LIST = test

# Compilation and linking flags for library
CC_OPTS := $(CC_OPTS) -I $(INC_DIR) -Wall -fpic
LD_OPTS = -shared
LIBS =
TEST_LIBS = -lunity -lnidaqmx

# Compilation and linking flags for test program
CC_TEST_OPTS := $(CC_TEST_OPTS) -I $(INC_DIR) -Wall
LD_TEST_OPTS = -L $(BIN_DIR)

# Header files
HEADERS = defs.h nidaqmx.h

# Source files
SRC = nidaqmx.c

# Source files with full paths
HEADER_FILES = $(patsubst %.h, $(INC_DIR)/%.h, $(HEADERS))

SRC_FILES = $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC))
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

# Test target file paths
TEST_TARGETS = $(patsubst %, $(TEST_DIR)/%, $(TEST_LIST))

# All targets
all: $(TARGET) $(TEST_TARGETS)

# Main target
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LD_OPTS) $^ -o $@

# Object file targets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_OPTS) $< -c -o $@

# Run all test targets
test: $(TEST_TARGETS)
	$(TEST_TARGETS)

# Test targets
$(TEST_DIR)/test: $(SRC_DIR)/nidaqmx.c $(TEST_SRC_DIR)/test.c
	@mkdir -p $(TEST_DIR)
	$(CC) $(CC_OPTS) $^ -o $@ $(TEST_LIBS)

install: $(TARGET)
	cp $(TARGET) /usr/local/lib/
	chmod 0755 /usr/local/lib/$(TARGET_NAME)
	ldconfig

uninstall:
	rm /usr/local/lib/$(TARGET_NAME)
	ldconfig

# Clean binary files
clean:
	-$(RM) -Rfv $(BUILD_DIR)

