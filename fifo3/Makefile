CXX=g++
MCXX=mipsel-linux-g++
OBJS=client
CFLAGS=-Wall -g

all:client

client:client.cpp callClient.cpp
	$(CXX) $(CFLAGS) $^ -o $@
M:clientM

clientM:client.cpp callClient.cpp
	$(MCXX) $(CFLAGS) $^ -o $@
	cp $@ /mnt/DVD3/

.PHONY:clean dist distclean
clean:
	rm -rf $(OBJS) /tmp/server_fifo /tmp/client*fifo
cleanF:
	rm -rf  /tmp/server_fifo /tmp/client*fifo
dist:
	tar zcvf fifo.tar.gz* && echo"OK"
distclean:
	rm -rf $(OBJS)fifo.tar.gz myfifo
