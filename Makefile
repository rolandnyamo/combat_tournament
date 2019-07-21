# # .author: Roland Nyamoga (nyamogar@oregonstate.edu)
# # .descr: Makefile for Fantasy combat functions

CC = g++

CFLAGS = -c
CFLAGS = -Wall
CFLAGS += -std=c++11
CFLAGS += -g #To debug with gdb

SRCS = lineup.cpp barbarian.cpp blueMen.cpp character.cpp harry.cpp medusa.cpp menu.cpp vampire.cpp main.cpp
OBJS = lineup.o barbarian.o blueMen.o character.o harry.o medusa.o menu.o vampire.o main.o
HEADERS = lineup.hpp barbarian.hpp blueMen.hpp character.hpp harry.hpp medusa.hpp menu.hpp vampire.hpp
OUT = combat #Name of the executable

#My output depends on the objects.
$(OUT): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -o $(OUT)
	rm $(OBJS) *.gch

#Objects depend on source and header files
$(OBJS): $(SRCS) $(HEADERS)
	$(CC) -c $(SRCS) $(HEADERS) 

#This cleans all files created from compiling
clean:
	rm $(OUT)
	clear
