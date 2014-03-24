OBJS = Hire Main.o Father.o Son.o
CXX = g++
Hire : $(OBJS) 
	$(CXX) $^ -o $@
#Father.o : Father.cpp 
#	$(CXX) -c $< -o $@
#Son.o : Son.cpp 
#	$(CXX) -c $< -o $@
#Main.o : Main.cpp 	
#	$(CXX) -c $< -o $@
clean:
	$(RM) *.o Hire

