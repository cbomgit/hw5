/* 
 * File:   main.cpp
 * Author: christian
 *
 * Created on October 28, 2014, 1:02 PM
 */

#include <cstdlib>
#include <iostream>
#include "hw5functions.h"
#include <ctime>
#include <unistd.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    time_t start;
    start = time(&start);
    
    if(argc != 2)
    {
        std::cout << "Please supply one argument." << std::endl;
        return EXIT_FAILURE;
    }
    int arr_length = atoi(argv[1]);
    
    if(arr_length < 1)
    {
        std::cout << "Array size must be larger than zero." << std::endl;
        return EXIT_FAILURE;
    }
    
    int random_arr[arr_length];
    int sorted_arr[arr_length];
    
    randomize_array(random_arr, arr_length);
    print_array(random_arr, arr_length);
    
    merge_sort(random_arr, 0, arr_length - 1);
    print_array(random_arr, arr_length);
    return 0;
}

