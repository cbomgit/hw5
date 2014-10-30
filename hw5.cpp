/* 
 * File:   main.cpp
 * Author: christian
 *
 * Created on October 28, 2014, 1:02 PM
 */

#include <cstdlib>
#include <iostream>
#include "hw5functions.h"
#include <time.h>
#include <unistd.h>

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
    
    //declare the arrays, randomize one and pre-sort the other one
    int random_arr[arr_length];
    int sorted_arr[arr_length];
    
    randomize_array(random_arr, arr_length);
    for(int i = 0; i < arr_length; i++)
       sorted_arr[i] = i * 20;

    
    char option;
   
    greeting();
    show_menu();
    std::cin >> option;

    while(option != 'f')
    {
         switch(option) 
         {
            case 'a':
               run_all(random_arr, sorted_arr, arr_length);
               break;
            case 'b':
               run_all_except_insertion(random_arr, sorted_arr, arr_length);
               break;
            case 'c':
               sort_input_is_random(random_arr, arr_length);
               break;
            case 'd':
               sort_input_is_random_not_insertion(random_arr, arr_length);
               break;
            case 'e':
               sort_and_display(random_arr, sorted_arr, arr_length);
               break;
            default:
               std::cout << "Not a valid option" << std::endl;
               break;
         }
         show_menu();
         std::cin >> option;
    }
    
    
    
    return 0;
}

