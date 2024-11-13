// #include <iostream>
// using namespace std;

// class Person {
// private:
//     string name;      // name
//     string idNum;     // university ID number

// public:
//     // Parameterized constructor for Person
//     Person(const string& n, const string& id) : name(n), idNum(id) {}
// /*
// Alternative constructor
// */
// //     Person(const string& personName, const string& personId) {
// //         this->name = personName;
// //         this->idNum = personId;
// //     }

//     // Print information
//     void print() {
//         cout << "Name: " << name << ", ID: " << idNum << endl;
//     }

//     // Retrieve name
//     string getName() {
//         return name;
//     }
// };

// // Student (derived from Person)
// class Student : public Person {
// private:
//     string major;  // major subject
//     int gradYear;  // graduation year

// public:
//     // Parameterized constructor for Student
//     Student(const string& n, const string& id, const string& m) : Person(n, id), major(m) {}
// /*
// Alternative constructor
// */
//     // Student(const string& studentName, const string& studentId, const string& studentMajor)
//     //     : Person(studentName, studentId) {
//     //     this->major = studentMajor;
//     // }
//     // Print information (overrides base class method)
//     void print() {
//         Person::print();  // Call the base class print method
//         cout << "Major: " << major << endl;
//     }

//     // Change major
//     void changeMajor(const string& newMajor) {
//         major = newMajor;
//         cout << "Changed major to: " << major << endl;
//     }
// };

// int main() {
//     Person person("Mary", "12");               // declare a Person
//     Student student("Bob", "98", "Math");     // declare a Student

//     cout << student.getName() << endl;        // Person::getName()
//     person.print();                            // Person::print()
//     student.print();                           // Student::print()

//     // person.changeMajor("Physics");         // ERROR! Person does not have changeMajor method
//     student.changeMajor("English");            // okay

//     return 0;
// }

// ----------

// #include <iostream>

// class Person {
// public:
//     void print() {
//         std::cout << "Person::print()" << std::endl;
//     }
// };

// class Student : public Person {
// public:
//     void print() {
//         std::cout << "Student::print()" << std::endl;
//     }
// };

// int main() {
//     Person* pp[100]; // array of 100 Person pointers

//     pp[0] = new Person(); // add a Person 
//     pp[1] = new Student(); // add a Student 

//     pp[0]->print(); // calls Person::print() (static binding)
//     pp[1]->print(); // calls Person::print() (static binding)

//     delete pp[0]; // clean up memory
//     delete pp[1]; // clean up memory

//     return 0;
// }

// ----------

// #include <iostream>

// class Person {
// public:
//     virtual void print() { //virtual gives the power of dynamic binding
//         std::cout << "Person::print()" << std::endl;
//     }
// };

// class Student : public Person {
// public:
//     virtual void print()  { //virtual allows main function to reach the student print function
//         std::cout << "Student::print()" << std::endl;
//     }
// };

// int main() {
//     Person* pp[100]; // array of 100 Person pointers

//     pp[0] = new Person(); // add a Person (details omitted)
//     pp[1] = new Student(); // add a Student (details omitted)

//     pp[0]->print(); // calls Person::print()
//     pp[1]->print(); // calls Student::print()

//     delete pp[0]; // clean up memory
//     delete pp[1]; // clean up memory

//     return 0;
// }

/*
In C++, static binding (also known as early binding or compile-time binding) occurs when the function 
to be called is determined at compile time based on the static type of the object. 
On the other hand, dynamic binding (also known as late binding or run-time binding) 
occurs when the function to be called is determined at runtime based on the actual type of the object.
*/

/*
A virtual function in C++ is a member function of a class that can be 
overridden by a function with the same signature in a derived class. 
Virtual functions enable polymorphism, allowing objects of different derived classes to be 
treated as objects of the base class. This means that the 
appropriate function is called based on the actual type of the object at runtime, achieving dynamic binding.
*/



// ----------

#include <iostream>

template <typename T>
T genericMin(T a, T b) { // returns the minimum of a and b
    return (a < b ? a : b); //if a is less than b then return a, otherwise return b
}

int main() {
    std::cout << genericMin(3, 4) << ' ' // =genericMin<int>(3,4)
              << genericMin(1.1, 3.1) << ' ' // =genericMin<double>(1.1, 3.1)
              << genericMin('t', 'g')        // =genericMin<char>('t','g')
              << std::endl;

    return 0;
}

// ----------

// #include <iostream>

// // Class template for a generic Pair
// template <typename T1, typename T2>
// class Pair {
// public:
//     Pair(T1 first, T2 second) : firstValue(first), secondValue(second) {}

//     void display() const {
//         std::cout << "Pair: (" << firstValue << ", " << secondValue << ")\n";
//     }

// private:
//     T1 firstValue;
//     T2 secondValue;
// };

// int main() {
//     // Creating instances of Pair with different types
//     Pair<int, double> intDoublePair(3, 4.5);
//     Pair<std::string, char> stringCharPair("Hello", 'C');

//     // Displaying the pairs
//     intDoublePair.display();
//     stringCharPair.display();

//     return 0;
// }

// ----------

// #include <iostream>
// #include <string>

// using namespace std;

// class MathException {
// public:
//     MathException(const string& err) : errMsg(err) { }
//     string getError() { return errMsg; } // access error message

// private:
//     string errMsg; // error message
// };

// class ZeroDivide : public MathException {
// public:
//     ZeroDivide(const string& err) : MathException(err) { }
// };

// class NegativeRoot : public MathException {
// public:
//     NegativeRoot(const string& err) : MathException(err) { }
// };

// int main() {
//     try {
//         // ... application computations
//         int divisor = 0;  // Sample divisor, replace with actual computation

//         if (divisor == 0) // attempt to divide by 0?
//             throw ZeroDivide("Divide by zero in Module X");

//         // Add more computations here

//     } catch (ZeroDivide& zde) {
//         cout << "Caught ZeroDivide exception: " << zde.getError() << endl;
//         // Handle division by zero
//     } catch (MathException& me) {
//         cout << "Caught MathException: " << me.getError() << endl;
//         // Handle any math exception other than division by zero
//     }

//     return 0;
// }
