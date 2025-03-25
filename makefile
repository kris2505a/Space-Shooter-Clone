# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -m64 -I./thirdparty/SFML/include -I./src/Headers -DSFML_STATIC

# Directories
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
LIB_DIR = thirdparty/SFML/lib

# Executable name
TARGET = SpaceShooter

# Sources and objects
SOURCES = $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Default rule
all: $(BIN_DIR)/$(TARGET)

# Create output directories
$(BIN_DIR):
	@if not exist "$@" mkdir "$@"

$(BUILD_DIR):
	@if not exist "$@" mkdir "$@"

# Compile .cpp files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the executable with static SFML
$(BIN_DIR)/$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) -o $@ $^ -L$(LIB_DIR) -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lgdi32 -lwinmm -lws2_32 -lpthread -static -static-libgcc -static-libstdc++

# Clean up the build files
.PHONY: clean
clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist $(BIN_DIR) del /Q $(BIN_DIR)\$(TARGET).exe 2>nul

# Run the program
.PHONY: run
run: $(BIN_DIR)/$(TARGET)
	@$(BIN_DIR)\$(TARGET).exe