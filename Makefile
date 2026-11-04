CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: program

program: main.o
	$(CXX) $(CXXFLAGS) main.o -o program

main.o: main.cpp singlelist.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o program
