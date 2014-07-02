.SUFFIXES:

#TODO build without debug
#application of the playlist class
EXEC       = $(BINDIR)demo
DEMOBJ     = ./src/application.o
DEMOBJA    = ./obj/application.o
CC         = g++
DEBUGFLAGS = -ggdb 
EXECA      = $(BINDIR)demoarch
RM = rm -f 


#name of my library and ar flags
#ARCH    = $(BINDIR)playlist.a
#AR      = ar 
#ARFLAGS = -rc 

# RANLIB
#RANLIB = ranlib

#Directories
OBJDIR   = ./obj/
SRCDIR   = ./src/
BINDIR   = ./bin/
INCLUDES = ./inc/ 
LIBS =  gtkmm-3.0\
				glibmm-2.4

#sources 
SRCARC  = $(SRCDIR)KeyValueParser.cpp\

DEMOSRC  = $(SRCDIR)application.cpp\
					 $(SRCARC)

DEMOSRCA = $(SRCDIR)application.cpp\

DEMOBJ   := $(DEMOSRC:.cpp=.o) 
DEMOBJ	:= $(addprefix $(OBJDIR),$(subst $(SRCDIR),,$(DEMOBJ)))

#compile for archive and create obJ for archive
#SRC    = $(SRCARC)
#AROBJ  = $(SRC:.cpp=.o)
#/!\	AROBJ := $(addprefix $(OBJDIR),$(subst $(SRCDIR),,$(AROBJ)))

#compiler and linker flags
CFLAGS = `pkg-config --cflags $(LIBS)`\
				 -Wall -Werror -I $(INCLUDES) -I ../common/ \
				 -std=gnu++11\
				 -I ./inc/

LFLAGS = `pkg-config --libs $(LIBS)` \



# create objetcs for archive
$(OBJDIR)%.o:$(SRCDIR)%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

# archive object into library
#$(ARCH):$(AROBJ)
#       $(AR) $(ARFLAGS) $@ $^ 
#       $(RANLIB) $@

###### create the main
#$(DEMOBJA):$(DEMOSRCA)
#	$(CC) -c $(DEMOSRCA) -o $@ $(CFLAGS)

#DEMOARCH =  $(DEMOBJA) \
	#           $(ARCH)


%.o:%.cpp
	$(CC) $(DEBUGFLAGS) -c $^ -o $@ $(CFLAGS)

#demo with debug
$(EXEC):$(DEMOBJ)
	$(CC) $(DEMOBJ) -o $@ $(LFLAGS) 

#demo with arch
#$(EXECA):$(DEMOARCH)
#	$(CC) -o $@ $(DEMOARCH) $(LFLAGS)

# make requests
all:$(ARCH)
demo:$(EXEC)
demoarch:$(EXECA)
deo:$(DEMOBJA)

.PHONY: clean mrproper

clean:
	$(RM) $(ARCH)
	$(RM) $(OBJDIR)*.o
	$(RM) $(SRCDIR)*.o
	$(RM) $(EXEC)
	$(RM) $(EXECA)

mrproper:
	#rm ./obj/*.o
	$(RM) $(EXEC)

reset:clean demo
	clear && ./bin/demo

#PAQ de réference 
#PAQ de suivi 
