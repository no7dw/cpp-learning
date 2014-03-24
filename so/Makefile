OBJS = testso.o myfunction.o
CC = gcc
#CFLAGS = -shared -o
testso:$(OBJS)
	$(CC) $^ -o $@

clean:
	$(RM) *.o testso libmyfunction.so  -f

