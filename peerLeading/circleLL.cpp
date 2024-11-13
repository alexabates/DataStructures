// circularly linked lists
#include <iostream>
using namespace std;

class Node{
    public:
        Node(int x){data = x}; //allows us to pass and integer to the node when initializing a new node

    private:
        int data;
        Node *next;
        friend class CircularLL;
};

class CircularLL{
    private:
        Node *head;
        Node *tail;
        int numNodes;

    public: 
        CircularLL();
        ~CircularLL();
        void addBack(int x);
        void addFront(int x);
        int removeFront();
        void print();
        int getSize(){return numNodes};
};

CircularLL :: CircularLL(){
    head = nullptr;
    tail = nullptr;
    numNodes = 0;
}

CircularLL :: ~CircularLL(){
    while(numNodes > 0){
        removeFront();
    }
}

void CircularLL :: addBack(int x){
    Node *newNode = new Node(x);

    if(head == nullptr){ //if list is empty
        head = newNode;
        tail = newNode;
        tail->next = head; 
    } else {
        newNode->next = head;
        tail = newNode;
        tail->next = head;
    }
    numNodes++;
}

void CircularLL :: addFront(int x){
    Node *newNode = new Node(x);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    numNodes++;
}

int CircularLL :: removeFront(){
    if(head == nullptr){
        cout << "The list is already empty" << endl;
        return -1;
    }
    
    Node *temp = head;
    int data = head->data; 

    if(head == tail){ //when there is only one node
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;
    }
    delete temp;
    numNodes--;
    return data;
}

void CircularLL :: print(){
    if(head == nullptr){
        cout << "The list is empty" << endl;
        return;
    } 
    Node *curr = head;
    do{
        cout << curr->data << " ";
        curr = curr->next;
    } while(curr != head);
    cout << endl;
}