#include <iostream>
#include <vector>
using namespace std;
// 1. Factorial calculation
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 2. Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. Sum of array elements
int arraySum(const std::vector<int>& arr, int index) {
    if (index == arr.size()) {
        return 0;
    }
    return arr[index] + arraySum(arr, index + 1);
}

// 4. Binary search---more on this later!
int binarySearch(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Element not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, target, left, mid - 1);
    } else {
        return binarySearch(arr, target, mid + 1, right);
    }
}

// 5. String reversal
std::string reverseString(const std::string& str) {
    if (str.length() <= 1) {
        return str;
    }
    return reverseString(str.substr(1)) + str[0];
}

int main() {
    // Test factorial
    // std::cout << "Factorial of 5: " << factorial(5) << std::endl;

    // // Test Fibonacci
    // std::cout << "6th Fibonacci number: " << fibonacci(6) << std::endl;

    // // Test array sum
    // std::vector<int> arr = {1, 2, 3, 4, 5};
    // std::cout << "Sum of array elements: " << arraySum(arr, 0) << std::endl;

    // // Test binary search
    // std::vector<int> sortedArr = {1, 3, 5, 7, 9, 11, 13};
    // int target = 7;
    // int result = binarySearch(sortedArr, target, 0, sortedArr.size() - 1);
    // std::cout << "Binary search for " << target << ": " << 
    //     (result != -1 ? "Found at index " + std::to_string(result) : "Not found") << std::endl;

    // Test string reversal
    std::string str = "Hello, World!";
    cout<<str.substr(1)<<endl;
    // std::cout << "Reversed string: " << reverseString(str) << std::endl;

    return 0;
}

//g++ -std=c++11 -o rec recursion.cpp