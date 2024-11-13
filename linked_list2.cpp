// #include <iostream>

// // Node class to represent each element in the linked list
// template <typename T>
// class Node {
// public:
//     T data;
//     Node* next;

//     Node(T value) : data(value), next(nullptr) {}
// };

// // LinkedList class to manage the linked list
// template <typename T>
// class LinkedList {
// private:
//     Node<T>* head;

// public:
//     LinkedList() : head(nullptr) {}

//     // Function to insert a new element at the end of the list
//     void insert(T value) {
//         Node<T>* newNode = new Node<T>(value);
//         if (head == nullptr) {
//             head = newNode;
//         } else {
//             Node<T>* current = head;
//             while (current->next != nullptr) {
//                 current = current->next;
//             }
//             current->next = newNode;
//         }
//     }

//     // Function to insert a new element at the front of the list
//     void insertFront(T value) {
//         Node<T>* newNode = new Node<T>(value);
//         newNode->next = head;
//         head = newNode;
//     }

//     // Function to insert a new element after a node with a particular value
//     void insertAfter(T valueToFind, T valueToInsert) {
//         Node<T>* current = head;
//         while (current != nullptr && current->data != valueToFind) {
//             current = current->next;
//         }

//         if (current != nullptr) {
//             Node<T>* newNode = new Node<T>(valueToInsert);
//             newNode->next = current->next;
//             current->next = newNode;
//         }
//     }

//     // Function to display the elements in the list
//     void display() {
//         Node<T>* current = head;
//         while (current != nullptr) {
//             std::cout << current->data << " ";
//             current = current->next;
//         }
//         std::cout << std::endl;
//     }

//     // Destructor to free memory when the list is destroyed
//     ~LinkedList() {
//         Node<T>* current = head;
//         Node<T>* nextNode;
//         while (current != nullptr) {
//             nextNode = current->next;
//             delete current;
//             current = nextNode;
//         }
//     }
// };

// int main() {
//     // Creating a linked list of integers
//     LinkedList<int> myList;

//     // Inserting elements into the list
//     myList.insert(10);
//     myList.insert(20);
//     myList.insert(30);

//     // Displaying the elements in the list
//     myList.display();

//     // Inserting a new element after the node with value 20
//     myList.insertAfter(20, 25);

//     // Displaying the elements after insertion
//     myList.display();

//     myList.insert(56);
//     myList.display();

//     return 0;
// }


/*
how to compile- g++ -std=c++0x linked_list.cpp -o output
*/

// #include <iostream>

// class Node {
// public:
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int value) : data(value), prev(nullptr), next(nullptr) {}
// };

// class DoublyLinkedList {
// private:
//     Node* head;
//     Node* tail;

// public:
//     DoublyLinkedList() : head(nullptr), tail(nullptr) {}

//     // Function to insert a new node at the end of the list
//     void insert(int value) {
//         Node* newNode = new Node(value);
//         if (!head) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//     }

//     // Function to search for a value in the list
//     bool search(int value) {
//         Node* current = head;
//         while (current) {
//             if (current->data == value) {
//                 return true;
//             }
//             current = current->next;
//         }
//         return false;
//     }

//     // Function to remove the head node from the list
//     void removeHead() {
//         if (!head) {
//             std::cout << "List is empty. No head to remove." << std::endl;
//             return;
//         }

//         Node* temp = head;
//         head = head->next;
//         if (head) {
//             head->prev = nullptr;
//         } else {
//             tail = nullptr;
//         }
//         delete temp;
//     }

//     // Function to remove the tail node from the list
//     void removeTail() {
//         if (!tail) {
//             std::cout << "List is empty. No tail to remove." << std::endl;
//             return;
//         }

//         Node* temp = tail;
//         tail = tail->prev;
//         if (tail) {
//             tail->next = nullptr;
//         } else {
//             head = nullptr;
//         }
//         delete temp;
//     }

//     // Function to print the elements of the list
//     void print() {
//         Node* current = head;
//         while (current) {
//             std::cout << current->data << " ";
//             current = current->next;
//         }
//         std::cout << std::endl;
//     }
// };

// int main() {
//     DoublyLinkedList dll;

//     dll.insert(1);
//     dll.insert(2);
//     dll.insert(3);
//     dll.insert(4);

//     std::cout << "Original list: ";
//     dll.print();

//     int searchValue = 3;
//     std::cout << "Search for value " << searchValue << ": ";
//     if (dll.search(searchValue))
//         std::cout << "Found" << std::endl;
//     else
//         std::cout << "Not Found" << std::endl;

//     std::cout << "Removing head..." << std::endl;
//     dll.removeHead();
//     std::cout << "List after removing head: ";
//     dll.print();

//     std::cout << "Removing tail..." << std::endl;
//     dll.removeTail();
//     std::cout << "List after removing tail: ";
//     dll.print();

//     return 0;
// }
// #include <iostream>
// #include <vector>

// struct Node {
//     char data;
//     Node* prev;
//     Node* next;
//     Node(char c) : data(c), prev(nullptr), next(nullptr) {}
// };

// class TextBuffer {
// private:
//     Node* head;
//     Node* tail;
//     Node* cursor;
//     std::vector<char> clipboard;

//     void insertNode(Node* node) {
//         if (!head) {
//             head = tail = cursor = node;  // Initialize head, tail, and cursor when list is empty
//         } else if (cursor == head) {
//             node->next = head;
//             head->prev = node;
//             head = node;
//         } else if (!cursor) {
//             node->prev = tail;
//             tail->next = node;
//             tail = node;
//         } else {
//             node->prev = cursor->prev;
//             node->next = cursor;
//             if (cursor->prev) cursor->prev->next = node;
//             cursor->prev = node;
//         }
//     }

//     void removeNode(Node* node) {
//         if (node == head) {
//             head = node->next;
//             if (head) head->prev = nullptr;
//             if (cursor == node) cursor = head;  // Move cursor to the new head if it was at the node being deleted
//         } else if (node == tail) {
//             tail = node->prev;
//             if (tail) tail->next = nullptr;
//             if (cursor == node) cursor = tail;  // Move cursor to the new tail if it was at the node being deleted
//         } else {
//             node->prev->next = node->next;
//             node->next->prev = node->prev;
//             if (cursor == node) cursor = node->next;  // Move cursor forward when deleting the current node
//         }
//         delete node;
//     }

// public:
//     TextBuffer() : head(nullptr), tail(nullptr), cursor(nullptr) {}

//     ~TextBuffer() {
//         while (head) {
//             Node* temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }

//     void insert(char c) {
//         Node* newNode = new Node(c);
//         insertNode(newNode);
//         cursor = newNode->next ? newNode->next : nullptr;  // If at end, cursor should be nullptr
//     }

//     void deleteChar() {
//         if (cursor && cursor->prev) {
//             Node* toDelete = cursor->prev;
//             removeNode(toDelete);
//         }
//     }

//     void moveLeft() {
//         if (cursor && cursor->prev) {
//             cursor = cursor->prev;
//         }
//     }

//     void moveRight() {
//         if (cursor) {
//             cursor = cursor->next;
//         } else if (tail) {  // If cursor is at the end, move it to the last character
//             cursor = tail;
//         }
//     }

//     void cut(int n) {
//         clipboard.clear();
//         while (n > 0 && cursor && cursor->prev) {
//             clipboard.push_back(cursor->prev->data);
//             Node* toDelete = cursor->prev;
//             removeNode(toDelete);
//             n--;
//         }
//     }

//     void paste() {
//         for (char c : clipboard) {
//             insert(c);
//         }
//     }

//     void print() {
//         Node* current = head;
//         while (current) {
//             if (current == cursor) {
//                 std::cout << "|";
//             }
//             std::cout << current->data;
//             current = current->next;
//         }
//         if (!cursor) {
//             std::cout << "|";
//         }
//         std::cout << std::endl;
//     }
// };

// int main() {
//     TextBuffer editor;

//     // Example usage
//     editor.insert('H');
//     editor.insert('e');
//     editor.insert('l');
//     editor.insert('l');
//     editor.insert('o');
//     editor.print();  // Hello|

//     editor.moveLeft();
//     editor.moveLeft();
//     editor.print();  // Hel|lo

//     editor.deleteChar();
//     editor.print();  // He|lo

//     editor.cut(2);
//     editor.print();  // He|

//     editor.moveRight();
//     editor.paste();
//     editor.print();  // Helo|

//     return 0;
// }

#include <iostream>
#include <string>

class BrowserHistory {
private:
    struct Node {
        std::string url;
        Node* prev;
        Node* next;
        Node(const std::string& u) : url(u), prev(nullptr), next(nullptr) {}
    };

    Node* current;

public:
    BrowserHistory(const std::string& homepage) {
        current = new Node(homepage);
    }

    ~BrowserHistory() {
        while (current->prev) {
            current = current->prev;
        }
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void visit(const std::string& url) {
        // Delete forward history
        while (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }

        // Add new page --> adding new tail to our dll
        Node* newPage = new Node(url);
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }

    std::string back(int steps) {
        while (steps > 0 && current->prev) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    std::string forward(int steps) {
        while (steps > 0 && current->next) {
            current = current->next;
            steps--;
        }
        return current->url;
    }

    void printHistory() {
        Node* temp = current;
        while (temp->prev) {
            temp = temp->prev;
        }
        std::cout << "History: ";
        while (temp) {
            std::cout << temp->url;
            if (temp == current) {
                std::cout << "*";
            }
            if (temp->next) {
                std::cout << " <-> ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    BrowserHistory history("https://www.example.com");
    
    std::cout << "Initial state:" << std::endl;
    history.printHistory();

    history.visit("https://www.google.com");
    history.visit("https://www.github.com");
    std::cout << "\nAfter visiting Google and GitHub:" << std::endl;
    history.printHistory();

    std::cout << "\nGoing back 1 step: " << history.back(1) << std::endl;
    history.printHistory();

    history.visit("https://www.stackoverflow.com");
    std::cout << "\nAfter visiting Stack Overflow:" << std::endl;
    history.printHistory();

    std::cout << "\nGoing forward 1 step: " << history.forward(1) << std::endl;
    history.printHistory();

    std::cout << "\nGoing back 2 steps: " << history.back(2) << std::endl;
    history.printHistory();

    std::cout << "\nTrying to go back 3 more steps: " << history.back(3) << std::endl;
    history.printHistory();

    return 0;
}
 