#include <iostream>
#include <cstdlib> // For rand()
#include <chrono>  // For timing
#include "mergeSort.hpp"
#include "parallelMergeSort.hpp"

int main(int argc, char *argv[])
{

    const int SIZE = 10000000;
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);


    for (int i = 0; i < SIZE; ++i)
    {
        nums[i] = rand() % 10000000;
        nums1[i] = rand() % 10000000;
    }
    MergeSort *mergesort = new MergeSort(&nums); // returns the pointer to the address of merge sort in memory

    // chroo is a time library
    // we have to make sure the time taken by merge sort algorithm thats why we are making sure we know the current time
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortDuration = end - start;
    std::cout << "MergeSort algorithm time taken: " << mergesortDuration.count() << "seconds" << std::endl;

    delete mergesort; // deleting the memory allocated by this instead



    ParallelMergeSort *mergesort1 = new ParallelMergeSort(&nums1); // returns the pointer to the address of merge sort in memory

   //don't declare again
    start = std::chrono::high_resolution_clock::now();
    mergesort1->sort();
     end = std::chrono::high_resolution_clock::now();
    mergesortDuration = end - start;
    std::cout << "Parallel MergeSort algorithm time taken: " << mergesortDuration.count() << "seconds" << std::endl;

    delete mergesort1; // deleting the memory allocated by this instead



    
}