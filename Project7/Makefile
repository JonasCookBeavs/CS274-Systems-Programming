.PHONY: all clean pristine

TARGET := main

all: $(TARGET)

main: runprog.o cpu.o
	g++ -Wall -Wextra -o $@ $^

runprog.o: runprog.cpp cpu.h
	g++ -Wall -Wextra -c -o $@ $<

cpu.o: cpu.cpp cpu.h stack.h
	g++ -Wall -Wextra -c -o $@ $<

clean:
	rm -f runprog.o cpu.o

pristine: clean
	rm -f $(TARGET)