main: main.o boxer.o mather.o
	gcc -o $@ $^

main.o: main.c boxer.h mather.h
	gcc -Wall -Wextra -c -o $@ $<

boxer.o: boxer.c boxer.h
	gcc -Wall -Wextra -c -o $@ $<

mather.o: mather.c mather.h
	gcc -Wall -Wextra -c -o $@ $<