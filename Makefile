# Executable name
EXEC = Res

# Dependencies
INCLUDES = -I include
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
ifdef SFML-2.5.1
	INCLUDES += -I ${SFML-2.5.1}/include
	LIB_DIRS = -L ${SFML-2.5.1}/lib
endif

# Compiler
CXX = g++
CFLAGS = -c -Wall $(INCLUDES)

# Files
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,build/%.o,$(SRCS))

# Compilation
all: $(EXEC)

# Link objects and libraries into binary.
$(EXEC): $(OBJS)
	$(CXX) $(LIB_DIRS) -o $(EXEC) $(OBJS) $(LIBS)

# Compile object files from source files.
build/%.o: src/%.cpp build include
	$(CXX) $(CFLAGS) $< -o $@

# Create missing directories
MKDIR = mkdir
ifneq ($(OS), Windows_NT)
	MKDIR += -p
endif
build:
	$(MKDIR) build
include:
	$(MKDIR) include