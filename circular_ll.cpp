// #include <iostream>

// // Node structure for circular linked list
// struct Node {
//     int data;
//     Node* next;

//     Node(int value) : data(value), next(nullptr) {}
// };



// /*
// When a function takes a parameter by reference, any changes made to the parameter
//  within the function will affect the original object that was passed in. In this specific function:


// void removeAfterCursor(Node*& head, int cursorValue) {
   
// }
// head is a reference to the original head pointer of the linked list.
// The reference allows the function to modify the original head pointer, including 
// updating it to point to a different node if needed.
// So, when the function updates head, the changes will be reflected outside the 
// function, affecting the original pointer that was passed to the function. 
// This is different from passing a pointer by value (Node* head) 
// where modifications to the pointer inside the 
// function wouldn't affect the original pointer outside the function.

// */
// // Function to insert a new node at the end of the circular linked list
// void insertEnd(Node*& head, int value) {    //Node*&- pointer to a pointer
//     Node* newNode = new Node(value);

//     if (!head) {
//         // If the list is empty, make the new node the head and point it to itself
//         head = newNode;
//         head->next = head;
//     } else {
//         // Otherwise, insert the new node at the end
//         Node* current = head;
//         while (current->next != head) {
//             std::cout <<"skipped value"<< current->data << " ";
//             current = current->next;
            
//         }
//         current->next = newNode;
//         newNode->next = head;
//     }
// }

// void removeAfterCursor(Node*& head, int cursorValue) {  //Node*&- pointer to a pointer
//     if (!head || !head->next) {
//         // Empty list or a list with a single node, can't remove after cursor
//         return;
//     }

//     Node* cursor = head;
//     while (cursor->next != head) {
//         if (cursor->data == cursorValue) {
//             // Found the cursor node
//             Node* nodeToRemove = cursor->next;
//             if (nodeToRemove == head) {
//                 // If the node to remove is the head, update the head
//                 head = nodeToRemove->next;
//             }
//             cursor->next = nodeToRemove->next;
//             delete nodeToRemove;
//             return;
//         }
//         cursor = cursor->next;
//     }
// }

// // Function to print the circular linked list
// void printList(const Node* head) {
//     if (!head) {
//         // Empty list
//         return;
//     }

//     const Node* current = head;
//     do {
//         std::cout << current->data << " ";
//         current = current->next;
//     } while (current != head);

//     std::cout << std::endl;
// }

// bool searchInCircularList( Node* head, int target) {
//     if (!head) {
//         // Empty list
//         return false;
//     }

//     Node* current = head;
//     while (current->next != head) {
//         if (current->data == target) {
//             // Value found in the circular linked list
//             return true;
//         }
//         current = current->next;
//     }

//     // Check the last node
//     if (current->data == target) {
//         // Value found in the circular linked list
//         return true;
//     }

//     // Value not found in the circular linked list
//     return false;
// }


// int main() {
//     // Sample usage
//     Node* head = nullptr;

//     // Insert elements at the end
//     insertEnd(head, 1);
//     insertEnd(head, 2);
//     insertEnd(head, 3);
//     insertEnd(head, 4);

//     // std::cout << "Original Circular Linked List: ";
//     // printList(head);

//     // Remove after cursor (e.g., after node with value 2)
//     // int cursorValue = 2;
//     // removeAfterCursor(head, cursorValue);

//     // std::cout << "Circular Linked List after removal: ";
//     // // printList(head);


//     // Search for a value (e.g., value 3)
//     // int searchValue = 3;
//     // if (searchInCircularList(head, searchValue)) {
//     //     std::cout << "Value " << searchValue << " found in the circular linked list." << std::endl;
//     // } else {
//     //     std::cout << "Value " << searchValue << " not found in the circular linked list." << std::endl;
//     // }

//     // Free the allocated memory
//     Node* current = head;
//     Node* nextNode;
//     do {
//         nextNode = current->next;
//         delete current;
//         current = nextNode;
//     } while (current != head);

//     return 0;
// }


/* application- music playlist*/

#include <iostream>
#include <string>

class MusicPlaylist {
private:
    struct Song {
        std::string title;
        Song* next;
        Song(const std::string& t) : title(t), next(nullptr) {}
    };

    Song* current;

public:
    MusicPlaylist() : current(nullptr) {}

    ~MusicPlaylist() {
        if (!current) return;
        Song* start = current;
        do {      //destructor
            Song* temp = current;
            current = current->next;
            delete temp;
        } while (current != start);
    }

    void addSong(const std::string& title) {
        Song* newSong = new Song(title);
        if (!current) { //if playlist is null
            current = newSong;
            current->next = current; // Point to itself to form a circle
        } else {
            newSong->next = current->next;
            current->next = newSong;
        }
    }

    void play() {
        if (!current) {
            std::cout << "Playlist is empty." << std::endl;
            return;
        }
        std::cout << "Now playing: " << current->title << std::endl;
    }

    void nextSong() {
        if (current) {
            current = current->next;
        }
    }

    void displayPlaylist() {
        if (!current) {
            std::cout << "Playlist is empty." << std::endl;
            return;
        }
        Song* start = current;
        do {
            std::cout << current->title << " -> ";
            current = current->next;
        } while (current != start);
        std::cout << "Repeat" << std::endl;
        current = start; // Reset to starting position
    }
};

int main() {
    MusicPlaylist playlist;

    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");

    std::cout << "Initial playlist:" << std::endl;
    playlist.displayPlaylist();

    std::cout << "\nPlaying songs:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        playlist.play();
        playlist.nextSong();
    }

    return 0;
}