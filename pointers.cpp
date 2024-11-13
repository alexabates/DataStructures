#include <iostream>
#include <string>

// Function to be used with function pointers
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    // 1. Basic pointer usage
    int num = 42;
    int* ptr = &num;
    
    std::cout << "1. Basic Pointer Usage:" << std::endl;
    std::cout << "   Value of num: " << num << std::endl;
    std::cout << "   Address of num: " << ptr << std::endl;
    std::cout << "   Value pointed by ptr: " << *ptr << std::endl; //*&num

    // 2. Pointer arithmetic
    int arr[] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;
    
    std::cout << "\n2. Pointer Arithmetic:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "   Element " << i << ": " << *arrPtr << std::endl;
        arrPtr++;
    }

    // 3. Pointers to pointers
    int x = 5;
    int* p = &x;
    int** pp = &p;
    
    std::cout << "\n3. Pointers to Pointers:" << std::endl;
    std::cout << "   Adrress of x: " << &x << std::endl;
    std::cout << "   Value pointed by p: " << *p << std::endl;
    std::cout << "   Value pointed by pp: " << **pp << std::endl;

    // 4. Function pointers
    int (*operation)(int, int);
    operation = add;
    
    std::cout << "\n4. Function Pointers:" << std::endl;
    std::cout << "   Result of add: " << operation(5, 3) << std::endl;
    
    operation = subtract;
    std::cout << "   Result of subtract: " << operation(5, 3) << std::endl;



    return 0;
}