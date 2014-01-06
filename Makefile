CXXFLAGS += $(shell pkg-config --cflags --libs sigc++-2.0)

all: example1 example2

example1: example1.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

example2: example2.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f example[12] *.o
