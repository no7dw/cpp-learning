CXX=gcc
OBJS=server client
CFLAGS=-Wall -g

all:server client

server:server.c
	$(CXX) $(CFLAGS) $^ -o $@

client:client.c
	$(CXX) $(CFLAGS) $^ -o $@

.PHONY:clean dist distclean
clean:
	rm -rf $(OBJS) server_fifo client*fifo
dist:
	tar zcvf fifo.tar.gz* && echo"OK"
distclean:
	rm -rf $(OBJS)fifo.tar.gz myfifo
