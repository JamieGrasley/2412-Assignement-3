/******************************\
|    COMP-2412 Assignment 3    |
| Jamie Grasley & Felix Ikokwu |
\******************************/

//Heap definition for reference
//Remember heapsize is elements stored in arr, 
//Length is how many elements can be in arr.

struct Heap{
    unsigned long *arr;
    unsigned int heaspsize, length;
};
//struct Heap definition must be
//Removed when reintegrated into main, here for admin only
void heap_sort(struct Heap *h){
    unsigned int length= h->heaspsize;

    for(unsigned int i=length;i>0;i--){
        MAX_HEAPIFY(h,i);
    }
    for(unsigned int i=length-1;i>1;i--){
        unsigned int temp;
        temp=h->arr[i];
        h->arr[i]=h->arr[1];
        h->arr[1]=temp;
        MAX_HEAPIFY(h,i);
    }

    

}