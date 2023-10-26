
/*DESCRIPTION: This C++ program implements two sorting algorithms, Merge Sort and Quick Sort, 
as template functions for vectors. Merge Sort divides the vector into smaller halves, recursively
sorts them, and then merges them back together, providing stable sorting with a time complexity 
of O(n log n). Quick Sort uses a randomized pivot to partition and sort the vector efficiently, 
achieving an average-case time complexity of O(n log n). Thank you for reading my code! :)
*/

#pragma once

#include <vector>
#include <cstdlib>  // for rand()


// Helper function for merge sort
template <class T>
std::vector<T> merge(std::vector<T>& left, std::vector<T>& right) {
    std::vector<T> result;
    int i = 0, j = 0;

    // Merge two sorted vectors
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);  // Add the smaller element from left
            ++i;  // Move to the next element in the left vector
        } else {
            result.push_back(right[j]);  // Add the smaller element from right
            ++j;  // Move to the next element in the right vector
        }
    }

    // Add remaining elements from left vector, if any
    while (i < left.size()) {
        result.push_back(left[i]);
        ++i;
    }

    // Add remaining elements from right vector, if any
    while (j < right.size()) {
        result.push_back(right[j]);
        ++j;
    }

    return result;
}

// Merge Sort
template <class T>
std::vector<T> mergeSort(std::vector<T> lst) {
    if (lst.size() <= 1) {
        return lst;  // Base case: already sorted or empty
    }

    // Create separate vectors for left and right side of the vector
    int mid = lst.size() / 2;
    std::vector<T> left(lst.begin(), lst.begin() + mid);
    std::vector<T> right(lst.begin() + mid, lst.end());

    // Recursively sort and merge left and right halves
    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

// Helper function for quicksort partitioning
template <class T>
int partition(std::vector<T>& lst, int low, int high) {
    // Choose a random pivot index within the specified range
    int pivotIndex = rand() % (high - low + 1) + low;
    T pivotValue = lst[pivotIndex];

    // Swap the chosen pivot element with the element at the high index
    std::swap(lst[pivotIndex], lst[high]);

    int i = low - 1;

    // Partitioning step
    for (int j = low; j < high; ++j) {
        if (lst[j] < pivotValue) {
            ++i;
            std::swap(lst[i], lst[j]);  // Swap elements if smaller than the pivot
        }
    }

    std::swap(lst[i + 1], lst[high]);  // Move pivot element to its final position
    return i + 1;
}

// Quicksort
//Uses recursion, so separate helper function is used
template <class T>
void quickSortHelper(std::vector<T>& lst, int low, int high) {
    if (low < high) {
        int pivot = partition(lst, low, high);

        // Recursively sort left and right partitions
        quickSortHelper(lst, low, pivot - 1);
        quickSortHelper(lst, pivot + 1, high);
    }
}

// Wrapper function for quicksort
template <class T>
std::vector<T> quickSort(std::vector<T> lst) {
    quickSortHelper(lst, 0, lst.size() - 1);
    return lst;
}