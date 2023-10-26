
/*DESCRIPTION: This program includes linearSearch and binarySearch functions. 
linearSearch scans the vector linearly, returning the element's index if found
or -1 if not. binarySearch searches a sorted vector and returns the index if the
target is present or -1 if absent, offering two search options based on data 
characteristics. Thank you for reviewing my code! :)
*/

#pragma once

#include <vector>

// Function to perform linear search on a vector
template <class T>
int linearSearch(std::vector<T> data, T target) {
    // Iterates through data vector
    for (int i = 0; i < data.size(); ++i) {
        //returns if element of data is the same as target
        if (data[i] == target) {
            return i;  // Element found, return its index
        }
    }
    return -1;  // Element not found
}

// Function to perform binary search on a sorted vector
template <class T>
int binarySearch(std::vector<T> data, T target) {
    int left = 0;            // Initialize the left index
    int right = data.size() - 1;  // Initialize the right index
    
    while (left <= right) {  // Continue as long as there's a valid range
        int mid = left + (right - left) / 2;  // Calculate the middle index
        
	//if the middle index is equal to target
        if (data[mid] == target) {
            return mid;  // Element found, return its index
        }
        
	//if middle index is less than target
        if (data[mid] < target) {
            left = mid + 1;  // Adjust the left index

        } else {
            right = mid - 1;  // Adjust the right index
        }
    }
    
    return -1;  // Element not found
}
