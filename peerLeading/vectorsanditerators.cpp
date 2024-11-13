#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize the vector
    vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Initial vector: ";
    for (int num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    // Push back new elements
    vec1.push_back(10); // Add 10
    vec1.push_back(20); // Add 20
    vec1.push_back(30); // Add 30
    vec1.push_back(40); // Add 40
    vec1.push_back(50); // Add 50

    // //print using an iterator
    // for(vector<int> :: iterator it = vec1.begin(); it = vec1.end(), it++){ //as long as it != end of vec1, it will print
    //     cout << *it << " ";
    // }
    // cout << endl;

    cout << "After push_back: ";
    for (const auto& num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    // Pop elements from the end
    vec1.pop_back(); // Remove 50
    vec1.pop_back(); // Remove 40
    vec1.pop_back(); // Remove 30
    vec1.pop_back(); // Remove 20

    cout << "After pop_back: ";
    for (const auto& num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    // Insert at a specific position
    vec1.insert(vec1.begin() + 2, 200); // Insert 200 at index 2
    cout << "After insert: ";
    for (const auto& num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    // Iterate using range-based for loop
    cout << "Using for-each loop: ";
    for (const auto& num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    // Erase at a specific position
    vec1.erase(vec1.begin() + 2); // Remove the element at index 2
    cout << "After erase: ";
    for (const auto& num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    // Clear the vector
    vec1.clear();
    cout << "After clear: " << vec1.size() << endl; // Check size after clearing

    // Check if the vector is empty
    if (vec1.empty()) {
        cout << "Vector is empty" << endl;
    } else {
        cout << "Vector is not empty" << endl;
    }

    return 0;
}