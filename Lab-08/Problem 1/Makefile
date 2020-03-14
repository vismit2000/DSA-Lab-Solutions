exe: main.o List.o
	gcc -o exe main.o List.o
	./exe
	rm -rf *o exe
	
main.o: main.c
	gcc -c main.c
List.o: List.c
	gcc -c List.c