OBJS = LinkedList.o  AddList.o

INC = ../inc
SRC = ../src

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Addlist.exe : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o addlist.exe

LinkedList.o: $(INC)/LinkedList.h $(SRC)/LinkedList.cpp
		$(CC) $(CFLAGS) $(SRC)/LinkedList.cpp

AddListt.o: AddList.cpp
		$(CC) $(CFLAGS) AddList.cpp



clean:
	    \rm *.o *~ *.exe

tar:
	    tar cfv  welcome.tar *.cpp *.h 
