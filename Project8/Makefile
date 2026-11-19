.PHONY: all clean pristine

TARGET := shapes

all: $(TARGET)

shapes: shapes.o
	g++ -Wall -Wextra -o $@ $^

shapes.o: shapes.cpp shape_class.h
	g++ -Wall -Wextra -c -o $@ $<

clean:
	rm -f runprog.o cpu.o

pristine: clean
	rm -f $(TARGET)