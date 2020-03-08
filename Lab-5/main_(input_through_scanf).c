#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>

//size stores the current size of array, count stores the number of elements inserted
int count, size;

typedef struct Record Record;

struct Record
{
    char cardNo[20];
    char bankCode[20];
    char expiryDate[20];
    char fName[20];
    char lName[20];    
};

void insertInOrder(Record *arr, int n)
{
    Record last = arr[n-1];
    int j = n-2;
    
    while(j >= 0 && (strlen(last.cardNo) < strlen(arr[j].cardNo)))
    {
        arr[j+1] = arr[j];
        j--;
    }
    while(j >= 0 && (strlen(last.cardNo) == strlen(arr[j].cardNo)) && (strcmp(last.cardNo, arr[j].cardNo) < 0))
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

void insertionSort(Record *arr, int n)
{
    if(n <= 1)
        return;
    insertionSort(arr, n-1);
    insertInOrder(arr, n);
}

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    FILE *fout = fopen("output.txt", "w");
    
    if(fp == NULL)
        {
            printf("Error opening file\n");
            exit(1);
        }
    
    Record *arr = (Record *)malloc(4*sizeof(Record));
    size = 4;
    count = 0;
    
    int n = atoi(argv[1]);
    int i = 0;
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    while(fscanf(fp, "\"%[^,],%[^,],%[^,],%[^,],%[^\"]\"\n", (arr[i].cardNo), (arr[i].bankCode), (arr[i].expiryDate), (arr[i].fName), (arr[i].lName)) != EOF)
    {
        count++;
        if(count == size)
        {
            arr = (Record *)realloc(arr, 2*size*sizeof(Record));
            size *= 2;
        }
        
        i++;
    }
    
    gettimeofday(&end, NULL);

    long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    
    fprintf(fout, "Time elpased in reading from file is %ld seconds and %ld micros\n", seconds, micros);
    
    for(int i = 0; i < n; i++)
    {
        printf("%20s %10s %10s %10s %10s\n", (arr[i].cardNo), (arr[i].bankCode), (arr[i].expiryDate), (arr[i].fName), (arr[i].lName));
    }
    
    printf("\nSorted order according to card number : \n\n");
    
    gettimeofday(&start, NULL);
    
    insertionSort(arr, n);
    
    for(int i = 0; i < n; i++)
    {
        printf("%20s %10s %10s %10s %10s\n", (arr[i].cardNo), (arr[i].bankCode), (arr[i].expiryDate), (arr[i].fName), (arr[i].lName));
    }
    
    gettimeofday(&end, NULL);

    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    
    fprintf(fout, "\nTime elpased in insertion sort is %ld seconds and %ld micros\n", seconds, micros);
    
    fclose(fp);
    fclose(fout);
    return 0;
} 