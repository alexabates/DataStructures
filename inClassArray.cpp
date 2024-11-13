// #include <iostream>
// using namespace std;

// const int SIZE = 5;
// void printarray(int arr[], int size){

//     for(int i = 0; i <= size; i++){
//         cout << arr[i] << endl;
//     }
// }

// void insertArray(int arr[], int pos, int value){
//     if(pos < 0 || pos > SIZE){
//         cout << "invalid position" << endl;
//         return;
//     }
//     //shifting all the elements to the right to make space
//     for(int i = SIZE; i > pos; --i){
//         arr[i] = arr[i - 1];
//     }
//     arr[pos] = value;
// }

// int main(){

//     int arr[SIZE]={1,2,3,4,5};
//     int size = 5;

//     printarray(arr, size);
//     int val = 8;
//     insertArray(arr, 0, val);
//     printarray(arr, size);

//     return 0;
// }

#include <vector>
#include <iostream>
using namespace std;

int main(){

    vector <int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.insert(vec1.begin(), 5); //{5,10,20}
    cout << vec1[0] << endl;
    cout << vec1[1] << endl;
    cout << vec1.back() << endl; //prints the last element
    vec1.pop_back(); //deletes the last element
    cout << vec1.back() << endl; //{5,10}

    // vec1.clear(); //removes all elements

    for(const auto elem: vec1){
        cout << elem << endl;
    }

    return 0;
}