// #include <cstdlib>
// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     string text1, text2;
    
//     // Using cin to read a single word
//     cout << "Enter a single word: ";
//     cin >> text1;
    
//     // Clear the input buffer
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
//     // Using getline to read a full line of text
//     cout << "Enter a full line of text: ";
//     getline(cin, text2);

//     cout << "You entered (single word): " << text1 << endl;
//     cout << "You entered (full line): " << text2 << endl;

//     return 0;
// }

// /* Program inputs two numbers x and y and outputs their sum */
// int main( ) {
//  int x, y;
//  std::cout << "Please enter two numbers: ";
//  std::cin >> x >> y; // input x and y
//  int sum = x + y; // compute their sum
//  std::cout << "Their sum is " << sum << std::endl;

//  return EXIT_SUCCESS; // terminate successfully
// }
// ------------

// #include <cstdlib>
// #include <iostream>

// using namespace std; //makes std avialable

// /* Program inputs two numbers x and y and outputs their sum */

// int main( ) {
//     int x, y;

//     cout << "Please enter two numbers: ";
//     cin >> x >> y; // input x and y

//     int sum = x + y; // compute their sum

//     cout << "Their sum is " << sum << endl;

// /*EXIT_SUCCESS is a constant defined in the <cstdlib> header, representing a successful program termination.*/
//     return 0; // terminate successfully
// }

//----
// #include <iostream>
// #include <iomanip>

// int main() {
//     float f = 1.0f / 3.0f;
//     double d = 1.0 / 3.0;

//     std::cout << std::setprecision(20);
//     std::cout << "float:  " << f << std::endl;
//     std::cout << "double: " << d << std::endl;

//     return 0;
// }

//-------

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



// ------------
// using namespace std;
// int main()
// {
    // double f [5];     // array of 5 doubles: f[0], . . ., f[4]
    // int m[10];        // array of 10 ints: m[0], ..., m[9]

    // f[4] = 2.5;
    // m[2] = 4;
    // cout<< f[0] << endl;


    // cout << f[m[2]]<<endl;  // outputs f[4], which is 2.5

// **********************************************************//

    // int a[] = {10, 11, 12, 13}; // declares a[4] and initializes
    // bool b[] = {false, true};   // declares b[2] and initializes
    // char c[] = {'c', 'a', 't'}; // declares c[3] and initializes

// **********************************************************//

//     char c[] = {'c', 'a', 't'};

//     char* p = c;                  // p points to c[0]
//     char* q = &c[0];              // q also points to c[0]

//     cout << c[0] << p[0] << q[0]<<endl; // outputs “ttt”

// }

// ------------

// #include <iostream>

// int main() {
//     const int size = 5;

//     // Declare an array of integers
//     int numbers[size] = {10, 20, 30, 40, 50};

//     // Declare a pointer to an integer and assign the address of the array
//     int* ptr = numbers;

//     // Access and print array elements using pointer notation
//     std::cout << "Array elements using pointers:" << std::endl;
//     for (int i = 0; i < size; ++i) {
//         std::cout << "Element " << i << ": " << *(ptr + i) << std::endl;
//     }

//     // Modify array elements through the pointer
//     for (int i = 0; i < size; ++i) {
//         *(ptr + i) *= 2;  // Double the value of each element
//     }

//     // Print the modified array using array notation
//     std::cout << "\nModified array elements:" << std::endl;
//     for (int i = 0; i < size; ++i) {
//         std::cout << "Element " << i << ": " << numbers[i] << std::endl;
//     }

//     return 0;
// }
// ------------
// #include <iostream>

// // Define a structure named 'Person'
// struct Person {
//     // Member variables (fields or attributes)
//     std::string name;
//     int age;
//     double height;
// };

// int main() {
//     // Declare a pointer to a 'Person' structure
//     Person* ptrPerson = new Person;

//     // Access and modify the member variables using the -> notation
//     ptrPerson->name = "Jane";
//     ptrPerson->age = 30;
//     ptrPerson->height = 162.0;

//     // Print the information using the pointer and -> notation
//     std::cout << "Person Information (using -> notation):" << std::endl;
//     std::cout << "Name: " << ptrPerson->name << std::endl;
//     std::cout << "Age: " << ptrPerson->age << std::endl;
//     std::cout << "Height: " << ptrPerson->height << " cm" << std::endl;

//     // Don't forget to deallocate memory for the dynamically allocated structure
//     delete ptrPerson;

//     return 0;
// }
/*
Dynamic Memory Allocation:

The new keyword is used to dynamically allocate memory for a Person structure. This means that the memory for the structure is allocated at runtime on the heap rather than on the stack.
Dynamically allocating memory is useful when you want to control the lifetime of the object, especially when the object needs to persist beyond the scope of the current function or when you want to manage memory explicitly.
Pointer Declaration:

Person* ptrPerson = new Person;: Here, ptrPerson is a pointer to a Person structure. It's initialized with the address of the dynamically allocated Person object.
Accessing Members through Pointer:

Using the -> notation (ptrPerson->name, ptrPerson->age, ptrPerson->height) allows us to access and modify the members of the Person structure through the pointer.
This is a convenient shorthand for dereferencing the pointer and accessing the members ((*ptrPerson).name, (*ptrPerson).age, (*ptrPerson).height).
Deallocating Memory:

After using the dynamically allocated memory, it's important to release it to avoid memory leaks. In this example, we use delete ptrPerson; to free the memory.
*/
// one value and one reference
// ------------

// using namespace std;
// void f (int value, int &ref ) {
//  value++;                // no effect on the actual argument
//  ref++;                  // modifies the actual argument

//  cout << value << endl;  // outputs 2
//  cout << ref << endl;    // outputs 6
// }

// int main() {
//  int cat = 1;
//  int dog = 5;

//  f(cat, dog);          // pass cat by value, dog by ref

//  cout << cat << endl;  // outputs 1
//  cout << dog << endl;  // outputs 6

//  return EXIT_SUCCESS;
// }
// ------------

// #include <iostream>

// // Function that modifies a variable passed by value
// void passByValue(int x) {
//     x = 10;
// }

// // Function that modifies a variable passed by reference
// void passByReference(int &x) {
//     x = 20;
// }

// int main() {
//     int num1 = 5;
//     int num2 = 7;

//     // Demonstrate pass by value
//     std::cout << "Before passByValue: num1 = " << num1 << std::endl;
//     passByValue(num1);
//     std::cout << "After passByValue: num1 = " << num1 << std::endl;

//     // Demonstrate pass by reference
//     std::cout << "\nBefore passByReference: num2 = " << num2 << std::endl;
//     passByReference(num2);
//     std::cout << "After passByReference: num2 = " << num2 << std::endl;

//     return 0;
// }
/*
As you can see, changes made to the parameter inside passByValue do not affect the original variable, 
while changes made inside passByReference directly modify the original variable. 
Passing by reference is often used when you want a function to modify the original value of a variable.*/

// #include <iostream>

// void add(int* a, int* b)
// {
//     std::cout << "sum = " << (*a + *b)<< std::endl;
// }

// void add(double* a, double* b)
// {
//     std::cout << std::endl << "sum = " << (*a + *b)<< std::endl;
// }

// int main()
// {
//     int int1 = 10, int2 = 2;
//     double double1 = 5.3, double2 = 6.2;

//     add(&int1, &int2);
//     add(&double1, &double2);

//     return 0;
// }
// ------------




// #include <iostream>
// #include <cstring>

// // Function prototype
// void swapStrings(char*&, char*&);

// int main() {
//     char str1[] = "Hello";  // Initialize a character array with the string "Hello"
//     char str2[] = "World";  // Initialize a character array with the string "World"
//     char* pstr1 = str1;     // Create a pointer pstr1 and make it point to the start of str1
//     char* pstr2 = str2;     // Create a pointer pstr2 and make it point to the start of str2

//     std::cout << "Before swap:" << std::endl;
//     std::cout << "str1: " << str1 << std::endl;
//     std::cout << "str2: " << str2 << std::endl;

//     swapStrings(pstr1, pstr2); // Call the swapStrings function, passing the pointers by reference

//     std::cout << "After swap:" << std::endl;
//     std::cout << "str1: " << pstr1 << std::endl; // Print the string that pstr1 points to
//     std::cout << "str2: " << pstr2 << std::endl; // Print the string that pstr2 points to

//     return 0;
// }

// void swapStrings(char*& ptr1, char*& ptr2) {
//     char* temp = ptr1; // Create a temporary pointer and store the value of ptr1 in it
//     ptr1 = ptr2; // Store the value of ptr2 in ptr1 (swapping the pointers)
//     ptr2 = temp; // Store the original value of ptr1 (now in temp) in ptr2
// }
// ------------
// #include <iostream>
// using namespace std;

// // Class definition for Counter
// class Counter {
// public:
//     Counter();              // Initialization
//     int getCount();          // Get the current count
//     void increaseBy(int x);  // Add x to the count

// private:
    
//     int count;               // The counter’s value
// };

// // Constructor for Counter
// Counter::Counter() {
//     count = 0;  // Initializes the counter to zero
// }

// // Get the current count
// int Counter::getCount() {
//     return count;
// }

// // Add x to the count
// void Counter::increaseBy(int x) {
//     count += x;
// }

// int main() {
//     Counter ctr;                  // An instance of Counter

//     cout << ctr.getCount() << endl; // Prints the initial value (0)

//     ctr.increaseBy(3);               // Increase by 3

//     cout << ctr.getCount() << endl; // Prints 3

//     ctr.increaseBy(5);               // Increase by 5

//     cout << ctr.getCount() << endl; // Prints 8

//     // cout << ctr.count << endl; // ILLEGAL - count is private

//     return 0;
// }
// ------------

// #include <iostream>
// #include <string>

// enum MealType {
//     VEG,
//     NON_VEG,
//     OTHER
// };

// class Passenger {
// public:
//     Passenger();
//     Passenger(const std::string& newName, MealType newMealPref);
    
//     bool isFrequentFlyer() const;
//     void makeFrequentFlyer(const std::string& newFreqFlyerNo);

    
//     bool isEqual(const Passenger& other) const;

// private:
//     std::string name;
//     MealType mealPref;
//     bool isFreqFlyer;
//     std::string freqFlyerNo;
// };

// Passenger::Passenger() {
//     name = "Unknown";
//     mealPref = OTHER;
//     isFreqFlyer = false;
// }

// Passenger::Passenger(const std::string& newName, MealType newMealPref) {
//     name = newName;
//     mealPref = newMealPref;
//     isFreqFlyer = false;
// }

// bool Passenger::isFrequentFlyer() const {
//     return isFreqFlyer;
// }

// void Passenger::makeFrequentFlyer(const std::string& newFreqFlyerNo) {
//     isFreqFlyer = true;
//     freqFlyerNo = newFreqFlyerNo;
// }
// // The trailing const at the end of the method declaration signifies that this method does 
// // not modify the state of the current 
// // object (*this). It promises not to modify any member variables of the current object. 

// bool Passenger::isEqual(const Passenger& other) const {
//     // Custom logic to compare passengers
//     return name == other.name &&
//            mealPref == other.mealPref &&
//            isFreqFlyer == other.isFreqFlyer &&
//            freqFlyerNo == other.freqFlyerNo;
// }

// int main() {
//     Passenger passenger1;
//     std::cout << "Passenger 1 is a frequent flyer? " << (passenger1.isFrequentFlyer() ? "Yes" : "No") << std::endl;

//     Passenger passenger2("John Doe", VEG);
//     std::cout << "Passenger 2 is a frequent flyer? " << (passenger2.isFrequentFlyer() ? "Yes" : "No") << std::endl;

//     // Passenger passenger3("John Doe");
//     // Without operator overloading
//     std::cout << "Are passengers equal? " << (passenger1.isEqual(passenger2) ? "Yes" : "No") << std::endl;

//     return 0;
// }
// ------------
// #include <iostream>

// class ResourceHolder {
// public:
//     // Constructor
//     ResourceHolder(int size) {
//         resource = new int[size];
//         std::cout << "Resource allocated." << std::endl;
//     }

//     // Destructor
//     ~ResourceHolder() {
//         delete[] resource;
//         std::cout << "Resource deallocated." << std::endl;
//     }

//     // Function to perform some operation with the resource
//     void performOperation() {
//         std::cout << "Performing operation with the resource." << std::endl;
//         // ... (some operation)
//     }

// private:
//     int* resource;
// };

// int main() {
//     // Creating an object of ResourceHolder
//     ResourceHolder holder(10);

//     // Using the resource
//     holder.performOperation();

//     // The destructor is automatically called when 'holder' goes out of scope
//     // or when 'holder' is explicitly deleted

//     return 0;
// }


/*
In this example:

The ResourceHolder class has a constructor that allocates a dynamic array (resource) of integers.

The destructor (~ResourceHolder()) is responsible for deallocating the dynamic memory 
when the object goes out of scope or is explicitly deleted.

The performOperation function demonstrates using the allocated resource.

In the main function, an instance of ResourceHolder is created, and its performOperation function is called.
 When the ResourceHolder object goes out of scope at the end of the main function, 
the destructor is automatically called, freeing the allocated memory
*/
// ------------


//g++ -std=c++11 cpp_primer.cpp -o prim