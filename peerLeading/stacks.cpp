#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top;

    public:
        Stack();
        ~Stack();
        void push(int x);
        int pop();
        int peek(int pos);
        int isEmpty();
        int stackTop();
        void display();
};

void Stack :: display(){
    Node *p = top;
    while(p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Stack :: Stack(){
    top = nullptr;
}

Stack :: ~Stack(){
    Node *p = top;
    while(top != nullptr){
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack :: push(int x){
    Node *t = new Node;
    t->data = x;
    t->next = top;
    top = t;
}

int Stack :: pop(){
    if(top == nullptr){
        cout << "Stack underflow" << endl;
        return -1;
    } 
    Node *p = top;
    int x = p->data;

    top = top->next;
    delete p;
    return x;
}

int Stack :: isEmpty(){
    if(top != nullptr){
        return 0;
    } else {
        return 1;
    }
}

int Stack :: stackTop(){
    if(top != nullptr){
        return top->data;
    } else {
        return -1;
    }
    
}

int Stack :: peek(int pos){
    if(isEmpty()){
        return -1;
    } else {
        Node *p = top;
        for(int i = 0; i < (pos - 1); i++){
            p = p->next;
        }
        if(p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}

int main(){
    Stack stk;
    stk.push(7);
    stk.push(5);
    stk.push(9);
    stk.push(19);
    stk.display();
    cout << stk.peek(3) << endl;

}