all: exe exe1 exe2

exe: main.o linkedList.o cycle.o
	gcc -o exe main.o linkedList.o cycle.o
	./exe

exe1: main.o linkedList.o cycle1.o
	gcc -o exe1 main.o linkedList.o cycle1.o
	./exe1

exe2: main.o linkedList.o cycle2.o
	gcc -o exe2 main.o linkedList.o cycle2.o
	./exe2
	rm -rf *o exe
	rm -rf *o exe1
	rm -rf *o exe2

main.o: main.c
	gcc -c main.c

linkedList.o: linkedList.c
	gcc -c linkedList.c

cycle.o: cycle.c
	gcc -c cycle.c

cycle1.o: cycle1.c
	gcc -c cycle1.c

cycle2.o: cycle2.c
	gcc -c cycle2.c