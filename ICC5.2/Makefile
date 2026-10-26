main: main.c boxer.o mather.o
	gcc -o $@ $^

boxer.o: boxer.c boxer.h
	gcc -Wall -Wextra -c -o $@ $<

mather.o: mather.c mather.h
	gcc -Wall -Wextra -c -o $@ $<