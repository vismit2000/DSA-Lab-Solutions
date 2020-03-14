#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName){

	// printf("hi\n");
	FILE* fptr = fopen(fileName,"r");
	int count = 0,sz=0,i=0;
	char temp[11];
	int* marks;
	while(!feof(fptr)){

		if(!(count)){
			fscanf(fptr,"%d",&sz);
			printf("%d\n",sz);
			marks = (int *)malloc(sizeof(int)*sz);
			size = sz;
			count++;
		}

		fscanf(fptr,"%s %d",temp,&marks[i++]);
	}

	return marks;
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey){
	int arr[1000] = {0};
	int k=0;
	int* keyArr = (int *)malloc(sizeof(int)*lsSize);

	for(int i=0;i<lsSize; i++){

		if(!arr[Ls[i]]){
			arr[Ls[i]] = 1;
			// keyArr[k++] = Ls[i];
		}

	}

	int keyS=0;
	for(int i=0;i<1000; i++){

		if(arr[i]){
			keyArr[k++] = i;
			arr[i] = 0;
		}

	}
keyS = k;

	KeyStruct ks = (KeyStruct)malloc(sizeof(struct keyStruct));
	ks->Keys = keyArr;
	ks->keysSize = keyS;

	return ks;
}

void part2Loc(int* Ls, int lo, int hi, int piv){

	int j = -1,temp,i,pivotCount=0,endptr =size-1;

	for(i=lo; i<=hi; i++){
		if(Ls[i] < piv){
			j++;
			printf("a will swap %d at %d with %d at %d\n",Ls[j],j,Ls[i],i);
			temp = Ls[j];
			Ls[j] = Ls[i];
			Ls[i] = temp;
		}
		if(Ls[i] == piv && i<=endptr){
			printf("b will swap %d at %d with %d at %d\n",Ls[endptr],endptr,Ls[i],i);
			pivotCount++;
			temp = Ls[endptr];
			Ls[endptr--] = Ls[i];
			Ls[i] = temp;
		}
	}
	for(int i=0; i<pivotCount; i++){
		temp = Ls[hi-i];
		j++;
		Ls[hi-i] = Ls[j];
		Ls[j] = temp;
	}

}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey){

	KeyStruct ks = extractKeys(Ls,size,loKey,hiKey);

	printf("hi %d\n",ks->keysSize);
	for(int i=0; i<ks->keysSize; i++){
		// printf("Key no %d: is %d\n",i,ks->Keys[i]);
		printf("pivot is %d\n",ks->Keys[i]);
		part2Loc(Ls,0,size-1,ks->Keys[i]);
		printArray(Ls,size);
	}

}