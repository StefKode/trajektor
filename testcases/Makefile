SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGETS = $(SOURCES:.cpp=)

all: $(OBJECTS)
	for targ in $(TARGETS); do \
		g++ $$targ.o ../lib/libSpacePath.a -o $$targ; \
	done

%.o: %.cpp
	g++ -c -I../include -Wall $< -o $@

clean:
	rm -f *.o
	for targ in $(TARGETS); do \
		rm -f $$targ; \
	done

