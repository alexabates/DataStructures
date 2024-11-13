#include <iostream>
using namespace std;

class ArrayVector {
private:
    int *arr;
    int capacity;
    int current;

public:
    ArrayVector() {
        arr = new int[1];
        capacity = 1;
        current = 0;
    }

    void push_back(int x) {
        if (current == capacity) {
            int *temp = new int[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity *= 2; //updates the capacity within the whole code
        }
        arr[current] = x;
        current++;
    }

    void pop_back() {
        if (current > 0) {
            current--;
        } else {
            cerr << "Cannot pop from an empty vector." << endl;
        }
    }

    void insert(int index, int x) {
        if(current == capacity){
            push_back(x);
        } else {
            arr[current] = x;
        }
    }

    int size() {
        return current;
    }

    int get(int index) {
        if (index < 0 || index >= current) {
            cerr << "Index out of range." << endl;
            exit(1);
        }
        return arr[index];
    }

    // Define an operator
    int& operator[](int index) {
        if (index < 0 || index >= current) {
            cerr << "Index out of range." << endl;
            exit(1);
        }
        return arr[index];
    }

    void set(int index, int x) {
        if (index < 0 || index >= current) {
            cerr << "Index out of range." << endl;
            return;
        }
        arr[index] = x;
    }

    void clear() {
        current = 0;
    }

    ~ArrayVector() {
        delete[] arr;
    }
};

int main() {
    ArrayVector vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    cout << "Size: " << vec.size() << endl;

    vec[3] = 100;
    cout << "Elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Test insert
    vec.insert(2, 50);
    cout << "After inserting 50 at index 2: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Test pop_back
    vec.pop_back();
    cout << "After pop_back: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}