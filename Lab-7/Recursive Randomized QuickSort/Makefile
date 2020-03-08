all: target
target: main.o quick.o 
	gcc -o exe main.o quick.o 
	./exe 10000
	rm -rf *o exe
	
main.o: main.c
	gcc -c main.c
quick.o: quick.c
	gcc -c quick.c