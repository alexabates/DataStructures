#include<iostream>
#include<stdlib.h>
using namespace std;

class Queue
{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue();
        void enqueue(int x);
        int dequeue();
        void display();
};
Queue::Queue()
{
    cout<<"Enter the size of queue\n";
    cin>>size;
    size++; // Increment size to account for the circular behavior
    Q = new int[size];
    front = rear = 0; // Initialize front and rear to 0
}

void Queue::enqueue(int x)
{
    if ((rear+1)%size == front) // Queue is full when rear is right before front
        cout << "Queue is full\n";
    else {
        rear = (rear+1)%size; // Move rear circularly
        Q[rear] = x; // Insert the element
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear) // Queue is empty when front and rear are equal
        cout << "Queue is empty\n";
    else {
        front = (front+1)%size; // Move front circularly
        x = Q[front]; // Dequeue the element
    }
    return x;
}

void Queue::display()
{
    if (front == rear) {
        cout << "Queue is empty\n";
        return;
    }
    int i = front+1;
    do {
        cout << Q[i] << " "; // Display elements from front to rear
        i = (i+1)%size; // Move circularly
    } while (i != (rear+1)%size);
    cout << "\n";
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(67);
    cout << "Deleted " << q.dequeue() << endl;
    cout << "Deleted " << q.dequeue() << endl;
   
    q.display();
}
