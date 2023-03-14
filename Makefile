# Project
EXEC = Res

# Dependencies
INCLUDES = -I include
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
ifdef SFML-2.5.1
	ifeq ($(OS), Windows_NT)
		SEP = \ 
	else
		SEP = /
	endif
	INCLUDES += -I ${SFML-2.5.1}$(SEP)include
	LIB_DIRS = -L ${SFML-2.5.1}$(SEP)lib
endif

# Compiler
CXX = g++
CFLAGS = -c -Wall $(INCLUDES)

# Files
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,build/%.o,$(SRCS))

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(LIB_DIRS) -o $(EXEC) $(OBJS) $(LIBS)

build/%.o: src/%.cpp
	$(CXX) $(CFLAGS) $< -o $@