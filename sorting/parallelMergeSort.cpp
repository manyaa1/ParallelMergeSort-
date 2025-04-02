#include "parallelMergeSort.hpp"
#include <thread>
#include <iostream>

ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums) : nums(nums){}
ParallelMergeSort::~ParallelMergeSort(){}

void ParallelMergeSort::recursiveSort(int left, int right, int depth) {
    // Base case
    if (left >= right) {
        return;
    }

    // Calculate mid point safely
    int mid = left + (right - left) / 2;
    
    // Only create new threads if we're at a shallow depth
    // This prevents thread explosion
    const int MAX_DEPTH = 2; // Limit thread creation to first few levels
    
    if (depth < MAX_DEPTH) {
        // Create threads for parallel execution
        std::thread thread_1([this, left, mid, depth] { 
            this->recursiveSort(left, mid, depth + 1); 
        });
        
        // Process right half in this thread
        recursiveSort(mid + 1, right, depth + 1);
        
        // Wait for left half to complete
        thread_1.join();
    } else {
        // Sequential processing for deeper recursion levels
        recursiveSort(left, mid, depth + 1);
        recursiveSort(mid + 1, right, depth + 1);
    }
    
    // Merge the sorted halves
    std::vector<int> result;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if ((*nums)[i] <= (*nums)[j]) {
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back((*nums)[i]);
        i++;
    }
    
    while (j <= right) {
        result.push_back((*nums)[j]);
        j++;
    }
    
    // Copy result back to original array
    for (int k = 0; k < result.size(); k++) {
        (*nums)[left + k] = result[k];
    }
}

void ParallelMergeSort::sort() {
    if ((*nums).size() == 0) {
        return;
    }
    
    // Start recursion with depth 0
    recursiveSort(0, (*nums).size() - 1, 0);
}