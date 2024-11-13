#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    printArray(arr);
    
    insertionSort(arr);
    
    std::cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}
/*
//merge sort
#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted subarrays
void merge(vector<int>& arr, int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    
    // Merge the two sorted subarrays into arr
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    // Add remaining elements from left subarray (if any)
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    
    // Add remaining elements from right subarray (if any)
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

// Function to perform merge sort recursively
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;  // Base case: subarray has at most one element
    }
    
    int mid = left + (right - left) / 2;
    
    // Create temporary subarrays
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int leftArr[leftSize], rightArr[rightSize];
    
    // Copy data to temporary subarrays
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Recursively sort the subarrays
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    
    // Merge the sorted subarrays
    merge(arr, leftArr, leftSize, rightArr, rightSize);
}

int main() {
    std::vector<int> arr;
    arr.push_back(38);
    arr.push_back(27);
    arr.push_back(43);
    arr.push_back(3);
    arr.push_back(9);
    arr.push_back(82);
    arr.push_back(10);
    
    int n = arr.size();
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
*/

//-------
//quick sort

#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of smaller element
            swap(arr[i], arr[j]);  // Swap the current element with the smaller element
        }
    }

    // Swap the pivot element with the element at the index of the smaller element
    swap(arr[i + 1], arr[high]);

    return i + 1;  // Return the index of the pivot element
}

// Function to perform QuickSort recursively
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr;
    arr.push_back(38);
    arr.push_back(27);
    arr.push_back(43);
    arr.push_back(3);
    arr.push_back(9);
    arr.push_back(82);
    arr.push_back(10);
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/
//------

/*
//counting sort

#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum element in the array
int findMax(vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform Counting Sort
void countingSort(vector<int>& arr) {
    int n = arr.size();
    int max = findMax(arr);

    // Create a count array to store the count of each element
    vector<int> count(max + 1, 0);

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the count array to store the cumulative sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted elements
    vector<int> temp(n);

    // Place the elements in the temporary array based on their counts
    for (int i = n - 1; i >= 0; i--) {
        temp[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    vector<int> arr;
    // = {4, 2, 2, 8, 3, 3, 1}
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(1);

    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}*/