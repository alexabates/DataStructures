//Queue implementation by ARRAY

// #include <iostream>

// class Queue {
// private:
//     static const int MAX_SIZE = 100;  // Maximum size of the queue
//     int arr[MAX_SIZE];
//     int front, rear;

// public:
//     Queue() {
//         front = rear = -1;
//     }

//     bool isEmpty() {
//         return front == -1;
//     }
// /* for not full queue- suppose front is 2 and rear is 5 in a 6 element array. so now (rear + 1) % MAX_SIZE  will return 0 
// front is 2. So the queue is not full because 2!=0. New rear is 0
// for full queue- suppose front is 0(as we have not popped any element) and rear is 5 in a 6 element array. so now (rear + 1) % MAX_SIZE  will return 0 
// front is 2. So the queue is  full because 0==0. isEmpty() will be True
// */
//     bool isFull() {
//         return (rear + 1) % MAX_SIZE == front;
//     }

//     void enqueue(int value) {
//         if (isFull()) {
//             std::cout << "Queue is full. Cannot enqueue.\n";
//             return;
//         }

//         if (isEmpty()) {
//             front = rear = 0;
//         } else {
//             rear = (rear + 1) % MAX_SIZE;
//         }

//         arr[rear] = value;
//         std::cout << value << " enqueued to the queue.\n";
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             std::cout << "Queue is empty. Cannot dequeue.\n";
//             return;
//         }

//         std::cout << arr[front] << " dequeued from the queue.\n";

//         if (front == rear) {
//             front = rear = -1;
//         } else {
//             front = (front + 1) % MAX_SIZE;
//         }
//     }

//     int peek() {
//         if (isEmpty()) {
//             std::cout << "Queue is empty. Cannot peek.\n";
//             return -1;  // Assuming -1 as an error value
//         }

//         return arr[front];
//     }
// };

// int main() {
//     Queue myQueue;

//     myQueue.enqueue(10);
//     myQueue.enqueue(20);
//     myQueue.enqueue(30);

//     std::cout << "Front element: " << myQueue.peek() << "\n";

//     myQueue.dequeue();
//     myQueue.dequeue();
//     myQueue.dequeue();

//     myQueue.enqueue(40);

//     std::cout << "Front element: " << myQueue.peek() << "\n";

//     return 0;
// }


//-------



//Queue implementation from LINKED LISTS

// #include <iostream>

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int value) : data(value), next(nullptr) {}
// };

// class Queue {
// private:
//     Node* front;
//     Node* rear;

// public:
//     Queue() : front(nullptr), rear(nullptr) {}

//     bool isEmpty() {
//         return front == nullptr;
//     }

//     void enqueue(int value) {
//         Node* newNode = new Node(value);

//         if (isEmpty()) {
//             front = rear = newNode;
//         } else {
//             rear->next = newNode;
//             rear = newNode;
//         }

//         std::cout << value << " enqueued to the queue.\n";
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             std::cout << "Queue is empty. Cannot dequeue.\n";
//             return;
//         }

//         Node* temp = front;
//         std::cout << temp->data << " dequeued from the queue.\n";

//         front = front->next;
//         delete temp;

//         if (front == nullptr) {
//             rear = nullptr;
//         }
//     }

//     int peek() {
//         if (isEmpty()) {
//             std::cout << "Queue is empty. Cannot peek.\n";
//             return -1;  // Assuming -1 as an error value
//         }

//         return front->data;
//     }
// };

// int main() {
//     Queue myQueue;

//     myQueue.enqueue(10);
//     myQueue.enqueue(20);
//     myQueue.enqueue(30);

//     std::cout << "Front element: " << myQueue.peek() << "\n";

//     myQueue.dequeue();
//     myQueue.dequeue();
//     myQueue.dequeue();

//     myQueue.enqueue(40);

//     std::cout << "Front element: " << myQueue.peek() << "\n";

//     return 0;
// }



//-------



// #include <iostream>

// template <typename T>
// class Deque {
// private:
//     struct Node {
//         T data;
//         Node* prev;
//         Node* next;
//         Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
//     };

//     Node* head;
//     Node* tail;
//     size_t size;

// public:
//     Deque() : head(nullptr), tail(nullptr), size(0) {}

//     ~Deque() {
//         clear();
//     }

//     bool empty() const {
//         return size == 0;
//     }

//     size_t getSize() const {
//         return size;
//     }

//     void pushFront(const T& value) {
//         Node* newNode = new Node(value);
//         if (empty()) {
//             head = tail = newNode;
//         } else {
//             newNode->next = head;
//             head->prev = newNode;
//             head = newNode;
//         }
//         size++;
//     }

//     void pushBack(const T& value) {
//         Node* newNode = new Node(value);
//         if (empty()) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//         size++;
//     }

//     void popFront() {
//         if (empty()) {
//             std::cerr << "Deque is empty. Cannot pop from front.\n";
//             return;
//         }
//         Node* temp = head;
//         head = head->next;
//         if (head)
//             head->prev = nullptr;
//         else
//             tail = nullptr;
//         delete temp;
//         size--;
//     }

//     void popBack() {
//         if (empty()) {
//             std::cerr << "Deque is empty. Cannot pop from back.\n";
//             return;
//         }
//         Node* temp = tail;
//         tail = tail->prev;
//         if (tail)
//             tail->next = nullptr;
//         else
//             head = nullptr;
//         delete temp;
//         size--;
//     }

//     T& front() const {
//         if (empty()) {
//             throw std::out_of_range("Deque is empty. Cannot access front element.");
//         }
//         return head->data;
//     }

//     T& back() const {
//         if (empty()) {
//             throw std::out_of_range("Deque is empty. Cannot access back element.");
//         }
//         return tail->data;
//     }

//     void clear() {
//         while (!empty()) {
//             popFront();
//         }
//     }
// };

// int main() {
//     Deque<int> dq;
//     dq.pushBack(1);
//     dq.pushBack(2);
//     dq.pushFront(0);
//     std::cout << "Front: " << dq.front() << std::endl;
//     std::cout << "Back: " << dq.back() << std::endl;

//     dq.popBack();
//     std::cout << "After popping back, Back: " << dq.back() << std::endl;

//     dq.popFront();
//     std::cout << "After popping front, Front: " << dq.front() << std::endl;

//     return 0;
// }


//--------



///implementing queue using stack
// #include <stack>

// class MyQueue {
// private:
//     std::stack<int> inStack;  // Stack to store elements as they are enqueued
//     std::stack<int> outStack; // Stack to store elements in reverse order for dequeuing

//     // Helper function to transfer elements from inStack to outStack
//     void transferElements() {
//         // While inStack is not empty
//         while (!inStack.empty()) {
//             // Pop the top element from inStack
//             // and push it onto outStack
//             outStack.push(inStack.top());
//             inStack.pop();
//         }
//     }

// public:
//     MyQueue() {}  // Default constructor

//     // Enqueue operation: Add an element to the end of the queue
//     void enqueue(int x) {
//         // Push the element onto inStack
//         inStack.push(x);
//     }

//     // Dequeue operation: Remove and return the element at the front of the queue
//     int dequeue() {
//         // If outStack is empty
//         if (outStack.empty()) {
//             // Transfer all elements from inStack to outStack
//             transferElements();
//         }

//         // Get the front element from the top of outStack
//         int frontElement = outStack.top();
//         // Remove the front element from outStack
//         outStack.pop();
//         // Return the front element
//         return frontElement;
//     }

//     // Peek operation: Return the element at the front of the queue without removing it
//     int peek() {
//         // If outStack is empty
//         if (outStack.empty()) {
//             // Transfer all elements from inStack to outStack
//             transferElements();
//         }

//         // Return the top element of outStack (which is the front element)
//         return outStack.top();
//     }

//     // Check if the queue is empty
//     bool isEmpty() {
//         // The queue is empty if both inStack and outStack are empty
//         return inStack.empty() && outStack.empty();
//     }
// };



//--------

//Palindrome example

#include <iostream>
#include <string>
#include <deque>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        std::deque<char> charDeque;
        
        // Step 1: Clean the string and push characters to deque
        for (char c : s) {
            if (std::isalnum(c)) {
                charDeque.push_back(std::tolower(c));
            }
        }
        
        // Step 2: Compare characters from both ends
        while (charDeque.size() > 1) {
            if (charDeque.front() != charDeque.back()) {
                return false;
            }
            charDeque.pop_front();
            charDeque.pop_back();
        }
        
        return true;
    }
};

// Test the solution
int main() {
    Solution solution;
    
    std::cout << std::boolalpha; // To print true/false instead of 1/0
    
    // Test cases
    std::cout << solution.isPalindrome("A man, a plan, a canal: Panama") << std::endl; // Expected: true
    std::cout << solution.isPalindrome("race a car") << std::endl; // Expected: false
    std::cout << solution.isPalindrome(" ") << std::endl; // Expected: true
    std::cout << solution.isPalindrome("Madam, I'm Adam") << std::endl; // Expected: true
    
    return 0;
}



//--------



// #include <iostream>
// #include <deque>

// class RecentCounter {
// private:
//     std::deque<int> calls;

// public:
//     RecentCounter() {
//         // No initialization needed for the deque
//     }
    
//     int ping(int t) {
//         // Add the new call to the deque
//         calls.push_back(t);
        
//         // Remove calls older than t - 3000
//         while (!calls.empty() && calls.front() < t - 3000) {
//             calls.pop_front();
//         }
        
//         // Return the number of calls in the last 3000 ms
//         return calls.size();
//     }
// };

// // Test the solution
// int main() {
//     RecentCounter* recentCounter = new RecentCounter();
    
//     std::cout << recentCounter->ping(1) << std::endl;    // Output: 1
//     std::cout << recentCounter->ping(100) << std::endl;  // Output: 2
//     std::cout << recentCounter->ping(3001) << std::endl; // Output: 3
//     std::cout << recentCounter->ping(3002) << std::endl; // Output: 3
    
//     delete recentCounter;
//     return 0;
// }

//--------

'''
Given an array of integers and a sliding window size k, 
find the maximum value in each sliding window of size k.
'''
// #include <iostream>
// #include <vector>
// #include <deque>
// using namespace std;

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> result;  // To store the maximum values for each window
//     deque<int> dq;       // Deque to store indices of potential maximum elements

//     for (int i = 0; i < nums.size(); ++i) {
//         // Remove the front element if it's outside the current window
//         if (!dq.empty() && dq.front() == i - k) {
//             dq.pop_front();
//         }

//         // Remove elements smaller than the current element from the back
//         // This maintains a decreasing order of elements in the deque
//         while (!dq.empty() && nums[dq.back()] < nums[i]) {
//             dq.pop_back();
//         }

//         // Add the current element's index to the back of the deque
//         dq.push_back(i);

//         // If we have processed at least k elements, start adding to result
//         if (i >= k - 1) {
//             // The front of the deque always contains the maximum for the current window
//             result.push_back(nums[dq.front()]);
//         }
//     }

//     return result;
// }

// int main() {
//     // Example input
//     vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
//     int k = 3;  // Window size

//     // Call the function to get the maximum values for each sliding window
//     vector<int> result = maxSlidingWindow(nums, k);

//     // Print the result
//     for (int val : result) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }