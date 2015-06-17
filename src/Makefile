SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(OBJECTS)
	ar rvs ../lib/libSpacePath.a $(OBJECTS)

%.o: %.cpp
	g++ -g -c -I../include -I/usr/include/eigen3 -Wall $< -o $@

clean:
	rm -f *.o
