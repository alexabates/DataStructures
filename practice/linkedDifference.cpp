#include <iostream>
#include <cmath> //for std::abs
using namespace std;

//definition for singly linked list node
class Node{
    public:
        int data;
        Node* next;

        //constructor
        Node(int x) : data(x), next(nullptr) {}
};

//class to handle linked list operations
class LinkedList{
    public:
        Node* head;

        //constructor 
        LinkedList() : head(nullptr) {}

        //function to add a node to the end of the list
        void append(int value){
            if(!head){
                head = new Node(value);
            } else {
                Node* current = head;
                while(current->next != nullptr){
                    current = current->next;
                }
                current->next = new Node(value);
            }
        }

        //function to find the max absolute difference between nodes
        int maxAbsDifference(){
            Node* curr = head;

            if(head == nullptr || head->next == nullptr){
                //if the lsit is empty or only has one node, return 0
                return 0;
            }

            int maxDifference = 0;

            while(curr->next != nullptr){
                //calculate the absolute difference between curr and next node
                int difference = abs(curr->next->data - curr->data);

                //update maxDifference if the current difference is greater
                if(difference > maxDifference){
                    maxDifference = difference;
                }

                //traverse through list
                curr = curr->next;
            }

            return maxDifference;
        }

        //destructor to free memory
        ~LinkedList(){
            Node* curr = head;
            while(curr != nullptr){
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
};

int main(){
    LinkedList list;
    list.append(10);
    list.append(15);
    list.append(3);
    list.append(8);
    list.append(12);
    
    //find and print the max absolute difference
    int result = list.maxAbsDifference();
    cout << "The highest absolute value difference is: " << result << endl;

    return 0;
}
