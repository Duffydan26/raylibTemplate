# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra
LIBS = -lraylib -lgdi32 -lwinmm

# Project name (based on folder structure)
PROJECT_NAME = $(WORKSPACE_NAME)

# Source directory and output directory
SRC_DIR = src
BUILD_DIR = build

# Source file and target paths
SRC = $(SRC_DIR)/main.cpp
DEBUG_TARGET = $(BUILD_DIR)/$(PROJECT_NAME)_debug.exe
RELEASE_TARGET = $(BUILD_DIR)/$(PROJECT_NAME).exe

# Create the build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# Debug build
debug: CFLAGS += -O0 -g
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(DEBUG_TARGET) $(LIBS)

# Release build
release: CFLAGS += -O3
release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(RELEASE_TARGET) $(LIBS)

# Clean build files
clean:
	rm -f $(DEBUG_TARGET) $(RELEASE_TARGET)
