all: compRecMS compIterMS runRecMS runIterMS

compRecMS: main.o merge.o recMergeSort.o
	gcc -o exe main.o merge.o recMergeSort.o
		
compIterMS: main.o merge.o iterMergeSort.o
	gcc -o exe1 main.o merge.o iterMergeSort.o
		
runRecMS: 
	./exe 1024.txt
	rm -rf *o exe

runIterMS: 
	./exe1 1024.txt
	rm -rf *o exe1

main.o: main.c
	gcc -c main.c
	
merge.o: merge.c
	gcc -c merge.c

recMergeSort.o: recMergeSort.c
	gcc -c recMergeSort.c
	
iterMergeSort.o: iterMergeSort.c
	gcc -c iterMergeSort.c