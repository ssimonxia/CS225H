#include "radixSort.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>

using namespace std;

void Sort::countSort(std::vector<int>& array, int exp) {
    const int n = array.size();
    vector<int> output(n);
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

void Sort::radixSort(std::vector<int>& array) {
    // Find the maximum number to know the number of digits
    int max = getMaxNum(array);

    // Do counting sort for every digit. Note that
    // instead of passing digit number, exp is passed.
    // exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(array, exp);
    }
}

void Sort::print(std::vector<int> array) {
    for (unsigned i = 0; i < array.size(); i++) {
        std::cout<<" "<<array[i]<<" ";
    }
    std::cout<<std::endl;
}

int Sort::getMaxNum(std::vector<int> array) {
    int max = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

void Sort::stlSort(std::vector<int>& array) {
    std::sort(array.begin(), array.end());
}


int Sort::partition(std::vector<int>& array, int low, int high) {
    int pivot = array[high]; // Choose the last element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (array[j] <= pivot) {
            i++; // Increment index of the smaller element
            swap(array[i], array[j]);
        }
    }

    // Place the pivot element in its correct position
    swap(array[i + 1], array[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void Sort::quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to merge two sorted sub-arrays into one sorted array
void Sort::merge(std::vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left sub-array
    int n2 = right - mid;     // Size of the right sub-array

    // Create temporary arrays to store the data
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copy data to temporary arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++) {
        leftArr[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = array[mid + 1 + i];
    }

    // Merge the two sub-arrays back into the original array
    int i = 0; // Initial index of left sub-array
    int j = 0; // Initial index of right sub-array
    int k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            array[k] = leftArr[i];
            i++;
        } else {
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        array[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        array[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void Sort::mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        // Calculate the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}

void Sort::bucketSort(std::vector<int>& array) {
    int maxx = getMaxNum(array);
    int minn = getMinNum(array);
    int range = maxx-minn;
    int * count = new int[range+1];
    memset(count, 0 ,range+1);
    std::vector<int> output;
    for (int i = 0; i < array.size(); i++) {
        count[array[i] - minn]++;
    }
    for (int i = 0; i <= range; i++) {
        while(count[i] > 0) {
            output.push_back(i+minn);
            count[i]--;
        }
    }
    delete[] count;
    array = output;
}

void Sort::shuffleVector(std::vector<int>& array) {
    // generate the random number
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(array.begin(), array.end(), std::default_random_engine(seed));
}

int Sort::getMinNum(std::vector<int> array) {
    int min = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}


void Sort::heapify(vector<int>& array, int n, int rootIndex) {
    int largest = rootIndex; // Initialize the largest as the root
    int leftChild = 2 * rootIndex + 1; // Left child
    int rightChild = 2 * rootIndex + 2; // Right child

    // If the left child is larger than the root
    if (leftChild < n && array[leftChild] > array[largest]) {
        largest = leftChild;
    }

    // If the right child is larger than the largest so far
    if (rightChild < n && array[rightChild] > array[largest]) {
        largest = rightChild;
    }

    // If the largest is not the root
    if (largest != rootIndex) {
        swap(array[rootIndex], array[largest]);

        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

// Main function to perform Heap Sort
void Sort::heapSort(std::vector<int>& array) {
    int n = array.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end of the array
        swap(array[0], array[i]);

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}


void Sort::insertionSort(std::vector<int>& bucket) {
    for (int i = 1; i < bucket.size(); i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform bucket sort
void Sort::bucketSortII(std::vector<int>& array) {
    if (array.empty()) {
        return;
    }

    // Find the maximum and minimum values in the input array
    int max_val = *max_element(array.begin(), array.end());
    int min_val = *min_element(array.begin(), array.end());

    // Determine the range of values and the number of buckets
    int range = max_val - min_val + 1;
    int num_buckets = array.size();

    // Create buckets
    std::vector<vector<int>> buckets(num_buckets);

    // Distribute elements into buckets
    for (int i = 0; i < array.size(); i++) {
        int bucket_index = (array[i] - min_val) * (num_buckets - 1) / range;
        buckets[bucket_index].push_back(array[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < num_buckets; i++) {
        insertionSort(buckets[i]);
    }

    // Concatenate sorted buckets to get the sorted array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            array[index++] = buckets[i][j];
        }
    }
}


int Sort::medianOfThree(std::vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;

    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);

    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);

    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);

    swap(arr[mid], arr[right]); // Place pivot at arr[right]
    return partition(arr, left, right);
}

// Function to implement Quick Sort with a depth limit
void Sort::quickSort(std::vector<int>& arr, int left, int right, int depthLimit) {
    while (left < right) {
        if (depthLimit == 0) {
            // If the depth limit is reached, switch to Heap Sort
            make_heap(arr.begin() + left, arr.begin() + right + 1);
            sort_heap(arr.begin() + left, arr.begin() + right + 1);
            return;
        }

        if (right - left < 16) {
            // If the subarray is small, switch to Insertion Sort
            insertionSort(arr, left, right);
            return;
        }

        int pivotIndex = medianOfThree(arr, left, right);
        int pivotPos = partition(arr, left, right);

        // Recurse on the smaller subarray and use tail recursion on the larger one
        if (pivotPos - left < right - pivotPos) {
            quickSort(arr, left, pivotPos - 1, depthLimit - 1);
            left = pivotPos + 1;
        } else {
            quickSort(arr, pivotPos + 1, right, depthLimit - 1);
            right = pivotPos - 1;
        }
    }
}

// Function to perform IntroSort
void Sort::introSort(std::vector<int>& arr) {
    int depthLimit = 2 * log2(arr.size());

    quickSort(arr, 0, arr.size() - 1, depthLimit);
}

void Sort::insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}