/******************************\
|    COMP-2412 Assignment 3    |
| Jamie Grasley & Felix Ikokwu |
\******************************/

//Pseudocode for main.c file provided by professor

/*It is using 1-based indexing, leaves the first element of the array unused (for simplicity of learning)
Implement heapsort
Use safe pointers*/
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAXHEAP 20;

struct Heap{
    unsigned long *arr;
    unsigned int heaspsize, length;
};

void MAX_HEAPIFY(struct Heap *h, unsigned int i);
void BUILD_MAX_HEAP(struct Heap *h);
void heap_sort(struct Heap *h);
void insertion_sort(unsigned long *arr, unsigned int length);
void merge_sort(unsigned long *a, unsigned int left, unsigned int right);
void merge(unsigned long *a, unsigned int left, unsigned int mid, unsigned int right);//Added based on pseudo-code.



//array_size must be between 2^7 and 2^22

int main(int argc, const char * argv[]) {

    time_t insertRuntime_t=time(NULL);

    struct Heap *h;
    unsigned long *g, *f;
    int n = MAXHEAP + 1;
for (unsigned int array_size=128; array_size<4194304; array_size*2){
    g = NULL; f = NULL; 

    h = (struct Heap *) malloc(sizeof(struct Heap));
    f = (unsigned long*) malloc(  n  * sizeof(unsigned long));
    g = (unsigned long*) malloc(  n  * sizeof(unsigned long));
    
    if( !f || !g || !h)
        exit(EXIT_FAILURE);
    h->length = MAXHEAP; // we will not use the first array element to avoid zero-based indexing and to use a 1-based indexing instead
    
    h->arr = (long unsigned int*) malloc( n * sizeof(struct Heap));
    if(!h->arr)
        exit(EXIT_FAILURE);

    srand((unsigned int) time(0));
    
    printf("\n\nArray[1 .. Heap.Length]: ");
    int tmp;
    for(unsigned int i=1; i <= h->length; i++){
        tmp = rand()%101;
        f[i] = tmp; 
        g[i] = tmp;
        h->arr[i] = tmp;
        printf("%d ", h->arr[i]);  // for debugging purposes
    }   //Ensure that all three arrays are equal (i.e., same size and content).

    time_t startHeap_t, endHeap_t, startInsert_t, endInsert_t, startMerge_t, endMerge_t;
    double diffHeap_t, diffInsert_t, diffMerge_t;


    time(&startHeap_t);
        heap_sort(h);
    time(&endHeap_t);

    time(&startInsert_t);
        insertion_sort(g,h->length);
    time(&endInsert_t);

    time(&startMerge_t);
        merge_sort(f);
    time(&endMerge_t);

    diffHeap_t=difftime(endHeap_t,startHeap_t);
    diffInsert_t=difftime(endInsert_t,startInsert_t);    
    diffMerge_t=difftime(endMerge_t,startMerge_t);

    // write into a CSV; check the Excel for the structure of the coloumns
if(array_size==128){
    FILE *fpt;
    fpt=fopen("Output.csv", "w+");
    fprintf(fpt,"inputSize, f(inputSizei)=f(inputSizei-1)*4, runntime (Insertionsort), runntime (MergeSort), runntime (Heapsort)\n");
    fprintf(fpt,"%u, %f, %f, %f, %f\n", array_size, diffInsert_t, diffInsert_t, diffMerge_t, diffHeap_t);
    fclose (fpt);
    }
else{
    insertRuntime_t=insertRuntime_t*4;
    FILE *fpt;
    fpt=fopen("Output.csv", "w+");
    fprintf(fpt,"inputSize, f(inputSizei)=f(inputSizei-1)*4, runntime (Insertionsort), runntime (MergeSort), runntime (Heapsort)\n");
    fprintf(fpt,"%u, %f, %f, %f, %f\n", array_size, insertRuntime_t, diffInsert_t, diffMerge_t, diffHeap_t);
    fclose (fpt);
}

    insertRuntime_t= diffInsert_t;

    printf("\nArray[1 .. Heap.Length]: ");
    for(unsigned int i=1; i<=h->length; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
    

    if(h->arr) free(h->arr);
    if(h) free(h);

    if(g) free(g);

    if(f) free(f);
}
    return 0;
}
