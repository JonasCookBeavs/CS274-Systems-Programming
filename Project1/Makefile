.PHONY: all clean

SRCS=$(wildcard *.c)
TARGETS=$(subst .c,,$(SRCS))

all: $(TARGETS)

%: %.c
	gcc -Wall -Wextra -o $@ $<

clean:
	rm -rf $(TARGETS)
