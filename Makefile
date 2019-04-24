all: supportTest.o arch.o
	c++ -std=c++11 -g supportTest.o arch.o -o supportTest
supportTest.o: supportTest.cpp arch.cpp arch.h
	c++ -std=c++11 -c -g supportTest.cpp
arch.o: arch.cpp arch.h
	c++ -std=c++11 -c -g arch.cpp
clean:
	rm *.o my_string
