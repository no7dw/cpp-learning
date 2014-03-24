#CXX=mipsel-linux-g++
CXX=arm-linux-androideabi-g++

STANDALONE_PATH=/home/dengwei/standalone-toolchain
LDFLAGS= -static
LIBS+= -L /home/dengwei/standalone-toolchain/arm-linux-androideabi/lib/libsupc++.a

INCLUDES+= -I $(STANDALONE_PATH)/arm-linux-androideabi/include/c++/4.6/
INCLUDES+= -I $(STANDALONE_PATH)/arm-linux-androideabi/include/c++/4.6/arm-linux-androideabi
INCLUDES+= -I $(STANDALONE_PATH)/sysroot/usr/include/

OBJS=client_test
CFLAGS=-Wall -g

all:client_test 

#client:client.cpp Util.cpp
client_test_dead:client_test_dead.cpp Util.cpp
	$(CXX)$(LDFLAGS) $(CFLAGS) $(INCLUDES) $(LIBS) $^ -o $@ 



.PHONY:clean dist distclean
clean:
	rm -rf $(OBJS) /tmp/server_fifo /tmp/client*fifo
cleanF:
	rm -rf  /tmp/server_fifo /tmp/client*fifo
dist:
	tar zcvf fifo.tar.gz* && echo"OK"
distclean:
	rm -rf $(OBJS)fifo.tar.gz myfifo
