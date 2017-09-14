OBJS = main.o LinkedList.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

welcome.exe : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o welcome.exe

LinkedList.o: LinkedList.h LinkedList.cpp
		$(CC) $(CFLAGS) LinkedList.cpp

#hello.o: hello.h hello.cpp
#		$(CC) $(CFLAGS) hello.cpp

main.o: main.cpp hello.h
		$(CC) $(CFLAGS) main.cpp

clean:
	    \rm *.o *~ *.exe

tar:
	    tar cfv  welcome.tar *.cpp *.h 
