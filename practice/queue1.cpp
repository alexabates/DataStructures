#include <iostream>
#include <queue>
using namespace std;

class MyStack{
    private:
        queue<int> queue1;
        queue<int> queue2;

    public:
        MyStack(){};

        void push(int x){
            queue1.push(x);
        }

        int pop(){
            //move all elements except the last one to queue 2
            while(queue1.size() > 1){
                queue2.push(queue1.front());
                queue1.pop();
            }

            int topElement = queue1.front();
            queue1.pop();

            //swap queue1 and queue2
            swap(queue1, queue2);

            return topElement;
        }

        int top(){
            //move all elements except the last one to queue2
            while(queue1.size() > 1){
                queue2.push(queue1.front());
                queue1.pop();
            }

            //the lest element in queue1 is the top of the stack
            int topElement = queue1.front();

            //move the last element to queue2
            queue2.push(queue1.front());
            queue1.pop();

            swap(queue1, queue2);

            return topElement;
        }

        bool empty(){
            return queue1.empty();
        }
};

int main(){
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << "Top of stack: " << stack.top() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Is empty: " << boolalpha << stack.empty() << endl;

}