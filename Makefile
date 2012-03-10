DIR = ./
SRCDIR = $(DIR)src/
OBJDIR = $(DIR)obj/
BINDIR = $(DIR)bin/
INC = -I$(SRCDIR) -I$(SRCDIR)Display -I$(DIR)inc
LIB = -lSDL -lSDL_image -
CXX = g++

VPATH = $(SRCDIR):$(SRCDIR)Display
SOURCES= SDLFunctions.cpp Display.cpp Astral_OnEvent.cpp Astral_OnLoop.cpp Astral_OnCleanup.cpp Astral_OnInit.cpp Astral_OnRender.cpp Astral.cpp

OBJECTS=$(SOURCES:%.cpp=$(OBJDIR)%.o)


all: dir $(BINDIR)Astral

dir:
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

$(BINDIR)Astral: $(OBJECTS)	
	$(CXX) $(INC) $(LIB) $(OBJECTS) -o $@
$(OBJDIR)%.o: %.cpp
	$(CXX) -c $(INC) $^ -o $@

clean:
	rm -r $(OBJDIR) $(BINDIR)
