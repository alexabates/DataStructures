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
//     LinkedList() : head(nullptr) {} //initially assigning the head as null pointer

//     // Function to insert a new element at the end of the list
//     void insert(T value) { //T value means it can be any data type
//         Node<T>* newNode = new Node<T>(value);
//         if (head == nullptr) { //if this is true, that means the linked list is currently empty
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

//doubly linked lists

#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to search for a value in the list
    bool search(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to remove the head node from the list
    void removeHead() {
        if (!head) {
            std::cout << "List is empty. No head to remove." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // Function to remove the tail node from the list
    void removeTail() {
        if (!tail) {
            std::cout << "List is empty. No tail to remove." << std::endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // Function to print the elements of the list
    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);

    std::cout << "Original list: ";
    dll.print();

    int searchValue = 3;
    std::cout << "Search for value " << searchValue << ": ";
    if (dll.search(searchValue))
        std::cout << "Found" << std::endl;
    else
        std::cout << "Not Found" << std::endl;

    std::cout << "Removing head..." << std::endl;
    dll.removeHead();
    std::cout << "List after removing head: ";
    dll.print();

    std::cout << "Removing tail..." << std::endl;
    dll.removeTail();
    std::cout << "List after removing tail: ";
    dll.print();

    return 0;
}
