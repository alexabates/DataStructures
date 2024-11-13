#include <iostream>
using namespace std;

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

#include <iostream>

class ResourceHolder {
public:
    // Constructor
    ResourceHolder(int size) {
        resource = new int[size];
        std::cout << "Resource allocated." << std::endl;
    }

    // Destructor
    ~ResourceHolder() {
        delete[] resource;
        std::cout << "Resource deallocated." << std::endl;
    }

    // Function to perform some operation with the resource
    void performOperation() {
        std::cout << "Performing operation with the resource." << std::endl;
        // ... (some operation)
    }

private:
    int* resource;
};

int main() {
    // Creating an object of ResourceHolder
    ResourceHolder holder(10);

    // Using the resource
    holder.performOperation();

    // The destructor is automatically called when 'holder' goes out of scope
    // or when 'holder' is explicitly deleted

    return 0;
}


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