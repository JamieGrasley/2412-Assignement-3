/******************************\
|    COMP-2412 Assignment 3    |
| Jamie Grasley & Felix Ikokwu |
\******************************/

void insertion_sort(unsigned long *arr, unsigned int length){
    unsigned int temp;
    int check;

    for (unsigned int x=1; x<length; x++){
            temp=arr[x];
            check=x-1;
            while (check>=0 && arr[check]>temp){
                arr[check+1]=arr[check];
                check=check-1;
                arr[check+1]=temp;
            }
    }
}
