CXXFLAGS += $(shell pkg-config --cflags --libs sigc++-2.0)

example1: detector.o example1.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f example1 *.o
