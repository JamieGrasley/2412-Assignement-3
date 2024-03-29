/******************************\
|    COMP-2412 Assignment 3    |
| Jamie Grasley & Felix Ikokwu |
\******************************/

/*Compilation information:
//Per the instructor, he uses:\\
Apple LLVM-Clang version 14.0.3 (GNU 99)
MacOS 13.4.1
Targeting the x86_64 architecture
Using either XCode or Visual Studio Code Version 1.73.1

//For compiling we have used\\
Apple clang version 15.0.0 (clang-1500.0.40.1) (GNU 99)
MacOS 14.1
Targeting: arm64-apple-darwin23.1.0 (x86 should have no issues compiling the source code though)
Using VSCode 1.74.3
*/

//Final main function, please add to this and not skelemain (Internal comment artifact for my git repo please disregard)


//Pseudocode for main.c file provided by professor

/*Arrays are indexed at 1 instead of 0 per specifications.*/
/*Per specifications heap is set to h, arrays are f and g.*/

/*Per instructor MAXHEAP has been set to a reasonable value of 2^20. 2^22 is too large and the instructor 
stated that values in that range are ok.*/
 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXHEAP 1048576

struct Heap{
    unsigned long *arr;
    unsigned int heapsize, length;
};

void MAX_HEAPIFY(struct Heap *h, unsigned int i);
void BUILD_MAX_HEAP(struct Heap *h);
void heap_sort(struct Heap *h);
void insertion_sort(unsigned long *arr, unsigned int length);
void merge_sort(unsigned long *a, unsigned int left, unsigned int right);
void merge(unsigned long *a, unsigned int left, unsigned int mid, unsigned int right); //Added per pseudo-code




//array_size must be between 2^7 and 2^22

int main(int argc, const char * argv[]) {


    struct Heap *h;
    unsigned long *g, *f;
    
for (unsigned int array_size=128; array_size<=(MAXHEAP); array_size*=2){
    g = NULL; f = NULL; 

    int n=MAXHEAP+1;

    h = (struct Heap *) malloc(sizeof(struct Heap));
    f = (unsigned long*) malloc(n*sizeof(unsigned long));
    g = (unsigned long*) malloc(n*sizeof(unsigned long));
    
    if( !f || !g || !h)
        exit(EXIT_FAILURE);
    h->length = array_size; // we will not use the first array element to avoid zero-based indexing and to use a 1-based indexing instead
    
    h->arr = (long unsigned*) malloc( n * sizeof(struct Heap));
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
        printf("%lu ", h->arr[i]);  // for debugging purposes
    }   //Ensure that all three arrays are equal (i.e., same size and content).

    clock_t startHeap_t, endHeap_t, startInsert_t, endInsert_t, startMerge_t, endMerge_t;
    double diffHeap_t, diffInsert_t, diffMerge_t;


    startHeap_t=clock();
        heap_sort(h);
    endHeap_t=clock();

    startInsert_t=clock();
        insertion_sort(g,h->length);
    endInsert_t=clock();

    startMerge_t=clock();
        merge_sort(f, 1, h->length);
    endMerge_t=clock();

    diffHeap_t= (double)difftime(endHeap_t,startHeap_t)/(double)(CLOCKS_PER_SEC/1000);
    diffInsert_t= (double)difftime(endInsert_t,startInsert_t)/(double)(CLOCKS_PER_SEC/1000);
    diffMerge_t= (double)difftime(endMerge_t,startMerge_t)/(double)(CLOCKS_PER_SEC/1000);

    
    double logIS=(double)log2(array_size);

    // write into a CSV; check the Excel for the structure of the coloumns
    FILE *fpt;
    fpt=fopen("Output.csv", "a+");
if(array_size==128){
    printf("\n%u, %4.3e, %4.3e, %4.3e\n", array_size, diffInsert_t, diffMerge_t, diffHeap_t);
    fprintf(fpt,"inputSize, log2(inputSize), runntime (Insertionsort), runntime (MergeSort), runntime (Heapsort)\n");
    fprintf(fpt,"%u, %4.3e, %4.3e, %4.3e, %4.3e\n", array_size, logIS, diffInsert_t, diffMerge_t, diffHeap_t);    
    }
    else{
    printf("\n%u, %4.3e, %4.3e, %4.3e\n", array_size, diffInsert_t, diffMerge_t, diffHeap_t);
    fprintf(fpt,"%u, %4.3e, %4.3e, %4.3e, %4.3e\n", array_size, logIS, diffInsert_t, diffMerge_t, diffHeap_t);

    }
    fclose(fpt);
    

    printf("\nArray[1 .. Heap.Length]: ");
    for(unsigned int i=1; i<=h->length; i++)
        printf("%lu ", h->arr[i]);
    printf("\n");
    

    if(h->arr) free(h->arr);
    if(h) free(h);

    if(g) free(g);

    if(f) free(f);

    }
    return 0;
}

void BUILD_MAX_HEAP(struct Heap *h){

   h->heapsize=h->length;
   for(unsigned int i=h->length/2; i>=1;i--){
    MAX_HEAPIFY(h,i);
   }
}

void insertion_sort(unsigned long *arr, unsigned int length){
    unsigned int temp;
    int check;

    for (unsigned int x=1; x<length; x++){
            temp=arr[x];
            check=x-1;
            while (check>0 && arr[check]>temp){
                arr[check+1]=arr[check];
                check=check-1;
                arr[check+1]=temp;
            }
    }
}

void heap_sort(struct Heap *h){
    BUILD_MAX_HEAP(h);
    for(unsigned int i=h->length;i>=1;i--){
        unsigned int temp;
        temp=h->arr[i];
        h->arr[i]=h->arr[1];
        h->arr[1]=temp;
        h->heapsize=h->heapsize-1;
        MAX_HEAPIFY(h,i);
    }

    

}

void MAX_HEAPIFY(struct Heap *h, unsigned int i){
    unsigned int left, right, largest;

    largest=i;
    left=2*i;
    right=2*i+1;

    if (left <= h->heapsize && h->arr[left] > h->arr[largest]) {
    largest = left-1;

    }

    else{
        largest=i;
    }

    if (right <= h->heapsize && h->arr[right] > h->arr[largest]) {
    largest = right-1;

    }

    if(largest!=i){
        unsigned int temp;
        temp=h->arr[i];
        h->arr[i]=h->arr[largest];
        h->arr[largest]=temp;
        MAX_HEAPIFY(h,largest);
    }
}

void merge_sort(unsigned long *a, unsigned int left, unsigned int right){
    unsigned int mid;
    if (left<right){
            mid=((left+right)/2);
            merge_sort(a,left,mid);
            merge_sort(a,mid+1,right);
            merge(a,left,mid,right);
    }

}

void merge(unsigned long *a, unsigned int left, unsigned int mid, unsigned int right){
    unsigned long n1, n2;
    n1=mid-left+1;
    n2=right-mid;

    unsigned long *leftArr = malloc(n1 * sizeof(unsigned long));
    unsigned long *rightArr = malloc(n2 * sizeof(unsigned long));

    if( !leftArr || !rightArr)
        exit(EXIT_FAILURE);

   

    for(unsigned long i=1;i<n1;i++){
        leftArr[i]=a[left+i];
    }
    for(unsigned long x=1; x<n2;x++){
        rightArr[x]=a[mid+x+1];
    }
    unsigned long y=0,z=0;
    unsigned long l=left;

    while(y<n1&&z<n2){
        if(leftArr[y]<=rightArr[z]){
            a[l]=leftArr[y];
            y++;
        }
        else{
            a[l]=rightArr[z];
            z++;
        }
        l++;
    }
    while(y<n1){
        a[l]=leftArr[y];
        y++;
        l++;
    }
    while(z<n2){
        a[l]=rightArr[z];
        z++;
        l++;
    }
free(leftArr);
free(rightArr);


}