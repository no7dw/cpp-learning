PROGS: m n serv
all: ${PROGS}
n: n.o
	$(CXX) $(CFLAGS) -o $@ n.o
m: m.o
	$(CXX) $(CFLAGS) -o $@ m.o
serv: serv_spark.o
	$(CXX) $(CFLAGS) -o $@ serv_spark.o

