TARGETS= main

.PHONY:	all clean

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

main: main.c
	gcc -Wall -Wextra -o $@ $<