/* 
 * File:   hw5functions.h
 * Author: christian
 *
 * Created on October 28, 2014, 1:14 PM
 */

#ifndef HW5FUNCTIONS_H
#define	HW5FUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

/*runs insertion sort on an array
 *Parameters:
 *int [] array: array to sort
 * int length  : length of array
 */
void insertion_sort(int [], int);


/*runs a heap sort on an array
 *Parameters:
 *int [] array: array to sort
 *int length  : length of array
 *int heap_size: size of the heap
*/
void heap_sort(int [], int, int);

/*Function to build a heap
 *Parameters:
 *int [] array: array to build heap from
 *int length: length of the array
 *int heapsize size of heap
*/
void build_heap(int [], int);

/* Function to ensure that the subtree rooted at 
 * i is a heap. 
 * Parameters: 
 * int [] array = array to heapify
 * int i, index of array to start from
 * int length = length of the array for bounds checking
 */
void heapify(int [], int, int);

//Returns the left child of an item in a heap
int  left_child(int);
//returns the right child of an item in  a heap
int  right_child(int);
//returns the parent index of an item in a heap
int  parent(int);

/* Function to run a quicksort on an array
 * Parameters:
 * int [] arr: array to sort
 * int start : starting index of array
 * int end   : last index of array
 */
void quick_sort(int [], int,int);

/* Partition function that does the work in quick_sort
 * Parameters:
 * int [] arr: array to partition
 * int start : starting index
 * int end   : ending index
 * Returns   : pivot index
 */
int  partition(int [], int, int);

/* Merge sort recursive function
 * Parameters:
 * int [] arr: array to sort
 * int start : starting index
 * int end   : ending index
 */
void merge_sort(int [], int, int);

/* Merge fucntion called by merge_sort
 * parameters: 
 * int [] arr: array to mere to
 * int start : starting index of left sub-array
 * int middle: starting index of right sub-array
 * int end   : ending index of right sub-array
 * Invariant : sub arrays must already be sorted.
 */
void merge(int [], int, int, int);

//outputs a menu for the user to choose options from
void show_menu();

//shows a greeting for the user
void greeting();

//fills an array with random values
void randomize_array(int [], int);

//expects two arrays of size 4 with the running times of the various sorts on 
//the random and pre-sorted arrays.
void output_table(double [],double []);
//copy one array to another temporary array
void copy_array(int [], int [], int);

//print an array to the screen
void print_array(int [], int);

//Function to run all of the sorts on both arrays
void run_all(int [], int [], int length);


//Function to run only three sorts
void run_all_except_insertion(int [], int [], int);

//Function to run all sorts on randomized input
void sort_input_is_random(int [], int);

//Function to run only 3 sorts on randomized input
void sort_input_is_random_not_insertion(int [], int);

//Function to run all sorts and show the arrays, unsorted and sorted
void sort_and_display(int [], int [], int);

#endif	/* HW5FUNCTIONS_H */

