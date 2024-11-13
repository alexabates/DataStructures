#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};


class Queue {
private:
    Node *front;
    Node *rear;

public:
    Queue() { front = rear = NULL; }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x) {
    Node *t = new Node;
    if (t == NULL) {
        cout << "Queue is full\n";
    } else {
        t->data = x;
        t->next = NULL;
        if (front == NULL) {
            front = rear = t; // If queue is empty, front and rear are the same
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue() {
    int x = -1;
    Node *t;
    if (front == NULL) {
        cout << "Queue is empty\n";
    } else {
        t = front;
        x = t->data;
        front = front->next; // Move front to the next node
        if (front == NULL) { // If the queue is now empty, set rear to NULL too
            rear = NULL;
        }
        delete t;
    }
    return x;
}

void Queue::display() {
    Node *i = front;
    if (i == NULL) {
        cout << "Queue is empty\n";
    } else {
        while (i != NULL) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << "\n";
    }
}

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    cout << "Deleted " << q.dequeue() << endl;
    
    q.enqueue(14);
    q.enqueue(15);
    
    q.display();
}
