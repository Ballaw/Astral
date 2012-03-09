CC=g++
CFLAGS=-Wall
INCLUDE_DIR=-I./inc
AR=
LIBS=-lSDL -lSDL_image
SOURCES=./src/Astral_OnEvent.cpp ./src/Astral_OnLoop.cpp ./src/Astral_OnCleanup.cpp ./src/Astral_OnInit.cpp ./src/Astral_OnRender.cpp ./src/Astral.cpp
ASOBJECTS=$(ASSOURCES:.s=.o)
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=Astral

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)

.cpp.o:
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) -o $@ $<

clean:
	rm -rf $(OBJECTS) $(TARGET)


#g++ demo.cpp -o demo -lSDL -lSDL_image

