#include <iostream>
#include <vector>
#include <list>

int main() {
   // Example 1: std::vector with random access iterator
   std::vector<int> vec = {1, 2, 3, 4, 5};

   // Create iterators with begin() and end()
   std::vector<int>::iterator it = vec.begin();
   std::vector<int>::iterator end = vec.end();

   // Main iterator operations
   std::cout << "Value at begin: " << *it << std::endl; // Value at begin: 1
   ++it; // Move forward
   std::cout << "Value after incrementing: " << *it << std::endl; // Value after incrementing: 2
   --it; // Move backward
   std::cout << "Value after decrementing: " << *it << std::endl; // Value after decrementing: 1
   it += 2; // Move forward 2 positions
   std::cout << "Value after += 2: " << *it << std::endl; // Value after += 2: 3
   std::cout << "Value at it[2]: " << it[2] << std::endl; // Value at it[2]: 5

   // Iterate over vector using iterators
   std::cout << "Iterating over vector using iterators:" << std::endl;
   for (auto it = vec.begin(); it != vec.end(); ++it) {
       std::cout << *it << " ";
   }
   std::cout << std::endl;

   // Iterate over vector using range-based loop
   std::cout << "Iterating over vector using range-based loop:" << std::endl;
   for (int& i : vec) {
       std::cout << i << " ";
   }
   std::cout << std::endl;

   // Example 2: std::list with bidirectional iterator
   std::list<int> lst = {1, 2, 3, 4, 5};
   std::list<int>::iterator lst_it = lst.begin();

   // iterator operations supported by std::list
   std::cout << "Value at begin of list: " << *lst_it << std::endl; // Value at begin of list: 1
   ++lst_it; // Move forward
   std::cout << "Value after incrementing: " << *lst_it << std::endl; // Value after incrementing: 2
   --lst_it; // Move backward
   std::cout << "Value after decrementing: " << *lst_it << std::endl; // Value after decrementing: 1

   lst_it += 2; // Not allowed for std::list (bidirectional iterator)- random access operations not supported
   // lst_it[2]; // Not allowed for std::list (bidirectional iterator)

   return 0;
}