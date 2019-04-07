#NOM: VIERA SANTA CRUZ MATTHIEU
#NUMERO: 16700264
#EMAIL: matthieu0006@gmail.com

## Compilation thread et image ##

#g++ -Wall -std=c++14 -O3 -pthread a.cpp -lbenchmark

## Compilation image ##

#g++ -c -Wall -std=c++14 -O3 im_th.cpp $(sdl2-config --cflags)
#g++ -Wall -std=c++14 -O3 filtrage.cpp GSImage.o $(sdl2-config --libs) -lSDL2_image

#g++ -Wall -O3 opcv2.cpp `pkg-config --cflags --libs opencv`

#g++ -Wall -std=c++14 -O3 filtrage.cpp GSImage.o $(sdl2-config --libs) -lSDL2_image `pkg-config --cflags --libs opencv`

# CC=g++
# CFLAGS=-Wall -g -O3
# VERSION=-std=c++14 -pthread
# LLB=-lbenchmark
# SRC=mul_th.cpp
# OBJ=$(SRC:.c=.o)
#
# %.o:	%.c libR/%.c
#   $(CC) -c $(CFLAGS) $<
#
# prog: 	$(OBJ)
#   $(CC) $(OBJ) -o $@ $(VERSION)  $(LLB)
#
# clean:
#   rm *.o prog

CC=g++
CFLAGS= -Wall -std=c++14 -O3
OPENCV= `pkg-config --cflags --libs opencv`
SDLFLAGS= $(sdl2-config --cflags)
SDLLIBS= $(sdl2-config --libs)
SRC= main.cpp julia.cpp

julia: main.cpp julia.cpp julia.hpp
		$(CC) -o julia $(CFLAGS) $(SRC) -fopenmp $(OPENCV)


clean:
		rm -r *.o julia *.avi
