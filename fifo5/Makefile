CXX=mipsel-linux-g++
OBJS=client
CFLAGS=-Wall -g

all:client 

#client:client.cpp Util.cpp
client:client_test_dead.cpp Util.cpp
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
