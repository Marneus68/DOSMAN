# Takes the name of the current directory as a the executable and "pr" name
TARGET  := $(shell basename $$PWD | tr '[:upper:]' '[:lower:]')
# Compiler
CC      := g++
# Warning levels
WARN    :=
# Optimisation
OFLAGS  := 
# Link Options
LDFLAGS := `pkg-config gtkmm-3.0 --cflags` `pkg-config glibmm-2.4 --cflags`
# Link Libraries
LDLIBS 	:= `pkg-config gtkmm-3.0 --libs` `pkg-config glibmm-2.4 --libs`

# Source directory
SRCDIR	:= src
# Include directory
INCDIR	:= include
# Object directory
OBJDIR	:= obj

CFLAGS	:= -I $(INCDIR)

# setting the vpath (additionnal search path for make)
VPATH	:= $(INCDIR) $(SRCDIR) $(OBJDIR)

CPP_SRCS    = $(wildcard src/*.cpp)
OBJ_FILES   = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(CPP_SRCS))

all: ${TARGET}

$(TARGET): $(OBJ_FILES)
	@echo "Linking..."
	$(CC) $(WARN) $(OFLAGS) $(CFLAGS) $(LDFLAGS) $(OBJ_FILES) -o $@ $(LDLIBS) 
	@echo "Done."

obj/%.o: %.cpp
	@echo "Compiling "$<"..."
	$(CC) -c $(WARN) $(OFLAGS) $(CFLAGS) $(LDFLAGS) $< -o $@

clean: 
	@echo "Cleaning..."
	rm -rf $(OBJDIR)/*.o

mrproper: clean
	rm -rf ${TARGET}

install:
	@echo "Installing..."

doc:
	@echo "Building documentation..."
	doxygen doxygen.conf
	pandoc SPEC.md -o SPEC.pdf

cleandoc:
	@echo "Building documentation..."
	rm -f SPEC.pdf
	rm -rf doc

test: $(TARGET)
	@echo "Creating a test scenario..."
	mkdir -p ~/.dosman
	cp -rf test -t ~/.dosman
	./dosman


