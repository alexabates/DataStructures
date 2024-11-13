#include <iostream>
#include <vector>
using namespace std;

//using vector (dynamic array)
void reverseArray(vector<int>& arr){
    int start = 0;
    int end = arr.size() - 1;

    //swap elements from the start and end until they meet in the middle
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

//using a fixed-sized array
/*
void reverseArray(int arr[], int size){
    int start = 0;
    int end = size - 1;

    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}
*/
int main(){
    vector<int> arr = {10, 20, 30};

    cout << "Original array: ";
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    reverseArray(arr);

    cout << "Reversed array: ";
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}