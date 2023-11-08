/******************************\
|    COMP-2412 Assignment 3    |
| Jamie Grasley & Felix Ikokwu |
\******************************/
struct Heap{
    unsigned long *arr;
    unsigned int heaspsize, length;
};
//struct Heap definition must be
//Removed when reintegrated into main, here for admin only


void BUILD_MAX_HEAP(struct Heap *h){

   h->heaspsize=h->length;
   for(unsigned int i=h->length/2; i>=1;i--){
    MAX_HEAPIFY(h,i);
   }
}
