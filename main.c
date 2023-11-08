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
#include "time.h"
#include "math.h"
#include "heap.h"
#include "arrays.h"
#define MAXHEAP 20;


int main(int argc, const char * argv[]) {
    // insert code here...
    struct Heap *h;
    unsigned int *g, *f;
    int n = MAXHEAP + 1;

    g = NULL; f = NULL; 
    h = (struct Heap *) malloc(sizeof(struct Heap));
    
    f = (unsigned int*) malloc(  n  * sizeof(unsigned int));
    g = (unsigned int*) malloc(  n  * sizeof(unsigned int));
    
    if( !f || !g || !h)
        exit(EXIT_FAILURE);
    h->length = MAXHEAP; // we will not use the first array element to avoid zero-based indexing and to use a 1-based indexing instead
    h->arr = (unsigned int*) malloc( n * sizeof(struct Heap));
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
    }   
    // start timer 
        HEAPSORT(h);
    // end time

    // start timer
        //INSERTIONSERT(g);
    // end timer

    // start timer
        //MERGESORT(f);
    // end timer

    // write into a CSV; check the Excel for the structure of the coloumns
    
    printf("\nArray[1 .. Heap.Length]: ");
    for(unsigned int i=1; i<=h->length; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
    

    if(h->arr) free(h->arr);
    if(h) free(h);
    return 0;
}
