SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGETS = $(SOURCES:.cpp=)

unit-test:	all
		./test_unit

all: $(OBJECTS)
	for targ in $(TARGETS); do \
		g++ -g $$targ.o ../lib/libSpacePath.a -o $$targ; \
	done

test:	all
	./test_unit

%.o: %.cpp
	g++ -g -c -I../include -I/usr/include/eigen3 -Wall $< -o $@

clean:
	rm -f *.o
	for targ in $(TARGETS); do \
		rm -f $$targ; \
	done

