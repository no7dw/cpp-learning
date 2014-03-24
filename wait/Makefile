CC=gcc
MCC=mipsel-linux-gcc
#CFLAGS=-lpthread
SRCS=wait.c
OBJ=wait
MOBJ=wait

SRCSP=waitpid.c
OBJP=waitpid

all:
	 $(CC) $(SRCS) -o $(OBJ) 
	 $(CC) $(SRCSP) -o $(OBJP) 
Mall:
	 $(MCC) $(SRCS) -o $(MOBJ) 
clean:
	rm *.jpg* *.avi* $(OBJ) $(OBJP) *.o -f

Mclean:
	rm *.jpg* *.avi* $(MOBJ) *.o -f
