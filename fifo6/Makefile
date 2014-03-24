CXX=mipsel-linux-g++
OBJS=client_test
CFLAGS=-Wall -g

all:client_test 

#client:client.cpp Util.cpp
client_test_dead:client_test_dead.cpp Util.cpp
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
