OBJS = reversestring.o

INC = ../inc
SRC = ../src

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

reversestring.exe : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o reversestring.exe

reversestring.o: reversestring.cpp
		$(CC) $(CFLAGS) reversestring.cpp



clean:
	    \rm *.o *~ *.exe

tar:
	    tar cfv  welcome.tar *.cpp *.h 
