CXX = g++
CXXFLAGS = -Wall -g -std=c++11

calculator: tester.o linked_calc.o
	$(CXX) $(CXXFLAGS) -o calculator tester.o linked_calc.o

tester.o: tester.cpp linked_calc.hpp
	$(CXX) $(CXXFLAGS) -c tester.cpp

linked_calc.o: linked_calc.cpp linked_calc.hpp
	$(CXX) $(CXXFLAGS) -c linked_calc.cpp

clean:
	rm -f calculator tester.o linked_calc.o

