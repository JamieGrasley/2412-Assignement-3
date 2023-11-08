# 2412-Assignement-3
Assignment 3 for Lakehead Data Structures Class
##Assignment 3 Information from Professor

Assignment 3 Heapsort

2412FB-Data Structures 
Department of Computer Science
Fall 2023
1.	This assignment shall be completed in groups of two. 
o	Please don’t email us regarding team building.
2.	You must submit your solution through D2L
o	Don’t email me or the TA your submission, please. I am receiving a high number of emails. Your email may not be processed before the deadline. 
o	You can upload/submit several times. D2L is configured to keep the last submission with all previous submissions overwritten. 
o	Please refrain from uploading zipped files. 
o	Do not upload executables.
o	Your submission should consist of three files: 
	a  pdf file containing your report (same as for your first assignment; see next page for explanations), and 
	a CSV file containing your results as explained in the lab on Friday, November 3, 2023
	a file named main.c.txt containing your code. 
	Don’t submit a separate header file. Have all declarations and definitions in main.c.txt. 
3.	The evaluation policy is similar to the previous assignments
o	We will only evaluate a submission if we can successfully compile and run the submitted C-file. Otherwise, you won't receive any marks for this assignment. (We will fix the extension of main.c.txt to main.c manually. So, don’t worry about that part.)
o	Minor Errors: 5% will be deducted for each error. If the same minor error type (e.g. accessing null pointers) is encountered more than once, 5% will be deducted for each encounter. Examples of minor errors are:
	If your implementation fails to check all actual parameters for correctness (minimum value – maximum value) at the beginning of a function.
	If your implementation lacks proper error checking, e.g., for illegal pointer operations such as attempts to dereference a null pointer. The validity of variables in general and pointer variables in particular must be checked before you use them the first time. Further, when the value of a (pointer) variable could have possibly changed at a later position, e.g. because you made a call to a function that possibly manipulated that (pointer or global) variable, you must check again the validity of that variable before accessing it. 
Especially, the result of malloc() / realloc() must be checked before referencing the returned pointer.
	If your implementation fails to free dynamically allocated memory.
	If your implementation fails to check a pointer for validity before freeing it. This must happen just before the call to free().
o	Major Errors: Here is the revised text: If your code fails to correctly sort the input array or to implement the heapsort algorithm as demonstrated in the pseudo-codes provided in the corresponding lecture slides, points will be deducted (15% for each such error).
o	If your code crashes, you will lose 30%.
4.	Should you require further clarification regarding the assignment, please ask questions during lab hours, or feel free to contact me via Zoom during my office hours. 
o	You can find my office hours in the syllabus.
o	Technical questions asked via email cannot be answered. 
5.	The extended deadline is November 21, 2023, at 5:00 PM (Toronto time). 
o	The submission site will close after the deadline.
o	The deadline can’t be extended. 
o	Please see the syllabus regarding the penalty for late submissions. Please check the course page for the most updated version of the syllabus.



 
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
