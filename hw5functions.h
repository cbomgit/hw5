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

void insertion_sort(int [], int);

void heap_sort(int [], int, int);
void build_heap(int [], int);
void heapify(int [], int, int);
int  left_child(int);
int  right_child(int);
int  parent(int);

void quick_sort(int [], int,int);
int  partition(int [], int, int);

void merge_sort(int [], int, int);
void merge(int [], int, int, int);

//outputs a menu for the user to choose options from
void show_menu();

//fills an array with random values
void randomize_array(int [], int);

//expects two arrays of   4 with the running times of the various sorts on 
//the random and pre-sorted arrays.
void output_table(long double [], 
                  long double []);
void copy_array(int [], int [], int);

void print_array(int [], int);


#endif	/* HW5FUNCTIONS_H */

