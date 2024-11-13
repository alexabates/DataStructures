// doubly linked lists

#include <iostream>
#include <string> 
using namespace std;

class Node{
    public:
        Node(){prev = nullptr; next = nullptr;}
    private:
        Node *prev;
        int data;
        Node *next;
        friend class LinkedList;
};

class LinkedList{
    private:
        int numNodes;
        Node *head;
    public:
        LinkedList();
        ~LinkedList();
        void addBack(int x);
        void addFront(int x);
        int removeFront();
        void print();
        int getSize(){return numNodes;}
        void addAfterIndex(int index, int x);
};

LinkedList :: LinkedList(){
    head = nullptr;
    numNodes = 0;
}

LinkedList :: ~LinkedList(){
    while(head != nullptr){
        removeFront();
    }
}

void LinkedList :: addBack(int x){
    Node *newNode = new Node;
    newNode->data = x;
    if(head == nullptr){
        head = newNode;
    } 
    Node *curr = head;
    for(int i = 0; curr->next != nullptr; i++){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
}

void LinkedList :: addFront(int x){
    Node *newNode = new Node;
    newNode->data = x;

    if(head == nullptr){
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    numNodes++;
}

int LinkedList :: removeFront(){
    if(head == nullptr){
        cout << "The list is already empty" << endl;
        return -1;
    }
    Node *temp = head;
    int num = head->data;
    head = head->next;

    if(head != nullptr){
        head->prev = nullptr;
    }

    delete temp;
    return num;
}

void LinkedList :: addAfterIndex(int index, int x){
    Node *t = new Node;
    t->data = x;

    Node *before = head;

    for(int i = 0; i < index; i++){
        before = before->next;
    }

    Node *after = before->next;

    t->prev = before;
    t->next = after;
    before->next = t;
    after->prev = t;

    numNodes++;
}

void LinkedList :: print(){
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
}