#include <iostream>
using namespace std;

void removeEvenIndex(int arr[], int &size){
    int shift = 0;
    for(int i = 0; i < size; i++){
        if(i % 2 == 0){
            shift++;
        } else {
            arr[i - shift] = arr[i];
        }
    }

    size -= (size + 1) / 2;
}

int main(){
    const int originalSize = 7;
    int arr[originalSize] = {10, 20, 30, 40, 50, 60};
    int size = originalSize;

    cout << "Original array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    removeEvenIndex(arr, size);

    cout << "New array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}