CXX=g++
#MCXX=mipsel-linux-g++
OBJS=server client
CFLAGS=-Wall -g

all:server client clientLS

server:server.cpp Util.cpp
	$(CXX) $(CFLAGS) $^ -o $@

client:client.cpp
	$(CXX) $(CFLAGS) $^ -o $@

clientLS:clientLS.cpp
	$(CXX) $(CFLAGS) $^ -o $@

.PHONY:clean dist distclean
clean:
	rm -rf $(OBJS) /tmp/server_fifo /tmp/client*fifo
cleanF:
	rm -rf  /tmp/server_fifo /tmp/client*fifo
dist:
	tar zcvf fifo.tar.gz* && echo"OK"
distclean:
	rm -rf $(OBJS)fifo.tar.gz myfifo
