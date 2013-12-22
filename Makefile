# Takes the name of the current directory as a the executable and "pr" name
TARGET  := $(shell basename $$PWD | tr '[:upper:]' '[:lower:]')
# Compiler
CC      := g++
# Warning levels
WARN    :=
# Optimisation
OFLAGS  := 
# Link Options
LDFLAGS := $(shell pkg-config gtkmm-3.0 --cflags)
# Link Libraries
LDLIBS 	:= $(shell pkg-config gtkmm-3.0 --libs)

# Source directory
# SRCDIR := src
# Include directory
# INCDIR := include
# Object directory
# OBJDIR := obj

CPP_SRCS    = $(wildcard src/*.cpp)
OBJ_FILES   = $(CPP_SRCS:.cpp=.o)

all: ${TARGET}

$(TARGET): $(OBJ_FILES)
	@echo "Linking..."
	$(CC) $(WARN) $(OFLAGS) $(LDFLAGS) $(OBJ_FILES) -o $@ $(LDLIBS) 
	@echo "Done."

.cpp.o : 
	@echo "Compiling "$<"..."
	$(CC) -c $(WARN) $(OFLAGS) $(LDFLAGS) $< -o $@

clean: 
	@echo "Cleaning..."
	rm -rf ./src/*.o

mrproper: clean
	rm -rf ${TARGET}

