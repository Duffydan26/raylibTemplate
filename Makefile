# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra
LIBS = -lraylib -lgdi32 -lwinmm

# Platform and OS settings
PLATFORM = PLATFORM_DESKTOP
PLATFORM_OS = WINDOWS

# Raylib path
RAYLIB_PATH = C:/raylib/raylib

# Project name (based on folder structure)
PROJECT_NAME = $(WORKSPACE_NAME)

# Source directory and output directory
SRC_DIR = src
BUILD_DIR = build
SUBDIRS = $(BUILD_DIR)/debug $(BUILD_DIR)/release

# Source files (using wildcard to include all .cpp files in src and subdirectories)
SRC = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)

# Target paths
DEBUG_TARGET = $(BUILD_DIR)/debug/$(PROJECT_NAME)_debug.exe
RELEASE_TARGET = $(BUILD_DIR)/release/$(PROJECT_NAME).exe

# Create the build directories if they don't exist
$(shell mkdir -p $(SUBDIRS))

# Conditional for platform and OS (Windows desktop)
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    ifeq ($(PLATFORM_OS),WINDOWS)
        # resource file contains windows executable icon and properties
        # -Wl,--subsystem,windows hides the console window
        CFLAGS += $(RAYLIB_PATH)/src/raylib.rc.data
    endif
endif

# Debug build
debug: CFLAGS += -O0 -g
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(SRC) $(SUBDIRS)
	$(CC) $(CFLAGS) $(SRC) -o $(DEBUG_TARGET) $(LIBS)

# Release build
release: CFLAGS += -O3
release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(SRC) $(SUBDIRS)
	$(CC) $(CFLAGS) $(SRC) -o $(RELEASE_TARGET) $(LIBS)

# Ensure subdirectories exist
$(SUBDIRS):
	mkdir -p $(SUBDIRS)

# Clean build files
clean:
	rm -f $(DEBUG_TARGET) $(RELEASE_TARGET)
	rm -rf $(BUILD_DIR)
