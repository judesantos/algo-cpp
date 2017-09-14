OBJS = LinkedList.o  IsPalindrome.o

INC = ../inc
SRC = ../src

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

IsPalindrome.exe : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o ispalindrome.exe

LinkedList.o: $(INC)/LinkedList.h $(SRC)/LinkedList.cpp
		$(CC) $(CFLAGS) $(SRC)/LinkedList.cpp

IsPalindrome.o: IsPalindrome.cpp
		$(CC) $(CFLAGS) IsPalindrome.cpp



clean:
	    \rm *.o *~ *.exe

tar:
	    tar cfv  welcome.tar *.cpp *.h 
