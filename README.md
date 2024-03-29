# 2412-Assignement-3
Assignment 3 for Lakehead Data Structures Class
##Assignment 3 Information from Professor

Assignment 3 Heapsort

2412FB-Data Structures 
Department of Computer Science
Fall 2023

Write a C code to implement the heapsort, as explained in our lectures.  


1)	Implement the heapsort algorithm using the declarations below: (70 points)
a.	Your implementation must be consistent with the below declarations. (Minor or major error otherwise!)
b.	Your implementations must be consistent with the pseudocode introduced in the corresponding lectures (see lecture slides). 
struct Heap{
    unsigned long *arr;
    unsigned int heaspsize, length;
};

void MAX_HEAPIFY(struct Heap *h, unsigned int i);
void BUILD_MAX_HEAP(struct Heap *h);
void heap_sort(struct Heap *h);
void insertion_sort(unsigned long *arr, unsigned int length);
void merge_sort(unsigned long *a, unsigned int left, unsigned int right);

2)	Evaluate the Heapsort Algorithm (30 points)
a.	Use arrays of a large size, where array_size ranges from 27 … 222
i.	Create a heap named 'h' and two arrays named 'f' and 'g'. Please use these exact names.
ii.	Start indexing at 1. Leave out the first array index (it will remain unused).
iii.	Fill all three arrays with random numbers as demonstrated below.
    int tmp;
    for(unsigned int i=1; i < array_size; i++){ 
//deliberately leaving out the first array element
        tmp = rand()%INT16_MAX;
        f[i] = (unsigned long) tmp; 
        g[i] = (unsigned long) tmp;
        h->arr[i] = (unsigned long) tmp;
    }   

iv.	Ensure that all three arrays are equal (i.e., same size and content).
b.	Measure the time it takes to perform the following sorting operations:
i.	Sort the elements of 'h' using the heap_sort() algorithm.
ii.	Sort the elements of 'g' using the insertion_sort() algorithm.
iii.	Sort the elements of 'f' using the merge_sort() algorithm.
iv.	Use the methods provided by <time.h> (i.e., clock(), difftime(), and the constant CLOCKS_PER_SEC) to measure the time, as demonstrated in previous labs and lectures when discussing merge_sort.
v.	Write the necessary C code to store the results in a comma-separated file, following the instructions from the lab on November 3, 2023.

c.	Use Excel to generate a scatter plot, where each algorithm's measured running time 't' (in milliseconds) is plotted against log2(array_size).
