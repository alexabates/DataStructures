CXX = g++
CXXFLAGS = -Wall -g -std=c++11

fileSystem: FileSystemTester.o FileSystem.o
	$(CXX) $(CXXFLAGS) -o fileSystem FileSystemTester.o FileSystem.o

FileSystemTester.o: FileSystemTester.cpp FileSystem.hpp
	$(CXX) $(CXXFLAGS) -c FileSystemTester.cpp

FileSystem.o: FileSystem.cpp FileSystem.hpp
	$(CXX) $(CXXFLAGS) -c FileSystem.cpp

clean:
	rm -f fileSystem FileSystemTester.o FileSystem.o