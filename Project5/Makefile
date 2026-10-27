TARGETS= rpncalc

.PHONY:	all clean

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

rpncalc: rpncalc.o stack.o
	gcc -o $@ $^

rpncalc.o: rpncalc.c stack.h
	gcc -Wall -Wextra -c -o $@ $<

stack.o: stack.c stack.h
	gcc -Wall -Wextra -c -o $@ $<