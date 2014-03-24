CXX=g++
OBJS=fifo_write fifo_read
CFLAGS=-Wall -g

all:fifo_write fifo_read

fifo_write:fifo_write.cpp
	$(CXX) $(CFLAGS) $^ -o $@

fifo_read:fifo_read.cpp
	$(CXX) $(CFLAGS) $^ -o $@

.PHONY:clean dist distclean
clean:
	rm -rf $(OBJS) myfifo
dist:
	tar zcvf fifo.tar.gz* && echo"OK"
distclean:
	rm -rf $(OBJS)fifo.tar.gz myfifo
