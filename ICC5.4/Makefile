main: main.o llist.o
	gcc -Wall -Wextra -o $@ $^

main.o: main.c llist.h
	gcc -Wall -Wextra -c -o $@ $<

llist.o: llist.c llist.h
	gcc -Wall -Wextra -c -o $@ $<