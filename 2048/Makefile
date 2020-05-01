#compiler
COMPILER := gcc

#compiler flags
CFLAGS := `sdl2-config --cflags --libs` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm

#source files
SOURCE := main_sdl.c appear.c check.c grille.c move.c

#object files
OBJECT := $(SOURCE:.c=.o)

#name of excutable
EXEC := 2048.x

#default compiling recipe
all: $(EXEC)

#compiler executable
$(EXEC): $(OBJECT)
	$(COMPILER) -Wall $(OBJECT) $(CFLAGS) -o $(EXEC)


#build object files
$(OBJECT): $(SOURCE)
	$(COMPILER) -c $(SOURCE) $(CFLAGS)




clean:
	rm -rf $(OBJECT) $(EXEC) 
