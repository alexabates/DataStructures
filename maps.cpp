#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create a hashmap
    std::unordered_map<std::string, int> scores;
    
    // Insert elements
    scores["Alice"] = 95;
    scores.insert({"Bob", 89});
    scores.emplace("Charlie", 91);
    
    // Access elements
    std::cout << "Alice's score: " << scores["Alice"] << std::endl;
    
    // Check if key exists
    if (scores.find("David") != scores.end()) {
        std::cout << "David's score found" << std::endl;
    } else {
        std::cout << "David not found" << std::endl;
    }
    
    // Update value
    scores["Alice"] = 97;
    
    // Iterate through hashmap
    for (const auto& pair : scores) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // Get size
    std::cout << "Size: " << scores.size() << std::endl;
    
    // Remove element
    scores.erase("Bob");
    
    // Clear hashmap
    scores.clear();
    
    // Check if empty
    if (scores.empty()) {
        std::cout << "Hashmap is empty" << std::endl;
    }
    
    return 0;
}