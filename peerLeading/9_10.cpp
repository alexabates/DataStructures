#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        Node(){}

    private:
        int data;
        Node *next;
        friend class linkedList; // linkedList can gain access to private variables

};

class linkedList{
    public:
        linkedList();
        ~linkedList(); //destructor
        bool isEmpty() const;
        void addFront(int x);
        int removeFront();
        void print();
        int getSize();
        void addBack(int x);
        void addAfterIndex(int index, int x);

    private:
        int numNodes;
        Node *head;
};

linkedList :: linkedList(){ //defining constructor
    head = nullptr;
}

linkedList :: ~linkedList(){ //defining destructor

    while( head != nullptr ){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

bool linkedList :: isEmpty() const{
    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}

void linkedList :: addFront(int x){
    Node *t = new Node; //how to create a new node
    t -> data = x //stores x inside of node
    t -> next = head;
    head = t;
    numNodes++;
}

int linkedList :: removeFront(){
    Node *temp = head;
    head = head->next;
    int num = temp->data; 
    delete temp;
    numNodes--;
    return num;
}

void linkedList :: print(){
    Node *temp = head;
    while(temp != nullptr){
        cout << temp->data << " " <<;
        temp = temp->next;
    }
    cout << endl;
}

int linkedList :: getSize(){
    return numNodes;
}

void linkedList :: addBack(int x){
    Node *curr = head;
    while(curr-> != nullptr){
        curr = curr->next;
    }
    Node *t = new Node; 
    t->data = x;
    t->next = nullptr;
    curr->next = t;
    numNodes++;
}

void  linkedList :: addAfterIndex(int index, int x){
    Node *newNode = new Node;
    newNode->data = x;

    Node *curr = head;
    for(int i = 0; i < index; i++){
        curr = curr->next;
    }
    Node *nextBeforeInsertion = curr->next;
    curr->next = newNode;
    newNode->next = nextBeforeInsertion;
    numNodes++;
}

int main(){
    
}