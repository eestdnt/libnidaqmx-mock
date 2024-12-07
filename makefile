.DEFAULT_GOAL := all

# Make commands
.PHONY = all clean test install uninstall

# Compiler
CC ?= gcc

BUILD_DIR = ./build

# Directories
BIN_DIR ?= $(BUILD_DIR)/bin
OBJ_DIR ?= $(BUILD_DIR)/obj
INC_DIR ?= ./inc
SRC_DIR ?= ./src

# Target list
TARGET_NAME ?= libnidaqmx.so
TARGET = $(BIN_DIR)/$(TARGET_NAME)
TEST_PROGRAM = $(BIN_DIR)/test

# Compilation and linking flags for library
CC_OPTS := $(CC_OPTS) -I $(INC_DIR) -Wall -fpic
LD_OPTS = -shared
LIBS =

# Compilation and linking flags for test program
CC_TEST_OPTS := $(CC_TEST_OPTS) -I $(INC_DIR) -Wall
LD_TEST_OPTS = -L $(BIN_DIR)
LIBS_TEST_OPTS = -lnidaqmx

# Header files
HEADERS = defs.h nidaqmx.h

# Source files
SRC = nidaqmx.c
TEST_SRC = test.c

# Source files with full paths
HEADER_FILES = $(patsubst %.h, $(INC_DIR)/%.h, $(HEADERS))

SRC_FILES = $(patsubst %.c, $(SRC_DIR)/%.c, $(SRC))
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

TEST_SRC_FILES = $(patsubst %.c, $(SRC_DIR)/%.c, $(TEST_SRC))
TEST_OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SRC))

# All targets
all: $(TARGET)

# Main target
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LD_OPTS) $^ -o $@

# Test target
$(TEST_PROGRAM): $(TARGET) $(TEST_OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LD_TEST_OPTS) $(TEST_OBJ_FILES) -o $@ $(LIBS_TEST_OPTS)

# Object file targets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CC_OPTS) $< -c -o $@

# Run test program
test: $(TEST_PROGRAM)
	$(TEST_PROGRAM)

install: $(TARGET)
	cp $(TARGET) /usr/lib/
	chmod 0755 /usr/lib/$(TARGET_NAME)
	ldconfig

uninstall:
	rm /usr/lib/$(TARGET_NAME)
	ldconfig

# Clean binary files
clean:
	-$(RM) -Rfv $(BUILD_DIR)

