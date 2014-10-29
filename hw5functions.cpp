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
    for(int i = length - 1; i > 1; i--)
    {
	temp = arr[1];
	arr[1] = arr[i];
	arr[i] = temp;
	heap_size--;
	heapify(arr, 1, heap_size);
	
    }
}

void build_heap(int arr[], int length)
{
    int heap_size = length;
    for(int i = heap_size / 2; i >= 0; i--)
    {
	heapify(arr, i, heap_size);
    }
}

void heapify(int arr[], int i, int heap_size)
{
    int left = left_child(i);
    int right = right_child(i);
    int largest = 0;
    int swap_var = 0;
    
    if(left < heap_size && arr[left] < arr[i])
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
	
        int middle = (start + end) / 2;	// 9 / 2 = 4
        merge_sort(arr, start, middle);	//0, 4
        merge_sort(arr, middle + 1, end); //5, 9
        merge(arr, start, middle + 1, end); //0, 5, 9
    }
    
}

void merge(int arr[], int start, int middle, int end)
{
    //start and ending index of left sub array is start -> middle - 1
    //size is (middle - start)
    int left_size = middle - start + 1;
    
    //start and ending index of right sub array is middle -> end
    //size is end - middle + 1
    int right_size = (end - middle);
    
    //declare the two sub arrays
    int left_arr[left_size];
    int right_arr[right_size];
    
    for(int i = 0; i < left_size; i++)
    {
	left_arr[i] =arr[start + i ];
    }
    
    for(int i = 0; i < right_size; i++)
    {
	right_arr[i] = arr[middle + i];
    }
    
    int total_length = left_size + right_size;
    int i = 0;
    int j = 0;
    for(int k = 0; k < total_length; k++)
    {
	if(left_arr[i] <= right_arr[j])
	{
	    arr[k] = left_arr[i];
	    i++;
	}
	else
	{
	    arr[k] = right_arr[j];
	    j++;
	}
    }
 
}
//outputs a menu for the user to choose options from
void show_menu()
{
    std::cout << "Sort random and sorted arrays and output their run times." 
              << std::endl;
    
    std::cout << "a. Sort random array and sorted array on all 4 "
              << "sorts.\n" << std::endl;
    
    std::cout << "b. Sort random array and sorted array on 3 sorts "
              << "(quick, heap, and merge)." << std::endl;
    
    std::cout << "c. Sort random array only on all 4 sorts." << std::endl;
    
    std::cout << "d. Sort random array only on 3 sorts (quick, "
              << "heap, and merge)." << std::endl;
    
    std::cout << "e. Display the original array and the sorted "
              << "array on all 4 sorts." << std::endl;
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
void output_table(long double sorted_arr_times[], 
                  long double unsorted_arr_times[])
{
    
    
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
    for(int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}