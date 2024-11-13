#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        <T> data;
        Node* next;

        //constructor
        Node(T value) : data(value), next(nullptr){}
};

template <typename T>
class LinkedList {
    private:
        Node* head;

    public:
        //constructor
        LinkedList() : head(nullptr){} 

        void insert(T value){
            Node<T>* newNode = new Node<T>(value);
            Node<T>* current = head;
            if(head == nullptr){
                head = newNode;
            } else{
                while(current->next != nullptr){
                current = current->next;
                }
                current->next = newNode;
            }
        }

        void insertFront(T value){
            Node<T>* newNode = new Node<T>(value);
            newNode->next = head;
            head = newNode;
        }

        void insertAfter(T valueToFind, T valueToInsert){
            Node<T>* newNode = new Node<T>(value);
            Node<T>* current = head;
            while(current != nullptr && current->data != valueToFind){
                current = current->next;
            }
            if(current != nullptr){ //if current == nullptr, then the valueToFind was never found
                newNode->next = current->next;
                current->next = newNode; 
            }  
        }

        bool search(T value){
            Node<T>* current = head;
            while(current != nullptr){
                if(current->data == value){
                    return true;
                }
                current = current->next;
            }
        }

        void removeHead(){
            if(head == nullptr){
                cout << "The list is empty. There is no head to be removed." << endl;
                return;
            }

            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }

        void display(){
            Node<T>* current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
        }

        //destructor
        ~LinkedList(){
            Node<T>* current = head;
            Node<T>* nextNode;
            while(current != nullptr){
                nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
};