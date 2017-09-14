OBJS = longestpalindrome.o

INC = ../inc
SRC = ../src

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

longestpalindrome.exe : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o longestpalindrome.exe

longestpalindrome.o: longestpalindrome.cpp
		$(CC) $(CFLAGS) longestpalindrome.cpp



clean:
	    \rm *.o *~ *.exe

tar:
	    tar cfv  welcome.tar *.cpp *.h 
