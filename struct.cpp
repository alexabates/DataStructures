#include <iostream>

// Define a structure named 'Person'
struct Person {
    // Member variables (fields or attributes)
    std::string name;
    int age;
    double height;
};

int main() {
    // Declare a pointer to a 'Person' structure
    Person* ptrPerson = new Person;

    // Access and modify the member variables using the -> notation
    ptrPerson->name = "Jane";
    ptrPerson->age = 30;
    ptrPerson->height = 162.0;

    // Print the information using the pointer and -> notation
    std::cout << "Person Information (using -> notation):" << std::endl;
    std::cout << "Name: " << ptrPerson->name << std::endl;
    std::cout << "Age: " << ptrPerson->age << std::endl;
    std::cout << "Height: " << ptrPerson->height << " cm" << std::endl;

    // Don't forget to deallocate memory for the dynamically allocated structure
    delete ptrPerson;

    return 0;
}
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
