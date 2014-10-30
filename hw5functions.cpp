/* 
 * File:   main.cpp
 * Author: christian
 *
 * Created on October 28, 2014, 1:02 PM
 */

#include"hw5functions.h"
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include<iomanip>

void insertion_sort(int arr[], int length)
{
    long double elapsed = 0;
    
    int i, j;
    
    for(j = 1; j < length; j++)
    {
        int key = arr[j];
        i = j - 1;
        for(; i >= 0 && arr[i] > key; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = key;       
    }
    
}


void heap_sort(int arr[], int length, int heap_size)
{
    int temp;
    build_heap(arr, length);
    
    for(int i = length - 1; i >= 0; i--)
    {
	temp = arr[0];
	arr[0] = arr[i];
	arr[i] = temp;
	heap_size--;
	heapify(arr, 0, heap_size);
	
    }
}

void build_heap(int arr[], int length)
{
    for(int i = length / 2; i >= 0; i--)
    {
	heapify(arr, i, length);
    }
}

void heapify(int arr[], int i, int heap_size)
{
    int left = left_child(i);
    int right = right_child(i);
    int largest = 0;
    int swap_var = 0;
    
    if(left < heap_size && arr[left] > arr[i])
    {
	largest = left;
    }
    else
    {
	largest = i;
    }
    if(right < heap_size && arr[right] > arr[largest])
    {
	largest = right;
    }
    if(largest != i)
    {
	swap_var = arr[i];
	arr[i] = arr[largest];
	arr[largest] = swap_var;
	heapify(arr, largest, heap_size);
    }
    
}

int left_child(int i)
{
    return i * 2;
}

int right_child(int i)
{
    return (i * 2) + 1;
}

int parent(int i)
{
    return i / 2;
}
void quick_sort(int arr[], int start, int end)
{
    if(start < end)
    {
	int pivot = partition(arr, start, end);
	quick_sort(arr,start, pivot - 1);
	quick_sort(arr, pivot + 1, end);
    }
    
}

int partition(int arr[], int start, int end)
{
    int temp = arr[end];
    int swap_var = 0;
    int i = start - 1;
    for(int j = start; j < end; j++)
    {
	if(arr[j] <= temp)
	{
	    i++;
	    swap_var = arr[i];
	    arr[i] = arr[j];
	    arr[j] = swap_var;
	}
    }
    swap_var = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = swap_var;
    return i + 1;
}


void merge_sort(int arr[], int start, int end)
{
    
    if(start < end)
    {
	
        int middle = (start + end) / 2;
        merge_sort(arr, start, middle);
        merge_sort(arr, middle + 1, end); 
        merge(arr, start, middle, end); 
    }
    
}

void merge(int arr[], int start, int middle, int end)
{
    //start and ending index of left sub array is start -> middle - 1
    //size is (middle - start)
    int left_size = middle - start + 1;
    //start and ending index of right sub array is middle -> end
    //size is end - middle + 1
    int right_size = end - middle;
    
    //declare the two sub arrays
    int left_arr[left_size];
    int right_arr[right_size];
    
    for(int i = 0; i < left_size; i++)
    {
	left_arr[i] = arr[start + i];
    }
    
    for(int i = 0; i < right_size; i++)
    {
	right_arr[i] = arr[middle + i + 1];
    }
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    for(k = start; i < left_size && j < right_size; k++)
    {
	if(left_arr[i] <= right_arr[j])
	{
	    arr[k] = left_arr[i++];
	}
	else 
	{
	    arr[k] = right_arr[j++];
	}
    }
    
    while(i < left_size)
    {
        arr[k++] = left_arr[i++];
    }
    
    while(j < right_size)
    {
        arr[k++] = right_arr[j++];
    }
}

void greeting()
{
   char enter;

   std::cout << "This program performs various sorts on random and sorted arrays "
             << "and displays their running times. Press enter to continue." << std::endl;
   enter = std::cin.get();
}



//outputs a menu for the user to choose options from
void show_menu()
{
   
    std::cout << "Sort random and sorted arrays and output their run times." 
              << std::endl;
    
    std::cout << "a. Sort random array and sorted array on all 4 "
              << "sorts." << std::endl;
    
    std::cout << "b. Sort random array and sorted array on 3 sorts "
              << "(quick, heap, and merge)." << std::endl;
    
    std::cout << "c. Sort random array only on all 4 sorts." << std::endl;
    
    std::cout << "d. Sort random array only on 3 sorts (quick, "
              << "heap, and merge)." << std::endl;
    
    std::cout << "e. Display the original array and the sorted "
              << "array on all 4 sorts." << std::endl;
    std::cout << "f. Exit" << std::endl;
    
}

//fills an array with random values
void randomize_array(int arr[], int length)
{
    srand(time(NULL));
    
    for(int i = 0; i < length; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
}

//expects two arrays of length 4 with the running times of the various sorts on 
//the random and pre-sorted arrays.
void output_table(double random_arr_times[], double sorted_arr_times[])
{
    int i = 0;
    std::cout << std::left << std::setw(16) << "Sort" << std::left 
              << std::setw(16) << "Random" << std::left << std::setw(16) 
              << "Sorted" << std::endl;
    
    std::cout << std::left << std::setw(16)<< "Quick " << random_arr_times[i] 
              << std::left << std::setw(16) << ""
              << std::left << std::setw(16)<< sorted_arr_times[i++] << std::endl;
    
    std::cout << std::left << std::setw(16)<< "Heap " << random_arr_times[i]
              << std::left << std::setw(16) << ""
              << std::left << std::setw(16)<< sorted_arr_times[i++] << std::endl;
        
    std::cout << std::left << std::setw(16)<< "Merge " << random_arr_times[i]
              << std::left << std::setw(16) << ""
              << std::left << std::setw(16)<< sorted_arr_times[i++] << std::endl;
    
    std::cout << std::left << std::setw(16)<< "Insertion " << random_arr_times[i]
              << std::left << std::setw(16) << ""
              << std::left << std::setw(16)<< sorted_arr_times[i++] << std::endl;
}


void copy_array(int src[], int dest[], int length)
{
    for(int i = 0; i < length; i++)
    {
        dest[i] = src[i];
    }
}

void print_array(int arr[], int length)
{
    const int max_per_row = 8;
    int row_count = 0;
    
    for(int i = 0; i < length; i++)
    {
        std::cout << std::setw(7) << arr[i] << " ";
        if(++row_count >= max_per_row)
        {
            std::cout << std::endl;
            row_count = 0;
        }
    }
    
    std::cout << std::endl;
}


void run_all(int sorted_arr[], int random_arr[], int length)
{
    //copy of the input arrays to keep them intact
    int random_arr_copy[length];
    int sorted_arr_copy[length];
    
    //double arrays with running times
    double sorted_times[4];
    double random_times[4];
    
    //clock_t struct returned by the clock function for start and end times
    clock_t start, end;
    int ndx = 0;
    
    copy_array(sorted_arr, random_arr_copy, length);    
    copy_array(random_arr, sorted_arr_copy, length);
    
    //run quicksort getting elapsed time for each
    start = clock();
    quick_sort(random_arr_copy, 0, length - 1);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    quick_sort(sorted_arr_copy, 0, length - 1);
    end = clock();
    copy_array(sorted_arr, sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    //run heapsort
    start = clock();
    heap_sort(random_arr_copy, length, length);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    heap_sort(sorted_arr_copy, length, length);
    end = clock();
    copy_array(sorted_arr, sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;

    
    //run merge sort
    start = clock();
    merge_sort(random_arr_copy, 0, length - 1);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    merge_sort(sorted_arr_copy, 0, length - 1);
    end = clock();
    copy_array(sorted_arr, sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    //run insertion sort getting elapsed time for each
    start = clock();
    insertion_sort(random_arr_copy, length);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    insertion_sort(sorted_arr_copy, length);
    end = clock();
    copy_array(sorted_arr, sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    output_table(random_times, sorted_times);
}

void run_all_except_insertion(int random_arr[], int sorted_arr[], int length)
{
    //copy of the input arrays to keep them intact
    int random_arr_copy[length];
    int sorted_arr_copy[length];
    
    //double arrays with running times
    double sorted_times[4];
    double random_times[4];
    
    //clock_t struct returned by the clock function for start and end times
    clock_t start, end;
    int ndx = 0;
    
    copy_array(sorted_arr, random_arr_copy, length);    
    copy_array(random_arr, sorted_arr_copy, length);
    
    //run quicksort getting elapsed time for each
    start = clock();
    quick_sort(random_arr_copy, 0, length - 1);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    quick_sort(sorted_arr_copy, 0, length - 1);
    end = clock();
    copy_array(sorted_arr, sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    //run heapsort
    start = clock();
    heap_sort(random_arr_copy, length, length);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    heap_sort(sorted_arr_copy, length, length);
    end = clock();
    copy_array(sorted_arr, sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;

    
    //run merge sort
    start = clock();
    merge_sort(random_arr_copy, 0, length - 1);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    merge_sort(sorted_arr_copy, 0, length - 1);
    end = clock();
    copy_array(sorted_arr, sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    output_table(random_times, sorted_times);
}

void sort_input_is_random(int random_arr[], int length)
{
    int random_arr_copy[length];
    
    //double arrays with running times
    double random_times[4];
    double sorted_times[4] = {-1, -1, -1, -1};
    
    //clock_t struct returned by the clock function for start and end times
    clock_t start, end;
    int ndx = 0;
    
    copy_array(random_arr, random_arr_copy, length);
    
    //run quicksort getting elapsed time for each
    start = clock();
    quick_sort(random_arr_copy, 0, length - 1);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    
    //run heapsort
    start = clock();
    heap_sort(random_arr_copy, length, length);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    

    
    //run merge sort
    start = clock();
    merge_sort(random_arr_copy, 0, length - 1);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    //run insertion sort getting elapsed time for each
    start = clock();
    insertion_sort(random_arr_copy, length);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    output_table(random_times, sorted_times);
}

void sort_input_is_random_not_insertion(int random_arr[], int length)
{
    int random_arr_copy[length];
    
    //double arrays with running times
    double random_times[4];
    //we won't need this array, but output_table expects it. 
    double sorted_times[4] = {-1, -1, -1, -1}; 
    
    //clock_t struct returned by the clock function for start and end times
    clock_t start, end;
    int ndx = 0;
    
    copy_array(random_arr, random_arr_copy, length);
    
    //run quicksort getting elapsed time for each
    start = clock();
    quick_sort(random_arr_copy, 0, length - 1);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    
    //run heapsort
    start = clock();
    heap_sort(random_arr_copy, length, length);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    

    
    //run merge sort
    start = clock();
    merge_sort(random_arr_copy, 0, length - 1);
    end = clock();
    copy_array(random_arr, random_arr_copy, length);
    random_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    output_table(random_times, sorted_times);
}

void sort_and_display(int random_arr[], int sorted_arr[], int length)
{
    std::cout << "Random array unsorted: " << std::endl;
    print_array(random_arr, length);
    
    std::cout << "Sorted array before sort: " << std::endl;
    print_array(sorted_arr, length);
    
    //copy of the input arrays to keep them intact
    int random_arr_copy[length];
    int sorted_arr_copy[length];
    
    //double arrays with running times
    double sorted_times[4];
    double random_times[4];
    
    //clock_t struct returned by the clock function for start and end times
    clock_t start, end;
    int ndx = 0;
    
    copy_array(sorted_arr, random_arr_copy, length);    
    copy_array(random_arr, sorted_arr_copy, length);
    
    //run a sort getting elapsed time for each
    //print the arrays before and after and then copy the original array 
    //back
    print_array(random_arr_copy, length);
    start = clock();
    quick_sort(random_arr_copy, 0, length - 1);
    end = clock();
    print_array(random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    print_array(sorted_arr_copy, length);
    start = clock();
    quick_sort(sorted_arr_copy, 0, length - 1);
    end = clock();
    print_array(sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    copy_array(sorted_arr, random_arr_copy, length);    
    copy_array(random_arr, sorted_arr_copy, length);
    
    //run a sort getting elapsed time for each
    //print the arrays before and after and then copy the original array 
    //back
    print_array(random_arr_copy, length);
    start = clock();
    heap_sort(random_arr_copy, length, length);
    end = clock();
    print_array(random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    print_array(sorted_arr_copy, length);
    start = clock();
    heap_sort(sorted_arr_copy, length, length);
    end = clock();
    print_array(sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    copy_array(sorted_arr, random_arr_copy, length);    
    copy_array(random_arr, sorted_arr_copy, length);
    
    //run a sort getting elapsed time for each
    //print the arrays before and after and then copy the original array 
    //back
    print_array(random_arr_copy, length);
    start = clock();
    merge_sort(random_arr_copy, 0, length - 1);
    end = clock();
    print_array(random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    print_array(sorted_arr_copy, length);
    start = clock();
    merge_sort(sorted_arr_copy, 0, length - 1);
    end = clock();
    print_array(sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    copy_array(sorted_arr, random_arr_copy, length);    
    copy_array(random_arr, sorted_arr_copy, length);
    
    //run insertion sort getting elapsed time for each
    print_array(random_arr_copy, length);
    start = clock();
    insertion_sort(random_arr_copy, length);
    end = clock();
    print_array(random_arr_copy, length);
    random_times[ndx] = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    print_array(sorted_arr_copy, length);
    start = clock();
    insertion_sort(sorted_arr_copy, length);
    end = clock();
    print_array(sorted_arr_copy, length);
    sorted_times[ndx++] = ((double)(end - start)) / CLOCKS_PER_SEC;

    copy_array(sorted_arr, random_arr_copy, length);    
    copy_array(random_arr, sorted_arr_copy, length);    
    
    output_table(random_times, sorted_times);
}