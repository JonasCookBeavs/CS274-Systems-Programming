printtest: main.o printcounter.o
	g++ -Wall -Wextra -std=c++20 -o $@ $^

main.o: main.cpp printcounter.h
	g++ -Wall -Wextra -std=c++20 -c -o $@ $<

printcounter.o: printcounter.cpp printcounter.h
	g++ -Wall -Wextra -std=c++20 -c -o $@ $<