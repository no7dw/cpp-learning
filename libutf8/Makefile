#include ../../../include/MakeConfig

CC=$(MYCC)
RANLIB=$(MYRANLIB)
AR=$(MYAR)
ARFLAGS=cru
CFLAGS=-Wall -I. -I. -D_GNU_SOURCE=1 -D_FILE_OFFSET_BITS=64 -static -g -O2 -std=c99 -c
LDFLAGS=
SOURCES=conv.c
OBJECTS=$(SOURCES:.c=.o)
LIBRARY=libutf8.a

all: $(SOURCES) $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS) 
	$(RANLIB) $@
	cp $@ ../../../lib/
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o *.a
