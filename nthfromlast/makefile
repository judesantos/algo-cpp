OBJS = LinkedList.o  main.o

INC = ../inc
SRC = ../src

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main.exe : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o main.exe

LinkedList.o: $(INC)/LinkedList.h $(SRC)/LinkedList.cpp
		$(CC) $(CFLAGS) $(SRC)/LinkedList.cpp

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp



clean:
	    \rm *.o *~ *.exe

tar:
	    tar cfv  welcome.tar *.cpp *.h 
