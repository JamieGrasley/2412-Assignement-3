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

//q=mid
//p=left
//r=right
void merge_sort(unsigned long *a, unsigned int left, unsigned int right){
    unsigned long n1, n2, leftArr[n1], rightArr[n2];

    if (left<right){
            unsigned long mid=((left+right)/2);
            merge_sort(a,left,mid);
            merge_sort(a,mid+1,right);
    }
}
