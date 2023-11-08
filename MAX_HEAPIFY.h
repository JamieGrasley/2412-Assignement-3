/******************************\
|    COMP-2412 Assignment 3    |
| Jamie Grasley & Felix Ikokwu |
\******************************/
struct Heap{
    unsigned long *arr;
    unsigned int heaspsize, length;
};//This struct definition will need to be removed once everything is reintegrated into main. It is simply here for admin purposes
void MAX_HEAPIFY(struct Heap *h, unsigned int i){
    unsigned int left, right, largest;

    //Note function definitions LEFT and RIGHT need to be replaced
    left=LEFT(i);
    right=RIGHT(i);

    if(left<=h->heaspsize && h->arr[left]>h->arr[i]){
        largest = left;
    }
    else{
        largest=i;
    }

    if (right<=h->heaspsize && h->arr[right]>h->arr[largest]){
        largest=right;
    }
    if(largest!=i){
        unsigned int temp;
        temp=h->arr[i];
        h->arr[i]=h->arr[largest];
        h->arr[largest]=temp;
        MAX_HEAPIFY(h->largest);
        //exchange arr[i] with arr[largest]
    }
}
