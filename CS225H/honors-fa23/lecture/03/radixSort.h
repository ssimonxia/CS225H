#include <vector>

#define RADIX_10 10 
class Sort {
    public:
        // print the result of sorts
        void print(std::vector<int> array);

        // A utility function to do counting sort of arr[] according to the digit represented by exp.
        void countSort(std::vector<int>& array, int exp);

        // get the maximum number in the array
        int getMaxNum(std::vector<int> array);

        int getMinNum(std::vector<int> array);

        // Radix sort
        void radixSort(std::vector<int>& array);

        // Sort in STL
        void stlSort(std::vector<int>& array);

        // Quick sort
        void quickSort(std::vector<int>& array, int low, int high);

        // Function to partition the array into two sub-arrays based on the pivot
        int partition(std::vector<int>& array, int low, int high);

        // Merge sort
        void mergeSort(std::vector<int>& array, int left, int right);

        // Function to merge two sorted sub-arrays into one sorted array
        void merge(std::vector<int>& array, int left, int mid, int right);

        // Heap sort
        void heapSort(std::vector<int>& array);

        // Heap helper
        // Function to heapify a subtree rooted at a given index
        // `n` is the size of the heap
        void heapify(std::vector<int>& array, int n, int rootIndex);

        // Bucket sort
        void bucketSort(std::vector<int>& array);

        // Shuffle elements in the vector
        void shuffleVector(std::vector<int>& array);
        
        // Another version of bucket sort got from ChatGPT
        void bucketSortII(std::vector<int>& array);

        // Function to perform insertion sort on a bucket
        void insertionSort(std::vector<int>& bucket);

        // Get from ChatGPT
        void introSort(std::vector<int>& array);

        void quickSort(std::vector<int>& arr, int left, int right, int depthLimit);

        int medianOfThree(std::vector<int>& arr, int left, int right);

        void insertionSort(std::vector<int>& arr, int left, int right);

};
