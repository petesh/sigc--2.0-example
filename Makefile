CXXFLAGS += $(shell pkg-config --cflags sigc++-2.0)
LDLIBS += $(shell pkg-config --libs sigc++-2.0)

all: example1 example2 example3

clean:
	rm -f example[123] *.o
