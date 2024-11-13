// #include <iostream>

// template <typename Type>
// void insertion_sort(Type *const array, int const n) {
//     for (int k = 1; k < n; ++k) {
//         for (int j = k; j > 0; --j) {
//             if (array[j - 1] > array[j]) {
//                 // Swap elements if they are in the wrong order
//                 std::swap(array[j - 1], array[j]);
//             } else {
//                 // As soon as we don't need to swap, the (k + 1)st
//                 // is in the correct location, break out of the loop
//                 break;
//             }
//         }
//     }
// }

// int main() {
//     // Example usage with an array of integers
//     int arr[] = {5, 2, 9, 1, 5, 6};
//     //n is the number of elements in the array
//     int n = sizeof(arr) / sizeof(arr[0]);//sizeof()- return size in bytes

//     std::cout << "Original array: ";
//     for (int i = 0; i < n; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     // Sorting the array using insertion_sort
//     insertion_sort(arr, n);

//     std::cout << "Sorted array: ";
//     for (int i = 0; i < n; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

#include <iostream>
#include <vector>

int main() {
    // Creating a vector of integers
    std::vector<int> numbers;

    // Adding elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Printing the vector elements
    std::cout << "Vector elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Accessing vector elements
    std::cout << "First element: " << numbers[0] << std::endl;
    std::cout << "Last element: " << numbers.back() << std::endl;

    // Modifying vector elements
    numbers[1] = 25;
    std::cout << "Vector elements after modification: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Getting the size of the vector
    std::cout << "Vector size: " << numbers.size() << std::endl;

    // Removing an element from the vector
    numbers.pop_back();
    std::cout << "Vector elements after removing last element: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}