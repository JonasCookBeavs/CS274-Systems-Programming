TARGETS= main

.PHONY:	all clean

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

ssdb: ssdb.c
	gcc -Wall -Wextra -o $@ $<