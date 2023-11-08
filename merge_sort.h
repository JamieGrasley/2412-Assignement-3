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

    if (left<right){
            unsigned int mid=((left+right)/2);
            merge_sort(a,left,mid);
            merge_sort(a,mid+1,right);
    }
    //Merge
    merge(a,left,mid,right);

}

void merge(unsigned long *a, unsigned int left, unsigned int mid, unsigned int right);

void merge(unsigned long *a, unsigned int left, unsigned int mid, unsigned int right){
    unsigned long n1, n2, leftArr[n1], rightArr[n2];

    for(unsigned long i=1;i<n1;i++){
        leftArr[i]=a[left+i-1];
    }
    for(unsigned long x=1; x<n2;x++){
        rightArr[x]=a[mid+x];
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
        l++
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


}
