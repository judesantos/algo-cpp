OBJS = main.o ThreadPool.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -L/usr/lib/x86_64-linux-gnu/ -lboost_filesystem -lboost_system -lboost_thread -Wall

thread.exe : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o thread.exe

ThreadPool.o: ThreadPool.h ThreadPool.cpp
		$(CC) $(CFLAGS) ThreadPool.cpp

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

clean:
	    \rm *.o *~ *.exe

tar:
	    tar cfv  welcome.tar *.cpp *.h 
